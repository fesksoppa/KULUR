/**
  ******************************************************************************
  * File Name          : TIM.c
  * Description        : This file provides code for the configuration
  *                      of the TIM instances.
  ******************************************************************************
  *
  * Copyright (c) 2017 STMicroelectronics International N.V. 
  * All rights reserved.
  *
  * Redistribution and use in source and binary forms, with or without 
  * modification, are permitted, provided that the following conditions are met:
  *
  * 1. Redistribution of source code must retain the above copyright notice, 
  *    this list of conditions and the following disclaimer.
  * 2. Redistributions in binary form must reproduce the above copyright notice,
  *    this list of conditions and the following disclaimer in the documentation
  *    and/or other materials provided with the distribution.
  * 3. Neither the name of STMicroelectronics nor the names of other 
  *    contributors to this software may be used to endorse or promote products 
  *    derived from this software without specific written permission.
  * 4. This software, including modifications and/or derivative works of this 
  *    software, must execute solely and exclusively on microcontroller or
  *    microprocessor devices manufactured by or for STMicroelectronics.
  * 5. Redistribution and use of this software other than as permitted under 
  *    this license is void and will automatically terminate your rights under 
  *    this license. 
  *
  * THIS SOFTWARE IS PROVIDED BY STMICROELECTRONICS AND CONTRIBUTORS "AS IS" 
  * AND ANY EXPRESS, IMPLIED OR STATUTORY WARRANTIES, INCLUDING, BUT NOT 
  * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY, FITNESS FOR A 
  * PARTICULAR PURPOSE AND NON-INFRINGEMENT OF THIRD PARTY INTELLECTUAL PROPERTY
  * RIGHTS ARE DISCLAIMED TO THE FULLEST EXTENT PERMITTED BY LAW. IN NO EVENT 
  * SHALL STMICROELECTRONICS OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
  * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, 
  * OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF 
  * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING 
  * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
  * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
  *
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "tim.h"
#include "main.h"
#include "gpio.h"
#include "kulur_functions.h"

/* USER CODE BEGIN 0 */
/* USER CODE END 0 */

TIM_HandleTypeDef htim1;

/* TIM1 init function */
void MX_TIM1_Init(void)
{
  TIM_ClockConfigTypeDef sClockSourceConfig;
  TIM_SlaveConfigTypeDef sSlaveConfig;
  TIM_MasterConfigTypeDef sMasterConfig;
  TIM_IC_InitTypeDef sConfigIC;

  htim1.Instance = TIM1;
  htim1.Init.Prescaler = 71; //71 Gives 1 us period
  htim1.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim1.Init.Period = 0xFFFF;
  htim1.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  htim1.Init.RepetitionCounter = 0;
  if (HAL_TIM_Base_Init(&htim1) != HAL_OK)
  {
    Error_Handler();
  }

  sClockSourceConfig.ClockSource = TIM_CLOCKSOURCE_INTERNAL;
  if (HAL_TIM_ConfigClockSource(&htim1, &sClockSourceConfig) != HAL_OK)
  {
    Error_Handler();
  }

  if (HAL_TIM_IC_Init(&htim1) != HAL_OK)
  {
    Error_Handler();
  }

  sSlaveConfig.SlaveMode = TIM_SLAVEMODE_RESET;
  sSlaveConfig.InputTrigger = TIM_TS_TI1FP1;
  sSlaveConfig.TriggerPolarity = TIM_INPUTCHANNELPOLARITY_RISING;
  sSlaveConfig.TriggerFilter = 0;
  if (HAL_TIM_SlaveConfigSynchronization(&htim1, &sSlaveConfig) != HAL_OK)
  {
    Error_Handler();
  }

  sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
  sMasterConfig.MasterOutputTrigger2 = TIM_TRGO2_RESET;
  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
  if (HAL_TIMEx_MasterConfigSynchronization(&htim1, &sMasterConfig) != HAL_OK)
  {
    Error_Handler();
  }

  sConfigIC.ICPolarity = TIM_INPUTCHANNELPOLARITY_RISING; 
  sConfigIC.ICSelection = TIM_ICSELECTION_DIRECTTI;
  sConfigIC.ICPrescaler = TIM_ICPSC_DIV1;
  sConfigIC.ICFilter = 0;
  if (HAL_TIM_IC_ConfigChannel(&htim1, &sConfigIC, TIM_CHANNEL_1) != HAL_OK)
  {
    Error_Handler();
  }

  sConfigIC.ICPolarity = TIM_INPUTCHANNELPOLARITY_FALLING;
  sConfigIC.ICSelection = TIM_ICSELECTION_INDIRECTTI;
  if (HAL_TIM_IC_ConfigChannel(&htim1, &sConfigIC, TIM_CHANNEL_2) != HAL_OK)
  {
    Error_Handler();
  }
    
  HAL_TIM_IC_Start_IT(&htim1, TIM_CHANNEL_1); //Start Input Capture läget
  HAL_TIM_IC_Start_IT(&htim1, TIM_CHANNEL_2); //Start Input Capture läget

}

