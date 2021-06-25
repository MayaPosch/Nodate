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


#include <ethernet_def.h>

// Configure each Ethernet driver receive buffer to fit the Max size Ethernet packet.
#ifndef ETH_RX_BUF_SIZE
 #define ETH_RX_BUF_SIZE         ETH_MAX_PACKET_SIZE 
#endif

// 5 Ethernet driver receive buffers are used in a chained linked list.
#ifndef ETH_RXBUFNB
 #define ETH_RXBUFNB             ((uint32_t) 4U)     //  5 Rx buffers of size ETH_RX_BUF_SIZE
#endif


// Configure each Ethernet driver transmit buffer to fit the Max size Ethernet packet.
#ifndef ETH_TX_BUF_SIZE 
 #define ETH_TX_BUF_SIZE         ETH_MAX_PACKET_SIZE
#endif

// 5 Ethernet driver transmit buffers are used in a chained linked list.
#ifndef ETH_TXBUFNB
 #define ETH_TXBUFNB             ((uint32_t) 4U)      // 5  Tx buffers of size ETH_TX_BUF_SIZE
#endif


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
	GpioPinDef	CRS_;
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
	static void dmaRxDescListInit(bool interruptMode);
	static void dmaTxDescListInit(bool interruptMode, bool hardwareChecksum);
	static bool setupMPU();
	static bool writePhyRegister(uint16_t reg, uint32_t value);
	static bool readPhyRegister(uint16_t reg, uint32_t &value);
	static bool macDmaConfig(uint32_t speed, uint32_t duplexMode, bool hardwareChecksum, 
								bool interruptMode, uint8_t macAddress[6]);
	
public:
	static bool startEthernet(Ethernet_MII &ethDef);
	static bool startEthernet(Ethernet_RMII &ethDef);
	
	static bool receiveData(uint8_t* buffer, uint32_t &length);
	static bool sendData(uint8_t* buffer, uint32_t len);
};

#endif
