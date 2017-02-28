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
#include "stdbool.h"
#include "stm32f3xx_hal.h"
#include "cmsis_os.h"
#include "rtc.h"
#include "tim.h"
#include "usart.h"
#include "string.h"
#include "crc.h"
#include "stm32f3_discovery.h" 

    
void SystemClock_Config(void);
void Error_Handler(void);
void MX_FREERTOS_Init(void);
void frame_decoder(uint32_t radio_frame[]);
void Send_zero(void);
void Send_one(void);

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
 // MX_USART3_UART_Init();
 // MX_RTC_Init();
  
 // RTC_TimeConfig();
  
  MX_TIM1_Init();
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
  
  
  
  
 while (1)
 {
   
   
        
   /*    //CLOCK_Displays
        HAL_GPIO_WritePin(GPIOC,DIG1clk_Pin,GPIO_PIN_RESET); 
        HAL_GPIO_WritePin(GPIOC,DIG2clk_Pin,GPIO_PIN_RESET);
        HAL_GPIO_WritePin(GPIOC,DIG3clk_Pin,GPIO_PIN_SET); //set
        HAL_GPIO_WritePin(GPIOC,DIG4clk_Pin,GPIO_PIN_RESET);
        
        //Kolon
        HAL_GPIO_WritePin(GPIOC,Kolon_Pin,GPIO_PIN_SET);
        
        HAL_GPIO_WritePin(GPIOD,DP_led_Pin,GPIO_PIN_SET); //Decimalpunkt
        
        
        
      HAL_GPIO_WritePin(GPIOD,A_led_Pin,GPIO_PIN_RESET);
      HAL_GPIO_WritePin(GPIOD,B_led_Pin,GPIO_PIN_RESET);
      HAL_GPIO_WritePin(GPIOD,C_led_Pin,GPIO_PIN_RESET);
      HAL_GPIO_WritePin(GPIOD,D_led_Pin,GPIO_PIN_RESET);
      HAL_GPIO_WritePin(GPIOD,E_led_Pin,GPIO_PIN_RESET);
      HAL_GPIO_WritePin(GPIOD,F_led_Pin,GPIO_PIN_RESET);
      HAL_GPIO_WritePin(GPIOD,G_led_Pin,GPIO_PIN_SET);
   
      HAL_Delay(5);
      
       
        
        //CLOCK_Displays
       HAL_GPIO_WritePin(GPIOC,DIG1clk_Pin,GPIO_PIN_RESET); 
       HAL_GPIO_WritePin(GPIOC,DIG2clk_Pin,GPIO_PIN_RESET);
       HAL_GPIO_WritePin(GPIOC,DIG3clk_Pin,GPIO_PIN_RESET); 
       HAL_GPIO_WritePin(GPIOC,DIG4clk_Pin,GPIO_PIN_SET); //set
       
        //Kolon
       HAL_GPIO_WritePin(GPIOC,Kolon_Pin,GPIO_PIN_SET);
      
      
      HAL_GPIO_WritePin(GPIOD,A_led_Pin,GPIO_PIN_SET);
      HAL_GPIO_WritePin(GPIOD,B_led_Pin,GPIO_PIN_RESET);
      HAL_GPIO_WritePin(GPIOD,C_led_Pin,GPIO_PIN_RESET);
      HAL_GPIO_WritePin(GPIOD,D_led_Pin,GPIO_PIN_SET);
      HAL_GPIO_WritePin(GPIOD,E_led_Pin,GPIO_PIN_SET);
      HAL_GPIO_WritePin(GPIOD,F_led_Pin,GPIO_PIN_SET);
      HAL_GPIO_WritePin(GPIOD,G_led_Pin,GPIO_PIN_SET);
   
   HAL_Delay(5);
   */
   
   
  //Display Test, trying all combinations.  
   //for(int i=0;i<NUMBER_OF_NUMBERS;i++)
    //{
     // for(int j=0;j<NUMBER_OF_NUMBERS;j++)
      //{
       // HAL_GPIO_TogglePin(GPIOE,LD8_Pin); //PE14 && PA8
       // HAL_Delay(8);
        Display_Seven_Seg(3,false);
      //  HAL_GPIO_TogglePin(GPIOE,LD8_Pin); //PE14 && PA8
        //HAL_Delay(1000);
      //}
    //}   
   
    //HAL_GPIO_TogglePin(GPIOE, GPIO_PIN_14);
    //HAL_GPIO_TogglePin(GPIOE, GPIO_PIN_13);
    
    
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

   //************* Radio TEST *************
   
   
/*   BSP_LED_On(LED3);   
    

   Send_one();  // Preamble 9 ones
    Send_one();
    Send_one();
    Send_one();
    Send_one();
    Send_one();
    Send_one();
    Send_one();
    Send_one();
    
    Send_zero();  // Net id? 01001
    Send_one();
    Send_zero();
    Send_zero();
    Send_one();

    Send_zero();  // Channel number 000
    Send_zero();
    Send_zero();   

    Send_zero();  // Unknown 011100
    Send_one();
    Send_one();
    Send_one();
    Send_zero();
    Send_zero();
    
    Send_zero();  // Temperature 00 1101 0111 21,5 C
    Send_zero();   

    Send_one();
    Send_one();
    Send_zero();
    Send_one();

    Send_zero();
    Send_one();
    Send_one();
    Send_one();

    Send_zero();  // Unknown 0
    
    Send_zero();  // Humidity 010 0010 34%
    Send_one();
    Send_zero();

    Send_zero();
    Send_zero();
    Send_one();
    Send_zero();

    Send_zero();   // CRC-8 0101 1101
    Send_one();
    Send_zero();
    Send_one();

    Send_one();
    Send_one(); 
    Send_zero();
    Send_one();
   
   
    BSP_LED_Off(LED3);
          
   HAL_Delay(20000);
   
   
   
   
    Send_one();  // Preamble 9 ones
    Send_one();
    Send_one();
    Send_one();
    Send_one();
    Send_one();
    Send_one();
    Send_one();
    Send_one();
    
    Send_zero();  // Net id? 01001
    Send_one();
    Send_zero();
    Send_zero();
    Send_one();

    Send_zero();  // Channel number 000
    Send_zero();
    Send_zero();   

    Send_zero();  // Unknown 011100
    Send_one();
    Send_one();
    Send_one();
    Send_zero();
    Send_zero();
    
    Send_one();  // Temperature 00 1101 0111 21,5 C
    Send_zero();   

    Send_one();
    Send_one();
    Send_zero();
    Send_zero();

    Send_zero();
    Send_one();
    Send_one();
    Send_one();

    Send_zero();  // Unknown 0
    
    Send_zero();  // Humidity 010 0010 34%
    Send_one();
    Send_zero();

    Send_zero();
    Send_zero();
    Send_one();
    Send_zero();

    Send_zero();   // CRC-8 0101 1101
    Send_one();
    Send_zero();
    Send_one();

    Send_one();
    Send_one(); 
    Send_zero();
    Send_one();
    
 
   
   HAL_Delay(10000);
   */
    }
}  




