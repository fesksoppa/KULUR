/**
  ******************************************************************************
  * File Name          : main.c
  * Description        : Test project for Kulur
  ******************************************************************************
  
  *
  ******************************************************************************
  */
/* Includes ------------------------------------------------------------------*/
#include "main.h"

#include "stm32f3xx_hal.h"
#include "cmsis_os.h"
#include "rtc.h"
#include "tim.h"
#include "usart.h"

#include "stm32f3_discovery.h" 

    
void SystemClock_Config(void);
void Error_Handler(void);
void MX_FREERTOS_Init(void);



int main(void)
{
  uint8_t HOUR_DIG_1;
  uint8_t HOUR_DIG_2;
  uint8_t MIN_DIG_1;
  uint8_t MIN_DIG_2;
  
  static uint8_t hour;
  static uint8_t min;
  static uint8_t sec;
   
  
  
  HAL_Init();

  /* Configure the system clock */
  SystemClock_Config();

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  //MX_USART3_UART_Init();
  MX_RTC_Init();
  
 // RTC_TimeConfig();
  
 // MX_TIM1_Init();
  MX_CRC_Init();


  
  //-------------------------------------------------------------------
  
  
  // ----------Used to set the time and date with uart---------
   
  
   
 
  /* Call init function for freertos objects (in freertos.c) */
 // MX_FREERTOS_Init();

  //osKernelStart();
  
  
  /* We should never get here as control is now taken by the scheduler */

 // ******Test preamble duty 7500 us to 8500 us*****
  
 /*   for(int i=0;i<5;i++)
    {
      HAL_GPIO_TogglePin(GPIOE,LD8_Pin);
      HAL_Delay(7);
      HAL_GPIO_TogglePin(GPIOE,LD8_Pin);
      HAL_Delay(1000);
      
      if(i<4){
        HAL_GPIO_TogglePin(GPIOE,LD8_Pin);
        HAL_Delay(8);
        HAL_GPIO_TogglePin(GPIOE,LD8_Pin);
        HAL_Delay(1000);
      }
    }//FOR-loop */
  
  
 int temp=215; 
  
 while (1)
 {
   
 static char tempString[4];
  tempString[0]=temp/100;
  tempString[1]=(temp/10)%10;
  tempString[2]=',';
  tempString[3]=(temp%100)%10;
  
  for(int i=0;i<4;i++)
  {
    printf("%s \n",tempString[i]);
  }
        
  
   
  //Display Test, trying all combinations.  
   //for(int i=0;i<NUMBER_OF_NUMBERS;i++)
    //{
     // for(int j=0;j<NUMBER_OF_NUMBERS;j++)
      //{
       // HAL_GPIO_TogglePin(GPIOE,LD8_Pin); //PE14 && PA8
       // HAL_Delay(8);
    //    Display_Seven_Seg(3,false);
      //  HAL_GPIO_TogglePin(GPIOE,LD8_Pin); //PE14 && PA8
        //HAL_Delay(1000);
      //}
    //}   
   
   
    
    
    //---------RTC TEST && UART TEST----------------------------------
   
   // RTC_TimeConfig(); Aktivera längre upp
     // Show_RTC_Time(&hour,&min,&sec);
     // HAL_Delay(1000);
     // printf("Tid: %2d : %2d: %2d \n", hour,min,sec);
   
    
   // HOUR_DIG_1=hour/10; //För att få ut första siffran
   // HOUR_DIG_2=hour%10; //För att få ut andra siffran
    
   // MIN_DIG_1=min/10; //För att få ut första siffran
   // MIN_DIG_2=min%10; //För att få ut andra siffran
    
    
    //printf("YO MF!!---  %d: %d \n \n", HOUR_DIG_1,HOUR_DIG_2);
    //printf("MIN MF!! -- %d: %d \n ", MIN_DIG_1,MIN_DIG_2);
    
  /*  Display_Seven_Seg(4,HOUR_DIG_1);
    HAL_Delay(1000);
    Display_Seven_Seg(5,HOUR_DIG_2);
    HAL_Delay(1000);
    Display_Seven_Seg(6,MIN_DIG_1);
    HAL_Delay(1000);
    Display_Seven_Seg(7,MIN_DIG_2);
    HAL_Delay(1000);*/
    
    
    
    //------------------Usart Test ---------------------------
  
 
     //Put UART peripheral in reception process /
   /* if(HAL_UART_Receive_IT(&huart3, (uint8_t *) Buffer, BUFFERSIZE) != HAL_OK)
    {
      Error_Handler();
    }
     while( UartReady != SET)
    { 
    }
    printf("done!\n");
    HAL_Delay(500);
    //When transfer is done, reset flag
    UartReady = RESET;
    */
    
    
    
          //Start the transmission process
    /*
    if(HAL_UART_Transmit_IT(&huart3, (uint8_t *)Buffer, BUFFERSIZE) != HAL_OK)
    {
      Error_Handler();
    }
    while(UartReady != SET)
    {
     
    }
    // Reset flag when transmission is done 
     HAL_Delay(500); //lets wait a bit. 
    printf("done! Skickat tillbaka\n"); 
    UartReady = RESET;
    */
    
    
  //--------- Test Timer and interrupt-----------
  
    /*  HAL_GPIO_TogglePin(GPIOE,LD8_Pin); //PE14 && PA8
      HAL_Delay(6);
      HAL_GPIO_TogglePin(GPIOE,LD8_Pin);
      HAL_Delay(9);
      HAL_GPIO_TogglePin(GPIOE,LD8_Pin);
      HAL_Delay(6);
      HAL_GPIO_TogglePin(GPIOE,LD8_Pin);
      HAL_Delay(9); */
      
   // Display_Seven_Seg(225,false); //Dubbelkolla
    //HAL_Delay(1000);


    }
}  




 



