PROJ_NAME	=	stm32f0_discovery_gpio

OUTPUT_DIR	=	output
INC_DIR		= 	inc
SRC_DIR 	=	src

OBJ_FILE	= $(OUTPUT_DIR)/main.o $(OUTPUT_DIR)/startup_ARMCM0.o $(OUTPUT_DIR)/reg.o $(OUTPUT_DIR)/interrupt.o
LINKER_FILE	= ld/stm32f0_discovery.ld
COMPILER_PATH	= 'C:/Program Files (x86)/ARM_GCC/2020/bin/arm-none-eabi'

CC				= $(COMPILER_PATH)-gcc
OBJCPY			= $(COMPILER_PATH)-objcopy
ASM				= $(COMPILER_PATH)-as
LD				= $(COMPILER_PATH)-ld

CC_OPT			= -mcpu=cortex-m0 -c -O0  -I$(INC_DIR)
ASM_OPT			= -mcpu=cortex-m0 -c 
LD_OPT			= -T $(LINKER_FILE) -Map $(OUTPUT_DIR)/$(PROJ_NAME).map $(OBJ_FILE)

all: clean build

$(OUTPUT_DIR)/main.o: $(SRC_DIR)/main.c
	$(CC) $(CC_OPT) -o $@ $<

$(OUTPUT_DIR)/reg.o: $(SRC_DIR)/reg.c 
	$(CC) $(CC_OPT) -o $@ $<

$(OUTPUT_DIR)/interrupt.o: $(SRC_DIR)/interrupt.c
	$(CC) $(CC_OPT) -o $@ $<
	
$(OUTPUT_DIR)/startup_ARMCM0.o: $(SRC_DIR)/startup_ARMCM0.S
	$(ASM) $(ASM_OPT) -o $@ $<

build: $(OBJ_FILE) $(LINKER_FILE)
	$(LD)  $(LD_OPT) -o   $(OUTPUT_DIR)/$(PROJ_NAME).elf
	$(OBJCPY) -O ihex $(OUTPUT_DIR)/$(PROJ_NAME).elf $(OUTPUT_DIR)/$(PROJ_NAME).hex


clean:
	rm -rf $(OUTPUT_DIR)/*