void HAL_TIM_Base_MspInit(TIM_HandleTypeDef* tim_baseHandle)
{

  GPIO_InitTypeDef GPIO_InitStruct;
  if(tim_baseHandle->Instance==TIM1)
  {
  /* USER CODE BEGIN TIM1_MspInit 0 */

  /* USER CODE END TIM1_MspInit 0 */
    /* Peripheral clock enable */
    __HAL_RCC_TIM1_CLK_ENABLE();
  
    /**TIM1 GPIO Configuration    
    PA8     ------> TIM1_CH1 
    */
    GPIO_InitStruct.Pin = Rxdata_Pin;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
    GPIO_InitStruct.Alternate = GPIO_AF6_TIM1;
    HAL_GPIO_Init(Rxdata_GPIO_Port, &GPIO_InitStruct);

    /* Peripheral interrupt init */
    HAL_NVIC_SetPriority(TIM1_CC_IRQn, 5, 0);
    HAL_NVIC_EnableIRQ(TIM1_CC_IRQn);
  /* USER CODE BEGIN TIM1_MspInit 1 */

  /* USER CODE END TIM1_MspInit 1 */
  }
}

void HAL_TIM_Base_MspDeInit(TIM_HandleTypeDef* tim_baseHandle)
{

  if(tim_baseHandle->Instance==TIM1)
  {
  /* USER CODE BEGIN TIM1_MspDeInit 0 */

  /* USER CODE END TIM1_MspDeInit 0 */
    /* Peripheral clock disable */
    __HAL_RCC_TIM1_CLK_DISABLE();
  
    /**TIM1 GPIO Configuration    
    PA8     ------> TIM1_CH1 
    */
    HAL_GPIO_DeInit(Rxdata_GPIO_Port, Rxdata_Pin);

    /* Peripheral interrupt Deinit*/
    HAL_NVIC_DisableIRQ(TIM1_CC_IRQn);

  }
  /* USER CODE BEGIN TIM1_MspDeInit 1 */

  /* USER CODE END TIM1_MspDeInit 1 */
} 



