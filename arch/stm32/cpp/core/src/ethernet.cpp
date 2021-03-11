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

#define ETH_REG_WRITE_DELAY ((uint32_t)0x00000001U)

#define ETH_RXPOLLING_MODE      ((uint32_t)0x00000000U)
#define ETH_RXINTERRUPT_MODE    ((uint32_t)0x00000001U)

#define ETH_CHECKSUM_BY_HARDWARE      ((uint32_t)0x00000000U)
#define ETH_CHECKSUM_BY_SOFTWARE      ((uint32_t)0x00000001U)

#define ETH_WATCHDOG_ENABLE       ((uint32_t)0x00000000U)
#define ETH_WATCHDOG_DISABLE      ((uint32_t)0x00800000U)

#define ETH_JABBER_ENABLE    ((uint32_t)0x00000000U)
#define ETH_JABBER_DISABLE   ((uint32_t)0x00400000U)

#define ETH_INTERFRAMEGAP_96BIT   ((uint32_t)0x00000000U)  /*!< minimum IFG between frames during transmission is 96Bit */
#define ETH_INTERFRAMEGAP_88BIT   ((uint32_t)0x00020000U)  /*!< minimum IFG between frames during transmission is 88Bit */
#define ETH_INTERFRAMEGAP_80BIT   ((uint32_t)0x00040000U)  /*!< minimum IFG between frames during transmission is 80Bit */
#define ETH_INTERFRAMEGAP_72BIT   ((uint32_t)0x00060000U)  /*!< minimum IFG between frames during transmission is 72Bit */
#define ETH_INTERFRAMEGAP_64BIT   ((uint32_t)0x00080000U)  /*!< minimum IFG between frames during transmission is 64Bit */
#define ETH_INTERFRAMEGAP_56BIT   ((uint32_t)0x000A0000U)  /*!< minimum IFG between frames during transmission is 56Bit */
#define ETH_INTERFRAMEGAP_48BIT   ((uint32_t)0x000C0000U)  /*!< minimum IFG between frames during transmission is 48Bit */
#define ETH_INTERFRAMEGAP_40BIT   ((uint32_t)0x000E0000U)  /*!< minimum IFG between frames during transmission is 40Bit */

#define ETH_CARRIERSENSE_ENABLE   ((uint32_t)0x00000000U)
#define ETH_CARRIERSENSE_DISABLE  ((uint32_t)0x00010000U)

#define ETH_RECEIVEOWN_ENABLE     ((uint32_t)0x00000000U)
#define ETH_RECEIVEOWN_DISABLE    ((uint32_t)0x00002000U)

#define ETH_LOOPBACKMODE_ENABLE        ((uint32_t)0x00001000U)
#define ETH_LOOPBACKMODE_DISABLE       ((uint32_t)0x00000000U)

#define ETH_CHECKSUMOFFLOAD_ENABLE     ((uint32_t)0x00000400U)
#define ETH_CHECKSUMOFFLOAD_DISABLE    ((uint32_t)0x00000000U)

#define ETH_RETRYTRANSMISSION_ENABLE   ((uint32_t)0x00000000U)
#define ETH_RETRYTRANSMISSION_DISABLE  ((uint32_t)0x00000200U)

#define ETH_AUTOMATICPADCRCSTRIP_ENABLE     ((uint32_t)0x00000080U)
#define ETH_AUTOMATICPADCRCSTRIP_DISABLE    ((uint32_t)0x00000000U)

#define ETH_BACKOFFLIMIT_10  ((uint32_t)0x00000000U)
#define ETH_BACKOFFLIMIT_8   ((uint32_t)0x00000020U)
#define ETH_BACKOFFLIMIT_4   ((uint32_t)0x00000040U)
#define ETH_BACKOFFLIMIT_1   ((uint32_t)0x00000060U)

#define ETH_DEFFERRALCHECK_ENABLE       ((uint32_t)0x00000010U)
#define ETH_DEFFERRALCHECK_DISABLE      ((uint32_t)0x00000000U)

#define ETH_RECEIVEALL_ENABLE     ((uint32_t)0x80000000U)
#define ETH_RECEIVEAll_DISABLE    ((uint32_t)0x00000000U)

#define ETH_SOURCEADDRFILTER_NORMAL_ENABLE       ((uint32_t)0x00000200U)
#define ETH_SOURCEADDRFILTER_INVERSE_ENABLE      ((uint32_t)0x00000300U)
#define ETH_SOURCEADDRFILTER_DISABLE             ((uint32_t)0x00000000U)

#define ETH_PASSCONTROLFRAMES_BLOCKALL                ((uint32_t)0x00000040U)  /*!< MAC filters all control frames from reaching the application */
#define ETH_PASSCONTROLFRAMES_FORWARDALL              ((uint32_t)0x00000080U)  /*!< MAC forwards all control frames to application even if they fail the Address Filter */
#define ETH_PASSCONTROLFRAMES_FORWARDPASSEDADDRFILTER ((uint32_t)0x000000C0U)  /*!< MAC forwards control frames that pass the Address Filter. */ 

#define ETH_BROADCASTFRAMESRECEPTION_ENABLE     ((uint32_t)0x00000000U)
#define ETH_BROADCASTFRAMESRECEPTION_DISABLE    ((uint32_t)0x00000020U)

#define ETH_DESTINATIONADDRFILTER_NORMAL    ((uint32_t)0x00000000U)
#define ETH_DESTINATIONADDRFILTER_INVERSE   ((uint32_t)0x00000008U)

#define ETH_PROMISCUOUS_MODE_ENABLE     ((uint32_t)0x00000001U)
#define ETH_PROMISCUOUS_MODE_DISABLE    ((uint32_t)0x00000000U)

#define ETH_MULTICASTFRAMESFILTER_PERFECTHASHTABLE    ((uint32_t)0x00000404U)
#define ETH_MULTICASTFRAMESFILTER_HASHTABLE           ((uint32_t)0x00000004U)
#define ETH_MULTICASTFRAMESFILTER_PERFECT             ((uint32_t)0x00000000U)
#define ETH_MULTICASTFRAMESFILTER_NONE                ((uint32_t)0x00000010U)

#define ETH_UNICASTFRAMESFILTER_PERFECTHASHTABLE ((uint32_t)0x00000402U)
#define ETH_UNICASTFRAMESFILTER_HASHTABLE        ((uint32_t)0x00000002U)
#define ETH_UNICASTFRAMESFILTER_PERFECT          ((uint32_t)0x00000000U)

#define ETH_ZEROQUANTAPAUSE_ENABLE     ((uint32_t)0x00000000U)
#define ETH_ZEROQUANTAPAUSE_DISABLE    ((uint32_t)0x00000080U)

#define ETH_PAUSELOWTHRESHOLD_MINUS4        ((uint32_t)0x00000000U)  /*!< Pause time minus 4 slot times */
#define ETH_PAUSELOWTHRESHOLD_MINUS28       ((uint32_t)0x00000010U)  /*!< Pause time minus 28 slot times */
#define ETH_PAUSELOWTHRESHOLD_MINUS144      ((uint32_t)0x00000020U)  /*!< Pause time minus 144 slot times */
#define ETH_PAUSELOWTHRESHOLD_MINUS256      ((uint32_t)0x00000030U)  /*!< Pause time minus 256 slot times */

#define ETH_UNICASTPAUSEFRAMEDETECT_ENABLE  ((uint32_t)0x00000008U)
#define ETH_UNICASTPAUSEFRAMEDETECT_DISABLE ((uint32_t)0x00000000U)

#define ETH_RECEIVEFLOWCONTROL_ENABLE       ((uint32_t)0x00000004U)
#define ETH_RECEIVEFLOWCONTROL_DISABLE      ((uint32_t)0x00000000U)

#define ETH_TRANSMITFLOWCONTROL_ENABLE      ((uint32_t)0x00000002U)
#define ETH_TRANSMITFLOWCONTROL_DISABLE     ((uint32_t)0x00000000U)

#define ETH_VLANTAGCOMPARISON_12BIT    ((uint32_t)0x00010000U)
#define ETH_VLANTAGCOMPARISON_16BIT    ((uint32_t)0x00000000U)

#define ETH_DROPTCPIPCHECKSUMERRORFRAME_ENABLE   ((uint32_t)0x00000000U)
#define ETH_DROPTCPIPCHECKSUMERRORFRAME_DISABLE  ((uint32_t)0x04000000U)

#define ETH_RECEIVESTOREFORWARD_ENABLE      ((uint32_t)0x02000000U)
#define ETH_RECEIVESTOREFORWARD_DISABLE     ((uint32_t)0x00000000U)

#define ETH_FLUSHRECEIVEDFRAME_ENABLE       ((uint32_t)0x00000000U)
#define ETH_FLUSHRECEIVEDFRAME_DISABLE      ((uint32_t)0x01000000U)

#define ETH_TRANSMITSTOREFORWARD_ENABLE     ((uint32_t)0x00200000U)
#define ETH_TRANSMITSTOREFORWARD_DISABLE    ((uint32_t)0x00000000U)

#define ETH_TRANSMITTHRESHOLDCONTROL_64BYTES     ((uint32_t)0x00000000U)  /*!< threshold level of the MTL Transmit FIFO is 64 Bytes */
#define ETH_TRANSMITTHRESHOLDCONTROL_128BYTES    ((uint32_t)0x00004000U)  /*!< threshold level of the MTL Transmit FIFO is 128 Bytes */
#define ETH_TRANSMITTHRESHOLDCONTROL_192BYTES    ((uint32_t)0x00008000U)  /*!< threshold level of the MTL Transmit FIFO is 192 Bytes */
#define ETH_TRANSMITTHRESHOLDCONTROL_256BYTES    ((uint32_t)0x0000C000U)  /*!< threshold level of the MTL Transmit FIFO is 256 Bytes */
#define ETH_TRANSMITTHRESHOLDCONTROL_40BYTES     ((uint32_t)0x00010000U)  /*!< threshold level of the MTL Transmit FIFO is 40 Bytes */
#define ETH_TRANSMITTHRESHOLDCONTROL_32BYTES     ((uint32_t)0x00014000U)  /*!< threshold level of the MTL Transmit FIFO is 32 Bytes */
#define ETH_TRANSMITTHRESHOLDCONTROL_24BYTES     ((uint32_t)0x00018000U)  /*!< threshold level of the MTL Transmit FIFO is 24 Bytes */
#define ETH_TRANSMITTHRESHOLDCONTROL_16BYTES     ((uint32_t)0x0001C000U)  /*!< threshold level of the MTL Transmit FIFO is 16 Bytes */

#define ETH_FORWARDERRORFRAMES_ENABLE       ((uint32_t)0x00000080U)
#define ETH_FORWARDERRORFRAMES_DISABLE      ((uint32_t)0x00000000U)

#define ETH_FORWARDUNDERSIZEDGOODFRAMES_ENABLE   ((uint32_t)0x00000040U)
#define ETH_FORWARDUNDERSIZEDGOODFRAMES_DISABLE  ((uint32_t)0x00000000U)   

#define ETH_RECEIVEDTHRESHOLDCONTROL_64BYTES      ((uint32_t)0x00000000U)  /*!< threshold level of the MTL Receive FIFO is 64 Bytes */
#define ETH_RECEIVEDTHRESHOLDCONTROL_32BYTES      ((uint32_t)0x00000008U)  /*!< threshold level of the MTL Receive FIFO is 32 Bytes */
#define ETH_RECEIVEDTHRESHOLDCONTROL_96BYTES      ((uint32_t)0x00000010U)  /*!< threshold level of the MTL Receive FIFO is 96 Bytes */
#define ETH_RECEIVEDTHRESHOLDCONTROL_128BYTES     ((uint32_t)0x00000018U)  /*!< threshold level of the MTL Receive FIFO is 128 Bytes */

#define ETH_SECONDFRAMEOPERARTE_ENABLE       ((uint32_t)0x00000004U)
#define ETH_SECONDFRAMEOPERARTE_DISABLE      ((uint32_t)0x00000000U)  

#define ETH_ADDRESSALIGNEDBEATS_ENABLE      ((uint32_t)0x02000000U)
#define ETH_ADDRESSALIGNEDBEATS_DISABLE     ((uint32_t)0x00000000U) 

#define ETH_FIXEDBURST_ENABLE     ((uint32_t)0x00010000U)
#define ETH_FIXEDBURST_DISABLE    ((uint32_t)0x00000000U) 

#define ETH_RXDMABURSTLENGTH_1BEAT          ((uint32_t)0x00020000U)  /*!< maximum number of beats to be transferred in one RxDMA transaction is 1 */
#define ETH_RXDMABURSTLENGTH_2BEAT          ((uint32_t)0x00040000U)  /*!< maximum number of beats to be transferred in one RxDMA transaction is 2 */
#define ETH_RXDMABURSTLENGTH_4BEAT          ((uint32_t)0x00080000U)  /*!< maximum number of beats to be transferred in one RxDMA transaction is 4 */
#define ETH_RXDMABURSTLENGTH_8BEAT          ((uint32_t)0x00100000U)  /*!< maximum number of beats to be transferred in one RxDMA transaction is 8 */
#define ETH_RXDMABURSTLENGTH_16BEAT         ((uint32_t)0x00200000U)  /*!< maximum number of beats to be transferred in one RxDMA transaction is 16 */
#define ETH_RXDMABURSTLENGTH_32BEAT         ((uint32_t)0x00400000U)  /*!< maximum number of beats to be transferred in one RxDMA transaction is 32 */                
#define ETH_RXDMABURSTLENGTH_4XPBL_4BEAT    ((uint32_t)0x01020000U)  /*!< maximum number of beats to be transferred in one RxDMA transaction is 4 */
#define ETH_RXDMABURSTLENGTH_4XPBL_8BEAT    ((uint32_t)0x01040000U)  /*!< maximum number of beats to be transferred in one RxDMA transaction is 8 */
#define ETH_RXDMABURSTLENGTH_4XPBL_16BEAT   ((uint32_t)0x01080000U)  /*!< maximum number of beats to be transferred in one RxDMA transaction is 16 */
#define ETH_RXDMABURSTLENGTH_4XPBL_32BEAT   ((uint32_t)0x01100000U)  /*!< maximum number of beats to be transferred in one RxDMA transaction is 32 */
#define ETH_RXDMABURSTLENGTH_4XPBL_64BEAT   ((uint32_t)0x01200000U)  /*!< maximum number of beats to be transferred in one RxDMA transaction is 64 */
#define ETH_RXDMABURSTLENGTH_4XPBL_128BEAT  ((uint32_t)0x01400000U)  /*!< maximum number of beats to be transferred in one RxDMA transaction is 128 */

#define ETH_TXDMABURSTLENGTH_1BEAT          ((uint32_t)0x00000100U)  /*!< maximum number of beats to be transferred in one TxDMA (or both) transaction is 1 */
#define ETH_TXDMABURSTLENGTH_2BEAT          ((uint32_t)0x00000200U)  /*!< maximum number of beats to be transferred in one TxDMA (or both) transaction is 2 */
#define ETH_TXDMABURSTLENGTH_4BEAT          ((uint32_t)0x00000400U)  /*!< maximum number of beats to be transferred in one TxDMA (or both) transaction is 4 */
#define ETH_TXDMABURSTLENGTH_8BEAT          ((uint32_t)0x00000800U)  /*!< maximum number of beats to be transferred in one TxDMA (or both) transaction is 8 */
#define ETH_TXDMABURSTLENGTH_16BEAT         ((uint32_t)0x00001000U)  /*!< maximum number of beats to be transferred in one TxDMA (or both) transaction is 16 */
#define ETH_TXDMABURSTLENGTH_32BEAT         ((uint32_t)0x00002000U)  /*!< maximum number of beats to be transferred in one TxDMA (or both) transaction is 32 */                
#define ETH_TXDMABURSTLENGTH_4XPBL_4BEAT    ((uint32_t)0x01000100U)  /*!< maximum number of beats to be transferred in one TxDMA (or both) transaction is 4 */
#define ETH_TXDMABURSTLENGTH_4XPBL_8BEAT    ((uint32_t)0x01000200U)  /*!< maximum number of beats to be transferred in one TxDMA (or both) transaction is 8 */
#define ETH_TXDMABURSTLENGTH_4XPBL_16BEAT   ((uint32_t)0x01000400U)  /*!< maximum number of beats to be transferred in one TxDMA (or both) transaction is 16 */
#define ETH_TXDMABURSTLENGTH_4XPBL_32BEAT   ((uint32_t)0x01000800U)  /*!< maximum number of beats to be transferred in one TxDMA (or both) transaction is 32 */
#define ETH_TXDMABURSTLENGTH_4XPBL_64BEAT   ((uint32_t)0x01001000U)  /*!< maximum number of beats to be transferred in one TxDMA (or both) transaction is 64 */
#define ETH_TXDMABURSTLENGTH_4XPBL_128BEAT  ((uint32_t)0x01002000U)  /*!< maximum number of beats to be transferred in one TxDMA (or both) transaction is 128 */

#define ETH_DMAENHANCEDDESCRIPTOR_ENABLE              ((uint32_t)0x00000080U)
#define ETH_DMAENHANCEDDESCRIPTOR_DISABLE             ((uint32_t)0x00000000U)

#define ETH_DMAARBITRATION_ROUNDROBIN_RXTX_1_1   ((uint32_t)0x00000000U)
#define ETH_DMAARBITRATION_ROUNDROBIN_RXTX_2_1   ((uint32_t)0x00004000U)
#define ETH_DMAARBITRATION_ROUNDROBIN_RXTX_3_1   ((uint32_t)0x00008000U)
#define ETH_DMAARBITRATION_ROUNDROBIN_RXTX_4_1   ((uint32_t)0x0000C000U)
#define ETH_DMAARBITRATION_RXPRIORTX             ((uint32_t)0x00000002U)

Timer timer;


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


/* void macAddressConfig(uint32_t MacAddr, uint8_t* addr) {
#if defined __stm32f7
	/* Calculate the selected MAC address high register */
	/*uint32_t tmpreg = ((uint32_t) addr[5] << 8) | (uint32_t) addr[4];
	
	/* Load the selected MAC address high register */
	/*(*(__IO uint32_t *)((uint32_t)(ETH_MAC_ADDR_HBASE + MacAddr))) = tmpreg;
	
	/* Calculate the selected MAC address low register */
	//tmpreg = ((uint32_t)Addr[3] << 24) | ((uint32_t)Addr[2] << 16) | ((uint32_t)Addr[1] << 8) | Addr[0];
  
	/* Load the selected MAC address low register */
	/*(*(__IO uint32_t *)((uint32_t)(ETH_MAC_ADDR_LBASE + MacAddr))) = tmpreg;
#endif
} */


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
	
#endif
	
	return true;
}

