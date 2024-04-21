################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/src/ADC.c \
../Drivers/src/Keypad.c \
../Drivers/src/LCD.c \
../Drivers/src/board.c \
../Drivers/src/uart.c 

OBJS += \
./Drivers/src/ADC.o \
./Drivers/src/Keypad.o \
./Drivers/src/LCD.o \
./Drivers/src/board.o \
./Drivers/src/uart.o 

C_DEPS += \
./Drivers/src/ADC.d \
./Drivers/src/Keypad.d \
./Drivers/src/LCD.d \
./Drivers/src/board.d \
./Drivers/src/uart.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/src/%.o: ../Drivers/src/%.c Drivers/src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -I"D:\01_embedded\AVR\mine_work\RTOSapps\FreeRTOS\Inc" -I"D:\01_embedded\AVR\mine_work\RTOSapps\Drivers\inc" -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


