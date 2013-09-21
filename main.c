#include "main.h"

static void GPIO_Config(void);
void vLedTask (void *pvParameters);


int main(void)
{
  GPIO_Config();

  xTaskCreate(vLedTask,(signed char*) "LedTask", configMINIMAL_STACK_SIZE, (void *) NULL, tskIDLE_PRIORITY + 1, NULL);
  vTaskStartScheduler();

}

void vLedTask (void *pvParameters)
{
    uint8_t state=0;
    while(1)    {
	if (state==0){
	    GPIO_SetBits(GPIOC, GPIO_Pin_9);
	    state=1;
	} else {
	    GPIO_ResetBits(GPIOC, GPIO_Pin_9);
	    state=0;
	}
	vTaskDelay(1000);
    }
    vTaskDelete(NULL);
}


void GPIO_Config(void)
{
	  GPIO_InitTypeDef GPIO_InitStruct;

	  /*GPIOC config - LED Configuration*/
	  RCC_AHBPeriphClockCmd( RCC_AHBPeriph_GPIOC, ENABLE );
	  GPIO_InitStruct.GPIO_Pin =  GPIO_Pin_8 | GPIO_Pin_9;
	  GPIO_InitStruct.GPIO_Mode = GPIO_Mode_OUT;
	  GPIO_InitStruct.GPIO_Speed = GPIO_Speed_2MHz;
	  GPIO_InitStruct.GPIO_OType = GPIO_OType_PP;
	  GPIO_InitStruct.GPIO_PuPd = GPIO_PuPd_UP;
	  GPIO_Init( GPIOC, &GPIO_InitStruct );

}


/*-----------------------------------------------------------*/

void vApplicationIdleHook( void )
{
	/* vApplicationIdleHook() will only be called if configUSE_IDLE_HOOK is set
	to 1 in FreeRTOSConfig.h.  It will be called on each iteration of the idle
	task.  It is essential that code added to this hook function never attempts
	to block in any way (for example, call xQueueReceive() with a block time
	specified, or call vTaskDelay()).  If the application makes use of the
	vTaskDelete() API function (as this demo application does) then it is also
	important that vApplicationIdleHook() is permitted to return to its calling
	function, because it is the responsibility of the idle task to clean up
	memory allocated by the kernel to any task that has since been deleted. */
}
/*-----------------------------------------------------------*/

void vApplicationStackOverflowHook( xTaskHandle pxTask, signed char *pcTaskName )
{
	( void ) pcTaskName;
	( void ) pxTask;

	/* Run time stack overflow checking is performed if
	configCHECK_FOR_STACK_OVERFLOW is defined to 1 or 2.  This hook
	function is called if a stack overflow is detected. */
	taskDISABLE_INTERRUPTS();
	for( ;; );
}
/*-----------------------------------------------------------*/

void vApplicationTickHook( void )
{
	/* This function will be called by each tick interrupt if
	configUSE_TICK_HOOK is set to 1 in FreeRTOSConfig.h.  User code can be
	added here, but the tick hook is called from an interrupt context, so
	code must not attempt to block, and only the interrupt safe FreeRTOS API
	functions can be used (those that end in FromISR()). */
}
/*-----------------------------------------------------------*/




