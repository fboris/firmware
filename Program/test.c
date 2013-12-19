#include "stm32f4_system.h"
#include "module_rs232.h"
#include "module_nrf24l01.h"
#include "algorithm_string.h"
#include <unistd.h>
#include <stdarg.h>
/*=====================================================================================================*
**函數 : test_printf
**功能 :
**輸入 :
**輸出 :
**使用 :
**=====================================================================================================*/

void test_printf(void)
{
	/*test printf can support USART*/
	float f1 = 5.04, f2 = 0xFFFF, f3 = 0xFFFFFFFF - 1;
	int i1 = -23, i2 = 56, i3 = 0xFFFF;
	printf("test printf!\n\r");
	printf("float: 5.04=%f, 0xFFFF = %f, 0xFFFFFFF = %f\n\r", f1, f2, f3);
	printf("int: -23 = %d, 56 = %d, 0xFFFF = %d\n\r", i1, i2, i3);

	

}

/*=====================================================================================================*
**函數 : test_puts
**功能 : 
**輸入 : 
**輸出 : 
**使用 : 
**=====================================================================================================*/

void test_puts(void)
{
	char str[]="Hello puts.";
	puts(str);
}

/*=====================================================================================================*
**函數 : test_nRF
**功能 :
**輸入 :
**輸出 :
**使用 :
**=====================================================================================================*/

void test_nRF(void)
{
	uint8_t TxBuff[] = "123";
	printf("Tx mode test...\n\r");
	nRF_TX_Mode();
	uint8_t Sta = 0;

	do {
		printf("Transmit : 123 ");
		Sta = nRF_Tx_Data("123");
	} while (Sta == MAX_RT);
}

/*=====================================================================================================*
**函數 : test_Xbee
**功能 :
**輸入 :
**輸出 :
**使用 :
**=====================================================================================================*/

void test_Xbee(void)
{
	char String[50] ;
	char x;
	printf("Test Xbee .....\n\r");

	while (1) {
		x = getch_base();
		printf("%c\n\r", x);
	}
}

/*=====================================================================================================*
**函數 : test_gets
**功能 :
**輸入 :
**輸出 :
**使用 :
**=====================================================================================================*/

void test_gets(void)
{
	printf("\n\n\r");
	printf("Please, input the word....\n\r");
	while(1){
		gets();
	}
}