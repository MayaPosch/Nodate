# Makefile for the Nodate framework: SAM (ARM) architecture
#
# 

GPP = arm-none-eabi-g++
GCC = arm-none-eabi-gcc
OBJCOPY = arm-none-eabi-objcopy
MAKEDIR = mkdir -p
CD = cd
RM = rm

FORMAT = binary

TOP := $(NODATE_HOME)/arch/$(ARCH)


ifdef BOARD
include $(TOP)/boards/$(BOARD)
endif

include $(TOP)/mcu/$(MCU)
#include $(TOP)/programmer/$(PROGRAMMER)


OUTPUT := $(OUTPUT).$(MCU)
INCLUDE := -I $(TOP)/arduino -I $(TOP)/variants/$(VARIANT) \
			-I $(TOP)/libraries/HID/src \
			-I $(TOP)/libraries/Wire/src \
			-I $(TOP)/libraries/SPI/src \
			-I $(TOP)/system/libsam \
			-I $(TOP)/system/CMSIS/Device/ATMEL \
			-I $(TOP)/system/CMSIS/CMSIS/Include

FLAGS := $(INCLUDE) -D$(ARM_TYPE) -DF_CPU=$(F_CPU) -mcpu=$(MCU) -mthumb -fno-exceptions  --specs=nano.specs -ffunction-sections -fdata-sections -DUSBCON -MMD -Os -g -nostdlib --param max-inline-insns-single=500 -fno-rtti -Dprintf=iprintf -L$(TOP)/libraries -lsam_$(ARM_MCU)_gcc_dbg -lc -lgcc -Wl,-Map=$(APPFOLDER)/bin/$(OUTPUT).map,--cref -Wl,--gc-sections
CFLAGS := $(FLAGS) -std=gnu11
CPPFLAGS := $(FLAGS) -std=gnu++11 -fno-threadsafe-statics
CPPSOURCES := $(wildcard arch/sam/arduino/*.cpp) \
			$(wildcard arch/sam/arduino/USB/*.cpp) \
			$(wildcard arch/sam/libraries/Wire/src/*.cpp) \
			$(wildcard arch/sam/libraries/SPI/src/*.cpp) \
			$(wildcard arch/sam/libraries/HID/src/*.cpp) \
			$(wildcard arch/sam/variants/$(VARIANT)/*.cpp) \
			$(APP_CPP_FILES)
CSOURCES := $(wildcard arch/sam/arduino/*.c) \
			$(wildcard arch/sam/arduino/avr/*.c) \
			$(APP_C_FILES)
SSCOURCES := $(wildcard arch/sam/arduino/*.s)
CPPOBJECTS := $(addprefix $(APPFOLDER)/obj/,$(notdir) $(CPPSOURCES:.cpp=.o))
COBJECTS := $(addprefix $(APPFOLDER)/obj/,$(notdir) $(CSOURCES:.c=.o))
SOBJECTS := $(addprefix $(APPFOLDER)/obj/,$(notdir) $(SSOURCES:.s=.o))

#$(warning Print: $(COBJECTS))

all: makedir $(CPPOBJECTS) $(COBJECTS) $(SOBJECTS) $(APPFOLDER)/bin/$(OUTPUT).elf $(APPFOLDER)/bin/$(OUTPUT).bin

makedir:
	$(MAKEDIR) $(APPFOLDER)/obj/src
	$(MAKEDIR) $(APPFOLDER)/obj/arch/sam/arduino/avr
	$(MAKEDIR) $(APPFOLDER)/obj/arch/sam/arduino/USB
	$(MAKEDIR) $(APPFOLDER)/obj/arch/sam/libraries/SPI/src
	$(MAKEDIR) $(APPFOLDER)/obj/arch/sam/libraries/Wire/src
	$(MAKEDIR) $(APPFOLDER)/obj/arch/sam/libraries/HID/src
	$(MAKEDIR) $(APPFOLDER)/obj/arch/sam/variants/$(VARIANT)
	$(MAKEDIR) $(APPFOLDER)/bin

$(APPFOLDER)/obj/%.o: $(APPFOLDER)/%.cpp
	$(GPP) -c -o $@ $< $(CPPFLAGS)

$(APPFOLDER)/obj/%.o: $(APPFOLDER)/%.c
	$(GCC) -c -o $@ $< $(CFLAGS)

$(APPFOLDER)/obj/%.o: %.cpp
	$(GPP) -c -o $@ $< $(CPPFLAGS)

$(APPFOLDER)/obj/%.o: %.s
	$(GCC) -c -o $@ $< $(CFLAGS)

$(APPFOLDER)/obj/%.o: %.c
	$(GCC) -c -o $@ $< $(CFLAGS)
	
$(APPFOLDER)/bin/$(OUTPUT).elf:
	$(GPP) -o $@ $(CPPOBJECTS) $(COBJECTS) $(LIB) $(FLAGS)
	
$(APPFOLDER)/bin/%.bin: $(APPFOLDER)/bin/%.elf
	$(OBJCOPY) -O $(FORMAT) $< $@
	
flash:
	$(CD) $(APPFOLDER) && \
	bossac -i -d --port=$(COM_PORT) --erase --write --verify --boot -U=1 -R bin/$(OUTPUT).bin

clean:
	$(RM) $(COBJECTS) $(CPPOBJECTS) $(SOBJECTS) $(APPFOLDER)/bin/$(OUTPUT).*
	