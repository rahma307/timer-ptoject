/*  lib layer */
#include "STD_TYPES.h"
#include "BIT_MATH.h" 
#define   F_CPU 8000000UL
#include  <util/delay.h>



/* MCAL layer */

#include  "TIM0_INT.h"
#include  "TIM0_CONFIG .h"
#include  "TIM0_PRV.h"

// set call back  overflow
void (* ptr)(void)=	NULL;

//// set call back  ctc

void (* ptrctc)(void)=	NULL;


/* Start timer */

void TIM0_INIT(void){
	
/*SELECT TIMER MODER   => normal mode */	

CLR_BIT(TIM0_TCCR0 ,TIM0_WGM00);
CLR_BIT(TIM0_TCCR0 ,TIM0_WGM01 );


/* Enable Interrupt => OVERFLOW */

SET_BIT(TIMERS_TIMSK,TOIE0);



/* set PRELOAD VALUE   */

/*
F_CPU  = 8MHZ   PRESCALER =8  TIMO_RESOLUTION = 8 BITS      DESIRED TIME = 1S    
TIMER Frequency  = 8MHZ/ 8 = 1MHZ 
TIMER TICK TIME  = 1/1MHZ  =  1uS
Overflow time    =  1uS * (2^8) = 256 uS
case 3   desired time > overflow time
Number  of overflows = 1S/ 256uS   =  3906.25 overflows 
total number of overflows = 3907    >> number of time for interring ISR to generate 1S
Tick time for 0.25  = 0.25 * 256uS =  64 uS
preload value = 256 - 64 = 192    >> the intial value which  TCNT0 counting from it 
*/


TIM0_TCNT0 =  192 ;



/* Select clk source >> CLK/8  */

SET_BIT(TIM0_TCCR0,TIM0_CS01);	
CLR_BIT(TIM0_TCCR0 ,TIM0_CS02);
CLR_BIT(TIM0_TCCR0 ,TIM0_CS00);

	
}



void TIM1_INTI(void){
	/* select timer1 mode =>> mode 14 */
	SET_BIT(TIM1_TCCR1A ,  1);
	CLR_BIT(TIM1_TCCR1A ,  0);
    SET_BIT(TIM1_TCCR1B ,4);
    SET_BIT(TIM1_TCCR1B ,3);

   /* clear oc1a on compare match */
	SET_BIT(TIM1_TCCR1A ,  7);
	CLR_BIT(TIM1_TCCR1A ,  6);

	/* set top value in ICR1 REG */
	TIM1_ICR1 = 19999 ;   // period  = 20 ms



    /* Select clk source >> CLK/8  */

    		 SET_BIT(TIM1_TCCR1B,1);
    		 CLR_BIT(TIM1_TCCR1B,2);
    		 CLR_BIT(TIM1_TCCR1B,0);

}


void TIM1_OCR1AVAL(u16 val ){

	/* set angle of servo */

	     TIM1_OCR1A = val;
}

u8 TIM0_SetCallBackoverflow (void (*pf)(void)){
	
	u8 local_u8errorstate= STD_TYPES_OK ;
		if(pf != NULL){
           ptr =  pf ;
	}
	else{
		local_u8errorstate= STD_TYPES_NOK ;
	}

	return local_u8errorstate;
	
}


void TIMERS_TIM0SetCompareMatchVAlue(u8 val){
	TIM0_OCR0 = val ;

}

u8 TIM0_SetCallBackctc (void (*pf)(void)) {


u8 local_u8errorstate= STD_TYPES_OK ;
	if(pf != NULL){
       ptrctc  =  pf ;
}
else{
	local_u8errorstate= STD_TYPES_NOK ;
}

return local_u8errorstate;

}

/* ISR for TIM0 overflow */

void __vector_11(void) __attribute__((signal));

void __vector_11(void){
	
static u16 counter_overflow =0 ;
counter_overflow++;
if(counter_overflow == 3907 ){
	
	/* Update preload value */
	TIM0_TCNT0 =  192 ;
	/* clear counter_overflow */
	counter_overflow=0;
	if(ptr != NULL){
	/* call APP Function */
	ptr();
	}
	
}	
	
	
}


/* ISR for TIM0 ctc*/


void __vector_10(void) __attribute__((signal));

void __vector_10(void){

static u16 counter_ctc =0 ;
counter_ctc++;
if(counter_ctc == 10000 ){
	/* clear counte*/
	counter_ctc=0;
	if(ptrctc != NULL){
	/* call APP Function */
		ptrctc();
	}

}


}


