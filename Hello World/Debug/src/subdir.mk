################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/Hello\ World.c 

OBJS += \
./src/Hello\ World.o 

C_DEPS += \
./src/Hello\ World.d 


# Each subdirectory must supply rules for building sources it contributes
src/Hello\ World.o: ../src/Hello\ World.c src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"src/Hello World.d" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


