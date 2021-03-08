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
};


class Ethernet {
	//
	
public:
	static bool startEthernet(Ethernet_RMII ethDef);
	static bool startEthernet(Ethernet_MII ethDef);
};

#endif
