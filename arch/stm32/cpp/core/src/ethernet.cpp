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

#include <nodate.h>

// Preprocessor definitions for this implementation.
#include <ethernet_def.h>

#include <cstring>

Timer timer;


// TODO: ETH interrupt for RX.
#ifdef __stm32f7
extern "C" {
	void ETH_IRQHandler();
	void ETH_WKUP_IRQHandler();
}

// TODO: implement.
void ETH_IRQHandler() {
	// TODO:
	/* Frame received */
 /* if (__HAL_ETH_DMA_GET_FLAG(heth, ETH_DMA_FLAG_R)) 
  {
#if (USE_HAL_ETH_REGISTER_CALLBACKS == 1)*/
    /*Call registered Receive complete callback*/
    /*heth->RxCpltCallback(heth);
#else*/
    /* Receive complete callback */
    /*HAL_ETH_RxCpltCallback(heth);
#endif /* USE_HAL_ETH_REGISTER_CALLBACKS */
    
     /* Clear the Eth DMA Rx IT pending bits */
    //__HAL_ETH_DMA_CLEAR_IT(heth, ETH_DMA_IT_R);

    // Set device state to Ready.

  //}
  /* Frame transmitted */
  /*else if (__HAL_ETH_DMA_GET_FLAG(heth, ETH_DMA_FLAG_T)) 
  {
#if (USE_HAL_ETH_REGISTER_CALLBACKS == 1)*/
    /*  Call resgistered Transfer complete callback*/
    /*heth->TxCpltCallback(heth);
#else*/
    /* Transfer complete callback */
   // HAL_ETH_TxCpltCallback(heth);
//#endif /* USE_HAL_ETH_REGISTER_CALLBACKS */
    
    /* Clear the Eth DMA Tx IT pending bits */
    //__HAL_ETH_DMA_CLEAR_IT(heth, ETH_DMA_IT_T);

    // Set device state to Ready.
  //}
  
  /* Clear the interrupt flags */
  //__HAL_ETH_DMA_CLEAR_IT(heth, ETH_DMA_IT_NIS);
  
  /* ETH DMA Error */
  /*if(__HAL_ETH_DMA_GET_FLAG(heth, ETH_DMA_FLAG_AIS))
  {
#if (USE_HAL_ETH_REGISTER_CALLBACKS == 1)
    heth->DMAErrorCallback(heth);
#else*/
    /* Ethernet Error callback */
   /* HAL_ETH_ErrorCallback(heth);
#endif /* USE_HAL_ETH_REGISTER_CALLBACKS */

    /* Clear the interrupt flags */
    //__HAL_ETH_DMA_CLEAR_IT(heth, ETH_DMA_FLAG_AIS);
  
    // Set device state to Ready.
}


void ETH_WKUP_IRQHandler() {
	// TODO: Implement along with wake-up feature.
}
#endif


// DMA Descriptors & TX/RX buffers.
struct ETH_DMADescTypeDef {
  __IO uint32_t   Status;           // DES 0 - Status
  uint32_t   ControlBufferSize;     // DES 1 - Control and Buffer1, Buffer2 lengths
  uint32_t   Buffer1Addr;           // DES 2 - Buffer1 address pointer
  uint32_t   Buffer2NextDescAddr;   // DES 3 - Buffer2 or next descriptor address pointer
  
  // Enhanced Ethernet DMA PTP Descriptors
  uint32_t   ExtendedStatus;        // DES 4 - Extended status for PTP receive descriptor
  uint32_t   Reserved1;             // DES 5 - Reserved
  uint32_t   TimeStampLow;          // DES 6 - Time Stamp Low value for transmit and receive
  uint32_t   TimeStampHigh;         // DES 7 - Time Stamp High value for transmit and receive
};

// Configure each Ethernet driver receive buffer to fit the Max size Ethernet packet.
#ifndef ETH_RX_BUF_SIZE
 #define ETH_RX_BUF_SIZE         ETH_MAX_PACKET_SIZE 
#endif

