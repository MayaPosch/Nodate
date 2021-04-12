# Makefile for the Nodate framework: STM32 (ARM Cortex-M) architecture
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


# Toggle Nodate core modules.
ifneq (, $(findstring gpio, $(NODATE_MODULES)))
	NODATE_GPIO = 1 
	NODATE_MOD_ENABLE += -DNODATE_GPIO_ENABLED 
endif

ifneq (, $(findstring ethernet, $(NODATE_MODULES)))
	NODATE_ETH = 1
	NODATE_MOD_ENABLE += -DNODATE_ETHERNET_ENABLED
endif

ifneq (, $(findstring i2c, $(NODATE_MODULES)))
	NODATE_I2C = 1
	NODATE_MOD_ENABLE += -DNODATE_I2C_ENABLED
endif

ifneq (, $(findstring interrupts, $(NODATE_MODULES)))
	NODATE_ISR = 1
	NODATE_MOD_ENABLE += -DNODATE_INTERRUPTS_ENABLED
endif

ifneq (, $(findstring usart, $(NODATE_MODULES)))
	NODATE_USART = 1
	NODATE_MOD_ENABLE += -DNODATE_USART_ENABLED
endif

ifneq (, $(findstring timer, $(NODATE_MODULES)))
	NODATE_TIMER = 1
	NODATE_MOD_ENABLE += -DNODATE_TIMER_ENABLED
endif

# Toggle optional library modules.
ifneq (, $(findstring freertos, $(NODATE_LIBRARIES)))
	NODATE_FREERTOS = 1
endif


# Define FreeRTOS port to use.
ifeq ($(MCU_FAMILY), stm32f0)
ARMA := ARM_CM0
endif
ifeq ($(MCU_FAMILY), stm32f1)
ARMA := ARM_CM3
endif
ifeq ($(MCU_FAMILY), stm32f3)
ARMA := ARM_CM3
endif
ifeq ($(MCU_FAMILY), stm32f4)
ARMA := ARM_CM4_MPU
endif
ifeq ($(MCU_FAMILY), stm32f7)
ARMA := ARM_CM7/r0p1
endif


OUTPUT := $(OUTPUT).$(MCU)
INCLUDE := -I $(TOP)/$(NDLANGUAGE)/core/include -I $(TOP)/$(NDLANGUAGE)/core/include/$(MCU_FAMILY) \
			-I $(TOP)/$(NDLANGUAGE)/libs -I $(TOP)/$(NDLANGUAGE)/boards/$(BOARD) \
			-I $(TOP)/$(NDLANGUAGE)/peripherals \
			# -I $(TOP)/$(NDLANGUAGE)/libs/LwIP/src/include/netif/ppp \
			# -I $(TOP)/$(NDLANGUAGE)/libs/LwIP/src/include/lwip \
			# -I $(TOP)/$(NDLANGUAGE)/libs/LwIP/src/include/lwip/apps \
			# -I $(TOP)/$(NDLANGUAGE)/libs/LwIP/src/include/lwip/priv \
			# -I $(TOP)/$(NDLANGUAGE)/libs/LwIP/src/include/lwip/prot \
			# -I $(TOP)/$(NDLANGUAGE)/libs/LwIP/src/include \
			# -I $(TOP)/$(NDLANGUAGE)/libs/LwIP/src/include/netif \
			# -I $(TOP)/$(NDLANGUAGE)/libs/LwIP/src/include/compat/posix \
			# -I $(TOP)/$(NDLANGUAGE)/libs/LwIP/src/include/compat/posix/arpa \
			# -I $(TOP)/$(NDLANGUAGE)/libs/LwIP/src/include/compat/posix/net \
			# -I $(TOP)/$(NDLANGUAGE)/libs/LwIP/src/include/compat/posix/sys \
			# -I $(TOP)/$(NDLANGUAGE)/libs/LwIP/src/include/compat/stdc \
			# -I $(TOP)/$(NDLANGUAGE)/libs/FreeRTOS/Source/portable/GCC/$(ARMA) \
			# -I $(TOP)/$(NDLANGUAGE)/libs/FreeRTOS/Source/ \
			# -I $(TOP)/$(NDLANGUAGE)/libs/FreeRTOS/Source/CMSIS_RTOS \
			# -I $(TOP)/$(NDLANGUAGE)/libs/FreeRTOS/Source/include \
			# -I $(TOP)/$(NDLANGUAGE)/libs/libscpi/inc \
			# -I $(TOP)/$(NDLANGUAGE)/libs/libscpi/src \
			-I $(APPFOLDER)/src

DEFINES := -D__$(MCU_FAMILY)=1 -D__$(MCU_GENUS)=1 -D$(MCU_GENUS_CAP)=1 $(NODATE_MOD_ENABLE)
FLAGS := $(INCLUDE) $(MCU_FLAGS) -ffunction-sections -fdata-sections -MMD -Os -g3 $(APP_FLAGS)
CFLAGS := $(FLAGS) $(DEFINES) -std=gnu11 $(APP_C_FLAGS)
CPPFLAGS := $(FLAGS) $(DEFINES) -std=gnu++11 -fno-threadsafe-statics -fno-rtti -fno-exceptions -fno-use-cxa-atexit $(APP_CPP_FLAGS)
LD_FLAGS := -T $(TOP)/linker/$(MCU_FAMILY)/$(MCU_LD) -Wl,-Map=$(APPFOLDER)/bin/$(OUTPUT).map,--cref \
			 --specs=nano.specs --specs=nosys.specs -Wl,--gc-sections -Wl,--print-memory-usage \
			  $(MCU_FLAGS)
