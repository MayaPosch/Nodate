# Generates the recorder files.

INCLUDES := -I../core/include/

all: makedir stm32f042x6

makedir:
	mkdir -p out
	
stm32f042x6:
	#gcc -E -o out/stm32f042x6.cpp $(INCLUDES) -D__stm32f0 -DSTM32F042x6 stm32f042x6.cpp
	g++ -c -fdump-ada-spec $(INCLUDES) -D__stm32f0 -DSTM32F042x6 stm32.h