///******* CALLLBACK INTERRUPT *******
//******* Handles interrupt from the Radioreceiver, checks for preamble and
//*******  then store the values. 
void HAL_TIM_IC_CaptureCallback(TIM_HandleTypeDef *htim){
  static uint32_t duty_in_microseconds=0;
  static uint32_t radio_frame[FRAME_SIZE];
  static uint32_t preamble_bits[NUMBER_OF_PREAMBLE_BITS];
  static uint8_t bit_counter=0;
  static uint8_t preamble_counter=0;
  static bool preamble_flag=false;
  
  
  //Lock function
  HAL_TIM_IC_Stop_IT(&htim1, TIM_CHANNEL_2);
  
  //Captures the pulse width
  if(htim->Channel == HAL_TIM_ACTIVE_CHANNEL_2)
  {
    duty_in_microseconds=HAL_TIM_ReadCapturedValue(htim, TIM_CHANNEL_2);
    
   
  //Checks for preamble bits and sets a flag when 9 "1" in a row
    
   if(duty_in_microseconds>MINIMUM_DUTY_TICKS && duty_in_microseconds <MAX_DUTY_TICKS && !preamble_flag)
    {
       if(duty_in_microseconds <PULSE_WIDTH_ONE)
       {
         preamble_bits[preamble_counter]=duty_in_microseconds;
         preamble_counter++;
       
       }
       else
         preamble_counter=0;
   
    } 
    //Fills the array with bits from Radiorecevier, trys to block the interference 
   if(preamble_flag && duty_in_microseconds>MINIMUM_DUTY_TICKS && duty_in_microseconds <MAX_DUTY_TICKS)
    {
      if(bit_counter > 39)
      {
        bit_counter=0;
        preamble_flag=false;
        preamble_counter=0;
        frame_decoder(radio_frame); //New temp value
      }
      else if(duty_in_microseconds < PULSE_WIDTH_ONE)
      {
        radio_frame[bit_counter]=duty_in_microseconds;
        bit_counter++; 
      
      }
      else if(duty_in_microseconds>PULSE_WIDTH_ZERO)
      {
        radio_frame[bit_counter]=duty_in_microseconds;
        bit_counter++; 
      }
      
    } 
    
      if(preamble_counter==PREAMBLE_SIZE && !preamble_flag)
       {
         preamble_flag=true;
       }
  }
  //Unlock function
   HAL_TIM_IC_Start_IT(&htim1, TIM_CHANNEL_2);
      
  return;
}
  
