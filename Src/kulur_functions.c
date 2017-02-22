//KULUR_FUNCTIONS.C


#include "main.h"

/* Function Display_Seven_Seg
Input: Seg_Number - Decides which display to me lit
       Number- Decides which number to be shown, 0-9.
Output: None
*/

 void Display_Seven_Seg(uint8_t Seg_Number ,uint8_t Number){
     //---------- 7-SEGMENT ---------------------- 
    switch(Seg_Number){
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
        
        //Kolon
        HAL_GPIO_WritePin(GPIOC,Kolon_Pin,GPIO_PIN_RESET);
        
        HAL_GPIO_WritePin(GPIOD,DP_led_Pin,GPIO_PIN_SET); //Decimalpunkt
        
        printf("DISPLAY: DIG1term---");
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
        
        //Kolon
        HAL_GPIO_WritePin(GPIOC,Kolon_Pin,GPIO_PIN_RESET);
        
        HAL_GPIO_WritePin(GPIOD,DP_led_Pin,GPIO_PIN_RESET); //Decimalpunkt
        printf("DISPLAY: DIG2term---");
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
       
        //Kolon
        HAL_GPIO_WritePin(GPIOC,Kolon_Pin,GPIO_PIN_RESET);
        
        HAL_GPIO_WritePin(GPIOD,DP_led_Pin,GPIO_PIN_SET); //Decimalpunkt
        
        printf("DISPLAY: DIG3term---");
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
       
        //Kolon
        HAL_GPIO_WritePin(GPIOC,Kolon_Pin,GPIO_PIN_RESET);
        
        
        HAL_GPIO_WritePin(GPIOD,DP_led_Pin,GPIO_PIN_SET); //Decimalpunkt
        
        printf("DISPLAY: DIG4term---");
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
        
        //Kolon
        HAL_GPIO_WritePin(GPIOC,Kolon_Pin,GPIO_PIN_RESET);
        
        HAL_GPIO_WritePin(GPIOD,DP_led_Pin,GPIO_PIN_SET); //Decimalpunkt
        
        printf("DISPLAY: DIG1clk---");
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
      
        //Kolon
        HAL_GPIO_WritePin(GPIOC,Kolon_Pin,GPIO_PIN_RESET);
        
        HAL_GPIO_WritePin(GPIOD,DP_led_Pin,GPIO_PIN_SET); //Decimalpunkt
        
        printf("DISPLAY: DIG2clk---");
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
        
        //Kolon
        HAL_GPIO_WritePin(GPIOC,Kolon_Pin,GPIO_PIN_RESET);
        
        HAL_GPIO_WritePin(GPIOD,DP_led_Pin,GPIO_PIN_SET); //Decimalpunkt
        
        printf("DISPLAY: DIG3clk---");
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
       
        //Kolon
        HAL_GPIO_WritePin(GPIOC,Kolon_Pin,GPIO_PIN_RESET);
        
        printf("DISPLAY: DIG4clk---");
        HAL_GPIO_WritePin(GPIOD,DP_led_Pin,GPIO_PIN_SET); //Decimalpunkt
        
        break;
        
        //TA BORT, DENNA ÄR SEPARAT KOLLA PINNE FÖR ATT TÄNDA
        case 8:   //Kolon
        
        //Term_Displays
        HAL_GPIO_WritePin(GPIOC,DIG1term_Pin,GPIO_PIN_RESET); 
        HAL_GPIO_WritePin(GPIOC,DIG2term_Pin,GPIO_PIN_RESET); 
        HAL_GPIO_WritePin(GPIOC,DIG3term_Pin,GPIO_PIN_RESET);
        HAL_GPIO_WritePin(GPIOC,DIG4term_Pin,GPIO_PIN_RESET);
        
        //CLOCK_Displays
        HAL_GPIO_WritePin(GPIOC,DIG1clk_Pin,GPIO_PIN_RESET); 
        HAL_GPIO_WritePin(GPIOC,DIG2clk_Pin,GPIO_PIN_RESET);
        HAL_GPIO_WritePin(GPIOC,DIG3clk_Pin,GPIO_PIN_RESET);
        HAL_GPIO_WritePin(GPIOC,DIG4clk_Pin,GPIO_PIN_RESET);
       
        //Kolon
        HAL_GPIO_WritePin(GPIOC,Kolon_Pin,GPIO_PIN_SET);
        
        HAL_GPIO_WritePin(GPIOD,DP_led_Pin,GPIO_PIN_SET); //Decimalpunkt
        
        printf("DISPLAY: Kolon---");
        break;
        
        
       
        
    default:
      ;
    } //end switch 7-seg
    
    
    //---------------- DISPLAY NUMBER------------------------
    switch(Number){
      
    case 0: 
      HAL_GPIO_WritePin(GPIOD,A_led_Pin,GPIO_PIN_RESET);
      HAL_GPIO_WritePin(GPIOD,B_led_Pin,GPIO_PIN_RESET);
      HAL_GPIO_WritePin(GPIOD,C_led_Pin,GPIO_PIN_RESET);
      HAL_GPIO_WritePin(GPIOD,D_led_Pin,GPIO_PIN_RESET);
      HAL_GPIO_WritePin(GPIOD,E_led_Pin,GPIO_PIN_RESET);
      HAL_GPIO_WritePin(GPIOD,F_led_Pin,GPIO_PIN_RESET);
      HAL_GPIO_WritePin(GPIOD,G_led_Pin,GPIO_PIN_SET);
      //Tänk på DP, ligger över 
      
      printf("NUMBER: 0 \n");
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
      printf("NUMBER: 1 \n");
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
      printf("NUMBER: 2 \n");
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
      printf("NUMBER: 3 \n");
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
      printf("NUMBER: 4 \n");
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
      printf("NUMBER: 5 \n");
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
      printf("NUMBER: 6 \n");
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
      printf("NUMBER: 7 \n");
      
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
      printf("NUMBER: 8 \n");
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
      printf("NUMBER: 9 \n");
      break;
      
     default: 
       ;
    }

   return; //end of function
 }