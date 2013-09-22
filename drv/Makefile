TOOLS_PREFIX=arm-none-eabi-


CFLAGS = -c -fno-common -O2 -Wall -g -mcpu=cortex-m0 -mthumb

CFLAGS+=-I. -I.. -I../inc -I../stm32_lib -I../stm32_lib/inc -I../stm32_lib/cmsis -I../freertos -I../freertos/inc

CC=$(TOOLS_PREFIX)gcc
AS=$(TOOLS_PREFIX)as
AR=$(TOOLS_PREFIX)ar


SRCS=	usart.c


OBJS=$(SRCS:.c=.o)


all: $(OBJS)

%.o:%.c
	$(CC) $(CFLAGS) -c $^ -o $@


clean:
	rm -f 	$(OBJS)




