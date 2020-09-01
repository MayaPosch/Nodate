# Makefile for the Nodate framework: STM32 (ARM Cortex-M) architecture
#
# 

GPP 		:= arm-none-eabi-g++
GCC 		:= arm-eabi-gcc
GNATMAKE 	:= gnatmake
GNATBIND	:= arm-eabi-gnatbind
GNATLINK	:= gnatlink
MAKEDIR 	:= mkdir -p
RM 			:= rm -f
AR 			:= arm-eabi-ar
OBJCOPY 	:= arm-eabi-objcopy
CD 			:= cd

FORMAT = binary

TOP := $(NODATE_HOME)/arch/$(ARCH)


ifdef BOARD
include $(TOP)/boards/$(BOARD)
endif

include $(TOP)/mcu/$(MCU)


OUTPUT := $(OUTPUT).$(MCU)
INCLUDE := -I $(TOP)/cpp/core/include -I $(TOP)/cpp/core/include/$(MCU_FAMILY)

DEFINES := -D__$(MCU_FAMILY)=1 -D__$(MCU_GENUS)=1 -D$(MCU_GENUS_CAP)=1
FLAGS := $(INCLUDE) $(MCU_FLAGS) -ffunction-sections -fdata-sections -MMD -Os -g -T $(TOP)/linker/$(MCU_LD) -lgcc
LIBS := -Wl,-Map=$(APPFOLDER)/bin/$(OUTPUT).map,--cref -Wl,--gc-sections -Wl,--print-memory-usage -lstdc++_nano
ADALIBS := -Wl,-Map=$(APPFOLDER)/bin/$(OUTPUT).map,--cref -Wl,--gc-sections -Wl,--print-memory-usage
CFLAGS := $(FLAGS) $(DEFINES) -std=gnu11
CPPFLAGS := $(FLAGS) $(DEFINES) -std=gnu++11 -fno-threadsafe-statics -fno-rtti -fno-exceptions
ADAFLAGS := -aIarch/stm32/ada/core/spec -aIarch/stm32/ada/core/body \
			-aIarch/stm32/ada/core/spec/stm32f0 -aIarch/stm32/ada/core/body/stm32f0 -D $(APPFOLDER)/obj/ -g

# CPPSOURCES := $(wildcard arch/stm32/cpp/recorders/*.cpp) \
				# $(APP_CPP_FILES)
			
CSOURCES := $(wildcard arch/stm32/cpp/core/src/$(MCU_FAMILY)/*.c) \
			$(APP_C_FILES)
SSOURCES := arch/stm32/asm/$(MCU_FAMILY)/startup_$(MCU_GENUS).S
CPPOBJECTS := $(addprefix $(APPFOLDER)/obj/,$(notdir) $(CPPSOURCES:.cpp=.o))
COBJECTS := $(addprefix $(APPFOLDER)/obj/,$(notdir) $(CSOURCES:.c=.o))
SOBJECTS := $(addprefix $(APPFOLDER)/obj/,$(notdir) $(SSOURCES:.S=.o))

all: makedir $(APPFOLDER)/bin/$(OUTPUT).elf $(APPFOLDER)/bin/$(OUTPUT).bin

makedir:
	$(MAKEDIR) $(APPFOLDER)/obj/src
	$(MAKEDIR) $(APPFOLDER)/obj/arch/stm32/asm/$(MCU_FAMILY)
	$(MAKEDIR) $(APPFOLDER)/obj/arch/stm32/$(cpp)/core/src
	$(MAKEDIR) $(APPFOLDER)/obj/arch/stm32/cpp/core/src/$(MCU_FAMILY)
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
	
$(APPFOLDER)/bin/$(OUTPUT).elf: $(SOBJECTS) $(COBJECTS)
	$(GNATMAKE) $(ADAFLAGS) --GCC=$(GCC) -c $(APPFOLDER)/src/$(APP_MAIN)
	$(GPP) -c -o $(APPFOLDER)/obj/stm32.o arch/stm32/cpp/recorders/stm32.cpp $(CPPFLAGS) $(INCLUDES)
	#$(GPP) -c -o $(APPFOLDER)/obj/system_stm32.o arch/stm32/cpp/recorders/stm32.cpp $(CPPFLAGS) $(INCLUDES)
	$(GNATBIND) $(APPFOLDER)/obj/$(APP_MAIN)
	$(GNATLINK) -g -o $@ $(ADALIBS) --LINK=$(GPP) $(APPFOLDER)/obj/$(APP_MAIN) $(APPFOLDER)/obj/stm32.o $(COBJECTS) $(SOBJECTS) $(COBJECTS)
	
# $(APPFOLDER)/bin/$(OUTPUT).elf: $(CPPOBJECTS) $(SOBJECTS) $(COBJECTS)
	# $(GPP) -o $@ $(CPPOBJECTS) $(SOBJECTS) $(COBJECTS) $(LIBS) $(FLAGS)
	
$(APPFOLDER)/bin/%.bin: $(APPFOLDER)/bin/%.elf
	$(OBJCOPY) -O $(FORMAT) $< $@
	
flash:
	$(CD) $(APPFOLDER) && \
	openocd -f board/$(PROGRAMMER) -d -c "program bin/$(OUTPUT).elf verify reset exit"

clean:
	$(RM) $(CPPOBJECTS) $(SOBJECTS) $(COBJECTS) $(APPFOLDER)/bin/$(OUTPUT).*

	