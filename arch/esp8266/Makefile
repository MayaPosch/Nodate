# Makefile for the Nodate framework: ESP8266 architecture.
#
# 

GPP = xtensa-lx106-elf-g++
GCC = xtensa-lx106-elf-gcc
OBJCOPY = xtensa-lx106-elf-objcopy
MAKEDIR = mkdir -p
CD = cd
RM = rm

FORMAT = ihex


OUTPUT := $(OUTPUT).$(MCU)
INCLUDE = -I arduino -I variants/$(VARIANT) \
			-I libraries/EEPROM/ \
			-I libraries/Wire \
			-I libraries/SPI

FLAGS := $(INCLUDE) -D$(AVR_TYPE) -DF_CPU=$(F_CPU) -mmcu=$(MCU) -D__OPTIMIZE__ -fno-exceptions -ffunction-sections -fdata-sections -MMD -Os -g -flto -fuse-linker-plugin -Wl,-Map=$(APPFOLDER)/bin/$(OUTPUT).map,--cref -Wl,--gc-sections
CFLAGS := $(FLAGS) -std=gnu11
CPPFLAGS := $(FLAGS) -std=gnu++11 -fpermissive -fno-threadsafe-statics
CPPSOURCES := $(wildcard arduino/*.cpp) \
			$(wildcard libraries/Wire/src/*.cpp) \
			$(wildcard libraries/SPI/src/*.cpp) \
			$(APP_CPP_FILES)
CSOURCES := $(wildcard arduino/*.c) \
			$(wildcard libraries/Wire/src/utility/*.c) \
			$(APP_C_FILES)
CPPOBJECTS := $(addprefix $(APPFOLDER)/obj/,$(notdir) $(CPPSOURCES:.cpp=.o)) 
COBJECTS := $(addprefix $(APPFOLDER)/obj/,$(notdir) $(CSOURCES:.c=.o))

all: makedir $(CPPOBJECTS) $(COBJECTS) $(APPFOLDER)/bin/$(OUTPUT).elf $(APPFOLDER)/bin/$(OUTPUT).hex

makedir:
	$(MAKEDIR) $(APPFOLDER)/obj
	$(MAKEDIR) $(APPFOLDER)/obj/src
	$(MAKEDIR) $(APPFOLDER)/obj/libraries/SPI
	$(MAKEDIR) $(APPFOLDER)/obj/libraries/Wire
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
	