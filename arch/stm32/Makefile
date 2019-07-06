# Makefile for the Nodate framework: STM32 ARM architecture
#
# 

GPP = arm-none-eabi-g++
GCC = arm-none-eabi-gcc
AR = arm-none-eabi-ar
OBJCOPY = arm-none-eabi-objcopy
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
INCLUDE = -I $(TOP)/arduino -I $(TOP)/variants/$(VARIANT) \
			-I $(TOP)/arduino/stm32 \
			-I $(TOP)/arduino/stm32/HAL \
			-I $(TOP)/arduino/stm32/LL \
			-I $(TOP)/arduino/stm32/usb \
			-I $(TOP)/arduino/stm32/usb/cdc \
			-I $(TOP)/arduino/stm32/usb/hid \
			-I $(TOP)/libraries/EEPROM/src \
			-I $(TOP)/libraries/Wire/src \
			-I $(TOP)/libraries/SPI/src \
			-I $(TOP)/libraries/Ethernet \
			-I $(TOP)/libraries/Ethernet/utility \
			-I $(TOP)/libraries/IWatchdog/src \
			-I $(TOP)/libraries/Keyboard/src \
			-I $(TOP)/libraries/LwIP \
			-I $(TOP)/libraries/LwIP/arch \
			-I $(TOP)/libraries/LwIP/lwip \
			-I $(TOP)/libraries/LwIP/lwip/apps \
			-I $(TOP)/libraries/LwIP/lwip/priv \
			-I $(TOP)/libraries/LwIP/lwip/prot \
			-I $(TOP)/libraries/LwIP/netif \
			-I $(TOP)/libraries/LwIP/netif/ppp \
			-I $(TOP)/libraries/LwIP/netif/ppp/polarssl \
			-I $(TOP)/libraries/LwIP/posix \
			-I $(TOP)/libraries/LwIP/posix/sys \
			-I $(TOP)/libraries/Mouse/src \
			-I $(TOP)/libraries/Servo/src \
			-I $(TOP)/libraries/Servo/stm32 \
			-I $(TOP)/system/STM32F0xx \
			-I $(TOP)/system/STM32F1xx \
			-I $(TOP)/system/STM32F2xx \
			-I $(TOP)/system/STM32F3xx \
			-I $(TOP)/system/STM32F4xx \
			-I $(TOP)/system/STM32F7xx \
			-I $(TOP)/system/STM32G0xx \
			-I $(TOP)/system/STM32H7xx \
			-I $(TOP)/system/STM32L0xx \
			-I $(TOP)/system/STM32L1xx \
			-I $(TOP)/system/STM32L4xx \
			-I $(TOP)/system/STM32WBxx \
			-I $(TOP)/system/Drivers/CMSIS/Device/ST/STM32F7xx/Include \
			-I $(TOP)/system/Drivers/CMSIS/Core/Include \
			-I $(TOP)/system/Drivers/STM32F7xx_HAL_Driver/Inc \
			-I $(TOP)/system/Middlewares/ST/STM32_USB_Device_Library/Core/Inc \
			-I $(APPFOLDER)/src
			
FLASH_OFFSET := 0

FLAGS := $(INCLUDE) $(MCU_FLAGS) -w -DARDUINO=3000 -Os -g $(PROJECT_FLAGS)
CFLAGS := $(FLAGS) -std=gnu11 -ffunction-sections -fdata-sections -nostdlib --param max-inline-insns-single=500 -MMD
CPPFLAGS := $(FLAGS) -std=gnu++14 -ffunction-sections -fdata-sections -nostdlib -fno-threadsafe-statics --param max-inline-insns-single=500 -fno-rtti -fno-exceptions -MMD
LDFLAGS :="-T$(CURDIR)/arch/$(ARCH)/variants/$(VARIANT)/ldscript.ld" "-Wl,-Map,$(APPFOLDER)/bin/$(OUTPUT).map"  --specs=nano.specs -Wl,--defsym=LD_FLASH_OFFSET=$(FLASH_OFFSET) -Wl,--defsym=LD_MAX_SIZE=$(MCU_UPLOAD_MAX_SIZE) -Wl,--defsym=LD_MAX_DATA_SIZE=$(MCU_UPLOAD_MAX_DATA_SIZE) -Wl,--cref -Wl,--check-sections -Wl,--gc-sections -Wl,--entry=Reset_Handler -Wl,--unresolved-symbols=report-all -Wl,--warn-common 
LIBS := -Wl,--start-group -Wl,--no-whole-archive -lc -Wl,--end-group -lm -lgcc -lstdc++

