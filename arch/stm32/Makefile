# Makefile for the Nodate framework: STM32 (ARM Cortex-M) architecture
#
# 

GPP = arm-none-eabi-g++
GCC = arm-none-eabi-gcc
AR = arm-none-eabi-ar
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


OUTPUT := $(OUTPUT).$(MCU)
INCLUDE := -I $(TOP)/$(LANGUAGE)/core/include -I $(TOP)/$(LANGUAGE)/core/include/$(MCU_FAMILY)

DEFINES := -D__$(MCU_FAMILY)=1 -D__$(MCU_GENUS)=1 -D$(MCU_GENUS_CAP)=1
FLAGS := $(INCLUDE) $(MCU_FLAGS) --specs=nosys.specs -ffunction-sections -fdata-sections -MMD -Os -g -T $(TOP)/linker/$(MCU_LD) -lgcc
LIBS := -Wl,-Map=$(APPFOLDER)/bin/$(OUTPUT).map,--cref -Wl,--gc-sections -Wl,--print-memory-usage -lstdc++_nano
CFLAGS := $(FLAGS) $(DEFINES) -std=gnu11
CPPFLAGS := $(FLAGS) $(DEFINES) -std=gnu++11 -fno-threadsafe-statics -fno-rtti -fno-exceptions

CPPSOURCES := $(wildcard arch/stm32/$(LANGUAGE)/core/src/*.cpp) \
				$(APP_CPP_FILES)
			
CSOURCES := $(wildcard arch/stm32/$(LANGUAGE)/core/src/$(MCU_FAMILY)/*.c) \
			$(APP_C_FILES)
SSOURCES := arch/stm32/asm/$(MCU_FAMILY)/startup_$(MCU_GENUS).S
CPPOBJECTS := $(addprefix $(APPFOLDER)/obj/,$(notdir) $(CPPSOURCES:.cpp=.o))
COBJECTS := $(addprefix $(APPFOLDER)/obj/,$(notdir) $(CSOURCES:.c=.o))
SOBJECTS := $(addprefix $(APPFOLDER)/obj/,$(notdir) $(SSOURCES:.S=.o))

all: makedir $(APPFOLDER)/bin/$(OUTPUT).elf $(APPFOLDER)/bin/$(OUTPUT).bin

makedir:
	$(MAKEDIR) $(APPFOLDER)/obj/src
	$(MAKEDIR) $(APPFOLDER)/obj/arch/stm32/asm/$(MCU_FAMILY)
	$(MAKEDIR) $(APPFOLDER)/obj/arch/stm32/$(LANGUAGE)/core/src
	$(MAKEDIR) $(APPFOLDER)/obj/arch/stm32/$(LANGUAGE)/core/src/$(MCU_FAMILY)
	$(MAKEDIR) $(APPFOLDER)/bin

$(APPFOLDER)/obj/%.o: $(APPFOLDER)/%.cpp
	$(GPP) -c -o $@ $< $(CPPFLAGS)

$(APPFOLDER)/obj/%.o: $(APPFOLDER)/%.c
	$(GCC) -c -o $@ $< $(CFLAGS)

$(APPFOLDER)/obj/%.o: %.cpp
	$(GPP) -c -o $@ $< $(CPPFLAGS)

$(APPFOLDER)/obj/%.o: %.S
	$(GCC) -c -o $@ $< $(CFLAGS)

$(APPFOLDER)/obj/%.o: %.c
	$(GCC) -c -o $@ $< $(CFLAGS)
	
$(APPFOLDER)/bin/$(OUTPUT).elf: $(CPPOBJECTS) $(SOBJECTS) $(COBJECTS)
	$(GPP) -o $@ $(CPPOBJECTS) $(SOBJECTS) $(COBJECTS) $(LIBS) $(FLAGS)
	
$(APPFOLDER)/bin/%.bin: $(APPFOLDER)/bin/%.elf
	$(OBJCOPY) -O $(FORMAT) $< $@
	
flash:
	$(CD) $(APPFOLDER) && \
	openocd -f board/$(PROGRAMMER) -d -c "program bin/$(OUTPUT).elf verify reset exit"

clean:
	$(RM) $(CPPOBJECTS) $(SOBJECTS) $(COBJECTS) $(APPFOLDER)/bin/$(OUTPUT).*

	