//KULUR_FUNCTIONS.C


#include "main.h"
#include "stdbool.h"
#include "kulur_functions.h"
#include "crc.h"

/* Function Display_Seven_Seg
Input: Temp - New temp value
       new_temp- Ture if you want to update temp, else false.
Output: None
*/

 void Display_Seven_Seg(uint16_t temp ,bool new_temp){
   

  static uint8_t tempAndTimeValues[8];
   
  uint8_t display_counter=0;
  uint8_t hour=0;
  uint8_t min=0;
  uint8_t sec=0;
 
  Show_RTC_Time(&hour,&min, &sec); //Get current time 
 if(new_temp)
  {
    if(temp>=512) // Negativ temp
    {
      tempAndTimeValues[0]=10;
      temp-=512;
      
    }
    else
    tempAndTimeValues[0]=11;
    
    tempAndTimeValues[1]=temp/100;
    tempAndTimeValues[2]=(temp%100)/10;
    tempAndTimeValues[3]=temp%10;
  }
  
  tempAndTimeValues[4]=hour/10;
  tempAndTimeValues[5]=hour%10;
  tempAndTimeValues[6]=min/10;
  tempAndTimeValues[7]=min%10;
  
 
  uint32_t current_second=HAL_GetTick();
  static uint32_t last_second;
  if((current_second-last_second)>500)
  {
    HAL_GPIO_TogglePin(GPIOC,Kolon_Pin);
    last_second=current_second;
  }
  

  //display_counter=1;
   
  while(display_counter<8 && !new_temp )
  {
    
      //---------- 7-SEGMENT ---------------------- 
    switch(display_counter){
      case 0:   //DIG1term
        
        //Term_Displays
        HAL_GPIO_WritePin(GPIOC,DIG1term_Pin,GPIO_PIN_SET); //SET
        HAL_GPIO_WritePin(GPIOC,DIG2term_Pin,GPIO_PIN_RESET);
        HAL_GPIO_WritePin(GPIOC,DIG3term_Pin,GPIO_PIN_RESET);
        HAL_GPIO_WritePin(GPIOC,DIG4term_Pin,GPIO_PIN_RESET);
        
        //CLOCK_Displays
        HAL_GPIO_WritePin(GPIOC,DIG1clk_Pin,GPIO_PIN_RESET);
        HAL_GPIO_WritePin(GPIOC,DIG2clk_Pin,GPIO_PIN_RESET);
        HAL_GPIO_WritePin(GPIOC,DIG3clk_Pin,GPIO_PIN_RESET);
        HAL_GPIO_WritePin(GPIOC,DIG4clk_Pin,GPIO_PIN_RESET);
        
        
        
        HAL_GPIO_WritePin(GPIOD,DP_led_Pin,GPIO_PIN_SET); //Decimalpunkt
        
        
        break;
        
       case 1:   //DIG2term
        
        //Term_Displays
        HAL_GPIO_WritePin(GPIOC,DIG1term_Pin,GPIO_PIN_RESET); 
        HAL_GPIO_WritePin(GPIOC,DIG2term_Pin,GPIO_PIN_SET); //SET
        HAL_GPIO_WritePin(GPIOC,DIG3term_Pin,GPIO_PIN_RESET);
        HAL_GPIO_WritePin(GPIOC,DIG4term_Pin,GPIO_PIN_RESET);
        
        //CLOCK_Displays
        HAL_GPIO_WritePin(GPIOC,DIG1clk_Pin,GPIO_PIN_RESET);
       HAL_GPIO_WritePin(GPIOC,DIG2clk_Pin,GPIO_PIN_RESET);
       HAL_GPIO_WritePin(GPIOC,DIG3clk_Pin,GPIO_PIN_RESET);
       HAL_GPIO_WritePin(GPIOC,DIG4clk_Pin,GPIO_PIN_RESET);
        
       
        
        HAL_GPIO_WritePin(GPIOD,DP_led_Pin,GPIO_PIN_SET); //Decimalpunkt
        
         
        break;
        
       case 2:   //DIG3term
        
        //Term_Displays
        HAL_GPIO_WritePin(GPIOC,DIG1term_Pin,GPIO_PIN_RESET); 
        HAL_GPIO_WritePin(GPIOC,DIG2term_Pin,GPIO_PIN_RESET); 
        HAL_GPIO_WritePin(GPIOC,DIG3term_Pin,GPIO_PIN_SET); //SET 
        HAL_GPIO_WritePin(GPIOC,DIG4term_Pin,GPIO_PIN_RESET);
        
        //CLOCK_Displays
        HAL_GPIO_WritePin(GPIOC,DIG1clk_Pin,GPIO_PIN_RESET);
        HAL_GPIO_WritePin(GPIOC,DIG2clk_Pin,GPIO_PIN_RESET);
        HAL_GPIO_WritePin(GPIOC,DIG3clk_Pin,GPIO_PIN_RESET);
        HAL_GPIO_WritePin(GPIOC,DIG4clk_Pin,GPIO_PIN_RESET);
       
       
        
        HAL_GPIO_WritePin(GPIOD,DP_led_Pin,GPIO_PIN_RESET); //Decimalpunkt
        
        
        
        break;
        
       case 3:   //DIG4term
        
        //Term_Displays
        HAL_GPIO_WritePin(GPIOC,DIG1term_Pin,GPIO_PIN_RESET); 
        HAL_GPIO_WritePin(GPIOC,DIG2term_Pin,GPIO_PIN_RESET); 
        HAL_GPIO_WritePin(GPIOC,DIG3term_Pin,GPIO_PIN_RESET);
        HAL_GPIO_WritePin(GPIOC,DIG4term_Pin,GPIO_PIN_SET); //set
        
        //CLOCK_Displays
        HAL_GPIO_WritePin(GPIOC,DIG1clk_Pin,GPIO_PIN_RESET);
        HAL_GPIO_WritePin(GPIOC,DIG2clk_Pin,GPIO_PIN_RESET);
        HAL_GPIO_WritePin(GPIOC,DIG3clk_Pin,GPIO_PIN_RESET);
        HAL_GPIO_WritePin(GPIOC,DIG4clk_Pin,GPIO_PIN_RESET);
       
       
        
        
        HAL_GPIO_WritePin(GPIOD,DP_led_Pin,GPIO_PIN_SET); //Decimalpunkt
        
        
        break;
        
       case 4:   //DIG1clk
        
        //Term_Displays
        HAL_GPIO_WritePin(GPIOC,DIG1term_Pin,GPIO_PIN_RESET); 
        HAL_GPIO_WritePin(GPIOC,DIG2term_Pin,GPIO_PIN_RESET); 
        HAL_GPIO_WritePin(GPIOC,DIG3term_Pin,GPIO_PIN_RESET);
        HAL_GPIO_WritePin(GPIOC,DIG4term_Pin,GPIO_PIN_RESET);
        
        //CLOCK_Displays
        HAL_GPIO_WritePin(GPIOC,DIG1clk_Pin,GPIO_PIN_SET); //set
        HAL_GPIO_WritePin(GPIOC,DIG2clk_Pin,GPIO_PIN_RESET);
        HAL_GPIO_WritePin(GPIOC,DIG3clk_Pin,GPIO_PIN_RESET);
        HAL_GPIO_WritePin(GPIOC,DIG4clk_Pin,GPIO_PIN_RESET);
        
       
        
        HAL_GPIO_WritePin(GPIOD,DP_led_Pin,GPIO_PIN_SET); //Decimalpunkt
        
        
        break;
        
       case 5:   //DIG2clk
        
        //Term_Displays
        HAL_GPIO_WritePin(GPIOC,DIG1term_Pin,GPIO_PIN_RESET); 
        HAL_GPIO_WritePin(GPIOC,DIG2term_Pin,GPIO_PIN_RESET); 
        HAL_GPIO_WritePin(GPIOC,DIG3term_Pin,GPIO_PIN_RESET);
        HAL_GPIO_WritePin(GPIOC,DIG4term_Pin,GPIO_PIN_RESET);
        
        //CLOCK_Displays
        HAL_GPIO_WritePin(GPIOC,DIG1clk_Pin,GPIO_PIN_RESET);
        HAL_GPIO_WritePin(GPIOC,DIG2clk_Pin,GPIO_PIN_SET); //set
        HAL_GPIO_WritePin(GPIOC,DIG3clk_Pin,GPIO_PIN_RESET);
        HAL_GPIO_WritePin(GPIOC,DIG4clk_Pin,GPIO_PIN_RESET);
      
       
        
        HAL_GPIO_WritePin(GPIOD,DP_led_Pin,GPIO_PIN_SET); //Decimalpunkt
        
        
        break;
        
       case 6:   //DIG3clk
        
        //Term_Displays
        HAL_GPIO_WritePin(GPIOC,DIG1term_Pin,GPIO_PIN_RESET); 
        HAL_GPIO_WritePin(GPIOC,DIG2term_Pin,GPIO_PIN_RESET); 
        HAL_GPIO_WritePin(GPIOC,DIG3term_Pin,GPIO_PIN_RESET);
        HAL_GPIO_WritePin(GPIOC,DIG4term_Pin,GPIO_PIN_RESET);
        
        //CLOCK_Displays
        HAL_GPIO_WritePin(GPIOC,DIG1clk_Pin,GPIO_PIN_RESET); 
        HAL_GPIO_WritePin(GPIOC,DIG2clk_Pin,GPIO_PIN_RESET);
        HAL_GPIO_WritePin(GPIOC,DIG3clk_Pin,GPIO_PIN_SET); //set
        HAL_GPIO_WritePin(GPIOC,DIG4clk_Pin,GPIO_PIN_RESET);
        
       
      
        
        HAL_GPIO_WritePin(GPIOD,DP_led_Pin,GPIO_PIN_SET); //Decimalpunkt
        
       
        break;
        
        case 7:   //DIG4clk
        
        //Term_Displays
        HAL_GPIO_WritePin(GPIOC,DIG1term_Pin,GPIO_PIN_RESET); 
        HAL_GPIO_WritePin(GPIOC,DIG2term_Pin,GPIO_PIN_RESET); 
        HAL_GPIO_WritePin(GPIOC,DIG3term_Pin,GPIO_PIN_RESET);
        HAL_GPIO_WritePin(GPIOC,DIG4term_Pin,GPIO_PIN_RESET);
        
        //CLOCK_Displays
        HAL_GPIO_WritePin(GPIOC,DIG1clk_Pin,GPIO_PIN_RESET); 
        HAL_GPIO_WritePin(GPIOC,DIG2clk_Pin,GPIO_PIN_RESET);
        HAL_GPIO_WritePin(GPIOC,DIG3clk_Pin,GPIO_PIN_RESET); 
        HAL_GPIO_WritePin(GPIOC,DIG4clk_Pin,GPIO_PIN_SET); //set
       
        
        
       
        HAL_GPIO_WritePin(GPIOD,DP_led_Pin,GPIO_PIN_SET); //Decimalpunkt
        
        break;
        
        
    default:
      ;
    } //end switch 7-seg
    
    
    //---------------- DISPLAY NUMBER------------------------
    switch(tempAndTimeValues[display_counter]){
      
    case 0: 
      HAL_GPIO_WritePin(GPIOD,A_led_Pin,GPIO_PIN_RESET);
      HAL_GPIO_WritePin(GPIOD,B_led_Pin,GPIO_PIN_RESET);
      HAL_GPIO_WritePin(GPIOD,C_led_Pin,GPIO_PIN_RESET);
      HAL_GPIO_WritePin(GPIOD,D_led_Pin,GPIO_PIN_RESET);
      HAL_GPIO_WritePin(GPIOD,E_led_Pin,GPIO_PIN_RESET);
      HAL_GPIO_WritePin(GPIOD,F_led_Pin,GPIO_PIN_RESET);
      HAL_GPIO_WritePin(GPIOD,G_led_Pin,GPIO_PIN_SET);
      //Tänk på DP, ligger över 
      
      
      break;
      
     case 1: 
      HAL_GPIO_WritePin(GPIOD,A_led_Pin,GPIO_PIN_SET);
      HAL_GPIO_WritePin(GPIOD,B_led_Pin,GPIO_PIN_RESET);
      HAL_GPIO_WritePin(GPIOD,C_led_Pin,GPIO_PIN_RESET);
      HAL_GPIO_WritePin(GPIOD,D_led_Pin,GPIO_PIN_SET);
      HAL_GPIO_WritePin(GPIOD,E_led_Pin,GPIO_PIN_SET);
      HAL_GPIO_WritePin(GPIOD,F_led_Pin,GPIO_PIN_SET);
      HAL_GPIO_WritePin(GPIOD,G_led_Pin,GPIO_PIN_SET);
      //Tänk på DP, ligger över 
    
      break;
      
      case 2: 
      HAL_GPIO_WritePin(GPIOD,A_led_Pin,GPIO_PIN_RESET);
      HAL_GPIO_WritePin(GPIOD,B_led_Pin,GPIO_PIN_RESET);
      HAL_GPIO_WritePin(GPIOD,C_led_Pin,GPIO_PIN_SET);
      HAL_GPIO_WritePin(GPIOD,D_led_Pin,GPIO_PIN_RESET);
      HAL_GPIO_WritePin(GPIOD,E_led_Pin,GPIO_PIN_RESET);
      HAL_GPIO_WritePin(GPIOD,F_led_Pin,GPIO_PIN_SET);
      HAL_GPIO_WritePin(GPIOD,G_led_Pin,GPIO_PIN_RESET);
      //Tänk på DP, ligger över 
     
      break;
      
      case 3: 
      HAL_GPIO_WritePin(GPIOD,A_led_Pin,GPIO_PIN_RESET);
      HAL_GPIO_WritePin(GPIOD,B_led_Pin,GPIO_PIN_RESET);
      HAL_GPIO_WritePin(GPIOD,C_led_Pin,GPIO_PIN_RESET);
      HAL_GPIO_WritePin(GPIOD,D_led_Pin,GPIO_PIN_RESET);
      HAL_GPIO_WritePin(GPIOD,E_led_Pin,GPIO_PIN_SET);
      HAL_GPIO_WritePin(GPIOD,F_led_Pin,GPIO_PIN_SET);
      HAL_GPIO_WritePin(GPIOD,G_led_Pin,GPIO_PIN_RESET);
      //Tänk på DP, ligger över 
     
      break;
      
      
      case 4: 
      HAL_GPIO_WritePin(GPIOD,A_led_Pin,GPIO_PIN_SET);
      HAL_GPIO_WritePin(GPIOD,B_led_Pin,GPIO_PIN_RESET);
      HAL_GPIO_WritePin(GPIOD,C_led_Pin,GPIO_PIN_RESET);
      HAL_GPIO_WritePin(GPIOD,D_led_Pin,GPIO_PIN_SET);
      HAL_GPIO_WritePin(GPIOD,E_led_Pin,GPIO_PIN_SET);
      HAL_GPIO_WritePin(GPIOD,F_led_Pin,GPIO_PIN_RESET);
      HAL_GPIO_WritePin(GPIOD,G_led_Pin,GPIO_PIN_RESET);
      //Tänk på DP, ligger över 
     
      break;
      
     case 5: 
      HAL_GPIO_WritePin(GPIOD,A_led_Pin,GPIO_PIN_RESET);
      HAL_GPIO_WritePin(GPIOD,B_led_Pin,GPIO_PIN_SET);
      HAL_GPIO_WritePin(GPIOD,C_led_Pin,GPIO_PIN_RESET);
      HAL_GPIO_WritePin(GPIOD,D_led_Pin,GPIO_PIN_RESET);
      HAL_GPIO_WritePin(GPIOD,E_led_Pin,GPIO_PIN_SET);
      HAL_GPIO_WritePin(GPIOD,F_led_Pin,GPIO_PIN_RESET);
      HAL_GPIO_WritePin(GPIOD,G_led_Pin,GPIO_PIN_RESET);
      //Tänk på DP, ligger över 
      
      
      break;
      
       case 6: 
      HAL_GPIO_WritePin(GPIOD,A_led_Pin,GPIO_PIN_RESET);
      HAL_GPIO_WritePin(GPIOD,B_led_Pin,GPIO_PIN_SET);
      HAL_GPIO_WritePin(GPIOD,C_led_Pin,GPIO_PIN_RESET);
      HAL_GPIO_WritePin(GPIOD,D_led_Pin,GPIO_PIN_RESET);
      HAL_GPIO_WritePin(GPIOD,E_led_Pin,GPIO_PIN_RESET);
      HAL_GPIO_WritePin(GPIOD,F_led_Pin,GPIO_PIN_RESET);
      HAL_GPIO_WritePin(GPIOD,G_led_Pin,GPIO_PIN_RESET);
      //Tänk på DP, ligger över 
      
      break;
      
       case 7: 
      HAL_GPIO_WritePin(GPIOD,A_led_Pin,GPIO_PIN_RESET);
      HAL_GPIO_WritePin(GPIOD,B_led_Pin,GPIO_PIN_RESET);
      HAL_GPIO_WritePin(GPIOD,C_led_Pin,GPIO_PIN_RESET);
      HAL_GPIO_WritePin(GPIOD,D_led_Pin,GPIO_PIN_SET);
      HAL_GPIO_WritePin(GPIOD,E_led_Pin,GPIO_PIN_SET);
      HAL_GPIO_WritePin(GPIOD,F_led_Pin,GPIO_PIN_SET);
      HAL_GPIO_WritePin(GPIOD,G_led_Pin,GPIO_PIN_SET);
      //Tänk på DP, ligger över 
     
      
      
      break;
      
       case 8: 
      HAL_GPIO_WritePin(GPIOD,A_led_Pin,GPIO_PIN_RESET);
      HAL_GPIO_WritePin(GPIOD,B_led_Pin,GPIO_PIN_RESET);
      HAL_GPIO_WritePin(GPIOD,C_led_Pin,GPIO_PIN_RESET);
      HAL_GPIO_WritePin(GPIOD,D_led_Pin,GPIO_PIN_RESET);
      HAL_GPIO_WritePin(GPIOD,E_led_Pin,GPIO_PIN_RESET);
      HAL_GPIO_WritePin(GPIOD,F_led_Pin,GPIO_PIN_RESET);
      HAL_GPIO_WritePin(GPIOD,G_led_Pin,GPIO_PIN_RESET);
      //Tänk på DP, ligger över 
      
      break;
      
      case 9: 
      HAL_GPIO_WritePin(GPIOD,A_led_Pin,GPIO_PIN_RESET);
      HAL_GPIO_WritePin(GPIOD,B_led_Pin,GPIO_PIN_RESET);
      HAL_GPIO_WritePin(GPIOD,C_led_Pin,GPIO_PIN_RESET);
      HAL_GPIO_WritePin(GPIOD,D_led_Pin,GPIO_PIN_SET);
      HAL_GPIO_WritePin(GPIOD,E_led_Pin,GPIO_PIN_SET);
      HAL_GPIO_WritePin(GPIOD,F_led_Pin,GPIO_PIN_RESET);
      HAL_GPIO_WritePin(GPIOD,G_led_Pin,GPIO_PIN_RESET);
      //Tänk på DP, ligger över 
      
      break;
      
      case 10: //-
      HAL_GPIO_WritePin(GPIOD,A_led_Pin,GPIO_PIN_SET);
      HAL_GPIO_WritePin(GPIOD,B_led_Pin,GPIO_PIN_SET);
      HAL_GPIO_WritePin(GPIOD,C_led_Pin,GPIO_PIN_SET);
      HAL_GPIO_WritePin(GPIOD,D_led_Pin,GPIO_PIN_SET);
      HAL_GPIO_WritePin(GPIOD,E_led_Pin,GPIO_PIN_SET);
      HAL_GPIO_WritePin(GPIOD,F_led_Pin,GPIO_PIN_SET);
      HAL_GPIO_WritePin(GPIOD,G_led_Pin,GPIO_PIN_RESET);
   
      break;
      
     default:   
      HAL_GPIO_WritePin(GPIOD,A_led_Pin,GPIO_PIN_SET);
      HAL_GPIO_WritePin(GPIOD,B_led_Pin,GPIO_PIN_SET);
      HAL_GPIO_WritePin(GPIOD,C_led_Pin,GPIO_PIN_SET);
      HAL_GPIO_WritePin(GPIOD,D_led_Pin,GPIO_PIN_SET);
      HAL_GPIO_WritePin(GPIOD,E_led_Pin,GPIO_PIN_SET);
      HAL_GPIO_WritePin(GPIOD,F_led_Pin,GPIO_PIN_SET);
      HAL_GPIO_WritePin(GPIOD,G_led_Pin,GPIO_PIN_SET);
      
      break;
    }
    
    
    
   
    
    
    
    display_counter++;
    HAL_Delay(1);
   
  } //While loop
  
   
  
   return; //end of function
 }

 
//Decodes the radioframe, takes the sample array and the position of the first bit in the frame
//The function have a CRC, the temp value updates when the crc =0
void frame_decoder(uint32_t radio_frame[] , uint16_t bit_counter)
{
  uint32_t decoded_frame[FRAME_SIZE]=0;
  uint16_t temp=0;
  
 
   
    //Dummy check
  //if(bit_counter >= SAMPLE_ARRAY_SIZE-40)
 // {
   
      for(int i=0;i<FRAME_SIZE;i++)
      {
        if(radio_frame[i+bit_counter]>=MINIMUM_DUTY_TICKS && radio_frame[i+bit_counter] <=PULSE_WIDTH_ONE)
        {
          decoded_frame[i]=1;
        }
        else if(radio_frame[i+bit_counter]>=PULSE_WIDTH_ZERO && radio_frame[i+bit_counter] <=MAX_DUTY_TICKS)
        {
          decoded_frame[i]=0;
        }
      }
      //CRC Check 
      if(HAL_CRC_Calculate(&hcrc,decoded_frame, FRAME_SIZE)==0)
      { 
      
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
        
        Display_Seven_Seg(temp,true);
        
      }
 // }
  return; 
}
