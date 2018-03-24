# Makefile for example Nodate project for AVR.
#

# Set the MCU and programmer types.
MCU ?= atmega2560
PROGRAMMER ?= wiring

# Pin variant. Set 'standard' for ATMega328P, 'mega' for ATMega2560.
VARIANT ?= mega

# Set the name of the output (ELF & Hex) file.
OUTPUT := blinky


# Add files to include for compilation to these variables.
APP_CPP_FILES = $(wildcard src/*.cpp)
APP_C_FILES = $(wildcard src/*.c)


#
# --- End of user-editable variables --- #
#

# Nodate includes. Requires that the NODATE_HOME environment variable has been set.
APPFOLDER=$(CURDIR)
export

include $(NODATE_HOME)/mcu/$(MCU)
include $(NODATE_HOME)/programmer/$(PROGRAMMER)

all:
	$(MAKE) -C $(NODATE_HOME)
	
flash:
	$(MAKE) -C $(NODATE_HOME) flash
	
clean:
	$(MAKE) -C $(NODATE_HOME) clean
