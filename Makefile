BIN=project

TOOLS_PREFIX=arm-none-eabi-

CFLAGS=-c -fno-common -O2 -Wall -g3 -mcpu=cortex-m0 -mthumb
CFLAGS+=-I./stm32_lib/cmsis -I./stm32_lib -I./stm32_lib/inc -I. -I./freertos/ -I./freertos/inc -I./drv

LDFLAGS=-static -mcpu=cortex-m0 -mthumb -mthumb-interwork -Wl,--start-group
LDFLAGS+=-T./stm32_lib/stm32_flash.ld -nostartfiles

STM32F0_LIB=./stm32_lib
FREERTOS_LIB=./freertos


CC=$(TOOLS_PREFIX)gcc
CP=$(TOOLS_PREFIX)objcopy
OD=$(TOOLS_PREFIX)objdump -S
SIZE=$(TOOLS_PREFIX)size


SRC=main.c
OBJ=$(SRC:.c=.o)

DRV_DIR=./drv
DRV_OBJ=$(DRV_DIR)/usart.o



all: proj
	$(CP) -O binary $(BIN).elf $(BIN).bin
	$(OD) $(BIN).elf > $(BIN).lst
	$(SIZE) -B $(BIN).elf

drivers:
	$(MAKE) -C $(DRV_DIR)

lib:
	$(MAKE) -C $(STM32F0_LIB)
	$(MAKE) -C $(FREERTOS_LIB)

proj: cc lib drivers
	$(CC) $(LDFLAGS) -L $(STM32F0_LIB) -lstm32f0 -L $(FREERTOS_LIB)  -lfreertos_1 -o $(BIN).elf $(OBJ) $(DRV_OBJ)

cc: $(SRC)
	$(CC) $(CFLAGS) $(SRC)


clean:
	rm -f 	$(OBJ) \
		$(BIN).map \
		$(BIN).bin \
		$(BIN).lst \
		$(BIN).elf
	$(MAKE) -C $(DRV_DIR) clean

cleanall: clean
	$(MAKE) -C $(STM32F0_LIB) clean
	$(MAKE) -C $(FREERTOS_LIB) clean



