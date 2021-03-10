/*
	ethernet.cpp - Implementation of the Ethernet class.
	
	Revision 0
	
	Features:
			- 
			
	Notes:
			- 
			
	2021/02/17, Maya Posch
*/


#include <ethernet.h>

/* #include <rcc.h>
#include <gpio.h> */
#include <nodate.h>


#define ETH_RXPOLLING_MODE      ((uint32_t)0x00000000U)
#define ETH_RXINTERRUPT_MODE    ((uint32_t)0x00000001U)

#define ETH_CHECKSUM_BY_HARDWARE      ((uint32_t)0x00000000U)
#define ETH_CHECKSUM_BY_SOFTWARE      ((uint32_t)0x00000001U)


// --- WRITE PHY REGISTER ---
bool writePhyRegister(uint16_t reg, uint32_t value) {
	// TODO: check for busy status on ETH.
	
	uint32_t tmpreg = ETH->MACMIIAR;
	
	// Keep only the CSR Clock Range CR[2:0] bits value.
	tmpreg &= ~ETH_MACMIIAR_CR;
	
	// Prepare the MII address register value.
	tmpreg |= (((uint32_t) PHY_ADDRESS << 11) & ETH_MACMIIAR_PA);	// Set the PHY device address
	tmpreg |= (((uint32_t) reg << 6 ) & ETH_MACMIIAR_MR);			// Set the PHY register address
	tmpreg |= ETH_MACMIIAR_MW;										// Set the write mode
	tmpreg |= ETH_MACMIIAR_MB;										// Set the MII Busy bit
  
	// Write the value into the MII Data Register.
	ETH->MACMIIDR = (uint16_t) value;
  
	// Write the new value into the MII Address register.
	ETH->MACMIIAR = tmpreg;
	
	// Check for the Busy flag.
	while((tmpreg & ETH_MACMIIAR_MB) == ETH_MACMIIAR_MB) { }
	
	// TODO: set state to ready.
	
	return true;
}


// --- READ PHY REGISTER ---
bool readPhyRegister(uint16_t reg, uint32_t &value) {
	// TODO: check for busy status on ETH.
	
	uint32_t tmpreg = ETH->MACMIIAR;
	
	// Keep only the CSR Clock Range CR[2:0] bits value.
	tmpreg &= ~ETH_MACMIIAR_CR;
	
	// Prepare the MII address register value.
	tmpreg |= (((uint32_t) PHY_ADDRESS << 11) & ETH_MACMIIAR_PA);	// Set the PHY device address
	tmpreg |= (((uint32_t) reg << 6 ) & ETH_MACMIIAR_MR);			// Set the PHY register address
	tmpreg &= ~ETH_MACMIIAR_MW;										// Set the read mode
	tmpreg |= ETH_MACMIIAR_MB;										// Set the MII Busy bit
  
	// Write the new value into the MII Address register.
	ETH->MACMIIAR = tmpreg;
	
	// Check for the Busy flag.
	while((tmpreg & ETH_MACMIIAR_MB) == ETH_MACMIIAR_MB) { }
	
	// TODO: set state to ready.
	
	return true;
}


bool macDMAConfig() {
	//
	
	return true;
}


// --- START ETHERNET ---
bool Ethernet::startEthernet(Ethernet_MII &ethDef) {
	// TODO:
	
	return true;
}


