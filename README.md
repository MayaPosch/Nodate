# Nodate (野点) #

Restructuring of the Arduino AVR core in order to allow it to be used as a generic C++ framework while still remaining compatible with Arduino libraries.

This initial version has been tested with the following boards:

* Arduino Duemilanove (ATMega328P)
* Arduino Mega (ATMega1280, ATMega2560)

## Usage ##

Nodate can be copied to any location, with the environment variable `NODATE_HOME` set to this location so that it can be found later on.

Take a look at the Blinky example in the `examples/` folder to get an idea of how Nodate is meant to be used. Essentially one can use Nodate as one would use Arduino, using the same API calls. Main differences include having to handle one's own includes, such as:

* <wiring.h> - For GPIO.
* <HardwareSerial.h> - For UART
* <SPI.h> - For SPI.


After adapting the example's Makefile for one's own use, simply execute `make` and a `bin/` folder will be created in the project's root folder containing both the ELF binary and the .hex file that is to be flashed to the device.

Execute `make flash COM_PORT=<port>` to flash this file to the MCU's EEPROM/Flash. The port is for example **COM4** on Windows, and **/dev/ttyUSB#** on Linux, depending on how the system is connected to the board or programming device. 

## Note ##

This is a project in its early stages. While so far UART, GPIO and SPI have been successfully used on a limited number of configurations, this is no guarantee of success on other configurations. 

Feedback and PRs would be most kind and helpful :)

## Required Packages ##

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
