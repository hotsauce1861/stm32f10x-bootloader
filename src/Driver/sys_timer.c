#include "sys_timer.h"
#include "stm32f10x.h"
#include "core_cm3.h"
#include "system_stm32f10x.h"

volatile uint32_t sys_time_cnt = 0;
volatile uint32_t user_time_cnt = 0;

void gw_hal_set_time_cnt(uint32_t val){
	user_time_cnt = val;
}

uint32_t gw_hal_get_time_cnt(void){
	return user_time_cnt;
}

void gw_hal_delay(volatile uint32_t ntime){

	sys_time_cnt = ntime;
	while(sys_time_cnt != 0);
	
}

void gw_hal_dec(void){
	if (sys_time_cnt != 0x00)
	{ 
		sys_time_cnt--;
	}	
	if (user_time_cnt != 0x00){
		user_time_cnt--;
	}
}


void hal_system_timer_config(void){
		/* Setup SysTick Timer for 1 msec interrupts.
	   ------------------------------------------
	  1. The SysTick_Config() function is a CMSIS function which configure:
		 - The SysTick Reload register with value passed as function parameter.
		 - Configure the SysTick IRQ priority to the lowest value (0x0F).
		 - Reset the SysTick Counter register.
		 - Configure the SysTick Counter clock source to be Core Clock Source (HCLK).
		 - Enable the SysTick Interrupt.
		 - Start the SysTick Counter.
	  
	  2. You can change the SysTick Clock source to be HCLK_Div8 by calling the
		 SysTick_CLKSourceConfig(SysTick_CLKSource_HCLK_Div8) just after the
		 SysTick_Config() function call. The SysTick_CLKSourceConfig() is defined
		 inside the misc.c file.
	
	  3. You can change the SysTick IRQ priority by calling the
		 NVIC_SetPriority(SysTick_IRQn,...) just after the SysTick_Config() function 
		 call. The NVIC_SetPriority() is defined inside the core_cm3.h file.
	
	  4. To adjust the SysTick time base, use the following formula:
							  
		   Reload Value = SysTick Counter Clock (Hz) x	Desired Time base (s)
	  
		 - Reload Value is the parameter to be passed for SysTick_Config() function
		 - Reload Value should not exceed 0xFFFFFF
	 */
	if (SysTick_Config(SystemCoreClock / SYSTICK_FREQ))
	{ 
	  /* Capture error */ 
		while (1);
    }
}
