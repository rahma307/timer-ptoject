/*
 * main.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: hp
 */

/* lib layer */
#include  "STD_TYPES.h"
#include  "BIT_MATH.h"
#include   "util/delay.h"
/* mcal layer */
#include  "DIO_INT.h"
#include  "GLOPAL_INT.h"
#include  "TIM0_INT.h"
#include  "EXTI_INT.h"

/*hal layer  */
#include  "LCD_INT.h"
#include  "KP_INT.h"


u8 pinvalue ;
u8  sign_1 ;
u8 num_1=0 ;
u8 countr=0 ,countl=0;
u8 flagr=0 , flagl=0 ;
u8 minuts_tens=0 ;
u8 minuts_units =0;
u8 second_tens =0;
u8 second_units=0 ;
u8 hour_tens =0;
u8 hour_units =0;
u8 minuts=0 ;
u8 hours=0 ;
u8 seconds=0 ;
u8 num ;
u8 countr_alarm=0 ,countl_alarm=0;
u8 flagr_alarm=0 , flagl_alarm=0 ;
u8 minuts_tens_alarm=0 ;
u8 minuts_units_alarm =0;
u8 second_tens_alarm =0;
u8 second_units_alarm=0 ;
u8 hour_tens_alarm =0;
u8 hour_units_alarm =0;
u8 minuts_alarm=0 ;
u8 hours_Alarm=0 ;
u8 secondsalarm=0 ;
u8 num_al ;
u8 read ;
u8 set=0;
u8 alarm_flag =0 ;

u8 minuts_st=0 ;
u8 hours_st=0 ;
u8 secondst=0 ;
u8 stop_flag =0 ;
void time(void);



void set_time(void){
	s8 value ;
	LCD_WRITE_STRING(" 00:00:00  AM");

 while(1){
	 do{ KPD_u8KpdGetKeyState(&pinvalue);
		 }while(pinvalue ==  Kpd_keynotpressed);

	 if(value ==9){
	 		flagr =1 ;
	 	}
	 else{
		 flagr =0;
	 }

	if(pinvalue=='r' && flagr ==0 ){
		countr++;
		flagl=1 ;
	}
	else if(pinvalue=='l' && flagl ==1){
		countl++;

	}
	if( countl ==3 || countl ==6){
		countl++;
	}
	if( countr ==2 || countr ==5){
			countr++;
		}

	value = countl - countr;
	if(value <0){
		value*=-1 ;
	}
	LCD_GO_TO(line1 , value);
  sign_1 = pinvalue -'0';
   if(sign_1 >=0 && sign_1<=9 ){
   num_1 = (num_1*10) + (pinvalue -'0');
   LCD_GO_TO(line1 , value);
   Lcd_voidDisplayNumber(num_1);
  		switch(value){
	 		case 1:

	 			hour_tens=num_1*10 ;
	 			hours=hour_tens+hour_units;
	 			num_1 =0 ;
	 			break ;

	 		case 2:
	 			hour_units=num_1 ;
	 			hours=hour_tens+hour_units;
	 			num_1 =0;
	 		    break ;
	 		case 4:
	 			minuts_tens=num_1*10 ;
	 			minuts=minuts_tens+minuts_units;
	 			num_1=0;
	 		    break ;
	 		case 5:
	 			minuts_units=num_1 ;
	 			minuts=minuts_tens+minuts_units;
	 			num_1=0;
	 			break ;
	 		case 7:
	 			second_tens = num_1*10 ;
	 			seconds = second_tens+second_units;
	 			num_1=0;
	             break ;
	 		case 8:
	 			second_units = num_1;
	 			seconds = second_tens+second_units;
	 			num_1=0;
	 			break ;


	  }}
		if(pinvalue=='e'){
			break ;
		}
			  }


}


