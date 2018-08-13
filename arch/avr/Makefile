# Makefile for the Nodate framework: AVR architecture
#
# 

GPP = avr-g++
GCC = avr-gcc
OBJCOPY = avr-objcopy
MAKEDIR = mkdir -p
CD = cd
RM = rm

FORMAT = ihex

TOP := $(NODATE_HOME)/arch/$(ARCH)


ifdef BOARD
include $(TOP)/boards/$(BOARD)
endif

include $(TOP)/mcu/$(MCU)
include $(TOP)/programmer/$(PROGRAMMER)


OUTPUT := $(OUTPUT).$(MCU)
INCLUDE = -I $(TOP)/arduino -I $(TOP)/arduino/variants/$(VARIANT) \
			-I $(TOP)/arduino/libraries/EEPROM/src \
			-I $(TOP)/arduino/libraries/Wire/src \
			-I $(TOP)/arduino/libraries/SPI/src \
			-I $(TOP)/arduino/libraries/SD/src \
			-I $(TOP)/arduino/libraries/SD/src/utility

FLAGS := $(INCLUDE) -D$(AVR_TYPE) -DF_CPU=$(F_CPU) -mmcu=$(MCU) -D__OPTIMIZE__ -fno-exceptions -ffunction-sections -fdata-sections -MMD -Os -g -flto -fuse-linker-plugin -Wl,-Map=$(APPFOLDER)/bin/$(OUTPUT).map,--cref -Wl,--gc-sections
CFLAGS := $(FLAGS) -std=gnu11
CPPFLAGS := $(FLAGS) -std=gnu++11 -fpermissive -fno-threadsafe-statics
CPPSOURCES := $(wildcard arch/avr/arduino/*.cpp) \
			$(wildcard arch/avr/arduino/libraries/Wire/src/*.cpp) \
			$(wildcard arch/avr/arduino/libraries/SPI/src/*.cpp) \
			$(wildcard arch/avr/arduino/libraries/SD/src/*.cpp) \
			$(wildcard arch/avr/arduino/libraries/SD/src/utility/*.cpp) \
			$(APP_CPP_FILES)
CSOURCES := $(wildcard arch/avr/arduino/*.c) \
			$(wildcard arch/avr/arduino/libraries/Wire/src/utility/*.c) \
			$(APP_C_FILES)
CPPOBJECTS := $(addprefix $(APPFOLDER)/obj/,$(notdir) $(CPPSOURCES:.cpp=.o)) 
COBJECTS := $(addprefix $(APPFOLDER)/obj/,$(notdir) $(CSOURCES:.c=.o))

all: makedir $(CPPOBJECTS) $(COBJECTS) $(APPFOLDER)/bin/$(OUTPUT).elf $(APPFOLDER)/bin/$(OUTPUT).hex

makedir:
	$(MAKEDIR) $(APPFOLDER)/obj/arch/avr
	$(MAKEDIR) $(APPFOLDER)/obj/src
	$(MAKEDIR) $(APPFOLDER)/obj/arch/avr/arduino/libraries/SPI/src
	$(MAKEDIR) $(APPFOLDER)/obj/arch/avr/arduino/libraries/Wire/src/utility
	$(MAKEDIR) $(APPFOLDER)/obj/arch/avr/arduino/libraries/SD/src/
	$(MAKEDIR) $(APPFOLDER)/obj/arch/avr/arduino/libraries/SD/src/utility
	$(MAKEDIR) $(APPFOLDER)/bin

$(APPFOLDER)/obj/%.o: %.cpp
	$(GPP) -c -o $@ $< $(CPPFLAGS)

$(APPFOLDER)/obj/%.o: %.c
	$(GCC) -c -o $@ $< $(CFLAGS)

$(APPFOLDER)/obj/%.o: $(APPFOLDER)/%.cpp
	$(GPP) -c -o $@ $< $(CPPFLAGS)

$(APPFOLDER)/obj/%.o: $(APPFOLDER)/%.c
	$(GCC) -c -o $@ $< $(CFLAGS)
	
$(APPFOLDER)/bin/$(OUTPUT).elf:
	$(GPP) -o $@ $(CPPOBJECTS) $(COBJECTS) $(LIB) $(FLAGS)
	
$(APPFOLDER)/bin/%.hex: $(APPFOLDER)/bin/%.elf
	$(OBJCOPY) -O $(FORMAT) -R .eeprom $< $@
	
flash:
	$(CD) $(APPFOLDER) && \
	avrdude -v -p $(MCU) -c $(PROGRAMMER) -P $(COM_PORT) -b $(BAUD) -D -U flash:w:bin/$(OUTPUT).hex:i

clean:
	$(RM) $(COBJECTS) $(CPPOBJECTS) $(APPFOLDER)/bin/$(OUTPUT).*
	