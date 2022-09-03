// ST7735 TFT LC display example for the Nodate framework

#include <nodate.h>
#include <printf.h>
#include <st7735/st7735.h>

//#include <ssd1306/splash.h>	// Demo logo data (splash screen).


void uartCallback(char ch) {
	// Copy character into send buffer.
	USART::sendUart(USART_2, ch);
}


/* void i2cCallback(uint8_t byte) {
	// Unused.
} */


int main() {
	// 1. Set up UART
	USART_def& ud = boardUSARTs[1];
	//usartTarget = ud.usart;
	USART::startUart(ud.usart, ud.tx[0].port, ud.tx[0].pin, ud.tx[0].af, 
								ud.rx[0].port, ud.rx[0].pin, ud.rx[0].af, 115200, uartCallback);
	
	// Set up stdout.
	IO::setStdOutTarget(USART_2);
	
	// Start SysTick.
	McuCore::initSysTick();
	
	printf("Starting SPI ST7735 OLED example...\n");
	
	// This example shows a demo sequence on an attached ST7735-based LCD display.
	// Uses:
	// * GPIO pin for the first LED on the board, if any, to indicate when setup is complete.
	// * SPI to connect to the display.
	// * ST7735 library to communicate with the display.
	
	// 1. Set up LED.
	uint8_t 	led_pin;
	GPIO_ports 	led_port;
	bool		led_enable = true;
	if (boardLEDs_count > 0) {
		led_pin = boardLEDs[0].pin.pin;
		led_port = boardLEDs[0].pin.port;
	}
	else {
		led_enable = false;
	}
	
	// Set the pin mode on the LED pin and turn it off.
	GPIO::set_output(led_port, led_pin, GPIO_PULL_UP);
	GPIO::write(led_port, led_pin, GPIO_LEVEL_LOW);
	
	// 2. Set up SPI.
	// Note: this targets SPI 1 on the STM32F411CE MCU
	SPI_pins spins;
	spins.miso = { GPIO_PORT_A, 6, 5 };
	spins.mosi = { GPIO_PORT_A, 7, 5 };
	spins.sclk = { GPIO_PORT_A, 5, 5 };
	spins.nss = { GPIO_PORT_A, 4, 5 };
	if (!SPI::startSPIMaster(SPI_1, spins)) {
		// Handle error.
		printf("SPI master init error.\n");
		while (1) { }
	}
	
	// Start I2C in master mode.
	// Use Fast Mode. The SSD1306 supports this and slower speeds.
	/* if (!I2C::startMaster(I2C_1, I2C_MODE_FM, i2cCallback)) {
		printf("I2C master start error.\n");
		while (1) { }
	} */
	
	// 3. Set up ST7735 library instance.
	GpioPinDef reset 	= { GPIO_PORT_A, 1, 0 };
	GpioPinDef cs 		= { GPIO_PORT_A, 2, 0 };
	GpioPinDef dc 		= { GPIO_PORT_A, 3, 0 };
	ST7735 display(SPI_1, reset, cs, dc);
	
	printf("Created display instance.\n");
	
	// Check connected.
	/* if (!display.isReady()) {
		printf("Instance not ready.\n");
		while(1) { }
	} */
	
	// Initialise display.
	uint32_t width = 128;
	uint32_t height = 160;
	if (!display.init(width, height)) {
		// Handle error.
		printf("Display init error.\n");
		while (1) { }
	}
	
	// Set orientation to 180 rotated.
	display.setOrientation(ST7735_ORIENTATION_180);
	
	// Fill screen with black.
	display.setColor(0, 0, 0);
	display.fillScreen();
	display.display();
	
	// Set background colour to black.
	//display.setBackground(0, 0, 0);
	
	// Set font.
	//display.setFont(ter_u24b);
	
	// Draw text.
	//display.drawText(4, 33, "Hi World!");
	
	// Set splash screen for the demo.
	/* display.clearDisplay();
	display.drawBitmap((width - splash1_width) / 2, (height - splash1_height) / 2,
				splash1_data, splash1_width, splash1_height, white); */
	
	// Display the buffer contents.
	/* if (!display.display()) {
		printf("Displaying image failed.\n");
		while (1) { }
	} */
	
	// Light up LED.
	if (led_enable) {
		GPIO::write(led_port, led_pin, GPIO_LEVEL_HIGH);
	}
	
	// Clear the buffer
	//display.clearDisplay();
	
	//printf("Display on/off.\n");
	
	// Light up whole display.
	//display.displayFullOn();
	//Timer::delay(2000);
	//display.displayFullOn(false);
	
	Timer::delay(5000);
	
	// Set screen to white.
	display.setColor(255, 255, 255);
	display.fillScreen();
	display.display();
	
	Timer::delay(5000);
	
	// Set screen to grey.
	display.setColor(128, 128, 128);
	display.fillScreen();
	display.display();
	
	//printf("Pixel@20x20\n");

	// Draw a single lit pixel at 10x10.
	//display.drawPixel(20, 20, white);
	//display.display();
	
	//Timer::delay(1000);
	
	//printf("Pixel@10x10\n");

	// Draw a single lit pixel at 10x10.
	//display.drawPixel(10, 10, white);
	//display.display();
	
	//Timer::delay(1000);
	
	// Clear the buffer
	//display.clearDisplay();
	
	// Display something useful.
	//char* hello = "Hello Nodate!";
	//display.writeString(hello, Font_11x18, white);
	
	while (1) {
		//
	}
	
	return 0;
}