LIBS :=  -lstdc++_nano -lgcc

CPPSOURCES := arch/stm32/$(NDLANGUAGE)/boards/$(BOARD)/board_definition.cpp \
				$(wildcard arch/stm32/$(NDLANGUAGE)/core/src/*.cpp) \
				$(wildcard arch/stm32/$(NDLANGUAGE)/libs/bme280/*.cpp) \
				$(APP_CPP_FILES)
			
CSOURCES := $(wildcard arch/stm32/$(NDLANGUAGE)/core/src/$(MCU_FAMILY)/*.c) \
			# $(wildcard arch/stm32/$(NDLANGUAGE)/libs/LwIP/src/netif/ppp/*.c) \
			# $(wildcard arch/stm32/$(NDLANGUAGE)/libs/LwIP/src/netif/*.c) \
			# $(wildcard arch/stm32/$(NDLANGUAGE)/libs/LwIP/src/api/*.c) \
			# $(wildcard arch/stm32/$(NDLANGUAGE)/libs/LwIP/src/core/ipv4/*.c) \
			# $(wildcard arch/stm32/$(NDLANGUAGE)/libs/LwIP/src/core/ipv6/*.c) \
			# $(wildcard arch/stm32/$(NDLANGUAGE)/libs/LwIP/src/core/*.c) \
			# $(wildcard arch/stm32/$(NDLANGUAGE)/libs/LwIP/src/apps/mqtt/*.c) \
			# $(wildcard arch/stm32/$(NDLANGUAGE)/libs/LwIP/src/apps/http/*.c) \
			# $(wildcard arch/stm32/$(NDLANGUAGE)/libs/LwIP/src/system/OS/*.c) \
			# $(TOP)/$(NDLANGUAGE)/libs/FreeRTOS/Source/portable/MemMang/heap_4.c \
			# $(TOP)/$(NDLANGUAGE)/libs/FreeRTOS/Source/portable/GCC/$(ARMA)/port.c \
			# $(TOP)/$(NDLANGUAGE)/libs/FreeRTOS/Source/CMSIS_RTOS/cmsis_os.c \
			# $(TOP)/$(NDLANGUAGE)/libs/FreeRTOS/Source/queue.c \
			# $(TOP)/$(NDLANGUAGE)/libs/FreeRTOS/Source/tasks.c \
			# $(TOP)/$(NDLANGUAGE)/libs/FreeRTOS/Source/croutine.c \
			# $(TOP)/$(NDLANGUAGE)/libs/FreeRTOS/Source/timers.c \
			# $(TOP)/$(NDLANGUAGE)/libs/FreeRTOS/Source/list.c \
			$(APP_C_FILES)
			
SSOURCES := arch/stm32/asm/$(MCU_FAMILY)/startup_$(MCU_GENUS).S
CPPOBJECTS := $(addprefix $(APPFOLDER)/obj/,$(notdir) $(CPPSOURCES:.cpp=.o))
COBJECTS := $(addprefix $(APPFOLDER)/obj/,$(notdir) $(CSOURCES:.c=.o))
SOBJECTS := $(addprefix $(APPFOLDER)/obj/,$(notdir) $(SSOURCES:.S=.o))

all: makedir $(APPFOLDER)/bin/$(OUTPUT).elf $(APPFOLDER)/bin/$(OUTPUT).bin

makedir:
	$(MAKEDIR) $(APPFOLDER)/obj/src
	$(MAKEDIR) $(APPFOLDER)/obj/arch/stm32/asm/$(MCU_FAMILY)
	$(MAKEDIR) $(APPFOLDER)/obj/arch/stm32/$(NDLANGUAGE)/boards/$(BOARD)
	$(MAKEDIR) $(APPFOLDER)/obj/arch/stm32/$(NDLANGUAGE)/core/src/$(MCU_FAMILY)
	$(MAKEDIR) $(APPFOLDER)/obj/arch/stm32/$(NDLANGUAGE)/libs/bme280
	# $(MAKEDIR) $(APPFOLDER)/obj/arch/stm32/$(NDLANGUAGE)/libs/LwIP/src/netif/ppp
	# $(MAKEDIR) $(APPFOLDER)/obj/arch/stm32/$(NDLANGUAGE)/libs/LwIP/src/api
	# $(MAKEDIR) $(APPFOLDER)/obj/arch/stm32/$(NDLANGUAGE)/libs/LwIP/src/core/ipv4
	# $(MAKEDIR) $(APPFOLDER)/obj/arch/stm32/$(NDLANGUAGE)/libs/LwIP/src/core/ipv6
	# $(MAKEDIR) $(APPFOLDER)/obj/arch/stm32/$(NDLANGUAGE)/libs/LwIP/src/apps/mqtt
	# $(MAKEDIR) $(APPFOLDER)/obj/arch/stm32/$(NDLANGUAGE)/libs/LwIP/src/apps/http
	# $(MAKEDIR) $(APPFOLDER)/obj/arch/stm32/$(NDLANGUAGE)/libs/LwIP/src/system/OS
	# $(MAKEDIR) $(APPFOLDER)/obj/arch/stm32/$(NDLANGUAGE)/libs/FreeRTOS/Source/portable/MemMang
	# $(MAKEDIR) $(APPFOLDER)/obj/arch/stm32/$(NDLANGUAGE)/libs/FreeRTOS/Source/portable/GCC/$(ARMA)
	# $(MAKEDIR) $(APPFOLDER)/obj/arch/stm32/$(NDLANGUAGE)/libs/FreeRTOS/Source/CMSIS_RTOS
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

	