void alarm(void){
	s8 value ;
	LCD_GO_TO(line2, 0);
		LCD_WRITE_STRING(" 00:00:00  AM");

	 while(1){
		 do{ KPD_u8KpdGetKeyState(&pinvalue);
			 }while(pinvalue ==  Kpd_keynotpressed);

		 if(value ==9){
		 		flagr_alarm =1 ;
		 	}
		 else{
			 flagr_alarm =0;
		 }

		if(pinvalue=='r' && flagr_alarm ==0 ){
			countr_alarm++;
			flagl_alarm=1 ;
		}
		else if(pinvalue=='l' && flagl_alarm ==1){
			countl_alarm++;

		}
		if( countl_alarm ==3 || countl_alarm ==6){
			countl_alarm++;
		}
		if( countr_alarm ==2 || countr_alarm ==5){
				countr_alarm++;
			}

		value = countl_alarm - countr_alarm;
		if(value <0){
			value*=-1 ;
		}
		LCD_GO_TO(line2 , value);
	  sign_1 = pinvalue -'0';
	   if(sign_1 >=0 && sign_1<=9 ){
	   num_1 = (num_1*10) + (pinvalue -'0');
	   LCD_GO_TO(line2 , value);
	   Lcd_voidDisplayNumber(num_1);
	  		switch(value){
		 		case 1:

		 			hour_tens_alarm=num_1*10 ;
		 			hours_Alarm=hour_tens_alarm+hour_units_alarm;
		 			num_1 =0 ;
		 			break ;

		 		case 2:
		 			hour_units_alarm=num_1 ;
		 			hours_Alarm=hour_tens_alarm+hour_units_alarm;
		 			num_1 =0;
		 		    break ;
		 		case 4:
		 			minuts_tens_alarm=num_1*10 ;
		 			minuts_alarm=minuts_tens_alarm+minuts_units_alarm;
		 			num_1=0;
		 		    break ;
		 		case 5:
		 			minuts_units_alarm=num_1 ;
		 			minuts_alarm=minuts_tens_alarm+minuts_units_alarm;
		 			num_1=0;
		 			break ;
		 		case 7:
		 			second_tens_alarm = num_1*10 ;
		 			secondsalarm = second_tens_alarm+second_units_alarm;
		 			num_1=0;
		             break ;
		 		case 8:
		 			second_units_alarm = num_1;
		 			secondsalarm = second_tens_alarm+second_units_alarm;
		 			num_1=0;
		 			break ;


		  }}
			if(pinvalue=='e'){
				break ;
			}
				  }



}


void stop_watch(void){
	LCD_WRITE_COMMAND(lcd_Clear);
	LCD_GO_TO(line2,0);
	LCD_WRITE_STRING(" 00:00:00");
	 do{ KPD_u8KpdGetKeyState(&pinvalue);
		}while(pinvalue ==  Kpd_keynotpressed);

	 if(pinvalue=='e'){
          stop_flag=1;

	 }
}