/** System Clock Configuration
*/
void SystemClock_Config(void)
{

  RCC_OscInitTypeDef RCC_OscInitStruct;
  RCC_ClkInitTypeDef RCC_ClkInitStruct;
  RCC_PeriphCLKInitTypeDef PeriphClkInit;

    /**Initializes the CPU, AHB and APB busses clocks 
    */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.HSEPredivValue = RCC_HSE_PREDIV_DIV1;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLMUL = RCC_PLL_MUL9;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

    /**Initializes the CPU, AHB and APB busses clocks 
    */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV2;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_2) != HAL_OK)
  {
    Error_Handler();
  }

  PeriphClkInit.PeriphClockSelection = RCC_PERIPHCLK_USART3|RCC_PERIPHCLK_RTC
                              |RCC_PERIPHCLK_TIM1;
  PeriphClkInit.Usart3ClockSelection = RCC_USART3CLKSOURCE_PCLK1;
  PeriphClkInit.RTCClockSelection = RCC_RTCCLKSOURCE_HSE_DIV32;
  PeriphClkInit.Tim1ClockSelection = RCC_TIM1CLK_HCLK;
  if (HAL_RCCEx_PeriphCLKConfig(&PeriphClkInit) != HAL_OK)
  {
    Error_Handler();
  }

    /**Configure the Systick interrupt time 
    */
  HAL_SYSTICK_Config(HAL_RCC_GetHCLKFreq()/1000); //Ta bort en nolla för att återgå till microseconds

    /**Configure the Systick 
    */
  HAL_SYSTICK_CLKSourceConfig(SYSTICK_CLKSOURCE_HCLK);

  /* SysTick_IRQn interrupt configuration */
  HAL_NVIC_SetPriority(SysTick_IRQn, 15, 0);
}



void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler */
  /* User can add his own implementation to report the HAL error return state */
  
  
  
 // while(1) 
  //{
    //HAL_GPIO_TogglePin(GPIOE, GPIO_PIN_15);
    //HAL_Delay(500);
    printf("ERRORH_HANDLER\n");
 // }
  /* USER CODE END Error_Handler */ 
}

#ifdef USE_FULL_ASSERT

/**
   * @brief Reports the name of the source file and the source line number
   * where the assert_param error has occurred.
   * @param file: pointer to the source file name
   * @param line: assert_param error line source number
   * @retval None
   */
void assert_failed(uint8_t* file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
    ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */

}

#endif