// 5 Ethernet driver receive buffers are used in a chained linked list.
#ifndef ETH_RXBUFNB
 #define ETH_RXBUFNB             ((uint32_t)5U)     //  5 Rx buffers of size ETH_RX_BUF_SIZE
#endif


// Configure each Ethernet driver transmit buffer to fit the Max size Ethernet packet.
#ifndef ETH_TX_BUF_SIZE 
 #define ETH_TX_BUF_SIZE         ETH_MAX_PACKET_SIZE
#endif

// 5 Ethernet driver transmit buffers are used in a chained linked list.
#ifndef ETH_TXBUFNB
 #define ETH_TXBUFNB             ((uint32_t)5U)      // 5  Tx buffers of size ETH_TX_BUF_SIZE
#endif


#if defined __stm32f7
ETH_DMADescTypeDef 	DMARxDscrTab 	= *((ETH_DMADescTypeDef*) SRAM2_BASE);
ETH_DMADescTypeDef 	DMATxDscrTab 	= *((ETH_DMADescTypeDef*) SRAM2_BASE + 0x80);
uint8_t 			Rx_Buff 		= *((uint8_t*) SRAM2_BASE + 0x100);
uint8_t 			Tx_Buff 		= *((uint8_t*) SRAM2_BASE + 0x17D0);

//*((ETH_DMADescTypeDef*) SRAM2_BASE) = ETH_DMADescTypeDef DMARxDscrTab[ETH_RXBUFNB];
//*((ETH_DMADescTypeDef*) SRAM2_BASE + 0x80) = ETH_DMADescTypeDef DMATxDscrTab[ETH_TXBUFNB];
//*((uint8_t*) SRAM2_BASE + 0x100) = uint8_t Rx_Buff[ETH_RXBUFNB][ETH_RX_BUF_SIZE];
//*((uint8_t*) SRAM2_BASE + 0x17D0) = uint8_t Tx_Buff[ETH_TXBUFNB][ETH_TX_BUF_SIZE];
#endif


#if defined __stm32f7
bool dmaRxDescListInit(bool interruptMode) {
	// Set up new RX DMA descriptors and buffer.
	ETH_DMADescTypeDef descDef[ETH_RXBUFNB];
	uint8_t rxBuff[ETH_RXBUFNB][ETH_RX_BUF_SIZE];
	
	// Fill the RX DMA descriptors.
	for (uint32_t i = 0; i < ETH_RXBUFNB; ++i) {
		// Set up new descriptor.
		ETH_DMADescTypeDef& dd = descDef[i];
		dd.Status = ETH_DMARXDESC_OWN;
		dd.ControlBufferSize = ETH_DMARXDESC_RCH | ETH_RX_BUF_SIZE;
		dd.Buffer1Addr = (uint32_t) (&rxBuff[i * ETH_RX_BUF_SIZE]);
		if (interruptMode) {
			dd.ControlBufferSize &= ~ETH_DMARXDESC_DIC;
		}
		
		// Initialize the next descriptor with the Next Descriptor Polling Enable.
		if ((i + 1) < ETH_RXBUFNB) {
			// Set next descriptor address register with next descriptor base address.
			dd.Buffer2NextDescAddr = (uint32_t) &(descDef[i + 1]);
		}
		else {
			// Set next descriptor address register to beginning of descriptor list.
			dd.Buffer2NextDescAddr = (uint32_t) &(descDef[0]);
		}
	}
	
	memcpy(&DMARxDscrTab, &descDef, sizeof(descDef));
	memcpy(&Rx_Buff, &rxBuff, sizeof(rxBuff));
	
	// Set Receive Descriptor List Address Register.
	ETH->DMARDLAR = (uint32_t) &DMARxDscrTab;
	
	return true;
}


