################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../DIO_PRG.c \
../EXTI_PRG.c \
../GLOPAL_PRG.c \
../KP_PRG.c \
../LCD_PRG.c \
../TIM0_PRG.c \
../main.c 

OBJS += \
./DIO_PRG.o \
./EXTI_PRG.o \
./GLOPAL_PRG.o \
./KP_PRG.o \
./LCD_PRG.o \
./TIM0_PRG.o \
./main.o 

C_DEPS += \
./DIO_PRG.d \
./EXTI_PRG.d \
./GLOPAL_PRG.d \
./KP_PRG.d \
./LCD_PRG.d \
./TIM0_PRG.d \
./main.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


