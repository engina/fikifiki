################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/ff_block.c \
../src/ff_board.c \
../src/ff_cell.c \
../src/ff_filters.c \
../src/ff_line.c \
../src/ff_utils.c \
../src/fikifiki.c 

OBJS += \
./src/ff_block.o \
./src/ff_board.o \
./src/ff_cell.o \
./src/ff_filters.o \
./src/ff_line.o \
./src/ff_utils.o \
./src/fikifiki.o 

C_DEPS += \
./src/ff_block.d \
./src/ff_board.d \
./src/ff_cell.d \
./src/ff_filters.d \
./src/ff_line.d \
./src/ff_utils.d \
./src/fikifiki.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O3 -Wall -c -fmessage-length=0 -std=c99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


