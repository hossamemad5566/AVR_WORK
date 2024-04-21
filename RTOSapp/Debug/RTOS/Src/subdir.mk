################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../RTOS/Src/PollQ.c \
../RTOS/Src/croutine.c \
../RTOS/Src/event_groups.c \
../RTOS/Src/heap_1.c \
../RTOS/Src/integer.c \
../RTOS/Src/list.c \
../RTOS/Src/port.c \
../RTOS/Src/queue.c \
../RTOS/Src/tasks.c 

OBJS += \
./RTOS/Src/PollQ.o \
./RTOS/Src/croutine.o \
./RTOS/Src/event_groups.o \
./RTOS/Src/heap_1.o \
./RTOS/Src/integer.o \
./RTOS/Src/list.o \
./RTOS/Src/port.o \
./RTOS/Src/queue.o \
./RTOS/Src/tasks.o 

C_DEPS += \
./RTOS/Src/PollQ.d \
./RTOS/Src/croutine.d \
./RTOS/Src/event_groups.d \
./RTOS/Src/heap_1.d \
./RTOS/Src/integer.d \
./RTOS/Src/list.d \
./RTOS/Src/port.d \
./RTOS/Src/queue.d \
./RTOS/Src/tasks.d 


# Each subdirectory must supply rules for building sources it contributes
RTOS/Src/%.o: ../RTOS/Src/%.c RTOS/Src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -I"D:\01_embedded\AVR\mine_work\RTOSapps\FreeRTOS\Inc" -I"D:\01_embedded\AVR\mine_work\RTOSapps\Drivers\inc" -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


