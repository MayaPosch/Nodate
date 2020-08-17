# Makefile for STM32 C++ tests.


INCLUDES := -I. -I ../core/include
SOURCE_ROOT := ../core/src
FLAGS := -std=c++11 -g3


all: mkdir rcc_test interrupts_test gpio_test

mkdir:
	mkdir -p bin
	mkdir -p obj

rcc_test: rcc_test.cpp
	g++ -o bin/rcc_test rcc_test.cpp common.cpp $(SOURCE_ROOT)/rcc.cpp  $(FLAGS) $(INCLUDES)
	
interrupts_test:
	g++ -o bin/interrupts_test interrupts_test.cpp common.cpp $(SOURCE_ROOT)/rcc.cpp $(SOURCE_ROOT)/interrupts.cpp  $(FLAGS) $(INCLUDES)
	
gpio_test:
	g++ -o bin/gpio_test gpio_test.cpp common.cpp $(SOURCE_ROOT)/rcc.cpp $(SOURCE_ROOT)/gpio.cpp  $(FLAGS) $(INCLUDES)
