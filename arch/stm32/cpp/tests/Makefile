# Makefile for STM32 C++ tests.


INCLUDES := -I. -I ../core/include
SOURCE_ROOT := ../core/src
FLAGS := -std=c++11 -g3


all: rcc_test interrupts_test

rcc_test: rcc_test.cpp
	g++ -o rcc_test rcc_test.cpp common.cpp $(SOURCE_ROOT)/rcc.cpp  $(FLAGS) $(INCLUDES)
	
interrupts_test:
	g++ -o interrupts_test interrupts_test.cpp common.cpp $(SOURCE_ROOT)/rcc.cpp $(SOURCE_ROOT)/interrupts.cpp  $(FLAGS) $(INCLUDES)