void alarm_dis(void);
int main(){

	DIO_voidInit();
	LCD_INIT();
	GI_voidEnable();
	TIM0_SetCallBackoverflow(time);
	TIM0_INIT();
	EXTI_SET_CALL_BACK(alarm_dis , 0);
    EXTI_u8EXTEnable(EXT0, Falling_edge);

	while(1){

		LCD_WRITE_STRING(" 00:00:00");
	 if( num ==1){
		 LCD_GO_TO(line1 , 13);
		    LCD_WRITE_STRING("AM");
				  }
	 else if ( num == 2){
			  LCD_GO_TO(line1 , 13);
			 LCD_WRITE_STRING("PM");
					 	    }
        LCD_GO_TO(line2,0);
		LCD_WRITE_STRING("1-T 2-al 3-cont");
      do{
			 KPD_u8KpdGetKeyState(&pinvalue);
			  }while(pinvalue ==  Kpd_keynotpressed);
	    sign_1 = pinvalue -'0';
		if(sign_1 >=0 && sign_1<=9 ){
			num_1 = (num_1*10) + (pinvalue -'0');
			  }


	   switch( num_1){
	   case 1:
		   num_1=0 ;
		   LCD_WRITE_COMMAND(lcd_Clear);
		   set_time();

		   if( pinvalue!='s'){
            LCD_GO_TO(line2 ,0);
		   LCD_WRITE_STRING("1-AM 2-PM") ;

		   do{ KPD_u8KpdGetKeyState(&pinvalue);
		  		 }while(pinvalue ==  Kpd_keynotpressed);
		  sign_1 = pinvalue -'0';
		  if(sign_1 >=0 && sign_1<=9 ){
		  			num = (num*10) + (pinvalue -'0');
		  			  }

          }

		  num_1=0;
		  do{  KPD_u8KpdGetKeyState(&pinvalue);
		  			  }while(pinvalue ==  Kpd_keynotpressed);
		  if( pinvalue=='s'){
		  set =1 ;}
         LCD_WRITE_COMMAND(lcd_Clear);
		  num_1=0;



  break ;
  case 2:
	  LCD_WRITE_COMMAND(lcd_Clear);
	   num_1=0;
	   if( pinvalue!='s'){
	            alarm();
	            LCD_GO_TO(line2 ,0);
	 		   LCD_WRITE_STRING("1-AM 2-PM") ;
	 		   do{ KPD_u8KpdGetKeyState(&pinvalue);
	 		  		 }while(pinvalue ==  Kpd_keynotpressed);
	 		  sign_1 = pinvalue -'0';
	 		  if(sign_1 >=0 && sign_1<=9 ){
	 		  			num_al = (num_al*10) + (pinvalue -'0');
	 		  			  }


	 		  LCD_WRITE_COMMAND(lcd_Clear);}
	 		  num_1=0;


		   break ;

case 3:
	LCD_WRITE_COMMAND(lcd_Clear);
	 LCD_GO_TO(line2 ,0);
     LCD_WRITE_STRING("1-stop_w 2_back") ;
   num_1 =0 ;
   while(1) {
     do{ KPD_u8KpdGetKeyState(&pinvalue);
    	  }while(pinvalue ==  Kpd_keynotpressed);
    	 		  sign_1 = pinvalue -'0';
    	 		  if(sign_1 >=0 && sign_1<=9 ){
    	 		  			num_1 = (num_1*10) + (pinvalue -'0');
    	 		  			  }
    if(num_1 ==1){
    	 	stop_watch();
    	 	 LCD_GO_TO(line2 ,10);
             LCD_WRITE_STRING("2_back") ;
    	 	num_1=0 ;

    	 while(1){
    	 	do{ KPD_u8KpdGetKeyState(&pinvalue);
    	 	    }while(pinvalue ==  Kpd_keynotpressed);
    	 	   num_1=0 ;
    	 	  sign_1 = pinvalue -'0';
    	      num_1 = (num_1*10) + (pinvalue -'0');
    	    if(pinvalue=='g'){
    	    	stop_flag=0;
    	    }
    	    if( num_1==2){
    	    	stop_flag=0;
    	    	LCD_WRITE_COMMAND(lcd_Clear);
    	    	break ;
    	    }

    	 }

    }

        if(num_1 ==2){
        	LCD_WRITE_COMMAND(lcd_Clear);
        	stop_flag =0 ;
        	num_1=0;
     break ;

        }}
   num_1=0;
		   break ;






	   }


if(pinvalue=='g'){
	stop_flag=0;
	LCD_WRITE_COMMAND(lcd_Clear);
}



	}


}


