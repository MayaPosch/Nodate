# Makefile for the Nodate framework: RP (ARM Cortex-M) architecture
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
else
BOARD := generic_board
endif

include $(TOP)/mcu/$(MCU)


OUTPUT := $(OUTPUT).$(MCU)
INCLUDE := -I $(TOP)/$(NDLANGUAGE)/core/include -I $(TOP)/$(NDLANGUAGE)/core/include/$(MCU_FAMILY) \
			-I $(TOP)/$(NDLANGUAGE)/libs -I $(TOP)/$(NDLANGUAGE)/boards/$(BOARD) \
			-I $(TOP)/$(NDLANGUAGE)/peripherals \
			-I $(APPFOLDER)/src

DEFINES := -D__$(MCU_FAMILY)=1 -D__$(MCU_GENUS)=1 -D$(MCU_GENUS_CAP)=1
FLAGS := $(INCLUDE) $(MCU_FLAGS) -ffunction-sections -fdata-sections -MMD -Os -g3 $(APP_FLAGS)
CFLAGS := $(FLAGS) $(DEFINES) -std=gnu11 $(APP_C_FLAGS)
CPPFLAGS := $(FLAGS) $(DEFINES) -std=gnu++11 -fno-threadsafe-statics -fno-rtti -fno-exceptions -fno-use-cxa-atexit $(APP_CPP_FLAGS)
LD_FLAGS := -T $(TOP)/linker/$(MCU_FAMILY)/$(MCU_LD) -Wl,-Map=$(APPFOLDER)/bin/$(OUTPUT).map,--cref \
			 --specs=nano.specs --specs=nosys.specs -Wl,--gc-sections -Wl,--print-memory-usage \
			  $(MCU_FLAGS)
LIBS :=  -lstdc++_nano -lgcc

CPPSOURCES := arch/rp/$(NDLANGUAGE)/boards/$(BOARD)/board_definition.cpp \
				$(wildcard arch/rp/$(NDLANGUAGE)/core/src/*.cpp) \
				$(APP_CPP_FILES)
			
CSOURCES := $(wildcard arch/rp/$(NDLANGUAGE)/core/src/$(MCU_FAMILY)/*.c) \
			$(APP_C_FILES)
SSOURCES := arch/rp/asm/$(MCU_FAMILY)/bs2_default_padded_checksummed.S
CPPOBJECTS := $(addprefix $(APPFOLDER)/obj/,$(notdir) $(CPPSOURCES:.cpp=.o))
COBJECTS := $(addprefix $(APPFOLDER)/obj/,$(notdir) $(CSOURCES:.c=.o))
SOBJECTS := $(addprefix $(APPFOLDER)/obj/,$(notdir) $(SSOURCES:.S=.o))

all: makedir $(APPFOLDER)/bin/$(OUTPUT).elf $(APPFOLDER)/bin/$(OUTPUT).bin

makedir:
	$(MAKEDIR) $(APPFOLDER)/obj/src
	$(MAKEDIR) $(APPFOLDER)/obj/arch/rp/asm/$(MCU_FAMILY)
	$(MAKEDIR) $(APPFOLDER)/obj/arch/rp/$(NDLANGUAGE)/boards/$(BOARD)
	$(MAKEDIR) $(APPFOLDER)/obj/arch/rp/$(NDLANGUAGE)/core/src/$(MCU_FAMILY)
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
	$(GPP) -o $@ $(CPPOBJECTS) $(SOBJECTS) $(COBJECTS) $(LIBS) $(LD_FLAGS)
	
$(APPFOLDER)/bin/%.bin: $(APPFOLDER)/bin/%.elf
	$(OBJCOPY) -O $(FORMAT) $< $@
	
flash:
	$(CD) $(APPFOLDER) && \
	openocd -f $(PROGRAMMER) -c "program bin/$(OUTPUT).elf verify reset exit"

clean:
	$(RM) $(CPPOBJECTS) $(SOBJECTS) $(COBJECTS) $(APPFOLDER)/bin/$(OUTPUT).*

	