bool dmaTxDescListInit(bool interruptMode, bool hardwareChecksum) {
	// TODO: Set the ETH peripheral state to BUSY.
	
	// Set up new RX DMA descriptors and buffer.
	ETH_DMADescTypeDef descDef[ETH_TXBUFNB];
	uint8_t txBuff[ETH_TXBUFNB][ETH_TX_BUF_SIZE];
	
	// Fill the RX DMA descriptors.
	for (uint32_t i = 0; i < ETH_TXBUFNB; ++i) {
		// Set up new descriptor.
		ETH_DMADescTypeDef& dd = descDef[i];
		dd.Status = ETH_DMATXDESC_TCH;
		dd.Buffer1Addr = (uint32_t) (&txBuff[i * ETH_TX_BUF_SIZE]);
		if (hardwareChecksum) {
			dd.Status |= ETH_DMATXDESC_CIC_TCPUDPICMP_FULL;
		}
		
		if ((i + 1) < ETH_TXBUFNB) {
			dd.Buffer2NextDescAddr = (uint32_t) &(descDef[i + 1]);
		}
		else {
			dd.Buffer2NextDescAddr = (uint32_t) &(descDef[0]);
		}
	}
	
	memcpy(&DMATxDscrTab, &descDef, sizeof(descDef));
	memcpy(&Tx_Buff, &txBuff, sizeof(txBuff));

	// Set Transmit Descriptor List Address Register.
	ETH->DMATDLAR = (uint32_t) &DMATxDscrTab;

	// TODO: Set ETH state to Ready.
	
	return true;
}


// --- SETUP MPU ---
// Configure the memory protection for the TX/RX DMA descriptors and buffers.
bool setupMPU() {
	// TODO:
	
	return true;
}
#endif


// --- WRITE PHY REGISTER ---
bool writePhyRegister(uint16_t reg, uint32_t value) {
#if defined __stm32f7
	// TODO: check for busy status on ETH.
	
	// Get the ETHERNET MACMIIAR value's CR value.
	uint32_t tmpreg = 0;
	tmpreg = ETH->MACMIIAR & ((uint32_t) 0x7 << ETH_MACMIIAR_CR_Pos); // Mask CR bits.
	
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
#endif
	return true;
}


// --- READ PHY REGISTER ---
bool readPhyRegister(uint16_t reg, uint32_t &value) {
#if defined __stm32f7
	// TODO: check for busy status on ETH.
	
	// Get the ETHERNET MACMIIAR value's CR value.
	uint32_t tmpreg = 0;
	tmpreg = ETH->MACMIIAR & ((uint32_t) 0x7 << ETH_MACMIIAR_CR_Pos); // Mask CR bits.
	
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
#endif
	return true;
}