///******* CALLLBACK INTERRUPT *******
//******* Handles interrupt from the Radioreceiver, checks for preamble and
//*******  then stores 300 samples in an buffer. After the samples are stored, the 
//*******  function search for the net-id and channel number. If found, the frame is sent 
//*******  to a decode functon, if not. The counter and flags are rested.
void HAL_TIM_IC_CaptureCallback(TIM_HandleTypeDef *htim){
  static uint32_t duty_in_microseconds=0;
  static uint32_t buffer_array[SAMPLE_ARRAY_SIZE];//stores lots of samples
//  static uint32_t preamble_bits[NUMBER_OF_PREAMBLE_BITS]; 
  static uint16_t bit_counter=0; 
  static uint8_t preamble_counter=0;
  static bool preamble_flag=false;
  static bool preamble_done=false;
  
  
  //Lock interrupt
  HAL_TIM_IC_Stop_IT(&htim1, TIM_CHANNEL_2);
  HAL_TIM_IC_Stop_IT(&htim1, TIM_CHANNEL_1);
  
  //Captures the pulse width
  if(htim->Channel == HAL_TIM_ACTIVE_CHANNEL_2)
  {
    duty_in_microseconds=HAL_TIM_ReadCapturedValue(htim, TIM_CHANNEL_2);
    
   
  
        
   if(duty_in_microseconds>MINIMUM_DUTY_TICKS && duty_in_microseconds <MAX_DUTY_TICKS && !preamble_flag)
    {   
       if(duty_in_microseconds <PULSE_WIDTH_ONE)
       {
         preamble_counter++;
       
       }
       else
         preamble_counter=0;
       
       
   
    }
    
        
        //Filter out ONEs and ZEROs when the preamble is found and fills sample array
    if(!preamble_done && preamble_flag && ((duty_in_microseconds>PULSE_WIDTH_ZERO && duty_in_microseconds<MAX_DUTY_TICKS) || (duty_in_microseconds>MINIMUM_DUTY_TICKS && duty_in_microseconds<PULSE_WIDTH_ONE) ))
    {
      
        buffer_array[bit_counter]=duty_in_microseconds;
        bit_counter++; 
        
      if(bit_counter==SAMPLE_ARRAY_SIZE) //SAMPLE_ARRAY_SIZE = 300
      {
         for(int i=0;i<SAMPLE_ARRAY_SIZE-7;i++)
         {    //Looks for the Net id and channel number
             if(buffer_array[i]>= PULSE_WIDTH_ZERO && buffer_array[i] <= MAX_DUTY_TICKS && buffer_array[i+1]>= MINIMUM_DUTY_TICKS && 
                buffer_array[i+1]<= PULSE_WIDTH_ONE && buffer_array[i+2]>= PULSE_WIDTH_ZERO && buffer_array[i+2] <= MAX_DUTY_TICKS 
                  && buffer_array[i+3]>= PULSE_WIDTH_ZERO && buffer_array[i+3] <= MAX_DUTY_TICKS && buffer_array[i+4]>= MINIMUM_DUTY_TICKS 
                    && buffer_array[i+4] <= PULSE_WIDTH_ONE && buffer_array[i+5]>= PULSE_WIDTH_ZERO && buffer_array[i+5] <= MAX_DUTY_TICKS 
                      && buffer_array[i+6]>= PULSE_WIDTH_ZERO && buffer_array[i+6] <= MAX_DUTY_TICKS && buffer_array[i+7]>= PULSE_WIDTH_ZERO && buffer_array[i+7] <= MAX_DUTY_TICKS)
            {
               preamble_done=true;
               bit_counter=i; 
            } 
               if(preamble_done)
               {
                 break;
               }
         }
      } //Resets the the flags and counters
      else if(bit_counter>SAMPLE_ARRAY_SIZE)
      {
            preamble_flag=false;
            preamble_done=false;
            preamble_counter=0;
            bit_counter=0;
      }
     
    }
   
   if(preamble_counter>=PREAMBLE_SIZE && !preamble_flag)
      {
         preamble_flag=true;
      }
   
   //Sends the frame to the decoder 
      if(preamble_done)
        {
            preamble_flag=false;
            preamble_done=false;
            preamble_counter=0;
            frame_decoder(buffer_array,bit_counter);
            bit_counter=0; //Do this after you send the frame
        }
  
       
  }
  //Unlock interrupt
   HAL_TIM_IC_Start_IT(&htim1, TIM_CHANNEL_2);
   HAL_TIM_IC_Start_IT(&htim1, TIM_CHANNEL_1);
      
  return;
}





/**
  * @}
  */

/**
  * @}
  */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
