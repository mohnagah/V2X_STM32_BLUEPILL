################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/Delay.c \
../Src/EXTI_program.c \
../Src/GPIO_program.c \
../Src/LCD_private.c \
../Src/LCD_prog.c \
../Src/NVIC_program.c \
../Src/RCC_program.c \
../Src/SSD_program.c \
../Src/SYSTICK_program.c \
../Src/TIMERx_program.c \
../Src/TL_TIMER_program.c \
../Src/USART_PROG.c \
../Src/main.c \
../Src/syscalls.c \
../Src/sysmem.c 

OBJS += \
./Src/Delay.o \
./Src/EXTI_program.o \
./Src/GPIO_program.o \
./Src/LCD_private.o \
./Src/LCD_prog.o \
./Src/NVIC_program.o \
./Src/RCC_program.o \
./Src/SSD_program.o \
./Src/SYSTICK_program.o \
./Src/TIMERx_program.o \
./Src/TL_TIMER_program.o \
./Src/USART_PROG.o \
./Src/main.o \
./Src/syscalls.o \
./Src/sysmem.o 

C_DEPS += \
./Src/Delay.d \
./Src/EXTI_program.d \
./Src/GPIO_program.d \
./Src/LCD_private.d \
./Src/LCD_prog.d \
./Src/NVIC_program.d \
./Src/RCC_program.d \
./Src/SSD_program.d \
./Src/SYSTICK_program.d \
./Src/TIMERx_program.d \
./Src/TL_TIMER_program.d \
./Src/USART_PROG.d \
./Src/main.d \
./Src/syscalls.d \
./Src/sysmem.d 


# Each subdirectory must supply rules for building sources it contributes
Src/%.o Src/%.su Src/%.cyclo: ../Src/%.c Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -c -I../Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Src

clean-Src:
	-$(RM) ./Src/Delay.cyclo ./Src/Delay.d ./Src/Delay.o ./Src/Delay.su ./Src/EXTI_program.cyclo ./Src/EXTI_program.d ./Src/EXTI_program.o ./Src/EXTI_program.su ./Src/GPIO_program.cyclo ./Src/GPIO_program.d ./Src/GPIO_program.o ./Src/GPIO_program.su ./Src/LCD_private.cyclo ./Src/LCD_private.d ./Src/LCD_private.o ./Src/LCD_private.su ./Src/LCD_prog.cyclo ./Src/LCD_prog.d ./Src/LCD_prog.o ./Src/LCD_prog.su ./Src/NVIC_program.cyclo ./Src/NVIC_program.d ./Src/NVIC_program.o ./Src/NVIC_program.su ./Src/RCC_program.cyclo ./Src/RCC_program.d ./Src/RCC_program.o ./Src/RCC_program.su ./Src/SSD_program.cyclo ./Src/SSD_program.d ./Src/SSD_program.o ./Src/SSD_program.su ./Src/SYSTICK_program.cyclo ./Src/SYSTICK_program.d ./Src/SYSTICK_program.o ./Src/SYSTICK_program.su ./Src/TIMERx_program.cyclo ./Src/TIMERx_program.d ./Src/TIMERx_program.o ./Src/TIMERx_program.su ./Src/TL_TIMER_program.cyclo ./Src/TL_TIMER_program.d ./Src/TL_TIMER_program.o ./Src/TL_TIMER_program.su ./Src/USART_PROG.cyclo ./Src/USART_PROG.d ./Src/USART_PROG.o ./Src/USART_PROG.su ./Src/main.cyclo ./Src/main.d ./Src/main.o ./Src/main.su ./Src/syscalls.cyclo ./Src/syscalls.d ./Src/syscalls.o ./Src/syscalls.su ./Src/sysmem.cyclo ./Src/sysmem.d ./Src/sysmem.o ./Src/sysmem.su

.PHONY: clean-Src