CPPSOURCES := $(wildcard arch/$(ARCH)/arduino/*.cpp) \
			$(wildcard arch/$(ARCH)/arduino/stm32/*.cpp) \
			$(wildcard arch/$(ARCH)/libraries/Wire/src/*.cpp) \
			$(wildcard arch/$(ARCH)/libraries/Ethernet/*.cpp) \
			$(wildcard arch/$(ARCH)/libraries/SPI/src/*.cpp) \
			$(wildcard arch/$(ARCH)/libraries/IWatchdog/src/*.cpp) \
			$(wildcard arch/$(ARCH)/libraries/Keyboard/src/*.cpp) \
			$(wildcard arch/$(ARCH)/libraries/Mouse/src/*.cpp) \
			$(wildcard arch/$(ARCH)/libraries/Servo/src/stm32/*.cpp) \
			$(wildcard arch/$(ARCH)/variants/$(VARIANT)/*.cpp) \
			$(APP_CPP_FILES)
			
CSOURCES := $(wildcard arch/$(ARCH)/arduino/*.c) \
			$(wildcard arch/$(ARCH)/arduino/stm32/*.c) \
			$(wildcard arch/$(ARCH)/arduino/stm32/HAL/*.c) \
			$(wildcard arch/$(ARCH)/arduino/stm32/LL/*.c) \
			$(wildcard arch/$(ARCH)/arduino/stm32/usb/*.c) \
			$(wildcard arch/$(ARCH)/arduino/stm32/usb/cdc/*.c) \
			$(wildcard arch/$(ARCH)/arduino/stm32/usb/hid/*.c) \
			$(wildcard arch/$(ARCH)/libraries/Wire/src/utility/*.c) \
			$(wildcard arch/$(ARCH)/libraries/Ethernet/utility/*.c) \
			$(wildcard arch/$(ARCH)/libraries/LwIP/api/*.c) \
			$(wildcard arch/$(ARCH)/libraries/LwIP/core/*.c) \
			$(wildcard arch/$(ARCH)/libraries/LwIP/core/ipv4/*.c) \
			$(wildcard arch/$(ARCH)/libraries/LwIP/core/ipv6/*.c) \
			$(wildcard arch/$(ARCH)/libraries/LwIP/netif/*.c) \
			$(wildcard arch/$(ARCH)/libraries/LwIP/netif/ppp/*.c) \
			$(wildcard arch/$(ARCH)/libraries/LwIP/netif/ppp/polarssl/*.c) \
			$(wildcard arch/$(ARCH)/libraries/LwIP/system/OS/*.c) \
			$(wildcard arch/$(ARCH)/variants/$(VARIANT)/*.c) \
			$(APP_C_FILES)

ASMSOURCES := arch/$(ARCH)/system/Drivers/CMSIS/Device/ST/$(DEVICE)/Source/Templates/gcc/startup_$(STARTUP).s
			
CPPOBJECTS := $(addprefix $(APPFOLDER)/obj/,$(notdir) $(CPPSOURCES:.cpp=.o))
COBJECTS := $(addprefix $(APPFOLDER)/obj/,$(notdir) $(CSOURCES:.c=.o))
ASMOBJECTS := $(addprefix $(APPFOLDER)/obj/,$(notdir) $(ASMSOURCES:.s=.o))


all: makedir $(CPPOBJECTS) $(COBJECTS) $(ASMOBJECTS) $(APPFOLDER)/bin/$(OUTPUT).elf $(APPFOLDER)/bin/$(OUTPUT).hex

makedir:
	$(MAKEDIR) $(APPFOLDER)/obj/arch/$(ARCH)
	$(MAKEDIR) $(APPFOLDER)/obj/src
	$(MAKEDIR) $(APPFOLDER)/obj/arch/$(ARCH)/arduino/stm32/HAL
	$(MAKEDIR) $(APPFOLDER)/obj/arch/$(ARCH)/arduino/stm32/LL
	$(MAKEDIR) $(APPFOLDER)/obj/arch/$(ARCH)/arduino/stm32/usb/cdc
	$(MAKEDIR) $(APPFOLDER)/obj/arch/$(ARCH)/arduino/stm32/usb/hid
	$(MAKEDIR) $(APPFOLDER)/obj/arch/$(ARCH)/libraries/SPI/src
	$(MAKEDIR) $(APPFOLDER)/obj/arch/$(ARCH)/libraries/Wire/src/utility
	$(MAKEDIR) $(APPFOLDER)/obj/arch/$(ARCH)/libraries/SD/src/
	$(MAKEDIR) $(APPFOLDER)/obj/arch/$(ARCH)/libraries/SD/src/utility
	$(MAKEDIR) $(APPFOLDER)/bin
	$(MAKEDIR) $(APPFOLDER)/obj/arch/$(ARCH)/libraries/Wire/src/utility
	$(MAKEDIR) $(APPFOLDER)/obj/arch/$(ARCH)/libraries/Ethernet/utility
	$(MAKEDIR) $(APPFOLDER)/obj/arch/$(ARCH)/libraries/LwIP/api/
	$(MAKEDIR) $(APPFOLDER)/obj/arch/$(ARCH)/libraries/LwIP/core/ipv4
	$(MAKEDIR) $(APPFOLDER)/obj/arch/$(ARCH)/libraries/LwIP/core/ipv6
	$(MAKEDIR) $(APPFOLDER)/obj/arch/$(ARCH)/libraries/LwIP/netif/ppp/polarssl
	$(MAKEDIR) $(APPFOLDER)/obj/arch/$(ARCH)/libraries/LwIP/system/OS
	$(MAKEDIR) $(APPFOLDER)/obj/arch/$(ARCH)/libraries/IWatchdog/src
	$(MAKEDIR) $(APPFOLDER)/obj/arch/$(ARCH)/libraries/Keyboard/src
	$(MAKEDIR) $(APPFOLDER)/obj/arch/$(ARCH)/libraries/Mouse/src
	$(MAKEDIR) $(APPFOLDER)/obj/arch/$(ARCH)/libraries/Servo/src/stm32
	$(MAKEDIR) $(APPFOLDER)/obj/arch/$(ARCH)/system/STM32F7xx
	$(MAKEDIR) $(APPFOLDER)/obj/arch/$(ARCH)/variants/$(VARIANT)
	$(MAKEDIR) $(APPFOLDER)/obj/arch/$(ARCH)/system/Drivers/STM32F7xx_HAL_Driver/Src
	$(MAKEDIR) $(APPFOLDER)/obj/arch/$(ARCH)/system/Middlewares/STM32_USB_Device_Library/Core/Src
	$(MAKEDIR) $(APPFOLDER)/obj/arch/$(ARCH)/system/Drivers/CMSIS/Device/ST/$(DEVICE)/Source/Templates/gcc/

$(APPFOLDER)/obj/%.o: %.cpp
	$(GPP) -c -o $@ $< $(CPPFLAGS)

$(APPFOLDER)/obj/%.o: %.c
	$(GCC) -c -o $@ $< $(CFLAGS)

$(APPFOLDER)/obj/%.o: %.s
	$(GCC) -c -o $@ $< -x assembler-with-cpp

$(APPFOLDER)/obj/%.o: $(APPFOLDER)/%.cpp
	$(GPP) -c -o $@ $< $(CPPFLAGS)

$(APPFOLDER)/obj/%.o: $(APPFOLDER)/%.c
	$(GCC) -c -o $@ $< $(CFLAGS)

$(APPFOLDER)/obj/%.o: $(APPFOLDER)/%.s
	$(GCC) -c -o $@ $< -x assembler-with-cpp
	
$(APPFOLDER)/bin/$(OUTPUT).elf:
	$(GPP) -o $@ $(LDFLAGS) $(CPPOBJECTS) $(COBJECTS) $(ASMOBJECTS) $(LIB) $(FLAGS)
	
$(APPFOLDER)/bin/%.hex: $(APPFOLDER)/bin/%.elf
	$(OBJCOPY) -O $(FORMAT) -R .eeprom $< $@
	
flash:
	$(CD) $(APPFOLDER) && \
	#avrdude -v -p $(MCU) -c $(PROGRAMMER) -P $(COM_PORT) -b $(BAUD) -D -U flash:w:bin/$(OUTPUT).hex:i

clean:
	$(RM) $(COBJECTS) $(CPPOBJECTS) $(APPFOLDER)/bin/$(OUTPUT).*
	