void time(void){

if(set==1){

	if(seconds == 59 && minuts<=58){
		seconds=0;
		minuts++;
		if( hours == hours_Alarm && minuts== minuts_alarm && seconds ==secondsalarm && set ==1  && num==num_al){
	   		 	alarm_flag=1;
	   			  	 }
         if( alarm_flag==1){
            DIO_u8SetPinValue(PORTA,PIN_5,LOGIC_HIGH);
              }
	}
	else if(seconds==59 && minuts==59 && hours<12){
		minuts=0;
		seconds=0;
		hours++;
		if( hours == hours_Alarm && minuts== minuts_alarm && seconds ==secondsalarm && set ==1 && num==num_al){
	   			  	 	alarm_flag=1;
	   			  	 }

	   			  	 if( alarm_flag==1){

	   			  	 	DIO_u8SetPinValue(PORTA,PIN_5,LOGIC_HIGH);

	   			  	 }
	}
	else if(hours==12 && seconds==59 && minuts ==59 ){
				 		hours=1 ;
				 		minuts=0;
				 	    seconds=0;
				 	    if( num ==1){
				 	    	num =2;
					 	   	 LCD_GO_TO(line1 , 13);
					 	   	  LCD_WRITE_STRING("PM");
				 	    }
				 	    else if ( num == 2){
				 	    	num =1 ;
				 	    	 LCD_GO_TO(line1 , 13);
				 	    	 LCD_WRITE_STRING("AM");
				 	    }

				 		if( hours == hours_Alarm && minuts== minuts_alarm && seconds ==secondsalarm && set ==1 && num==num_al){
				 	   			  	 	alarm_flag=1;
				 	   			  	 }

				 	   			  	 if( alarm_flag==1){

				 	   			  	 	DIO_u8SetPinValue(PORTA,PIN_5,LOGIC_HIGH);

				 	   			  	 }

	}


 if( seconds <59){
		seconds++ ;
		if( hours == hours_Alarm && minuts== minuts_alarm && seconds ==secondsalarm && set ==1 && num==num_al){
	   			  	 	alarm_flag=1;
	   			  	 }

	   			  	 if( alarm_flag==1){
	   			  	alarm_flag =0 ;
	   			  	 	DIO_u8SetPinValue(PORTA,PIN_5,LOGIC_HIGH);

	   			  	 }
	}
      LCD_GO_TO(line1 , 1);
   	  Lcd_voidDisplayNumber(hours/10);
   	  LCD_GO_TO(line1 , 2);
   	  Lcd_voidDisplayNumber(hours%10);
   	  LCD_WRITE_Char(':');
   	  LCD_GO_TO(line1 , 4);
   	  Lcd_voidDisplayNumber(minuts/10);
   	  LCD_GO_TO(line1 , 5);
   	  Lcd_voidDisplayNumber(minuts%10);
   	  LCD_WRITE_Char(':');
   	  LCD_GO_TO(line1 , 7);
   	  Lcd_voidDisplayNumber(seconds/10);
   	  LCD_GO_TO(line1 , 8);
   	  Lcd_voidDisplayNumber(seconds%10);


 }

if(stop_flag==1){

	LCD_GO_TO(line2 , 0);
	if(secondst==59 &&  minuts_st<=58){
		secondst=0;
		minuts_st++;

	}
	else if(secondst==59 && minuts_st==59 ){
		    minuts_st=0;
			secondst=0;
			hours_st++;
 }
	 if( secondst <59){
		 secondst++ ;
 }

	           LCD_GO_TO(line2 , 1);
              Lcd_voidDisplayNumber(hours_st/10);
              LCD_GO_TO(line2 , 2);
		   	  Lcd_voidDisplayNumber(hours_st%10);
		   	  LCD_WRITE_Char(':');
		   	  LCD_GO_TO(line2 , 4);
		   	  Lcd_voidDisplayNumber(minuts_st/10);
		   	  LCD_GO_TO(line2 , 5);
		   	  Lcd_voidDisplayNumber(minuts_st%10);
		   	  LCD_WRITE_Char(':');
		   	  LCD_GO_TO(line2 , 7);
		   	  Lcd_voidDisplayNumber(secondst/10);
		   	  LCD_GO_TO(line2 , 8);
		   	  Lcd_voidDisplayNumber(secondst%10);


}



}

void alarm_dis(void){


  DIO_u8GetPinValue(PORTA , PIN_0 , &read);
	if(read ==0){

		DIO_u8SetPinValue(PORTA,PIN_5,LOGIC_LOW);
	}



}