// --- START ETHERNET ---
bool Ethernet::startEthernet(Ethernet_RMII &ethDef) {
	// Set up the pins.
#if defined __stm32f7
	// Port A: REF_CLK, MDIO, CRS_DV.
	Rcc::enablePort(RCC_PORT_A);
	GPIO::set_af(ethDef.REF_CLK.port, ethDef.REF_CLK.pin, ethDef.REF_CLK.af);
	GPIO::set_output_parameters(ethDef.REF_CLK.port, ethDef.REF_CLK.pin, GPIO_FLOATING,
								GPIO_PUSH_PULL, GPIO_HIGH);
	GPIO::set_af(ethDef.MDIO.port, ethDef.MDIO.pin, ethDef.MDIO.af);
	GPIO::set_output_parameters(ethDef.MDIO.port, ethDef.MDIO.pin, GPIO_FLOATING,
								GPIO_PUSH_PULL, GPIO_HIGH);
	GPIO::set_af(ethDef.CRS_DV.port, ethDef.CRS_DV.pin, ethDef.CRS_DV.af);
	GPIO::set_output_parameters(ethDef.CRS_DV.port, ethDef.CRS_DV.pin, GPIO_FLOATING,
								GPIO_PUSH_PULL, GPIO_HIGH);
								
	// Port B: TXD1.
	Rcc::enablePort(RCC_PORT_B);
	GPIO::set_af(ethDef.TXD1.port, ethDef.TXD1.pin, ethDef.TXD1.af);
	GPIO::set_output_parameters(ethDef.TXD1.port, ethDef.TXD1.pin, GPIO_FLOATING,
								GPIO_PUSH_PULL, GPIO_HIGH);
	
	// Port C: MDC, RXD0, RXD1.
	Rcc::enablePort(RCC_PORT_C);
	GPIO::set_af(ethDef.MDC.port, ethDef.MDC.pin, ethDef.MDC.af);
	GPIO::set_output_parameters(ethDef.MDC.port, ethDef.MDC.pin, GPIO_FLOATING,
								GPIO_PUSH_PULL, GPIO_HIGH);
	GPIO::set_af(ethDef.RXD0.port, ethDef.RXD0.pin, ethDef.RXD0.af);
	GPIO::set_output_parameters(ethDef.RXD0.port, ethDef.RXD0.pin, GPIO_FLOATING,
								GPIO_PUSH_PULL, GPIO_HIGH);
	GPIO::set_af(ethDef.RXD1.port, ethDef.RXD1.pin, ethDef.RXD1.af);
	GPIO::set_output_parameters(ethDef.RXD1.port, ethDef.RXD1.pin, GPIO_FLOATING,
								GPIO_PUSH_PULL, GPIO_HIGH);
								
	// Port G: RX_ER, TX_EN, TXD0.
	Rcc::enablePort(RCC_PORT_G);
	GPIO::set_af(ethDef.RX_ER.port, ethDef.RX_ER.pin, ethDef.RX_ER.af);
	GPIO::set_output_parameters(ethDef.RX_ER.port, ethDef.RX_ER.pin, GPIO_FLOATING,
								GPIO_PUSH_PULL, GPIO_HIGH);
	GPIO::set_af(ethDef.TX_EN.port, ethDef.TX_EN.pin, ethDef.TX_EN.af);
	GPIO::set_output_parameters(ethDef.TX_EN.port, ethDef.TX_EN.pin, GPIO_FLOATING,
								GPIO_PUSH_PULL, GPIO_HIGH);
	GPIO::set_af(ethDef.TXD0.port, ethDef.TXD0.pin, ethDef.TXD0.af);
	GPIO::set_output_parameters(ethDef.TXD0.port, ethDef.TXD0.pin, GPIO_FLOATING,
								GPIO_PUSH_PULL, GPIO_HIGH);
	
	// Enable Ethernet global interrupt.
	uint32_t prioritygroup = NVIC_GetPriorityGrouping();
	NVIC_SetPriority(ETH_IRQn, NVIC_EncodePriority(prioritygroup, 0x7, 0));
	NVIC_EnableIRQ(ETH_IRQn);

	// Enable ETH clock.
	if (!Rcc::enable(RCC_ETH)) {
		return false;
	}
	
	// Configure the ETH peripheral.
	// * Set RMII interface in SYSCFG.
	// * Reset ETH DMA.
	// * Initialise MAC.
	// * Initialise PHY.
	// * Configure DMA.
	if (!Rcc::enable(RCC_SYSCFGCOMP)) {
		return false;
	}
	
	SYSCFG->PMC &= ~(SYSCFG_PMC_MII_RMII_SEL);
	SYSCFG->PMC |= SYSCFG_PMC_MII_RMII_SEL;
	
	// Reset DMA.
	ETH->DMABMR |= ETH_DMABMR_SR;
	while ((ETH->DMABMR & ETH_DMABMR_SR) != (uint32_t) RESET) { }
	
	// >> Initialise MAC. <<
	// Get the ETHERNET MACMIIAR value
	uint32_t tempreg = ETH->MACMIIAR;
	// Clear CSR Clock Range CR[2:0] bits
	tempreg &= ~ETH_MACMIIAR_CR;
	
	uint32_t &hclk = SystemCoreClock;
	// Set CR bits depending on hclk value
	if ((hclk >= 20000000) && (hclk < 35000000)) {
		tempreg |= (uint32_t) ETH_MACMIIAR_CR_Div16;	// CSR Clock Range between 20-35 MHz
	}
	else if((hclk >= 35000000) && (hclk < 60000000)) {
		tempreg |= (uint32_t) ETH_MACMIIAR_CR_Div26;	// CSR Clock Range between 35-60 MHz
	}  
	else if((hclk >= 60000000) && (hclk < 100000000)) {
		tempreg |= (uint32_t) ETH_MACMIIAR_CR_Div42;	// CSR Clock Range between 60-100 MHz
	}  
	else if((hclk >= 100000000) && (hclk < 150000000)) {
		tempreg |= (uint32_t) ETH_MACMIIAR_CR_Div62;	// CSR Clock Range between 100-150 MHz
	}
	else { /* ((hclk >= 150000000) && (hclk <= 216000000)) */
		tempreg |= (uint32_t) ETH_MACMIIAR_CR_Div102;    // CSR Clock Range between 150-216 MHz
	}
  
	// Write to ETHERNET MAC MIIAR: Configure the ETHERNET CSR Clock Range
	ETH->MACMIIAR = (uint32_t) tempreg;
	
	// >> Initialise PHY <<
	// Reset PHY. Send command to the PHY.
	if (!writePhyRegister(PHY_BCR, PHY_RESET)) {
		return false;
	}
	
	// Wait for PHY_RESET_DELAY to ensure the PHY is ready.
	// TODO:
	
	// If auto-negotiation is enabled, wait for linked state. 
	uint32_t phyreg = 0;
	if (ethDef.autonegotiate) {
		do {
			readPhyRegister(PHY_BSR, phyreg);
		}
		while (((phyreg & PHY_LINKED_STATUS) != PHY_LINKED_STATUS));
		
		if (!writePhyRegister(PHY_BCR, PHY_AUTONEGOTIATION)) {
			return false;
		}
		
		// Wait for auto-negotiation to be completed.
		do {
			readPhyRegister(PHY_BSR, phyreg);
		}
		while (((phyreg & PHY_AUTONEGO_COMPLETE) != PHY_AUTONEGO_COMPLETE));
		
		// Read auto-negotiation result.
		if (!readPhyRegister(PHY_SR, phyreg)) {
			return false;
		}
		
		// Set the negotiated duplex mode.
		if ((phyreg & PHY_DUPLEX_STATUS) != (uint32_t) RESET) {
			ethDef.duplexMode = ETH_MODE_FULLDUPLEX;
		}
		else {
			ethDef.duplexMode = ETH_MODE_HALFDUPLEX;
		}
		
		// Set the speed negotiated.
		uint32_t speed = 0;
		if ((phyreg & PHY_SPEED_STATUS) == PHY_SPEED_STATUS) {
			ethDef.speed = ETH_SPEED_10M;
		}
		else {
			ethDef.speed = ETH_SPEED_100M;
		}
	}
	else {
		// Auto-negotiation is disabled. Set parameters manually.
		if (!writePhyRegister(PHY_BCR, ((uint16_t) (ethDef.duplexMode >> 3) | 
										(uint16_t) (ethDef.speed >> 1)))) {
			return false;
		}
		
		// Delay by PHY_CONFIG_DELAY.
		// TODO:
	}
	
	// Configure the DMA for the MAC.
	macDMAConfig();
	
#endif
	
	return true;
}

