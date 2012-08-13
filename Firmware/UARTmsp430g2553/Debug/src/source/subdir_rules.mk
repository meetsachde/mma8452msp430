################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Each subdirectory must supply rules for building sources it contributes
src/source/i2c.obj: ../src/source/i2c.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: MSP430 Compiler'
	"E:/ccsv5/tools/compiler/msp430_4.1.1/bin/cl430" -vmsp --abi=eabi -g --include_path="E://ccsv5/ccs_base/msp430/include" --include_path="E:/ccsv5/tools/compiler/msp430_4.1.1/include" --advice:power=all --define=__MSP430G2553__ --diag_warning=225 --display_error_number --diag_wrap=off --printf_support=minimal --preproc_with_compile --preproc_dependency="src/source/i2c.pp" --obj_directory="src/source" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/source/main.obj: ../src/source/main.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: MSP430 Compiler'
	"E:/ccsv5/tools/compiler/msp430_4.1.1/bin/cl430" -vmsp --abi=eabi -g --include_path="E://ccsv5/ccs_base/msp430/include" --include_path="E:/ccsv5/tools/compiler/msp430_4.1.1/include" --advice:power=all --define=__MSP430G2553__ --diag_warning=225 --display_error_number --diag_wrap=off --printf_support=minimal --preproc_with_compile --preproc_dependency="src/source/main.pp" --obj_directory="src/source" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/source/mma8452.obj: ../src/source/mma8452.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: MSP430 Compiler'
	"E:/ccsv5/tools/compiler/msp430_4.1.1/bin/cl430" -vmsp --abi=eabi -g --include_path="E://ccsv5/ccs_base/msp430/include" --include_path="E:/ccsv5/tools/compiler/msp430_4.1.1/include" --advice:power=all --define=__MSP430G2553__ --diag_warning=225 --display_error_number --diag_wrap=off --printf_support=minimal --preproc_with_compile --preproc_dependency="src/source/mma8452.pp" --obj_directory="src/source" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/source/uart.obj: ../src/source/uart.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: MSP430 Compiler'
	"E:/ccsv5/tools/compiler/msp430_4.1.1/bin/cl430" -vmsp --abi=eabi -g --include_path="E://ccsv5/ccs_base/msp430/include" --include_path="E:/ccsv5/tools/compiler/msp430_4.1.1/include" --advice:power=all --define=__MSP430G2553__ --diag_warning=225 --display_error_number --diag_wrap=off --printf_support=minimal --preproc_with_compile --preproc_dependency="src/source/uart.pp" --obj_directory="src/source" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '


