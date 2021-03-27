/*
	ethernet_def.h - Preprocessor definitions for use with the Ethernet class implementation.
	
*/


/** @defgroup ETH_Buffers_setting ETH Buffers setting
  * @{
  */ 
#define ETH_MAX_PACKET_SIZE    ((uint32_t)1524U)    /*!< ETH_HEADER + ETH_EXTRA + ETH_VLAN_TAG + ETH_MAX_ETH_PAYLOAD + ETH_CRC */
#define ETH_HEADER               ((uint32_t)14U)    /*!< 6 byte Dest addr, 6 byte Src addr, 2 byte length/type */
#define ETH_CRC                   ((uint32_t)4U)    /*!< Ethernet CRC */
#define ETH_EXTRA                 ((uint32_t)2U)    /*!< Extra bytes in some cases */   
#define ETH_VLAN_TAG              ((uint32_t)4U)    /*!< optional 802.1q VLAN Tag */
#define ETH_MIN_ETH_PAYLOAD       ((uint32_t)46U)    /*!< Minimum Ethernet payload size */
#define ETH_MAX_ETH_PAYLOAD       ((uint32_t)1500U)    /*!< Maximum Ethernet payload size */
#define ETH_JUMBO_FRAME_PAYLOAD   ((uint32_t)9000U)    /*!< Jumbo frame payload size */     


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


/*
   DMA Tx Descriptor
  -----------------------------------------------------------------------------------------------
  TDES0 | OWN(31) | CTRL[30:26] | Reserved[25:24] | CTRL[23:20] | Reserved[19:17] | Status[16:0] |
  -----------------------------------------------------------------------------------------------
  TDES1 | Reserved[31:29] | Buffer2 ByteCount[28:16] | Reserved[15:13] | Buffer1 ByteCount[12:0] |
  -----------------------------------------------------------------------------------------------
  TDES2 |                         Buffer1 Address [31:0]                                         |
  -----------------------------------------------------------------------------------------------
  TDES3 |                   Buffer2 Address [31:0] / Next Descriptor Address [31:0]              |
  -----------------------------------------------------------------------------------------------
*/

/** 
  * @brief  Bit definition of TDES0 register: DMA Tx descriptor status register
  */ 