void frame_decoder(uint32_t radio_frame[])
{
  static uint32_t decoded_frame[FRAME_SIZE];
  static uint16_t temp=0;
  bool find_id=false;
 
 /*   while(!find_id)
    {
      
    }
*/    
    
  
   // printf("It's inside!!!!! :) 8===(-)\n");
    for(int i;i<FRAME_SIZE;i++)
    {
      if(radio_frame[i]>=500 && radio_frame[i] <=PULSE_WIDTH_ONE)
      {
        decoded_frame[i]=1;
      }
      else if(radio_frame[i]>=1400 && radio_frame[i] <=1600)
      {
        decoded_frame[i]=0;
      }
   //   printf("Index%d = %d \n ",i,decoded_frame[i]);
    }
    
    // CRC FUCK
/*    decoded_frame[39]=1;
    decoded_frame[38]=0;
    decoded_frame[37]=1;
    decoded_frame[36]=1;
    decoded_frame[35]=1;
    decoded_frame[34]=0;
    decoded_frame[33]=1;
    decoded_frame[32]=0;
    
    decoded_frame[31]=0;
    decoded_frame[30]=1;
    decoded_frame[29]=0;
    decoded_frame[28]=0;
    decoded_frame[27]=0;
    decoded_frame[26]=1;
    decoded_frame[25]=0;
    decoded_frame[24]=0;
    
    decoded_frame[23]=1;
    decoded_frame[22]=1;
    decoded_frame[21]=1;
    decoded_frame[20]=0;
    decoded_frame[19]=1;
    decoded_frame[18]=0;
    decoded_frame[17]=1;
    decoded_frame[16]=1;
    
    decoded_frame[15]=0;
    decoded_frame[14]=0;
    decoded_frame[13]=0;
    decoded_frame[12]=0;
    decoded_frame[11]=1;
    decoded_frame[10]=1;
    decoded_frame[9]=1;
    decoded_frame[8]=0;
    
    decoded_frame[7]=0;
    decoded_frame[6]=0;
    decoded_frame[5]=0;
    decoded_frame[4]=1;
    decoded_frame[3]=0;
    decoded_frame[2]=0;
    decoded_frame[1]=1;
    decoded_frame[0]=0; */
  //  printf("CRC: %d \n" ,HAL_CRC_Calculate(&hcrc,decoded_frame, FRAME_SIZE));
    
  /*  decoded_frame[18]=1;
    decoded_frame[20]=1;
    */
    
    if(decoded_frame[14])
    {
      temp+=512;
    }
    if(decoded_frame[15])
    {
      temp+=256;
    }
    if(decoded_frame[16])
    {
      temp+=128;
    }
    if(decoded_frame[17])
    {
      temp+=64;
    }
    if(decoded_frame[18])
    {
      temp+=32;
    }
    if(decoded_frame[19])
    {
      temp+=16;
    }
    if(decoded_frame[20])
    {
      temp+=8;
    }
    if(decoded_frame[21])
    {
      temp+=4;
    }
    if(decoded_frame[22])
    {
      temp+=2;
    }
    if(decoded_frame[23])
    {
      temp+=1;
    }
    
    printf("Temp: %d \n " ,temp);
    //Display_Seven_Seg(temp,true);
   
    temp=0;
  
  return; 
}


void Send_one(void)

{
    uint16_t i;
  
    BSP_LED_On(LED4);
    for ( i = 0; i < 6260; ++i );

    BSP_LED_Off(LED4);
    for ( i = 0; i < 9260; ++i );

}

void Send_zero(void)

{
    uint16_t i;
  
    BSP_LED_On(LED4);
    for ( i = 0; i < 15500; ++i );

    BSP_LED_Off(LED4);
    for ( i = 0; i < 9260; ++i );

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




