# Makefile for 'Blinky' example Nodate project for RP2040.
#

# Architecture must be set.
# E.g.: AVR, SAM, ESP8266.
ARCH ?= rp

# Target programming language (Ada, C++)
NDLANGUAGE ?= cpp

# One can use the board preset.
BOARD ?= rpi_pico

# Set the MCU and programmer types.
#
# MCU
#MCU ?= rp2040

# Set the name of the output (ELF & Hex) file.
OUTPUT := blinky


# Add files to include for compilation to these variables.
APP_CPP_FILES = $(wildcard src/*.cpp)
APP_C_FILES = $(wildcard src/*.c)


# Set Nodate modules to enable.
# Available modules:
# i2c, gpio, interrupts, timer, usart
NODATE_MODULES = gpio

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