#define ETH_DMATXDESC_OWN                     ((uint32_t)0x80000000U)  /*!< OWN bit: descriptor is owned by DMA engine */
#define ETH_DMATXDESC_IC                      ((uint32_t)0x40000000U)  /*!< Interrupt on Completion */
#define ETH_DMATXDESC_LS                      ((uint32_t)0x20000000U)  /*!< Last Segment */
#define ETH_DMATXDESC_FS                      ((uint32_t)0x10000000U)  /*!< First Segment */
#define ETH_DMATXDESC_DC                      ((uint32_t)0x08000000U)  /*!< Disable CRC */
#define ETH_DMATXDESC_DP                      ((uint32_t)0x04000000U)  /*!< Disable Padding */
#define ETH_DMATXDESC_TTSE                    ((uint32_t)0x02000000U)  /*!< Transmit Time Stamp Enable */
#define ETH_DMATXDESC_CIC                     ((uint32_t)0x00C00000U)  /*!< Checksum Insertion Control: 4 cases */
#define ETH_DMATXDESC_CIC_BYPASS              ((uint32_t)0x00000000U)  /*!< Do Nothing: Checksum Engine is bypassed */ 
#define ETH_DMATXDESC_CIC_IPV4HEADER          ((uint32_t)0x00400000U)  /*!< IPV4 header Checksum Insertion */ 
#define ETH_DMATXDESC_CIC_TCPUDPICMP_SEGMENT  ((uint32_t)0x00800000U)  /*!< TCP/UDP/ICMP Checksum Insertion calculated over segment only */ 
#define ETH_DMATXDESC_CIC_TCPUDPICMP_FULL     ((uint32_t)0x00C00000U)  /*!< TCP/UDP/ICMP Checksum Insertion fully calculated */ 
#define ETH_DMATXDESC_TER                     ((uint32_t)0x00200000U)  /*!< Transmit End of Ring */
#define ETH_DMATXDESC_TCH                     ((uint32_t)0x00100000U)  /*!< Second Address Chained */
#define ETH_DMATXDESC_TTSS                    ((uint32_t)0x00020000U)  /*!< Tx Time Stamp Status */
#define ETH_DMATXDESC_IHE                     ((uint32_t)0x00010000U)  /*!< IP Header Error */
#define ETH_DMATXDESC_ES                      ((uint32_t)0x00008000U)  /*!< Error summary: OR of the following bits: UE || ED || EC || LCO || NC || LCA || FF || JT */
#define ETH_DMATXDESC_JT                      ((uint32_t)0x00004000U)  /*!< Jabber Timeout */
#define ETH_DMATXDESC_FF                      ((uint32_t)0x00002000U)  /*!< Frame Flushed: DMA/MTL flushed the frame due to SW flush */
#define ETH_DMATXDESC_PCE                     ((uint32_t)0x00001000U)  /*!< Payload Checksum Error */
#define ETH_DMATXDESC_LCA                     ((uint32_t)0x00000800U)  /*!< Loss of Carrier: carrier lost during transmission */
#define ETH_DMATXDESC_NC                      ((uint32_t)0x00000400U)  /*!< No Carrier: no carrier signal from the transceiver */
#define ETH_DMATXDESC_LCO                     ((uint32_t)0x00000200U)  /*!< Late Collision: transmission aborted due to collision */
#define ETH_DMATXDESC_EC                      ((uint32_t)0x00000100U)  /*!< Excessive Collision: transmission aborted after 16 collisions */
#define ETH_DMATXDESC_VF                      ((uint32_t)0x00000080U)  /*!< VLAN Frame */
#define ETH_DMATXDESC_CC                      ((uint32_t)0x00000078U)  /*!< Collision Count */
#define ETH_DMATXDESC_ED                      ((uint32_t)0x00000004U)  /*!< Excessive Deferral */
#define ETH_DMATXDESC_UF                      ((uint32_t)0x00000002U)  /*!< Underflow Error: late data arrival from the memory */
#define ETH_DMATXDESC_DB                      ((uint32_t)0x00000001U)  /*!< Deferred Bit */

/** 
  * @brief  Bit definition of TDES1 register
  */ 
#define ETH_DMATXDESC_TBS2  ((uint32_t)0x1FFF0000U)  /*!< Transmit Buffer2 Size */
#define ETH_DMATXDESC_TBS1  ((uint32_t)0x00001FFFU)  /*!< Transmit Buffer1 Size */

/** 
  * @brief  Bit definition of TDES2 register
  */ 
#define ETH_DMATXDESC_B1AP  ((uint32_t)0xFFFFFFFFU)  /*!< Buffer1 Address Pointer */

/** 
  * @brief  Bit definition of TDES3 register
  */ 
#define ETH_DMATXDESC_B2AP  ((uint32_t)0xFFFFFFFFU)  /*!< Buffer2 Address Pointer */

  /*---------------------------------------------------------------------------------------------
  TDES6 |                         Transmit Time Stamp Low [31:0]                                 |
  -----------------------------------------------------------------------------------------------
  TDES7 |                         Transmit Time Stamp High [31:0]                                |
  ----------------------------------------------------------------------------------------------*/

/* Bit definition of TDES6 register */
 #define ETH_DMAPTPTXDESC_TTSL  ((uint32_t)0xFFFFFFFFU)  /* Transmit Time Stamp Low */

/* Bit definition of TDES7 register */
 #define ETH_DMAPTPTXDESC_TTSH  ((uint32_t)0xFFFFFFFFU)  /* Transmit Time Stamp High */

/**
  * @}
  */ 
/** @defgroup ETH_DMA_RX_Descriptor ETH DMA RX Descriptor
  * @{
  */

/*
  DMA Rx Descriptor
  --------------------------------------------------------------------------------------------------------------------
  RDES0 | OWN(31) |                                             Status [30:0]                                          |
  ---------------------------------------------------------------------------------------------------------------------
  RDES1 | CTRL(31) | Reserved[30:29] | Buffer2 ByteCount[28:16] | CTRL[15:14] | Reserved(13) | Buffer1 ByteCount[12:0] |
  ---------------------------------------------------------------------------------------------------------------------
  RDES2 |                                       Buffer1 Address [31:0]                                                 |
  ---------------------------------------------------------------------------------------------------------------------
  RDES3 |                          Buffer2 Address [31:0] / Next Descriptor Address [31:0]                             |
  ---------------------------------------------------------------------------------------------------------------------
*/