bool macDmaConfig(uint32_t speed, uint32_t duplexMode, bool hardwareChecksum, bool interruptMode,
																		uint8_t macAddress[6]) {
#if defined __stm32f7
	// TODO: check for busy status on ETH.
	
	// >> MAC CR <<
	uint32_t tmpreg = ETH->MACCR;
	
	// Clear WD, PCE, PS, TE and RE.
	tmpreg &= ~(ETH_MACCR_WD | ETH_MACCR_IPCO | ETH_MACCR_APCS | ETH_MACCR_TE | ETH_MACCR_RE);
	
	uint32_t checksumOffload = ETH_CHECKSUMOFFLOAD_ENABLE;
	if (!hardwareChecksum) { checksumOffload = ETH_CHECKSUMOFFLOAD_DISABLE; }
	
	// Set the WD bit according to ETH Watchdog value.
	tmpreg |= (uint32_t) (ETH_WATCHDOG_ENABLE | 
						   ETH_JABBER_ENABLE | 
						   ETH_INTERFRAMEGAP_96BIT |
						   ETH_CARRIERSENSE_ENABLE |
						   speed | 
						   ETH_RECEIVEOWN_ENABLE |
						   ETH_LOOPBACKMODE_DISABLE |
						   duplexMode | 
						   checksumOffload |    
						   ETH_RETRYTRANSMISSION_DISABLE | 
						   ETH_AUTOMATICPADCRCSTRIP_DISABLE | 
						   ETH_BACKOFFLIMIT_10 | 
						   ETH_DEFFERRALCHECK_DISABLE);
						   
	ETH->MACCR = (uint32_t) tmpreg;
	
	// Wait until the write operation will be taken into account.
    // This takes at least four TX_CLK/RX_CLK clock cycles.
	tmpreg = ETH->MACCR;
	timer.delay(ETH_REG_WRITE_DELAY);
	ETH->MACCR = tmpreg; 
	
	// >> MAC FFR <<
	ETH->MACFFR = (uint32_t)(ETH_RECEIVEAll_DISABLE | 
								ETH_SOURCEADDRFILTER_DISABLE |
								ETH_PASSCONTROLFRAMES_BLOCKALL |
								ETH_BROADCASTFRAMESRECEPTION_ENABLE | 
								ETH_DESTINATIONADDRFILTER_NORMAL |
								ETH_PROMISCUOUS_MODE_DISABLE |
								ETH_MULTICASTFRAMESFILTER_PERFECT |
								ETH_UNICASTFRAMESFILTER_PERFECT);
								
	// Wait until write operation will be registered.
	tmpreg = ETH->MACFFR;
	timer.delay(ETH_REG_WRITE_DELAY);
	ETH->MACFFR = tmpreg;
	
	// >> MAC HTHR & MAC HTLR <<
	ETH->MACHTHR = (uint32_t) 0x0;
	ETH->MACHTLR = (uint32_t) 0x0;
	
	// >> MAC FCR <<
	tmpreg = 0;
	uint32_t pauseTime = 0x0;
	tmpreg |= (uint32_t) ((pauseTime << 16) | 
                        ETH_ZEROQUANTAPAUSE_DISABLE |
                        ETH_PAUSELOWTHRESHOLD_MINUS4 |
                        ETH_UNICASTPAUSEFRAMEDETECT_DISABLE | 
                        ETH_RECEIVEFLOWCONTROL_DISABLE |
                        ETH_TRANSMITFLOWCONTROL_DISABLE); 
						
	ETH->MACFCR = (uint32_t) tmpreg;
	
	// Wait for write operation being noticed: four TX/RX clock cycles.
	tmpreg = ETH->MACFCR;
	timer.delay(ETH_REG_WRITE_DELAY);
	ETH->MACFCR = tmpreg;
	
	// >> MAC VLANTR <<
	uint32_t VLANTagIdentifier = 0x0;
	ETH->MACVLANTR = (uint32_t)(ETH_VLANTAGCOMPARISON_16BIT | 
                                    VLANTagIdentifier);
									
	tmpreg = ETH->MACVLANTR;
    timer.delay(ETH_REG_WRITE_DELAY);
    ETH->MACVLANTR = tmpreg;
	
	// >> DMA INITIALISATION <<
	// Configure the DMA with default settings.
	tmpreg = 0;
	tmpreg |= (uint32_t)(ETH_DROPTCPIPCHECKSUMERRORFRAME_ENABLE | 
                         ETH_RECEIVESTOREFORWARD_ENABLE |
                         ETH_FLUSHRECEIVEDFRAME_ENABLE |
                         ETH_TRANSMITSTOREFORWARD_ENABLE | 
                         ETH_TRANSMITTHRESHOLDCONTROL_64BYTES |
                         ETH_FORWARDERRORFRAMES_DISABLE |
                         ETH_FORWARDUNDERSIZEDGOODFRAMES_DISABLE |
                         ETH_RECEIVEDTHRESHOLDCONTROL_64BYTES |
                         ETH_SECONDFRAMEOPERARTE_ENABLE);
						 
	ETH->DMAOMR = (uint32_t) tmpreg;
	
	tmpreg = ETH->DMAOMR;
    timer.delay(ETH_REG_WRITE_DELAY);
    ETH->DMAOMR = tmpreg;
	
	// >> DMA BMR <<
	uint32_t DescriptorSkipLength = 0x0;
	ETH->DMABMR = (uint32_t) (ETH_ADDRESSALIGNEDBEATS_ENABLE | 
							  ETH_FIXEDBURST_ENABLE |
							  ETH_RXDMABURSTLENGTH_32BEAT |    /* !! if 4xPBL is selected for Tx or Rx it is applied for the other */
							  ETH_TXDMABURSTLENGTH_32BEAT |
							  ETH_DMAENHANCEDDESCRIPTOR_ENABLE |
							  (DescriptorSkipLength << 2) |
							  ETH_DMAARBITRATION_ROUNDROBIN_RXTX_1_1 |
							  ETH_DMABMR_USP); /* Enable use of separate PBL for Rx and Tx */
							  
	// Wait until the write operation will be taken into account:
    // at least four TX_CLK/RX_CLK clock cycles.
    tmpreg = ETH->DMABMR;
    timer.delay(ETH_REG_WRITE_DELAY);
    ETH->DMABMR = tmpreg;
	
	if (interruptMode) {
		// Enable RX interrupt.
		ETH->DMAIER |= ETH_DMAIER_NISE | ETH_DMAIER_RIE;
	}
	
	// Initialize MAC address in ethernet MAC
	// High register contains the last two bytes, low register the first (LSB) bytes.
	ETH->MACA0LR |= ((uint32_t) macAddress[5] << 8) | (uint32_t) macAddress[4];
	ETH->MACA0HR |= ((uint32_t) macAddress[3] << 24) | 
						((uint32_t) macAddress[2] << 16) | 
						((uint32_t) macAddress[1] << 8) | 
						macAddress[0];
						
	// Set up DMA descriptors.
	if (!dmaRxDescListInit(interruptMode)) { return false; }
	if (!dmaTxDescListInit(interruptMode, hardwareChecksum)) { return false; }
	
	// Set up the memory protection.
	if (!setupMPU()) { return false; }
						
	return true;
#else
	return false;
#endif
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
	// NOTE: targeting the Nucleo-F746ZG development board here specifically.

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
	
	// Set RMII interface for ETH.
	SYSCFG->PMC &= ~(SYSCFG_PMC_MII_RMII_SEL);
	SYSCFG->PMC |= SYSCFG_PMC_MII_RMII_SEL;
	
	// Reset DMA.
	ETH->DMABMR |= ETH_DMABMR_SR;
	while ((ETH->DMABMR & ETH_DMABMR_SR) != (uint32_t) RESET) { }
	
	// >> Initialise MAC. <<
	// Get the ETHERNET MACMIIAR value's CR value.
	uint32_t tempreg = 0;
	tempreg = ETH->MACMIIAR & ((uint32_t) 0x7 << ETH_MACMIIAR_CR_Pos); // Mask CR bits.
	// Clear CSR Clock Range CR[2:0] bits
	//tempreg &= ~ETH_MACMIIAR_CR;
	
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
	timer.delay(PHY_RESET_DELAY);
	
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
		timer.delay(PHY_CONFIG_DELAY);
	}
	
	// Configure the DMA for the MAC.
	macDmaConfig(ethDef.speed, ethDef.duplexMode, ethDef.hardwareChecksum, 
					ethDef.interruptMode, ethDef.macAddress);
				
	// TODO: port code:
	
	/* Enable transmit state machine of the MAC for transmission on the MII */
  //ETH_MACTransmissionEnable(heth);
  
  /* Enable receive state machine of the MAC for reception from the MII */
  //ETH_MACReceptionEnable(heth);
  
  /* Flush Transmit FIFO */
  //ETH_FlushTransmitFIFO(heth);
  
  /* Start DMA transmission */
  //ETH_DMATransmissionEnable(heth);
  
  /* Start DMA reception */
  //ETH_DMAReceptionEnable(heth);
	
#endif
	
	return true;
}


// --- DMA RX DESC LIST INIT ---
bool Ethernet::dmaRxDescListInit() {
#if defined __stm32f7
	// TODO: Set device state to Busy.
	
	// 
	
	// TODO: Set device state to Ready.
	
#endif
	return true;
}


// --- DMA TX DESC LIST INIT ---
bool Ethernet::dmaTxDescListInit() {
	//
}
