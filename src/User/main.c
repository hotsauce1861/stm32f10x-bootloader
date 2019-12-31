/**
  ******************************************************************************
  * @file    IAP/src/main.c 
  * @author  MCD Application Team
  * @version V3.3.0
  * @date    10/15/2010
  * @brief   Main program body
  ******************************************************************************
  * @copy
  *
  * THE PRESENT FIRMWARE WHICH IS FOR GUIDANCE ONLY AIMS AT PROVIDING CUSTOMERS
  * WITH CODING INFORMATION REGARDING THEIR PRODUCTS IN ORDER FOR THEM TO SAVE
  * TIME. AS A RESULT, STMICROELECTRONICS SHALL NOT BE HELD LIABLE FOR ANY
  * DIRECT, INDIRECT OR CONSEQUENTIAL DAMAGES WITH RESPECT TO ANY CLAIMS ARISING
  * FROM THE CONTENT OF SUCH FIRMWARE AND/OR THE USE MADE BY CUSTOMERS OF THE
  * CODING INFORMATION CONTAINED HEREIN IN CONNECTION WITH THEIR PRODUCTS.
  *
  * <h2><center>&copy; COPYRIGHT 2010 STMicroelectronics</center></h2>
  */ 

/** @addtogroup IAP
  * @{
  */

/* Includes ------------------------------------------------------------------*/
#include "common.h"

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
extern pFunction Jump_To_Application;
extern uint32_t JumpAddress;

/* Private function prototypes -----------------------------------------------*/
static void IAP_Init(void);

/* Private functions ---------------------------------------------------------*/
uint8_t command = 0;
/**
  * @brief  Main program.
  * @param  None
  * @retval None
  */
int main(void)
{
  /* Flash unlock */
  FLASH_Unlock();

  /* Test if Key push-button on STM3210X-EVAL Board is pressed */
	if (command  == 0x00)
	{ 
		/* If Key is pressed */
		/* Execute the IAP driver in order to re-program the Flash */
		IAP_Init();
		SerialPutString("\r\n");
		SerialPutString("\r\n*******************************************************************************");
		SerialPutString("\r\n*              (C) COPYRIGHT 2019 UncleMac                                    *");
		SerialPutString("\r\n*                                                                             *");
		SerialPutString("\r\n*       ____              __  __                __                            *");
		SerialPutString("\r\n*      / __ )____  ____  / /_/ /___  ____ _____/ /__  _____                   *");
		SerialPutString("\r\n*     / __  / __ \\/ __ \\/ __/ / __ \\/ __ `/ __  / _ \\/ ___/                   *");
		SerialPutString("\r\n*    / /_/ / /_/ / /_/ / /_/ / /_/ / /_/ / /_/ /  __/ /                       *");
		SerialPutString("\r\n*   /_____/\\____/\\____/\\__/_/\\____/\\__,_/\\__,_/\\___/_/                        *");		
		SerialPutString("\r\n*                                                                             *");
		SerialPutString("\r\n*     Bootloader for PMSM on stm32f10cbt6(Version 0.0.1)                      *");
		SerialPutString("\r\n*                                                                             *");
		SerialPutString("\r\n*     https://blog.csdn.net/u010632165                                        *");
		SerialPutString("\r\n*                                                                             *");
		SerialPutString("\r\n*                                   By UncleMac                               *");
		SerialPutString("\r\n*                                                                             *");		
		SerialPutString("\r\n*******************************************************************************");
		SerialPutString("\r\n\r\n");
		Main_Menu ();
	}
  /* Keep the user application running */
  else
  {
    /* Test if user code is programmed starting from address "ApplicationAddress" */
   if (((*(__IO uint32_t*)ApplicationAddress) & 0x2FFE0000 ) == 0x20000000)
   { 
      /* Jump to user application */
      JumpAddress = *(__IO uint32_t*) (ApplicationAddress + 4);
      Jump_To_Application = (pFunction) JumpAddress;
      /* Initialize user application's Stack Pointer */
      __set_MSP(*(__IO uint32_t*) ApplicationAddress);
      Jump_To_Application();
    }
  }

  while (1)
  {}
}
#define COM_PORT USART3
/**
  * @brief  Initialize the IAP: Configure RCC, USART and GPIOs.
  * @param  None
  * @retval None
  */
void IAP_Init(void)
{
	usart_init();
}

#ifdef USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t* file, uint32_t line)
{
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */

  /* Infinite loop */
  while (1)
  {
  }
}
#endif

/**
  * @}
  */

/******************* (C) COPYRIGHT 2010 STMicroelectronics *****END OF FILE****/
