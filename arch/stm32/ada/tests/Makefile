# Makefile for STM32 Ada tests.

CPP 		:= g++
GNATMAKE 	:= gnatmake
GNATBIND	:= gnatbind
GNATLINK	:= gnatlink
MAKEDIR 	:= mkdir -p
RM 			:= rm -f

BIN_OUTPUT 	:= rcc_test
ADAFLAGS 	:= -aI../core/spec -aI../core/body -aI../core/spec/stm32f0 -aI../core/body/stm32f0 -D obj/

CPP_ROOT := ../../cpp
INCLUDES := -I. -I $(CPP_ROOT)/tests
CPPFLAGS := -std=c++11 -g3 -DSTM32F0=1


all: mkdir rcc_test interrupts_test gpio_test eventful

mkdir:
	mkdir -p bin
	mkdir -p obj

rcc_test:
	$(GNATMAKE) $(ADAFLAGS) -c rcc_test
	$(CPP) -c -o obj/stm32.o $(CPP_ROOT)/recorders/stm32.cpp $(CPPFLAGS) $(INCLUDES)
	$(CPP) -c -o obj/common.o $(CPP_ROOT)/tests/common.cpp $(CPPFLAGS) $(INCLUDES)
	$(GNATBIND) -n obj/rcc_test
	$(GNATLINK) obj/rcc_test -o bin/rcc_test --LINK=g++ -D obj/ obj/common.o
	
interrupts_test:
	#g++ -o bin/interrupts_test interrupts_test.cpp common.cpp $(SOURCE_ROOT)/rcc.cpp $(SOURCE_ROOT)/interrupts.cpp  $(FLAGS) $(INCLUDES)
	
gpio_test:
	#g++ -o bin/gpio_test gpio_test.cpp common.cpp $(SOURCE_ROOT)/rcc.cpp $(SOURCE_ROOT)/gpio.cpp  $(FLAGS) $(INCLUDES)
	
eventful:
	#g++ -o bin/eventful eventful.cpp common.cpp $(SOURCE_ROOT)/rcc.cpp \
												# $(SOURCE_ROOT)/gpio.cpp \
												# $(SOURCE_ROOT)/interrupts.cpp \
												# $(FLAGS) $(INCLUDES)
