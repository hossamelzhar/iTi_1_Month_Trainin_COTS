################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include App/subdir.mk
-include 03-HAL/02-LCD/subdir.mk
-include 02-MCAL/04-TIMERS/02-TIMER1/subdir.mk
-include 02-MCAL/04-TIMERS/01-TIMER0/subdir.mk
-include 02-MCAL/03-ADC/subdir.mk
-include 02-MCAL/02-INT/subdir.mk
-include 02-MCAL/01-DIO/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
LSS += \
ICU_HW_Test.lss \

SIZEDUMMY += \
sizedummy \


# All Target
all: ICU_HW_Test.elf secondary-outputs

# Tool invocations
ICU_HW_Test.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,ICU_HW_Test.map -mmcu=atmega32 -o "ICU_HW_Test.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

ICU_HW_Test.lss: ICU_HW_Test.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S ICU_HW_Test.elf  >"ICU_HW_Test.lss"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: ICU_HW_Test.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 ICU_HW_Test.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) ICU_HW_Test.elf
	-@echo ' '

secondary-outputs: $(LSS) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
