/*
	ethernet.h - Header for the Ethernet class.
	
	Revision 0
	
	Features:
			- 
			
	Notes:
			- 
			
	2021/02/17, Maya Posch
*/

#ifndef ETHERNET_H
#define ETHERNET_H

#include <common.h>
#include <gpio.h>

#define ETH_SPEED_10M        ((uint32_t)0x00000000U)
#define ETH_SPEED_100M       ((uint32_t)0x00004000U)

#define ETH_MODE_FULLDUPLEX       ((uint32_t)0x00000800U)
#define ETH_MODE_HALFDUPLEX       ((uint32_t)0x00000000U)


struct Ethernet_RMII {
	GpioPinDef	REF_CLK;
	GpioPinDef	TXD0;
	GpioPinDef	TXD1;
	GpioPinDef	TX_EN;
	GpioPinDef	RXD0;
	GpioPinDef	RXD1;
	GpioPinDef	CRS_DV;
	GpioPinDef	RX_ER;
	GpioPinDef	MDIO;
	GpioPinDef	MDC;
	uint32_t autonegotiate = true;
	uint32_t speed;
	uint32_t duplexMode;
	bool hardwareChecksum = true;
	bool interruptMode = true;
	uint8_t macAddress[6];
};


struct Ethernet_MII {
	GpioPinDef 	TX_CLK;	// Transmitter signals.
	GpioPinDef	TXD0;
	GpioPinDef	TXD1;
	GpioPinDef	TXD2;
	GpioPinDef	TXD3;
	GpioPinDef	TX_EN;
	GpioPinDef	TX_ER;
	GpioPinDef	RX_CLK;	// Receiver signals.
	GpioPinDef	RXD0;
	GpioPinDef	RXD1;
	GpioPinDef	RXD2;
	GpioPinDef	RXD3;
	GpioPinDef	RX_DV;
	GpioPinDef	RX_ER;
	GpioPinDef	CRS;
	GpioPinDef	COL;
	GpioPinDef	MDIO;	// Management signal.
	GpioPinDef	MDC;
	bool autonegotiate = true;
	uint32_t speed;
	uint32_t duplexMode;
	bool hardwareChecksum = true;
	bool interruptMode = true;
	uint8_t macAddress[6];
};


class Ethernet {
	//
	
public:
	static bool startEthernet(Ethernet_MII &ethDef);
	static bool startEthernet(Ethernet_RMII &ethDef);
	static bool dmaRxDescListInit();
	static bool dmaTxDescListInit();
};

#endif
