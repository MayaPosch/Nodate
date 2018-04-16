# Makefile for the Nodate framework: ESP8266 architecture.
#
# 

GPP = xtensa-lx106-elf-g++
GCC = xtensa-lx106-elf-gcc
#OBJCOPY = xtensa-lx106-elf-objcopy
OBJCOPY = esptool
AR = xtensa-lx106-elf-ar
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

LIBS :=  -L$(TOP)/sdk/lib \
		-L$(TOP)/sdk/libc/xtensa-lx106-elf/lib \
		 $(APPFOLDER)/obj/esp8266.a \
		 -lhal -lphy -lpp -lnet80211 -llwip_gcc -lwpa -lcrypto -lmain -lwps -laxtls -lespnow \
		 -lsmartconfig -lairkiss -lwpa2 -lstdc++ -lm -lc -lgcc -Wl,--end-group
LDFLAGS := -Os -nostdlib -Wl,--no-check-sections -u call_user_start -u _printf_float \
			-u _scanf_float -Wl,-static "-T$(TOP)/sdk/ld/$(FLASH_LD)" -Wl,--gc-sections \
			-Wl,-wrap,system_restart_local -Wl,-wrap,spi_flash_read \
			-Wl,-Map=$(APPFOLDER)/bin/$(OUTPUT).map -Wl,--start-group 

FLAGS := $(INCLUDE) -DF_CPU=$(F_CPU) -DICACHE_FLASH -U__STRICT_ANSI__ -D__ets__ -DESP8266 -DLWIP_OPEN_SRC -fdata-sections -MMD -Os -g -mtext-section-literals -ffunction-sections -fdata-sections -mlongcalls -falign-functions=4 
CFLAGS := $(FLAGS) -Wpointer-arith -Wno-implicit-function-declaration -Wl,-EL -fno-inline-functions -std=gnu11 -nostdlib
CPPFLAGS := $(FLAGS) -fno-exceptions -fno-rtti -std=c++11

CPPSOURCES := $(wildcard arch/$(ARCH)/arduino/*.cpp) \
			$(wildcard arch/$(ARCH)/libraries/Wire/*.cpp) \
			$(wildcard arch/$(ARCH)/libraries/SPI/*.cpp) \
			$(wildcard arch/$(ARCH)/sdk/lwip/src/*.cpp)
CSOURCES := $(wildcard arch/$(ARCH)/arduino/*.c) \
			$(wildcard arch/$(ARCH)/libraries/Wire/src/utility/*.c)
SSOURCES := $(wildcard arch/$(ARCH)/arduino/*.s)

# Application objects.
APPCPPOBJ := $(addprefix $(APPFOLDER)/obj/,$(notdir) $(APP_CPP_FILES:.cpp=.o))
APPCOBJ := $(addprefix $(APPFOLDER)/obj/,$(notdir) $(APP_C_FILES:.c=.o))

# Framework objects.
CPPOBJECTS := $(addprefix $(APPFOLDER)/obj/,$(notdir) $(CPPSOURCES:.cpp=.o)) 
COBJECTS := $(addprefix $(APPFOLDER)/obj/,$(notdir) $(CSOURCES:.c=.o))
SOBJECTS := $(addprefix $(APPFOLDER)/obj/,$(notdir) $(SSOURCES:.s=.o))

all: makedir $(CPPOBJECTS) $(COBJECTS) $(SOBJECTS) $(APPCOBJ) $(APPCPPOBJ) makear $(APPFOLDER)/bin/$(OUTPUT).elf $(APPFOLDER)/bin/$(OUTPUT).hex

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

$(APPFOLDER)/obj/%.o: $(APPFOLDER)/%.s
	$(GCC) -c -o $@ $< $(CFLAGS)
	
makear:
	$(AR) cru $(APPFOLDER)/obj/esp8266.a $(CPPOBJECTS) $(COBJECTS) $(SOBJECTS)
	
$(APPFOLDER)/bin/$(OUTPUT).elf:
	$(GCC) -o $@ $(LDFLAGS) $(APPCPPOBJ) $(APPCOBJ) $(LIBS)
	
$(APPFOLDER)/bin/%.hex: $(APPFOLDER)/bin/%.elf
	$(OBJCOPY) -eo $< -bo $@ -bm $(FLASH_MODE) -bf $(FLASH_FREQ) -bz $(FLASH_SIZE) -bs .text -bp 4096 -ec -bs .irom0.text -bs .text -bs .data -bs .rodata -bc -ec
	
flash:
	$(CD) $(APPFOLDER) && \
	esptool2 -v -p $(MCU) -c $(PROGRAMMER) -P $(COM_PORT) -b $(BAUD) -D -U flash:w:bin/$(OUTPUT).hex:i

clean:
	$(RM) $(COBJECTS) $(CPPOBJECTS) $(SOBJECTS) $(APPCPPOBJ) $(APPCOBJ) $(APPFOLDER)/bin/$(OUTPUT).*
	