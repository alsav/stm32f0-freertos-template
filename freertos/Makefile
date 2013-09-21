TOOLS_PREFIX=arm-none-eabi-


CFLAGS = -c -fno-common -O2 -Wall -g -mcpu=cortex-m0 -mthumb

CFLAGS+=-I. -I./inc -I../stm32_lib -I../stm32_lib/inc -I../stm32_lib/cmsis

CC=$(TOOLS_PREFIX)gcc
AS=$(TOOLS_PREFIX)as
AR=$(TOOLS_PREFIX)ar


SRCS=	src/heap_1.c	src/list.c	src/port.c	src/queue.c	src/tasks.c	src/timers.c	src/croutine.c


OBJS=$(SRCS:.c=.o)


all: libfreertos_1.a


%.o:%.c
	$(CC) $(CFLAGS) -c $^ -o $@

libfreertos_1.a: $(OBJS)
	$(AR) -r $@ $(OBJS) 


clean:
	rm -f 	$(OBJS) libfreertos_1.a