/** 
  * @brief  Bit definition of RDES0 register: DMA Rx descriptor status register
  */ 
#define ETH_DMARXDESC_OWN         ((uint32_t)0x80000000U)  /*!< OWN bit: descriptor is owned by DMA engine  */
#define ETH_DMARXDESC_AFM         ((uint32_t)0x40000000U)  /*!< DA Filter Fail for the rx frame  */
#define ETH_DMARXDESC_FL          ((uint32_t)0x3FFF0000U)  /*!< Receive descriptor frame length  */
#define ETH_DMARXDESC_ES          ((uint32_t)0x00008000U)  /*!< Error summary: OR of the following bits: DE || OE || IPC || LC || RWT || RE || CE */
#define ETH_DMARXDESC_DE          ((uint32_t)0x00004000U)  /*!< Descriptor error: no more descriptors for receive frame  */
#define ETH_DMARXDESC_SAF         ((uint32_t)0x00002000U)  /*!< SA Filter Fail for the received frame */
#define ETH_DMARXDESC_LE          ((uint32_t)0x00001000U)  /*!< Frame size not matching with length field */
#define ETH_DMARXDESC_OE          ((uint32_t)0x00000800U)  /*!< Overflow Error: Frame was damaged due to buffer overflow */
#define ETH_DMARXDESC_VLAN        ((uint32_t)0x00000400U)  /*!< VLAN Tag: received frame is a VLAN frame */
#define ETH_DMARXDESC_FS          ((uint32_t)0x00000200U)  /*!< First descriptor of the frame  */
#define ETH_DMARXDESC_LS          ((uint32_t)0x00000100U)  /*!< Last descriptor of the frame  */ 
#define ETH_DMARXDESC_IPV4HCE     ((uint32_t)0x00000080U)  /*!< IPC Checksum Error: Rx Ipv4 header checksum error   */    
#define ETH_DMARXDESC_LC          ((uint32_t)0x00000040U)  /*!< Late collision occurred during reception   */
#define ETH_DMARXDESC_FT          ((uint32_t)0x00000020U)  /*!< Frame type - Ethernet, otherwise 802.3    */
#define ETH_DMARXDESC_RWT         ((uint32_t)0x00000010U)  /*!< Receive Watchdog Timeout: watchdog timer expired during reception    */
#define ETH_DMARXDESC_RE          ((uint32_t)0x00000008U)  /*!< Receive error: error reported by MII interface  */
#define ETH_DMARXDESC_DBE         ((uint32_t)0x00000004U)  /*!< Dribble bit error: frame contains non int multiple of 8 bits  */
#define ETH_DMARXDESC_CE          ((uint32_t)0x00000002U)  /*!< CRC error */
#define ETH_DMARXDESC_MAMPCE      ((uint32_t)0x00000001U)  /*!< Rx MAC Address/Payload Checksum Error: Rx MAC address matched/ Rx Payload Checksum Error */

/** 
  * @brief  Bit definition of RDES1 register
  */ 
#define ETH_DMARXDESC_DIC   ((uint32_t)0x80000000U)  /*!< Disable Interrupt on Completion */
#define ETH_DMARXDESC_RBS2  ((uint32_t)0x1FFF0000U)  /*!< Receive Buffer2 Size */
#define ETH_DMARXDESC_RER   ((uint32_t)0x00008000U)  /*!< Receive End of Ring */
#define ETH_DMARXDESC_RCH   ((uint32_t)0x00004000U)  /*!< Second Address Chained */
#define ETH_DMARXDESC_RBS1  ((uint32_t)0x00001FFFU)  /*!< Receive Buffer1 Size */

/** 
  * @brief  Bit definition of RDES2 register  
  */ 
#define ETH_DMARXDESC_B1AP  ((uint32_t)0xFFFFFFFFU)  /*!< Buffer1 Address Pointer */

/** 
  * @brief  Bit definition of RDES3 register  
  */ 
#define ETH_DMARXDESC_B2AP  ((uint32_t)0xFFFFFFFFU)  /*!< Buffer2 Address Pointer */

