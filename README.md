# Nodate (野点) #

A light-weight framework for STM32 and other architectures written in C++ and Ada.

## Overview ##

* The STM32 branch is currently under heavy development, aiming to support all major STM32 MCUs and features.
* The SAM branch is considered a future development target once the STM32 branch stabilises.
* The AVR branch is still a modified Arduino AVR core, supporting C++ and compatible with Arduino libraries. The future of this branch is currently undecided.
* The ESP8266 branch is experimental and may be removed in the future.

## STM32 ##

**Supported boards:**

&nbsp; | MCU |Boards
----|--------|-----
**F0** | &nbsp; | &nbsp;
&nbsp; | STM32F042K6T | [Nucleo-F042K6](https://www.st.com/en/evaluation-tools/nucleo-f042k6.html)
&nbsp; | STM32F051R8T | [STM32F0-Discovery](https://www.st.com/en/evaluation-tools/stm32f0discovery.html)
&nbsp; | STM32F072C8Tx | ['Otter Pill'](https://github.com/Jan--Henrik/OtterPill)
**F1** | &nbsp; | &nbsp;
&nbsp; | STM32F103C8  | ['Blue Pill'](https://stm32-base.org/boards/STM32F103C8T6-Blue-Pill.html)
**F4** | &nbsp; | &nbsp;
&nbsp; | STM32F407VGT | [STM32F4-Discovery](https://www.st.com/en/evaluation-tools/stm32f4discovery.html)
**F7** | &nbsp; | &nbsp;
&nbsp; | STM32F746ZG | [Nucleo-F746ZG](https://www.st.com/en/evaluation-tools/nucleo-f746zg.html)



**Usage**

Nodate can be installed in any location, with the only requirement being that the environment variable `NODATE_HOME` is set to the root of this location.

Examples on how to use Nodate can be found in the `examples/stm32` folder. The basic structure of a Nodate project consists out of a Makefile and a source folder. This Makefile defines the project properties and target architecture, board or processor. E.g. the user-editable part of the 'Pushy' example's Makefile'

	ARCH ?= stm32
	
	# Target programming language (Ada, C++)
	NDLANGUAGE ?= cpp
	
	# Board preset.
	BOARD ?= nucleo-f042k6
	
	# Set the name of the output (ELF & Hex) file.
	OUTPUT := pushy	
	
	# Add files to include for compilation to these variables.
	APP_CPP_FILES = $(wildcard src/*.cpp)
	APP_C_FILES = $(wildcard src/*.c)

When running `make` in the folder with the project Makefile, the project's `.map`, `.elf` and `.bin` files will be written to the `/bin/` sub-folder. Use `make clean` to remove any build files.

In order to **flash** the target board, ensure that **OpenOCD** is installed, then run `make flash`.


**Dependencies**

Nodate-STM32 requires `make` and the `arm-none-eabi` GCC toolchain to be installed for compilation, and `OpenOCD` for flashing boards.

For Ada, use the STM32 toolchain from AdaCore.

**Implemented features**

The following functionality has been implemented on the C++ side:

* RCC.
* GPIO (digital & AF).
* USART (basic UART with settable baud rate).
* SysTick (millisecond-accurate delay function).
* IO: set stdout to e.g. a UART.

In progress:

* U(S)ART with DMA.
* I2S.
* I2C.
* SPI.
* SDIO (with FatFS).


## AVR & Others ##

The current version has been tested with the following boards:

* Arduino Duemilanove (ATmega328p)
* Arduino Mega (ATmega1280, ATmega2560)
* Arduino Uno (ATmega328p)

**Usage**

Nodate can be copied to any location, with the environment variable `NODATE_HOME` set to this location so that it can be found later on.

Take a look at the Blinky example in the `examples/` folder to get an idea of how Nodate is meant to be used. Essentially one can use Nodate as one would use Arduino, using the same API calls. Main differences include having to handle one's own includes, such as:

* <wiring.h> - For GPIO.
* <HardwareSerial.h> - For UART
* <SPI.h> - For SPI.
* <Wire.h> - For I2C.


After adapting the example's Makefile for one's own use, simply execute `make` and a `bin/` folder will be created in the project's root folder containing both the ELF binary and the .hex file that is to be flashed to the device.

Execute `make flash COM_PORT=<port>` to flash this file to the MCU's EEPROM/Flash. The port is for example **COM4** on Windows, and **/dev/ttyUSB#** on Linux, depending on how the system is connected to the board or programming device. 

**Note**

This is a project in its early stages. While so far UART, GPIO and SPI have been successfully used on a limited number of configurations, this is no guarantee of success on other configurations. 

Feedback and PRs would be most kind and helpful :)

**Required Packages**

### Debian ###

Of course, `make` is needed.

#### avr ####

To compile for AVR on Debian, install the following packages:
 * `gcc-avr`
 * `avr-libc`

#### sam (Atmel ARM) ####

To compile for sam on Arch Linux, install the following packages:
 * `gcc-arm-none-eabi`

### Arch Linux  ###

Of course, `make` is needed.

#### avr ####

To compile for AVR on Arch Linux, install the following packages:
 * `gcc-avr`
 * `avr-libc`

#### esp8266 ###

To compile for esp8266 on Arch Linux, install the following packages:
 * `esp-open-sdk` (from AUR, include /opt/esp-open-sdk/xtensa-lx106-elf/bin into PATH)

#### sam (Atmel ARM) ####

To compile for sam on Arch Linux, install the following packages:
 * `gcc-arm-none-eabi-bin` (from AUR)
