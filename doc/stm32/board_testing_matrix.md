# Nodate Test Matrix #

Test status for each supported board.

&nbsp; | MCU | Board name | GPIO | USART | Timer | Interrupts | I2C | SPI | I2S | Ethernet | ADC | DAC
----|--------|-----|---|---|---|---|---|---|---|---|---|---|
**F0** | &nbsp; | &nbsp; | &nbsp; | &nbsp; | &nbsp; | &nbsp; | &nbsp; | &nbsp; | &nbsp; | &nbsp; | &nbsp;
&nbsp; | STM32F042K6T  |nucleo-f042k6 | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | &nbsp; | &nbsp; | n/a | :accept: | &nbsp;
&nbsp; | STM32F051R8T  | stm32f0-discovery | :heavy_check_mark: | :question: | :question: | :question: | :question: | | | n/a
&nbsp; | STM32F072C8Tx  | otter_pill| :question: | :question: | :question: | :question: | :question: | | | n/a
**F1** | &nbsp; | &nbsp; | &nbsp;
&nbsp; | STM32F103C8   | blue_pill | :heavy_check_mark: | | | | | | | n/a
&nbsp; | CH32F103C8   | blue_pill_wch | :heavy_check_mark: | | | | | | | n/a
&nbsp; | STM32F103CB  | maple_mini | :heavy_check_mark: | | | | | | | n/a
**F4** | &nbsp; | &nbsp; | &nbsp;
&nbsp; | STM32F407VGT  | stm32f4-discovery | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | | | | :accept:
&nbsp; | STM32F411CE | black_pill_f411 | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | :question: | | | | n/a
**L4** | &nbsp; | &nbsp;
&nbsp; | STM32L433CCT | Fox Pill | 
&nbsp; | STM32L496ZG | Nucleo-L496ZG-P | 
**F7** | &nbsp; | &nbsp; | &nbsp;
&nbsp; | STM32F746ZG  | nucleo-f746zg | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | | | | :accept:


## Legend: ##

:heavy_check_mark: &nbsp; &nbsp; &nbsp;- Module usable, though not all features may be implemented yet.

:accept: &nbsp; &nbsp; &nbsp;- Currently being targeted for development & testing.

n/a &nbsp; &nbsp;- The feature cannot be supported by this board.

:question: &nbsp; &nbsp; - The feature may work, but untested.