/*---------------------------------------------------------------------------------------------------------------------
  RDES4 |                   Reserved[31:15]              |             Extended Status [14:0]                          |
  ---------------------------------------------------------------------------------------------------------------------
  RDES5 |                                            Reserved[31:0]                                                    |
  ---------------------------------------------------------------------------------------------------------------------
  RDES6 |                                       Receive Time Stamp Low [31:0]                                          |
  ---------------------------------------------------------------------------------------------------------------------
  RDES7 |                                       Receive Time Stamp High [31:0]                                         |
  --------------------------------------------------------------------------------------------------------------------*/

/* Bit definition of RDES4 register */
#define ETH_DMAPTPRXDESC_PTPV                            ((uint32_t)0x00002000U)  /* PTP Version */
#define ETH_DMAPTPRXDESC_PTPFT                           ((uint32_t)0x00001000U)  /* PTP Frame Type */
#define ETH_DMAPTPRXDESC_PTPMT                           ((uint32_t)0x00000F00U)  /* PTP Message Type */
#define ETH_DMAPTPRXDESC_PTPMT_SYNC                      ((uint32_t)0x00000100U)  /* SYNC message (all clock types) */
#define ETH_DMAPTPRXDESC_PTPMT_FOLLOWUP                  ((uint32_t)0x00000200U)  /* FollowUp message (all clock types) */ 
#define ETH_DMAPTPRXDESC_PTPMT_DELAYREQ                  ((uint32_t)0x00000300U)  /* DelayReq message (all clock types) */ 
#define ETH_DMAPTPRXDESC_PTPMT_DELAYRESP                 ((uint32_t)0x00000400U)  /* DelayResp message (all clock types) */ 
#define ETH_DMAPTPRXDESC_PTPMT_PDELAYREQ_ANNOUNCE        ((uint32_t)0x00000500U)  /* PdelayReq message (peer-to-peer transparent clock) or Announce message (Ordinary or Boundary clock) */ 
#define ETH_DMAPTPRXDESC_PTPMT_PDELAYRESP_MANAG          ((uint32_t)0x00000600U)  /* PdelayResp message (peer-to-peer transparent clock) or Management message (Ordinary or Boundary clock)  */ 
#define ETH_DMAPTPRXDESC_PTPMT_PDELAYRESPFOLLOWUP_SIGNAL ((uint32_t)0x00000700U)  /* PdelayRespFollowUp message (peer-to-peer transparent clock) or Signaling message (Ordinary or Boundary clock) */           
#define ETH_DMAPTPRXDESC_IPV6PR                          ((uint32_t)0x00000080U)  /* IPv6 Packet Received */
#define ETH_DMAPTPRXDESC_IPV4PR                          ((uint32_t)0x00000040U)  /* IPv4 Packet Received */
#define ETH_DMAPTPRXDESC_IPCB                            ((uint32_t)0x00000020U)  /* IP Checksum Bypassed */
#define ETH_DMAPTPRXDESC_IPPE                            ((uint32_t)0x00000010U)  /* IP Payload Error */
#define ETH_DMAPTPRXDESC_IPHE                            ((uint32_t)0x00000008U)  /* IP Header Error */
#define ETH_DMAPTPRXDESC_IPPT                            ((uint32_t)0x00000007U)  /* IP Payload Type */
#define ETH_DMAPTPRXDESC_IPPT_UDP                        ((uint32_t)0x00000001U)  /* UDP payload encapsulated in the IP datagram */
#define ETH_DMAPTPRXDESC_IPPT_TCP                        ((uint32_t)0x00000002U)  /* TCP payload encapsulated in the IP datagram */ 
#define ETH_DMAPTPRXDESC_IPPT_ICMP                       ((uint32_t)0x00000003U)  /* ICMP payload encapsulated in the IP datagram */

/* Bit definition of RDES6 register */
#define ETH_DMAPTPRXDESC_RTSL  ((uint32_t)0xFFFFFFFFU)  /* Receive Time Stamp Low */

/* Bit definition of RDES7 register */
#define ETH_DMAPTPRXDESC_RTSH  ((uint32_t)0xFFFFFFFFU)  /* Receive Time Stamp High */
