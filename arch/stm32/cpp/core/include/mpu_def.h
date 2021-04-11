#define  MPU_HFNMI_PRIVDEF_NONE      ((uint32_t)0x00000000U)  
#define  MPU_HARDFAULT_NMI           ((uint32_t)0x00000002U)
#define  MPU_PRIVILEGED_DEFAULT      ((uint32_t)0x00000004U)
#define  MPU_HFNMI_PRIVDEF           ((uint32_t)0x00000006U)
/**
  * @}
  */

/** @defgroup CORTEX_MPU_Region_Enable CORTEX MPU Region Enable
  * @{
  */
#define  MPU_REGION_ENABLE     ((uint8_t)0x01U)
#define  MPU_REGION_DISABLE    ((uint8_t)0x00U)
/**
  * @}
  */

/** @defgroup CORTEX_MPU_Instruction_Access CORTEX MPU Instruction Access
  * @{
  */
#define  MPU_INSTRUCTION_ACCESS_ENABLE      ((uint8_t)0x00U)
#define  MPU_INSTRUCTION_ACCESS_DISABLE     ((uint8_t)0x01U)
/**
  * @}
  */

/** @defgroup CORTEX_MPU_Access_Shareable CORTEX MPU Instruction Access Shareable
  * @{
  */
#define  MPU_ACCESS_SHAREABLE        ((uint8_t)0x01U)
#define  MPU_ACCESS_NOT_SHAREABLE    ((uint8_t)0x00U)
/**
  * @}
  */

/** @defgroup CORTEX_MPU_Access_Cacheable CORTEX MPU Instruction Access Cacheable
  * @{
  */
#define  MPU_ACCESS_CACHEABLE         ((uint8_t)0x01U)
#define  MPU_ACCESS_NOT_CACHEABLE     ((uint8_t)0x00U)
/**
  * @}
  */

/** @defgroup CORTEX_MPU_Access_Bufferable CORTEX MPU Instruction Access Bufferable
  * @{
  */
#define  MPU_ACCESS_BUFFERABLE         ((uint8_t)0x01U)
#define  MPU_ACCESS_NOT_BUFFERABLE     ((uint8_t)0x00U)
/**
  * @}
  */

/** @defgroup CORTEX_MPU_TEX_Levels MPU TEX Levels
  * @{
  */
#define  MPU_TEX_LEVEL0    ((uint8_t)0x00U)
#define  MPU_TEX_LEVEL1    ((uint8_t)0x01U)
#define  MPU_TEX_LEVEL2    ((uint8_t)0x02U)
/**
  * @}
  */

/** @defgroup CORTEX_MPU_Region_Size CORTEX MPU Region Size
  * @{
  */
#define   MPU_REGION_SIZE_32B      ((uint8_t)0x04U)
#define   MPU_REGION_SIZE_64B      ((uint8_t)0x05U)
#define   MPU_REGION_SIZE_128B     ((uint8_t)0x06U) 
#define   MPU_REGION_SIZE_256B     ((uint8_t)0x07U) 
#define   MPU_REGION_SIZE_512B     ((uint8_t)0x08U) 
#define   MPU_REGION_SIZE_1KB      ((uint8_t)0x09U)  
#define   MPU_REGION_SIZE_2KB      ((uint8_t)0x0AU)
#define   MPU_REGION_SIZE_4KB      ((uint8_t)0x0BU) 
#define   MPU_REGION_SIZE_8KB      ((uint8_t)0x0CU) 
#define   MPU_REGION_SIZE_16KB     ((uint8_t)0x0DU) 
#define   MPU_REGION_SIZE_32KB     ((uint8_t)0x0EU) 
#define   MPU_REGION_SIZE_64KB     ((uint8_t)0x0FU) 
#define   MPU_REGION_SIZE_128KB    ((uint8_t)0x10U)
#define   MPU_REGION_SIZE_256KB    ((uint8_t)0x11U)
#define   MPU_REGION_SIZE_512KB    ((uint8_t)0x12U)
#define   MPU_REGION_SIZE_1MB      ((uint8_t)0x13U) 
#define   MPU_REGION_SIZE_2MB      ((uint8_t)0x14U) 
#define   MPU_REGION_SIZE_4MB      ((uint8_t)0x15U) 
#define   MPU_REGION_SIZE_8MB      ((uint8_t)0x16U) 
#define   MPU_REGION_SIZE_16MB     ((uint8_t)0x17U)
#define   MPU_REGION_SIZE_32MB     ((uint8_t)0x18U)
#define   MPU_REGION_SIZE_64MB     ((uint8_t)0x19U)
#define   MPU_REGION_SIZE_128MB    ((uint8_t)0x1AU)
#define   MPU_REGION_SIZE_256MB    ((uint8_t)0x1BU)
#define   MPU_REGION_SIZE_512MB    ((uint8_t)0x1CU)
#define   MPU_REGION_SIZE_1GB      ((uint8_t)0x1DU) 
#define   MPU_REGION_SIZE_2GB      ((uint8_t)0x1EU) 
#define   MPU_REGION_SIZE_4GB      ((uint8_t)0x1FU)
/**                                
  * @}
  */
   
/** @defgroup CORTEX_MPU_Region_Permission_Attributes CORTEX MPU Region Permission Attributes 
  * @{
  */
#define  MPU_REGION_NO_ACCESS      ((uint8_t)0x00U)  
#define  MPU_REGION_PRIV_RW        ((uint8_t)0x01U) 
#define  MPU_REGION_PRIV_RW_URO    ((uint8_t)0x02U)  
#define  MPU_REGION_FULL_ACCESS    ((uint8_t)0x03U)  
#define  MPU_REGION_PRIV_RO        ((uint8_t)0x05U) 
#define  MPU_REGION_PRIV_RO_URO    ((uint8_t)0x06U)
/**
  * @}
  */

/** @defgroup CORTEX_MPU_Region_Number CORTEX MPU Region Number
  * @{
  */
#define  MPU_REGION_NUMBER0    ((uint8_t)0x00U)  
#define  MPU_REGION_NUMBER1    ((uint8_t)0x01U) 
#define  MPU_REGION_NUMBER2    ((uint8_t)0x02U)  
#define  MPU_REGION_NUMBER3    ((uint8_t)0x03U)  
#define  MPU_REGION_NUMBER4    ((uint8_t)0x04U) 
#define  MPU_REGION_NUMBER5    ((uint8_t)0x05U)
#define  MPU_REGION_NUMBER6    ((uint8_t)0x06U)
#define  MPU_REGION_NUMBER7    ((uint8_t)0x07U)
