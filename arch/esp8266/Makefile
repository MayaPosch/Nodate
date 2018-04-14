# Makefile for the Nodate framework: ESP8266 architecture.
#
# 

GPP = xtensa-lx106-elf-g++
GCC = xtensa-lx106-elf-gcc
#OBJCOPY = xtensa-lx106-elf-objcopy
OBJCOPY = esptool
MAKEDIR = mkdir -p
CD = cd
RM = rm

include $(NODATE_HOME)/arch/$(ARCH)/mcu/$(MCU)
#include $(NODATE_HOME)/arch/$(ARCH)/programmer/$(PROGRAMMER)

TOP := $(NODATE_HOME)/arch/$(ARCH)

OUTPUT := $(OUTPUT).$(MCU)
INCLUDE = -I $(TOP)/arduino -I $(TOP)/variants/$(VARIANT) \
			-I $(TOP)/libraries/EEPROM/ \
			-I $(TOP)/libraries/Wire \
			-I $(TOP)/libraries/SPI \
			-I $(TOP)/sdk/include \
			-I $(TOP)/sdk/lwip/include \
			-I $(TOP)/sdk/lwip2/include

FLAGS := $(INCLUDE) -DF_CPU=$(F_CPU) -DICACHE_FLASH -U__STRICT_ANSI__ -D__ets__ -fdata-sections -MMD -Os -g -mtext-section-literals -ffunction-sections -fdata-sections -mlongcalls -falign-functions=4 -L $(TOP)/sdk/lib -Wl,-Map=$(APPFOLDER)/bin/$(OUTPUT).map,--cref -Wl,--gc-sections -Wl,-wrap,system_restart_local -Wl,-wrap,spi_flash_read
CFLAGS := $(FLAGS) -Wpointer-arith -Wno-implicit-function-declaration -Wl,-EL -fno-inline-functions -nostdlib -std=gnu11
CPPFLAGS := $(FLAGS) -fno-exceptions -fno-rtti -std=c++11
CPPSOURCES := $(wildcard arch/$(ARCH)/arduino/*.cpp) \
			$(wildcard arch/$(ARCH)/libraries/Wire/*.cpp) \
			$(wildcard arch/$(ARCH)/libraries/SPI/*.cpp) \
			$(wildcard arch/$(ARCH)/sdk/lwip/src/*.cpp) \
			$(APP_CPP_FILES)
CSOURCES := $(wildcard arch/$(ARCH)/arduino/*.c) \
			$(wildcard arch/$(ARCH)/libraries/Wire/src/utility/*.c) \
			$(APP_C_FILES)
CPPOBJECTS := $(addprefix $(APPFOLDER)/obj/,$(notdir) $(CPPSOURCES:.cpp=.o)) 
COBJECTS := $(addprefix $(APPFOLDER)/obj/,$(notdir) $(CSOURCES:.c=.o))

all: makedir $(CPPOBJECTS) $(COBJECTS) $(APPFOLDER)/bin/$(OUTPUT).elf $(APPFOLDER)/bin/$(OUTPUT).hex

makedir:
	$(MAKEDIR) $(APPFOLDER)/obj
	$(MAKEDIR) $(APPFOLDER)/obj/src
	$(MAKEDIR) $(APPFOLDER)/obj/arch/$(ARCH)/arduino
	$(MAKEDIR) $(APPFOLDER)/obj/arch/$(ARCH)/libraries/SPI
	$(MAKEDIR) $(APPFOLDER)/obj/arch/$(ARCH)/libraries/Wire
	$(MAKEDIR) $(APPFOLDER)/obj/arch/$(ARCH)/libraries/EEPROM
	$(MAKEDIR) $(APPFOLDER)/obj/arch/$(ARCH)/sdk/lwip/src
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
	$(OBJCOPY) -eo $< -bo $@ -bm $(FLASH_MODE) -bf $(FLASH_FREQ) -bz $(FLASH_SIZE) -bs .text -bp 4096 -ec -bs .irom0.text -bs .text -bs .data -bs .rodata -bc -ec
	
flash:
	$(CD) $(APPFOLDER) && \
	esptool2 -v -p $(MCU) -c $(PROGRAMMER) -P $(COM_PORT) -b $(BAUD) -D -U flash:w:bin/$(OUTPUT).hex:i

clean:
	$(RM) $(COBJECTS) $(CPPOBJECTS) $(APPFOLDER)/bin/$(OUTPUT).*
	