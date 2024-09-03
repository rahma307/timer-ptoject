
/*  lib layer */
#include "STD_TYPES.h"
#include "BIT_MATH.h" 
#define   F_CPU 8000000UL
#include  <util/delay.h>

/*  mcal layer */
#include "EXTI_INT.h"
#include "EXT_CONFIG.h"
#include "EXTI_PRV.h"

/* Global Pointer To Function */
static  void (*EXTI_APFEXTI[3])(void) = { NULL , NULL , NULL };
 

u8 EXTI_SET_CALL_BACK(void(*ptr)(void) , u8 indix ){
  u8 local_u8Error_state =STD_TYPES_OK ;
  if(indix <=EXT2  && ptr !=NULL){
  EXTI_APFEXTI[indix]=ptr;
  }
  else{
	  local_u8Error_state =STD_TYPES_NOK ;
	  
  }
 return local_u8Error_state ;
} 
 


u8 EXTI_u8EXTEnable(u8 copy_u8EXTIINDEX,  u8 copy_u8edge){
 u8 local_u8Error_state = STD_TYPES_OK ;
	switch(copy_u8EXTIINDEX){
		
		case EXT0:
		
		/* select Edge source */
		
		switch(copy_u8edge){
			case rising_edge:
               
			   SET_BIT(EXTI_u8_MCUCR,ISC01);
               SET_BIT(EXTI_u8_MCUCR,ISC00);
			   		/* ENABLE EXTI0  */   
		
		       SET_BIT(EXTI_u8_GICR,INT0);
			   
            break ;
			
			case Falling_edge:
 
               SET_BIT(EXTI_u8_MCUCR,ISC01);
               CLR_BIT(EXTI_u8_MCUCR,ISC00);
		        /* ENABLE EXTI0  */
		
		        SET_BIT(EXTI_u8_GICR,INT0);			   
			break ;
			
			case Any_logical_change :
			
                SET_BIT(EXTI_u8_MCUCR,ISC00);
                CLR_BIT(EXTI_u8_MCUCR,ISC01);

                     /* ENABLE EXTI0  */
		
		         SET_BIT(EXTI_u8_GICR,INT0);
				
			break;
			
			case low_level:
			
			 CLR_BIT(EXTI_u8_MCUCR,ISC00);
             CLR_BIT(EXTI_u8_MCUCR,ISC01);
			 		/* ENABLE EXTI0  */
		
		        SET_BIT(EXTI_u8_GICR,INT0);
			 
			 
			break ;
			
			default:
			
			local_u8Error_state =STD_TYPES_NOK ;
			
		}
 
		
          break ;
		
		case EXT1:
          switch(copy_u8edge){
			case rising_edge:
               
			   SET_BIT(EXTI_u8_MCUCR,ISC11);
               SET_BIT(EXTI_u8_MCUCR,ISC10);
			   
			   	/* ENABLE EXTI1  */   
		
		       SET_BIT(EXTI_u8_GICR,INT1);
			   
            break ;
			
			case Falling_edge:
 
               SET_BIT(EXTI_u8_MCUCR,ISC11);
               CLR_BIT(EXTI_u8_MCUCR,ISC10);
			   
			   	/* ENABLE EXTI1  */   
		
		       SET_BIT(EXTI_u8_GICR,INT1);
			   
			break ;
			
			case Any_logical_change :
			
                SET_BIT(EXTI_u8_MCUCR,ISC10);
                CLR_BIT(EXTI_u8_MCUCR,ISC11);
				
			 	  /* ENABLE EXTI1  */   
		
		       SET_BIT(EXTI_u8_GICR,INT1);
			break;
			
			case low_level:
			
			 CLR_BIT(EXTI_u8_MCUCR,ISC11);
             CLR_BIT(EXTI_u8_MCUCR,ISC10);
			 
			 	/* ENABLE EXTI1  */   
		
		       SET_BIT(EXTI_u8_GICR,INT1);
			 
			break ;
			default:
			
			 local_u8Error_state =STD_TYPES_NOK ;
		}		
		break ;
		
		case EXT2:
		
		 switch(copy_u8edge){
			case rising_edge:
               
			   SET_BIT(EXTI_u8_MCUCSR,ISC2);
 
			    	/* ENABLE EXTI2  */   
		
		       SET_BIT(EXTI_u8_GICR,INT2);
			   
            break ;
			
			case Falling_edge:
 
               CLR_BIT(EXTI_u8_MCUCSR,ISC2);
			   
			   	/* ENABLE EXTI2  */   
		
		       SET_BIT(EXTI_u8_GICR,INT2);
			   
		    break ;
		    
			default:
			
			local_u8Error_state =STD_TYPES_NOK ;
		 
		 }
	     break ;
		
		default:  
			
			local_u8Error_state =STD_TYPES_NOK ;
	}
	
	
	return local_u8Error_state;
	
}




u8 EXTI_u8EXTDisable(u8 copy_u8EXTIINDEX ){
	
 u8 local_u8Error_state=STD_TYPES_OK ;
	switch(copy_u8EXTIINDEX){
		
		case EXT0:

			  /* DisABLE EXTI0  */   
		
		       CLR_BIT(EXTI_u8_GICR,INT0);
 
 
		
          break ;
		
		case EXT1:
 
         	   /* DisABLE EXTI1  */   
		
		      CLR_BIT(EXTI_u8_GICR,INT1);
 		
		break ;
		
		case EXT2:
 
           	/* DisABLE EXTI2  */   
		
		     CLR_BIT(EXTI_u8_GICR,INT2);
         break ;
		
		default:  
			
			local_u8Error_state =STD_TYPES_NOK ;
	}
	
	
	return local_u8Error_state;
	
	
}
/* prototype for ISR of EXTI0*/

void __vector_1(void) __attribute__((signal));

void __vector_1(void){
  if(EXTI_APFEXTI[EXT0] != NULL){	
  EXTI_APFEXTI[0]();
  }
	
}

/* prototype for ISR of EXTI1*/

/*void __vector_2(void) __attribute__((signal));

void __vector_2(void){
	
   if(EXTI_APFEXTI[EXT1] != NULL){	
      EXTI_APFEXTI[1]();}
}


/* prototype for ISR of EXTI2*/

/*void __vector_3(void) __attribute__((signal));

void __vector_3(void){
	if(EXTI_APFEXTI[EXT2] != NULL){	 // to avoid willd pointer 
           EXTI_APFEXTI[2]();}
	
}
*/
