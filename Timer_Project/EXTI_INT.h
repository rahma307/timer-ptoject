#ifndef EXTI_INT_H
#define EXTI_INT_H


u8 EXTI_u8EXTEnable(u8 copy_u8EXTIINDEX,  u8 copy_u8edge);

u8 EXTI_u8EXTDisable(u8 copy_u8EXTIINDEX );

u8 EXTI_SET_CALL_BACK(void(*ptr)(void) , u8 indix );


/* MCUCR PINS*/

#define ISC11   3
#define ISC10   2
#define ISC01   1
#define ISC00   0

/*MCUCSR PIN*/

#define ISC2    6

/*GICR PINS*/

#define INT1    7
#define INT0    6
#define INT2    5

/*IFR PINS */

#define INTF1   7
#define INTF0   6
#define INTF2   5

/*EXTERNAL index */

#define EXT0     0
#define EXT1     1
#define EXT2     2


/* EDGE index */

#define  rising_edge          0
#define  Falling_edge         1
#define  Any_logical_change   2
#define  low_level            3


#endif 