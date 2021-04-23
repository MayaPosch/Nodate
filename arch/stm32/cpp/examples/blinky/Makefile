# Makefile for 'Blinky' example Nodate project for STM32.
#

# Architecture must be set.
# E.g.: STM32, AVR, SAM, ESP8266.
ARCH ?= stm32

# Target programming language (Ada, C++)
NDLANGUAGE ?= cpp

# One can use the board preset.
BOARD ?= nucleo-f042k6
#BOARD ?= blue_pill
#BOARD ?= black_pill_f411
#BOARD ?= blue_pill_wch
#BOARD ?= stm32f4-discovery
#BOARD ?= nucleo-f746zg

# Set the MCU and programmer types.
#
# MCU
#MCU ?= stm32f042k6t

# Set the name of the output (ELF & Hex) file.
OUTPUT := blinky


# Add files to include for compilation to these variables.
APP_CPP_FILES = $(wildcard src/*.cpp)
APP_C_FILES = $(wildcard src/*.c)


# Set Nodate modules to enable.
# Available modules:
# ethernet, i2c, gpio, interrupts, timer, usart
NODATE_MODULES = gpio timer

# Set library modules to enable.
# library name matches the folder name in libs/. E.g. freertos, LwIP, libscpi, bme280
NODATE_LIBRARIES = 


#
# --- End of user-editable variables --- #
#

# Nodate includes. Requires that the NODATE_HOME environment variable has been set.
APPFOLDER=$(CURDIR)
export

all:
	$(MAKE) -C $(NODATE_HOME)
	
flash:
	$(MAKE) -C $(NODATE_HOME) flash
	
clean:
	$(MAKE) -C $(NODATE_HOME) clean
