#ifndef EXTI_PRV_H
#define EXTI_PRV_H

/* Define for EXTI Registers */

#define EXTI_u8_MCUCR     *((volatile u8 *)(0x55))
#define EXTI_u8_MCUCSR    *((volatile u8 *)(0x54))
#define EXTI_u8_GICR      *((volatile u8 *)(0x5B))
#define EXTI_u8_GIFR      *((volatile u8 *)(0x5A))

 


#endif