# Makefile for STM32 C++ tests.


INCLUDES := -I. -I ../core/include
SOURCE_ROOT := ../core/src
#FLAGS := -std=c++11 -g3 -DSTM32F4=1 -D__stm32f4
FLAGS := -std=c++11 -g3 -DSTM32F0=1 -D__stm32f0
#FLAGS := -std=c++11 -g3 -DSTM32F1=1 -D__stm32f1


all: mkdir rcc_test interrupts_test gpio_test eventful uart_test

mkdir:
	mkdir -p bin
	mkdir -p obj

rcc_test: rcc_test.cpp
	g++ -o bin/rcc_test rcc_test.cpp common.cpp $(SOURCE_ROOT)/rcc.cpp  $(FLAGS) $(INCLUDES)
	
interrupts_test:
	g++ -o bin/interrupts_test interrupts_test.cpp common.cpp $(SOURCE_ROOT)/rcc.cpp $(SOURCE_ROOT)/interrupts.cpp  $(FLAGS) $(INCLUDES)
	
gpio_test:
	g++ -o bin/gpio_test gpio_test.cpp common.cpp $(SOURCE_ROOT)/rcc.cpp $(SOURCE_ROOT)/gpio.cpp  $(FLAGS) $(INCLUDES)
	
eventful:
	g++ -o bin/eventful eventful.cpp common.cpp $(SOURCE_ROOT)/rcc.cpp \
												$(SOURCE_ROOT)/gpio.cpp \
												$(SOURCE_ROOT)/interrupts.cpp \
												$(FLAGS) $(INCLUDES)
	
uart_test:
	g++ -o bin/uart_test uart_test.cpp common.cpp $(SOURCE_ROOT)/rcc.cpp $(SOURCE_ROOT)/gpio.cpp $(SOURCE_ROOT)/usart.cpp  $(FLAGS) $(INCLUDES)
