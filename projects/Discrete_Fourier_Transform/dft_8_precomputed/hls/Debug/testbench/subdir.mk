################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
E:/xilinx/CS239/DFT/dft_8_precomputed/dft_test.cpp 

OBJS += \
./testbench/dft_test.o 

CPP_DEPS += \
./testbench/dft_test.d 


# Each subdirectory must supply rules for building sources it contributes
testbench/dft_test.o: E:/xilinx/CS239/DFT/dft_8_precomputed/dft_test.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -ID:/xilinx/Vivado/2020.1/include/etc -IE:/xilinx/CS239/DFT/dft_8_precomputed -ID:/xilinx/Vivado/2020.1/win64/tools/auto_cc/include -ID:/xilinx/Vivado/2020.1/include/ap_sysc -ID:/xilinx/Vivado/2020.1/include -ID:/xilinx/Vivado/2020.1/win64/tools/systemc/include -O0 -g3 -Wall -Wno-unknown-pragmas -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"testbench/dft_test.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


