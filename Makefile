export WORKSPACE_DIR=./program
export CONFIG_DIR=./configuration
#Primary firmware target
export FIRMWARE=./firmware

#
#include .mk
include $(WORKSPACE_DIR)/makefiles/toolchain.mk
include $(WORKSPACE_DIR)/makefiles/workspace.mk

#
#some config variable, leave this to user
BOARD_NAME?=vertigo
BOARD_VERSION?=2.1

#apply configurations
ifeq ($(BOARD_NAME),vertigo)
  ifeq ($(BOARD_VERSION),2.1)
    include $(CONFIG_DIR)/board/$(BOARD_NAME)/$(BOARD_VERSION)/board_config.mk
  else ifeq ($(BOARD_VERSION),2.2)
    include $(CONFIG_DIR)/board/$(BOARD_NAME)/$(BOARD_VERSION)/board_config.mk
  else
  $(error Not a valid version)
  endif

else
  $(error Not a valid name of board)
endif


OBJS = $(sort $(patsubst %c, %o, $(SRCS) ))


#
#make target
all: $(FIRMWARE).bin $(FIRMWARE).elf

	@echo "________________________________________________________________"
	@echo "Build Summary:"
	@echo "BOARD_NAME=$(BOARD_NAME) VERSION=$(BOARD_VERSION)"
	@echo "________________________________________________________________"
include $(WORKSPACE_DIR)/makefiles/rules.mk

clean:
	rm -rf $(STARTUP_OBJ)
	rm -rf $(FIRMWARE).elf
	rm -rf $(FIRMWARE).bin
	rm -f $(OBJS)
	rm -f $(DEPS)
#
#upload firmware through st-flash
flash:
	st-flash write $(FIRMWARE).bin 0x8000000

#
#create gdb server through openocd
openocd: flash
	openocd -f ./program/openocd.cfg

#
#execute cgdb 
cgdb:
	cgdb -d $(GDB) -x ./program/openocd_gdb.gdb

#
#execute gdbtui
gdbtui:
	$(GDB) -tui -x ./program/openocd_gdb.gdb

#
#upload firmware through black magic probe
flash_bmp:
	$(GDB) firmware.elf -x ./program/gdb_black_magic.gdb
#
#execute and connect to black magic gdb server, no needs to open a
#local sever in PC
cgdb_bmp:
	cgdb -d $(GDB) firmware.elf -x ./program/bmp_gdbinit.gdb
flash_openocd:
	openocd -f interface/stlink-v2.cfg \
	-f target/stm32f4x_stlink.cfg \
	-c "init" \
	-c "reset init" \
	-c "halt" \
	-c "flash write_image erase $(FIRMWARE).elf" \
	-c "verify_image $(FIRMWARE).elf" \
	-c "reset run" -c shutdown
#automatically formate
astyle: 
	astyle -r --exclude=lib  *.c *.h

.PHONY:all clean flash openocd gdbauto gdbtui cgdb astyle
