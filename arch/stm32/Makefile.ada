# Makefile for the Nodate framework: STM32 (ARM Cortex-M) architecture
#
# 

GPP 		:= arm-none-eabi-g++
GCC 		:= arm-eabi-gcc
GNATMAKE 	:= gnatmake
GPRBUILD 	:= gprbuild
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
FLAGS := $(INCLUDE) $(MCU_FLAGS) -ffunction-sections -fdata-sections -MMD -Os -g -lgcc
LIBS := -Wl,-Map=$(APPFOLDER)/bin/$(OUTPUT).map,--cref -Wl,--gc-sections -Wl,--print-memory-usage \
		-T $(TOP)/linker/$(MCU_FAMILY)/$(MCU_LD) 
		
		#-lstdc++_nano
ADALIBS := -Wl,-Map=$(APPFOLDER)/bin/$(OUTPUT).map,--cref -Wl,--gc-sections -Wl,--print-memory-usage
CFLAGS := $(FLAGS) $(DEFINES) -std=gnu11
CPPFLAGS := $(FLAGS) $(DEFINES) -std=gnu++11 -fno-threadsafe-statics -fno-rtti -fno-exceptions

#ADAINCLUDES := -I/d/Dev/GNAT/2020-arm-elf/arm-eabi/lib/gnat/
ADAINCLUDES	:= -I$(TOP)/ada/rts/zfp-cortex-m0
ADA_RTS		:= -I$(TOP)/ada/rts/$(MCU_FAMILY)
ADALIBS 	:= -L/d/Dev/GNAT/2020-arm-elf/arm-eabi/lib/gnat/
ADAFLAGS 	:= -aIarch/stm32/ada/core/spec -aIarch/stm32/ada/core/body \
				-aIarch/stm32/ada/core/spec/stm32f0 -aIarch/stm32/ada/core/body/stm32f0 \
				-D $(APPFOLDER)/obj/ -g \
				--RTS=$(TOP)/ada/rts/zfp-cortex-m0 \
				$(ADALIBS) $(ADAINCLUDES)
ADABINDPAR	:= -I/d/Dev/GNAT/2020-arm-elf/arm-eabi/lib/gnat/zfp-cortex-m0/adalib \
				-I/d/Dev/GNAT/2020-arm-elf/arm-eabi/lib/gnat/zfp-cortex-m0/adainclude -g
		
# ADAFLAGS := -cargs:Ada -aIarch/stm32/ada/core/spec \
			# -cargs:Ada -aIarch/stm32/ada/core/body \
			# -cargs:Ada -aIarch/stm32/ada/core/spec/stm32f0 \
			# -cargs:Ada -aIarch/stm32/ada/core/body/stm32f0 \
			# -cargs:Ada -D $(APPFOLDER)/obj/ -g \
			# --RTS=zfp-cortex-m0 \
			# --target=arm-eabi $(FLAGS)

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
	$(GPP) -c -o $(APPFOLDER)/obj/stm32.o arch/stm32/cpp/recorders/stm32.cpp $(CPPFLAGS) $(INCLUDES)
	#$(GNATMAKE) $(ADAFLAGS) --GCC=$(GCC) -c $(APPFOLDER)/src/$(APP_MAIN)
	#$(GPRBUILD) $(ADAFLAGS) --src- $(APPFOLDER)/src/$(APP_MAIN)
	#$(GCC) $(ADAFLAGS) $(APPFOLDER)/src/$(APP_MAIN)
	#$(GPP) -c -o $(APPFOLDER)/obj/system_stm32.o arch/stm32/cpp/recorders/stm32.cpp $(CPPFLAGS) $(INCLUDES)
	#$(GNATBIND)  -v $(ADABINDPAR) $(APPFOLDER)/obj/$(APP_MAIN)
	#$(GNATLINK) -o $@ $(ADALIBS) $(ADAINCLUDES) --LINK=$(GPP) --GCC=$(GCC) $(APPFOLDER)/obj/$(APP_MAIN) \
	#				$(APPFOLDER)/obj/stm32.o $(COBJECTS) $(SOBJECTS) $(COBJECTS) $(LIBS)
	$(GNATMAKE) -o $@ $(ADAFLAGS) --GCC=$(GCC) $(APPFOLDER)/src/$(APP_MAIN) \
					-largs $(APPFOLDER)/obj/stm32.o $(COBJECTS) $(SOBJECTS) $(LIBS)
	
# $(APPFOLDER)/bin/$(OUTPUT).elf: $(CPPOBJECTS) $(SOBJECTS) $(COBJECTS)
	# $(GPP) -o $@ $(CPPOBJECTS) $(SOBJECTS) $(COBJECTS) $(LIBS) $(FLAGS)
	
$(APPFOLDER)/bin/%.bin: $(APPFOLDER)/bin/%.elf
	$(OBJCOPY) -O $(FORMAT) $< $@
	
flash:
	$(CD) $(APPFOLDER) && \
	openocd -f board/$(PROGRAMMER) -d -c "program bin/$(OUTPUT).elf verify reset exit"

clean:
	$(RM) $(CPPOBJECTS) $(SOBJECTS) $(COBJECTS) $(APPFOLDER)/bin/$(OUTPUT).*

	