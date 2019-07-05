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
			-I $(TOP)/system/Drivers/STM32F7xx_HAL_Driver/Inc
			
			
#-I $(TOP)/system/Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_wwdg.c
			
$(info $$INCLUDE is [${INCLUDE}])
			
FLASH_OFFSET := 0

FLAGS := $(INCLUDE) $(MCU_FLAGS) -w -DARDUINO=3000 -Os -g -Wl,--gc-sections
CFLAGS := $(FLAGS) -std=gnu11 -ffunction-sections -fdata-sections -nostdlib --param max-inline-insns-single=500 -MMD
CPPFLAGS := $(FLAGS) -std=gnu++14 -ffunction-sections -fdata-sections -nostdlib -fno-threadsafe-statics --param max-inline-insns-single=500 -fno-rtti -fno-exceptions -MMD
LDFLAGS := --specs=nano.specs -Wl,--defsym=LD_FLASH_OFFSET=$(FLASH_OFFSET)-Wl,--defsym=LD_MAX_SIZE=$(MCU_UPLOAD_MAX_SIZE) -Wl,--defsym=LD_MAX_DATA_SIZE=$(MCU_UPLOAD_MAX_DATA_SIZE) -Wl,--cref -Wl,--check-sections -Wl,--gc-sections -Wl,--entry=Reset_Handler -Wl,--unresolved-symbols=report-all -Wl,--warn-common
CPPSOURCES := $(wildcard arch/$(ARCH)/arduino/*.cpp) \
			$(wildcard arch/$(ARCH)/arduino/stm32/*.cpp) \
			$(wildcard arch/$(ARCH)/libraries/Wire/src/*.cpp) \
			$(wildcard arch/$(ARCH)/libraries/SPI/src/*.cpp) \
			$(wildcard arch/$(ARCH)/libraries/IWatchdog/src/*.cpp) \
			$(wildcard arch/$(ARCH)/libraries/Keyboard/src/*.cpp) \
			$(wildcard arch/$(ARCH)/libraries/Mouse/src/*.cpp) \
			$(wildcard arch/$(ARCH)/libraries/Servo/src/stm32/*.cpp) \
			$(APP_CPP_FILES)
CSOURCES := $(wildcard arch/$(ARCH)/arduino/*.c) \
			$(wildcard arch/$(ARCH)/arduino/stm32/*.c) \
			$(wildcard arch/$(ARCH)/arduino/stm32/HAL/*.c) \
			$(wildcard arch/$(ARCH)/arduino/stm32/LL/*.c) \
			$(wildcard arch/$(ARCH)/arduino/stm32/usb/*.c) \
			$(wildcard arch/$(ARCH)/arduino/stm32/usb/cdc/*.c) \
			$(wildcard arch/$(ARCH)/arduino/stm32/usb/hid/*.c) \
			$(wildcard arch/$(ARCH)/libraries/Wire/src/utility/*.c) \
			$(wildcard arch/$(ARCH)/libraries/Ethernet/*.c) \
			$(wildcard arch/$(ARCH)/libraries/Ethernet/utility/*.c) \
			$(wildcard arch/$(ARCH)/libraries/LwIP/api/*.c) \
			$(wildcard arch/$(ARCH)/libraries/LwIP/core/*.c) \
			$(wildcard arch/$(ARCH)/libraries/LwIP/core/ipv4/*.c) \
			$(wildcard arch/$(ARCH)/libraries/LwIP/core/ipv6/*.c) \
			$(wildcard arch/$(ARCH)/libraries/LwIP/netif/*.c) \
			$(wildcard arch/$(ARCH)/libraries/LwIP/netif/ppp/*.c) \
			$(wildcard arch/$(ARCH)/libraries/LwIP/netif/ppp/polarssl/*.c) \
			$(wildcard arch/$(ARCH)/libraries/LwIP/system/OS/*.c) \
			$(wildcard arch/$(ARCH)/system/STM32F7xx/*.c) \
			$(wildcard arch/$(ARCH)/system/Drivers/CMSIS\Device/ST/STM32F7xx/Source/Templates/*.c) \
			$(wildcard arch/$(ARCH)/system/Drivers/STM32F7xx_HAL_Driver/Src/*.c) \
			$(APP_C_FILES)
# CSOURCES := $(shell cd "$(NODATE_HOME)"; find ./arduino/ -name \*.c) \
			# $(shell cd "$(NODATE_HOME)"; find ./libraries/ -name \*.c) \
			# $(shell cd "$(NODATE_HOME)"; find ./system/ -name \*.c) \
			# $(shell cd "$(NODATE_HOME)"; find ./variants/ -name \*.c) \
CPPOBJECTS := $(addprefix $(APPFOLDER)/obj/,$(notdir) $(CPPSOURCES:.cpp=.o))
COBJECTS := $(addprefix $(APPFOLDER)/obj/,$(notdir) $(CSOURCES:.c=.o))

# $(info $$CPPSOURCES is [${CPPSOURCES}])
# $(info $$CPPOBJECTS is [${CPPOBJECTS}])
# $(info $$CSOURCES is [${CSOURCES}])
# $(info $$COBJECTS is [${COBJECTS}])

all: makedir $(CPPOBJECTS) $(COBJECTS) $(APPFOLDER)/bin/$(OUTPUT).elf $(APPFOLDER)/bin/$(OUTPUT).hex

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
	$(MAKEDIR) $(APPFOLDER)/obj/arch/$(ARCH)/libraries/Servo/stm32
	$(MAKEDIR) $(APPFOLDER)/obj/arch/$(ARCH)/system/STM32F7xx
	$(MAKEDIR) $(APPFOLDER)/obj/arch/$(ARCH)/system/Drivers/CMSIS\Device/ST/STM32F7xx/Source/Templates
	$(MAKEDIR) $(APPFOLDER)/obj/arch/$(ARCH)/system/Drivers/STM32F7xx_HAL_Driver/Src

$(APPFOLDER)/obj/%.o: %.cpp
	$(GPP) -c -o $@ $< $(CPPFLAGS)

$(APPFOLDER)/obj/%.o: %.c
	$(GCC) -c -o $@ $< $(CFLAGS)

$(APPFOLDER)/obj/%.o: $(APPFOLDER)/%.cpp
	$(GPP) -c -o $@ $< $(CPPFLAGS)

$(APPFOLDER)/obj/%.o: $(APPFOLDER)/%.c
	#$(MKDIR) "$(@D)"
	$(GCC) -c -o $@ $< $(CFLAGS)
	
$(APPFOLDER)/bin/$(OUTPUT).elf:
	$(GPP) -o $@ $(CPPOBJECTS) $(COBJECTS) $(LIB) $(LDFLAGS) $(FLAGS)
	
$(APPFOLDER)/bin/%.hex: $(APPFOLDER)/bin/%.elf
	$(OBJCOPY) -O $(FORMAT) -R .eeprom $< $@
	
flash:
	$(CD) $(APPFOLDER) && \
	#avrdude -v -p $(MCU) -c $(PROGRAMMER) -P $(COM_PORT) -b $(BAUD) -D -U flash:w:bin/$(OUTPUT).hex:i

clean:
	$(RM) $(COBJECTS) $(CPPOBJECTS) $(APPFOLDER)/bin/$(OUTPUT).*
	