################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL := cmd.exe
RM := rm -rf

USER_OBJS :=

LIBS := 
PROJ := 

O_SRCS := 
C_SRCS := 
S_SRCS := 
S_UPPER_SRCS := 
OBJ_SRCS := 
ASM_SRCS := 
PREPROCESSING_SRCS := 
OBJS := 
OBJS_AS_ARGS := 
C_DEPS := 
C_DEPS_AS_ARGS := 
EXECUTABLES := 
OUTPUT_FILE_PATH :=
OUTPUT_FILE_PATH_AS_ARGS :=
AVR_APP_PATH :=$$$AVR_APP_PATH$$$
QUOTE := "
ADDITIONAL_DEPENDENCIES:=
OUTPUT_FILE_DEP:=
LIB_DEP:=
LINKER_SCRIPT_DEP:=

# Every subdirectory with source files must be described here
SUBDIRS := 


# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS +=  \
../MCAL_ATMEGA_BOOT.c \
../main.c \
../MCAL_ATMEGA_USART.c


PREPROCESSING_SRCS += 


ASM_SRCS += 


OBJS +=  \
MCAL_ATMEGA_BOOT.o \
main.o \
MCAL_ATMEGA_USART.o

OBJS_AS_ARGS +=  \
MCAL_ATMEGA_BOOT.o \
main.o \
MCAL_ATMEGA_USART.o

C_DEPS +=  \
MCAL_ATMEGA_BOOT.d \
main.d \
MCAL_ATMEGA_USART.d

C_DEPS_AS_ARGS +=  \
MCAL_ATMEGA_BOOT.d \
main.d \
MCAL_ATMEGA_USART.d

OUTPUT_FILE_PATH +=UART_BOOTLOADER_V3.elf

OUTPUT_FILE_PATH_AS_ARGS +=UART_BOOTLOADER_V3.elf

ADDITIONAL_DEPENDENCIES:=

OUTPUT_FILE_DEP:= ./makedep.mk

LIB_DEP+= 

LINKER_SCRIPT_DEP+= 


# AVR32/GNU C Compiler
./MCAL_ATMEGA_BOOT.o: .././MCAL_ATMEGA_BOOT.c
	@echo Building file: $<
	@echo Invoking: AVR/GNU C Compiler : 5.4.0
	$(QUOTE)D:\Setup\Atmel\Studio\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\avr-gcc.exe$(QUOTE)  -x c -funsigned-char -funsigned-bitfields -DDEBUG  -I"D:\Setup\Atmel\Studio\7.0\Packs\atmel\ATmega_DFP\1.6.364\include"  -Os -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -g2 -Wall -mmcu=atmega16 -B "D:\Setup\Atmel\Studio\7.0\Packs\atmel\ATmega_DFP\1.6.364\gcc\dev\atmega16" -c -std=gnu99 -MD -MP -MF "$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)"   -o "$@" "$<" 
	@echo Finished building: $<
	

./main.o: .././main.c
	@echo Building file: $<
	@echo Invoking: AVR/GNU C Compiler : 5.4.0
	$(QUOTE)D:\Setup\Atmel\Studio\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\avr-gcc.exe$(QUOTE)  -x c -funsigned-char -funsigned-bitfields -DDEBUG  -I"D:\Setup\Atmel\Studio\7.0\Packs\atmel\ATmega_DFP\1.6.364\include"  -Os -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -g2 -Wall -mmcu=atmega16 -B "D:\Setup\Atmel\Studio\7.0\Packs\atmel\ATmega_DFP\1.6.364\gcc\dev\atmega16" -c -std=gnu99 -MD -MP -MF "$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)"   -o "$@" "$<" 
	@echo Finished building: $<
	

./MCAL_ATMEGA_USART.o: .././MCAL_ATMEGA_USART.c
	@echo Building file: $<
	@echo Invoking: AVR/GNU C Compiler : 5.4.0
	$(QUOTE)D:\Setup\Atmel\Studio\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\avr-gcc.exe$(QUOTE)  -x c -funsigned-char -funsigned-bitfields -DDEBUG  -I"D:\Setup\Atmel\Studio\7.0\Packs\atmel\ATmega_DFP\1.6.364\include"  -Os -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -g2 -Wall -mmcu=atmega16 -B "D:\Setup\Atmel\Studio\7.0\Packs\atmel\ATmega_DFP\1.6.364\gcc\dev\atmega16" -c -std=gnu99 -MD -MP -MF "$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)"   -o "$@" "$<" 
	@echo Finished building: $<
	




# AVR32/GNU Preprocessing Assembler



# AVR32/GNU Assembler




ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

# Add inputs and outputs from these tool invocations to the build variables 

# All Target
all: $(OUTPUT_FILE_PATH) $(ADDITIONAL_DEPENDENCIES)

$(OUTPUT_FILE_PATH): $(OBJS) $(USER_OBJS) $(OUTPUT_FILE_DEP) $(LIB_DEP) $(LINKER_SCRIPT_DEP)
	@echo Building target: $@
	@echo Invoking: AVR/GNU Linker : 5.4.0
	$(QUOTE)D:\Setup\Atmel\Studio\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\avr-gcc.exe$(QUOTE) -o$(OUTPUT_FILE_PATH_AS_ARGS) $(OBJS_AS_ARGS) $(USER_OBJS) $(LIBS) -Wl,-Map="UART_BOOTLOADER_V3.map" -Wl,--start-group -Wl,-lm  -Wl,--end-group -Wl,--gc-sections -Wl,-section-start=.bootloader=0x3800  -mmcu=atmega16 -B "D:\Setup\Atmel\Studio\7.0\Packs\atmel\ATmega_DFP\1.6.364\gcc\dev\atmega16" -Ttext=0x3800  
	@echo Finished building target: $@
	"D:\Setup\Atmel\Studio\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\avr-objcopy.exe" -O ihex -R .eeprom -R .fuse -R .lock -R .signature -R .user_signatures  "UART_BOOTLOADER_V3.elf" "UART_BOOTLOADER_V3.hex"
	"D:\Setup\Atmel\Studio\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\avr-objcopy.exe" -j .eeprom  --set-section-flags=.eeprom=alloc,load --change-section-lma .eeprom=0  --no-change-warnings -O ihex "UART_BOOTLOADER_V3.elf" "UART_BOOTLOADER_V3.eep" || exit 0
	"D:\Setup\Atmel\Studio\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\avr-objdump.exe" -h -S "UART_BOOTLOADER_V3.elf" > "UART_BOOTLOADER_V3.lss"
	"D:\Setup\Atmel\Studio\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\avr-objcopy.exe" -O srec -R .eeprom -R .fuse -R .lock -R .signature -R .user_signatures "UART_BOOTLOADER_V3.elf" "UART_BOOTLOADER_V3.srec"
	"D:\Setup\Atmel\Studio\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\avr-size.exe" "UART_BOOTLOADER_V3.elf"
	
	





# Other Targets
clean:
	-$(RM) $(OBJS_AS_ARGS) $(EXECUTABLES)  
	-$(RM) $(C_DEPS_AS_ARGS)   
	rm -rf "UART_BOOTLOADER_V3.elf" "UART_BOOTLOADER_V3.a" "UART_BOOTLOADER_V3.hex" "UART_BOOTLOADER_V3.lss" "UART_BOOTLOADER_V3.eep" "UART_BOOTLOADER_V3.map" "UART_BOOTLOADER_V3.srec" "UART_BOOTLOADER_V3.usersignatures"
	