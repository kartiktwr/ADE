################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/AdaFruitServoDriver.cpp \
../src/Hexapod.cpp \
../src/MatrixMath.cpp \
../src/SlaveDevice.cpp \
../src/avoid_obj.cpp 

OBJS += \
./src/AdaFruitServoDriver.o \
./src/Hexapod.o \
./src/MatrixMath.o \
./src/SlaveDevice.o \
./src/avoid_obj.o 

CPP_DEPS += \
./src/AdaFruitServoDriver.d \
./src/Hexapod.d \
./src/MatrixMath.d \
./src/SlaveDevice.d \
./src/avoid_obj.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	arm-linux-gnueabihf-g++-4.6 -I/usr/arm-linux-gnueabihf/include/c++/4.6.3 -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


