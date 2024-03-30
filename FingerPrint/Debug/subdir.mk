################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../DIO_Prog.c \
../FP_prog.c \
../GIE_prog.c \
../LCD_Prog.c \
../LED_Prog.c \
../PushButton_Prog.c \
../UART_Prog.c \
../main.c 

OBJS += \
./DIO_Prog.o \
./FP_prog.o \
./GIE_prog.o \
./LCD_Prog.o \
./LED_Prog.o \
./PushButton_Prog.o \
./UART_Prog.o \
./main.o 

C_DEPS += \
./DIO_Prog.d \
./FP_prog.d \
./GIE_prog.d \
./LCD_Prog.d \
./LED_Prog.d \
./PushButton_Prog.d \
./UART_Prog.d \
./main.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


