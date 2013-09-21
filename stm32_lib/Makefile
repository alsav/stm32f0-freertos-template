TOOLS_PREFIX=arm-none-eabi-

CFLAGS = -c -fno-common -O2 -Wall -g -mcpu=cortex-m0 -mthumb
CFLAGS+=-I. -I./inc -I./cmsis

ASFLAGS=-mcpu=cortex-m0 -I./cmsis -I. -gdwarf-2 -gdwarf-2

CC=$(TOOLS_PREFIX)gcc
AS=$(TOOLS_PREFIX)as
AR=$(TOOLS_PREFIX)ar



SRCS=	src/stm32f0xx_adc.c	src/stm32f0xx_crc.c	src/stm32f0xx_dma.c	src/stm32f0xx_gpio.c \
	src/stm32f0xx_misc.c	src/stm32f0xx_rtc.c	src/stm32f0xx_tim.c	src/stm32f0xx_cec.c \
	src/stm32f0xx_dac.c	src/stm32f0xx_exti.c	src/stm32f0xx_i2c.c	src/stm32f0xx_pwr.c \
	src/stm32f0xx_spi.c	src/stm32f0xx_usart.c	src/stm32f0xx_comp.c	src/stm32f0xx_dbgmcu.c \
	src/stm32f0xx_flash.c	src/stm32f0xx_iwdg.c	src/stm32f0xx_rcc.c	src/stm32f0xx_syscfg.c \
	src/stm32f0xx_wwdg.c	stm32f0_discovery.c	system_stm32f0xx.c




OBJS=$(SRCS:.c=.o)


all: libstm32f0.a


startup:
	$(CC) $(CFLAGS) -c ./startup_stm32f0xx.S -o startup_stm32f0xx.o

%.o:%.c
	$(CC) $(CFLAGS) -c $^ -o $@

libstm32f0.a: $(OBJS) startup
	$(AR) -r $@ startup_stm32f0xx.o $(OBJS) 


clean:
	rm -f 	$(OBJS) libstm32f0.a startup_stm32f0xx.o




