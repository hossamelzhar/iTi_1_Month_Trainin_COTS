################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../02-MCAL/03-ADC/ADC.c 

OBJS += \
./02-MCAL/03-ADC/ADC.o 

C_DEPS += \
./02-MCAL/03-ADC/ADC.d 


# Each subdirectory must supply rules for building sources it contributes
02-MCAL/03-ADC/%.o: ../02-MCAL/03-ADC/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


