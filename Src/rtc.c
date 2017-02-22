/**
  ******************************************************************************
  * File Name          : RTC.c
  * Description        : This file provides code for the configuration
  *                      of the RTC instances.
  ******************************************************************************

  *
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "rtc.h"
#include "usart.h"

/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

ITStatus UartReady; //Status flag for UART 

RTC_HandleTypeDef hrtc;

/* RTC init function */
void MX_RTC_Init(void)
{

    /**Initialize RTC Only 
    */
  hrtc.Instance = RTC;
  hrtc.Init.HourFormat = RTC_HOURFORMAT_24;
  hrtc.Init.AsynchPrediv = 127; //127
  hrtc.Init.SynchPrediv = 1952; //Ger en upplösning på 1 sek
  hrtc.Init.OutPut = RTC_OUTPUT_DISABLE;
  hrtc.Init.OutPutPolarity = RTC_OUTPUT_POLARITY_HIGH;
  hrtc.Init.OutPutType = RTC_OUTPUT_TYPE_OPENDRAIN;
  if (HAL_RTC_Init(&hrtc) != HAL_OK)
  {
    Error_Handler();
  }

}

void HAL_RTC_MspInit(RTC_HandleTypeDef* rtcHandle)
{

  if(rtcHandle->Instance==RTC)
  {
  /* USER CODE BEGIN RTC_MspInit 0 */

  /* USER CODE END RTC_MspInit 0 */
    /* Peripheral clock enable */
    __HAL_RCC_RTC_ENABLE();
  /* USER CODE BEGIN RTC_MspInit 1 */

  /* USER CODE END RTC_MspInit 1 */
  }
}

void HAL_RTC_MspDeInit(RTC_HandleTypeDef* rtcHandle)
{

  if(rtcHandle->Instance==RTC)
  {
  /* USER CODE BEGIN RTC_MspDeInit 0 */

  /* USER CODE END RTC_MspDeInit 0 */
    /* Peripheral clock disable */
    __HAL_RCC_RTC_DISABLE();
  }
  /* USER CODE BEGIN RTC_MspDeInit 1 */

  /* USER CODE END RTC_MspDeInit 1 */
} 



void RTC_TimeConfig(){
  UartReady = RESET;
  
  static uint8_t Buffer[BUFFERSIZEDATE];
  
  char *hello ="Welcome Bengt Fucktard, Enter Date & Time\n\r";
  char *date ="Enter date (yyyy-mm-dd):\n\r";
  char *time ="Enter time (HH:MM):\n\r";
  
  HAL_UART_Transmit(&huart3, (uint8_t *)hello, strlen(hello),5000);
  HAL_UART_Transmit(&huart3, (uint8_t *)date, strlen(date),5000);
  // Startar seriekommunikation, för att ställa datum för RTC klockan
   // Fixa dummy säkerhet. 0<Year<99 0<month<? 1<day<31 yyyy-mm-dd 
  if(HAL_UART_Receive_IT(&huart3, (uint8_t *) Buffer, BUFFERSIZEDATE) != HAL_OK)
    {
      Error_Handler();
    }
     while( UartReady != SET)
    { 
    }
    printf("done!\n");
    HAL_Delay(500);
    UartReady = RESET; //Sätter tillbaka flaggan
  
  uint8_t year=(Buffer[2] -48)*10+Buffer[3]-48;
  uint8_t month=(Buffer[5]-48)*10+Buffer[6]-48;
  uint8_t day=(Buffer[8]-48)*10+Buffer[9]-48;
  
  printf("YEAR: %d : MONTH: %d DAY: %d \n", year,month,day);
  
  HAL_UART_Transmit(&huart3, (uint8_t *)time, strlen(time),5000);
  // Startar seriekommunikation, för att ställa tid och datum för RTC klockan
   // Fixa dummy säkerhet. 0<HOUR<23 0<MIN<59 0<SEC<59 HH:MM 
  if(HAL_UART_Receive_IT(&huart3, (uint8_t *) Buffer, BUFFERSIZETIME) != HAL_OK)
    {
      Error_Handler();
    }
     while( UartReady != SET)
    { 
    }
    printf("done!\n");
    HAL_Delay(500);
    UartReady = RESET; //Sätter tillbaka flaggan
    
    //Omvandlar från ASCI till binärt
      uint8_t hour=(Buffer[0] -48)*10+Buffer[1]-48;
      uint8_t min=(Buffer[3]-48)*10+Buffer[4]-48;
        //uint8_t sec=(Buffer[4] -48)*10+Buffer[5]-48;
  
  
  
  
  
  
  RTC_DateTypeDef sdatestructure; 
  RTC_TimeTypeDef stimestructure;
  
  /*##-1- Configure the Date #################################################*/
  /* Set Date: Tuesday February 18th 2014 */
  sdatestructure.Year = year;
  sdatestructure.Month = month;
  sdatestructure.Date = day;
  sdatestructure.WeekDay = RTC_WEEKDAY_TUESDAY;
  
   if(HAL_RTC_SetDate(&hrtc,&sdatestructure,RTC_FORMAT_BIN) != HAL_OK)
  {
    /* Initialization Error */
    Error_Handler();
  }
  
  
   
 //##-2- Configure the Time #################################################
  stimestructure.Hours = hour;
  stimestructure.Minutes = min;
  stimestructure.Seconds = 0x00;
  stimestructure.TimeFormat = RTC_HOURFORMAT12_AM;
  stimestructure.DayLightSaving = RTC_DAYLIGHTSAVING_NONE ;
  stimestructure.StoreOperation = RTC_STOREOPERATION_RESET;

  if (HAL_RTC_SetTime(&hrtc, &stimestructure, RTC_FORMAT_BIN) != HAL_OK)
  {
    /* Initialization Error */
    Error_Handler();
  }

  /*##-3- Writes a data in a RTC Backup data Register1 #######################*/
  HAL_RTCEx_BKUPWrite(&hrtc, RTC_BKP_DR1, 0x32F2);
} 

//Updates Real time variables and date. 
void Show_RTC_Time(uint8_t* hour, uint8_t* min, uint8_t* sec ){
  
   RTC_TimeTypeDef stimestructureget;
   RTC_DateTypeDef sdatestructureget; //Needed to unlock the time
  
   HAL_RTC_GetTime(&hrtc, &stimestructureget, RTC_FORMAT_BIN);
   HAL_RTC_GetDate(&hrtc, &sdatestructureget, RTC_FORMAT_BIN);//Needed to unlock the time
   
   *min=stimestructureget.Minutes;
   *hour=stimestructureget.Hours;
   *sec=stimestructureget.Seconds;
   
    
   printf("Test_Date! %2d-%2d-%2d  \n ",sdatestructureget.Year,sdatestructureget.Month, sdatestructureget.Date);
  
    return;
}




/**
brief: Tx transfer completed callback
param: UartHandle: Uart hadle.
note: simple example. 
retval: none
*/
void HAL_UART_TxCpltCallback(UART_HandleTypeDef *UartHandle)
{
  /* Set transmission flag: transfer completed */ 
    UartReady = SET;
}

/**
brief: Rx transfer completed callback
param: UartHandle: Uart hadle.
note: simple example. 
retval: none
*/
void HAL_UART_RxCpltCallback(UART_HandleTypeDef *UartHandle)
{
  /* Set transmission flag: transfer completed */ 
    UartReady = SET;
}

