//#define DEBUG
#include "stm32f4xx_conf.h"
#include "../common/delay.h"
#include "gpio.h"
#include "led.h"
#include "i2c.h"
#include "usart.h"
#include "spi.h"
#include "can.h"
#include "tim.h"
#include "flight_controller.h"

#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"
#include "semphr.h"
#include "timers.h"

#include "global.h"
#include "communication.h"
#include "system_time.h"
#include "lea6h_ubx.h"
extern uint8_t estimator_trigger_flag;

/* FreeRTOS */
extern xSemaphoreHandle serial_tx_wait_sem;
extern xQueueHandle serial_rx_queue;
extern xQueueHandle gps_serial_queue;
extern xSemaphoreHandle usart3_dma_send_sem;
xTimerHandle xTimers[1];

void vApplicationStackOverflowHook( xTaskHandle xTask, signed char *pcTaskName );
void vApplicationIdleHook(void);
void vApplicationMallocFailedHook(void);
void boot_time_timer(void);
void gpio_rcc_init(void);
void gpio_rcc_init(void)
{
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA | RCC_AHB1Periph_GPIOB | 
	RCC_AHB1Periph_GPIOC | RCC_AHB1Periph_GPIOD | RCC_AHB1Periph_GPIOE,  ENABLE);	
}

void vApplicationStackOverflowHook( xTaskHandle Task __attribute__ ((unused)), signed char *pcTaskName __attribute__ ((unused)))
{
	while(1);

}
void vApplicationIdleHook(void)
{

}
void vApplicationMallocFailedHook(void)
{
	while(1);
}
void rx_dma_test(void)
{
	bool is_first = true;
	uint8_t previous_num;
	int32_t total_data_count = 0;
	int32_t lost_data_count = 0;
	char msg_buffer[256];
	while(1) {
		uint8_t ch = (uint8_t)usart3_read();
		total_data_count++;

		if (is_first) {


			is_first = false;
		} else {

			previous_num++;
			if ( previous_num != ch ) {

				lost_data_count ++;
				sprintf(msg_buffer, " [%u] is not matched with [%u] \r\n", previous_num, ch);
				usart2_dma_send((uint8_t*)msg_buffer);
			}
		}
		previous_num = ch;

		if ( (total_data_count%1000) == 0) {
			sprintf(msg_buffer, "got %ld bytes, lost %ld byte \r\n"
				,total_data_count
				,lost_data_count);
			//usart3_dma_send((uint8_t*)msg_buffer, strlen(msg_buffer));
			usart2_dma_send((uint8_t*)msg_buffer);
		}
	}
}
int main(void)
{
	vSemaphoreCreateBinary(serial_tx_wait_sem);
	serial_rx_queue = xQueueCreate(256, sizeof(serial_msg));
	gps_serial_queue = xQueueCreate(5, sizeof(serial_msg));
	vSemaphoreCreateBinary(flight_control_sem);
	vSemaphoreCreateBinary(usart3_dma_send_sem);
	/* Global data initialazition */
	init_global_data();

	/* Hardware initialization */
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_4);
	gpio_rcc_init();
	led_init();
	usart_init();
	spi_init();
	pwm_input_output_init();
	init_pwm_motor();
	i2c_Init();
	usart2_dma_init();

	CAN2_Config();
	CAN2_NVIC_Config();
	usart3_dma_rx_setup();
	/* Register the FreeRTOS task */
	/* Flight control task */
	xTaskCreate(
		(pdTASK_CODE)rx_dma_test,
		(signed portCHAR*)"",
		4096,
		NULL,
		tskIDLE_PRIORITY + 9,
		NULL
	);

	vTaskStartScheduler();

	return 0;
}

