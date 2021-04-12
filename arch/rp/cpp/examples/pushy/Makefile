# Makefile for 'Pushy' example Nodate project for STM32.
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
OUTPUT := pushy


# Add files to include for compilation to these variables.
APP_CPP_FILES = $(wildcard src/*.cpp)
APP_C_FILES = $(wildcard src/*.c)


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
