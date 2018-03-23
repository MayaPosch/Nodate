# Makefile for example Nodate project for AVR.
#

# Set the MCU and programmer types.
MCU ?= atmega2560
PROGRAMMER ?= arduino

# Set the name of the output (ELF & Hex) file.
OUTPUT := blinky


# Add files to include for compilation to these variables.
APP_CPP_FILES = $(wildcard src/*.cpp)
APP_C_FILES = $(wildcard src/*.c)


#
# --- End of user-editable variables --- #
#

# Nodate includes. Requires that the NODATE_HOME environment variable has been set.
include $(NODATE_HOME)/mcu/$(MCU)
include $(NODATE_HOME)/programmer/$(PROGRAMMER)
APPFOLDER=$(CURDIR)
export

all:
	$(MAKE) -C $(NODATE_HOME)
	
flash:
	$(MAKE) -C $(NODATE_HOME) flash
	
clean:
	$(MAKE) -C $(NODATE_HOME) clean
