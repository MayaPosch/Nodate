# Makefile for the Nodate framework
#
# 

GPP = avr-g++
GCC = avr-gcc
OBJCOPY = avr-objcopy
MAKEDIR = mkdir -p
RM = rm
FORMAT = ihex

OUTPUT := $(OUTPUT).$(MCU)
INCLUDE = -I arduino -I arduino/variants/standard \
			-I arduino/libraries/EEPROM/src \
			-I arduino/libraries/Wire/src \
			-I arduino/libraries/SPI/src

FLAGS := $(INCLUDE) -D$(AVR_TYPE) -DF_CPU=$(F_CPU) -mmcu=$(MCU) -D__OPTIMIZE__ -fno-exceptions -ffunction-sections -fdata-sections -MMD -Os -g -flto -fuse-linker-plugin -Wl,-Map=$(APPFOLDER)/bin/$(OUTPUT).map,--cref -Wl,--gc-sections
CFLAGS := $(FLAGS) -std=gnu11
CPPFLAGS := $(FLAGS) -std=gnu++11 -fpermissive -fno-threadsafe-statics
CPPSOURCES := $(wildcard arduino/*.cpp) \
			$(wildcard arduino/libraries/Wire/src/*.cpp) \
			$(wildcard arduino/libraries/SPI/src/*.cpp) \
			$(APP_CPP_FILES)
CSOURCES := $(wildcard arduino/*.c) \
			$(wildcard arduino/libraries/Wire/src/utility/*.c) \
			$(APP_C_FILES)
CPPOBJECTS := $(addprefix $(APPFOLDER)/obj/,$(notdir) $(CPPSOURCES:.cpp=.o)) 
COBJECTS := $(addprefix $(APPFOLDER)/obj/,$(notdir) $(CSOURCES:.c=.o))

all: makedir $(CPPOBJECTS) $(COBJECTS) $(APPFOLDER)/bin/$(OUTPUT).elf $(APPFOLDER)/bin/$(OUTPUT).hex

makedir:
	$(MAKEDIR) $(APPFOLDER)/obj
	$(MAKEDIR) $(APPFOLDER)/obj/src
	$(MAKEDIR) $(APPFOLDER)/obj/arduino/libraries/SPI/src
	$(MAKEDIR) $(APPFOLDER)/obj/arduino/libraries/Wire/src/utility
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
	avrdude -v -p $(MCU) -c $(PROGRAMMER) -P $(COM_PORT) -b $(BAUD) -D -U flash:w:$(APPFOLDER)/bin/$(OUTPUT).hex:i

clean:
	$(RM) $(COBJECTS) $(CPPOBJECTS) $(APPFOLDER)/bin/*