
/*--------------------------------GPIO----------------------------------------------*/

#define GPIOA_BASE 				0x48000000u
#define GPIOB_BASE 				0x48000400u
#define	GPIOC_BASE				0x48000800u
#define GPIOD_BASE 				0x48000C00u
#define GPIOE_BASE 				0x48001000u
#define GPIOF_BASE 				0x48001400u

#define GPIOA_AFRL 				*((volatile unsigned int*)(GPIOA_BASE+0x20))
#define GPIOA_AFRH              *((volatile unsigned int*)(GPIOA_BASE+0x24))
/*----------------------------------------------------------------------------------*/


/*--------------------------------SYSTICK--------------------------------------------*/

#define STK_CSR					*((volatile unsigned int*)0xE000E010)
#define	STK_RVR					*((volatile unsigned int*)0xE000E014)
#define	STK_CVR					*((volatile unsigned int*)0xE000E018)
#define	STK_CALIB				*((volatile unsigned int*)0xE000E01C)
/*----------------------------------------------------------------------------------*/


/*--------------------------------NVIC--------------------------------------------------*/
#define ISER 					*((volatile unsigned int*)0xE000E100)
#define ICER 					*((volatile unsigned int*)0xE000E180)
#define ISPR 					*((volatile unsigned int*)0xE000E200)
#define ICPR 					*((volatile unsigned int*)0xE000E280)
/*----------------------------------------------------------------------------------*/


/*---------------------------------EXINT---------------------------------------------*/
#define EXINT_BASE              0x40010400
#define EXTI_IMR				*((volatile unsigned int*)(EXINT_BASE+0x00))
#define EXTI_RTSR				*((volatile unsigned int*)(EXINT_BASE+0x08))
#define EXTI_FTS				*((volatile unsigned int*)(EXINT_BASE+0x0C))
#define EXTI_EMR				*((volatile unsigned int*)(EXINT_BASE+0x04))
#define	EXTI_PR					*((volatile unsigned int*)(EXINT_BASE+0x14))
/*----------------------------------------------------------------------------------*/


/*---------------------------------SYSCFG---------------------------------------------*/
#define SYSCFG 					        0x40010000
#define SYSCFG_EXTICR1          *((volatile unsigned*)(SYSCFG+0x08))
/*----------------------------------------------------------------------------------*/



/*---------------------------------RCC-----------------------------------------*/

#define RCC_BASE				0x40021000u
#define RCC_CR 					*((volatile unsigned int*)RCC_BASE)
<<<<<<< HEAD
#define RCC_CFGR				*((volatile unsigned int*)(RCC_BASE+0x04u))
#define RCC_AHBENR				*((volatile unsigned int*)(RCC_BASE+0x14u))
#define RCC_APB2ENR             *((volatile unsigned int*)(RCC_BASE+0x18u))
=======
#define RCC_CFGR				*((volatile unsigned int*)(RCC_BASE+0x04))
#define RCC_AHBENR			*((volatile unsigned int*)(RCC_BASE+0x14))
>>>>>>> c8f94a7adbad3f3ba2b37813cba638ce6829ae4d

/*------------------------------------------------------------------------------*/




/*---------------------------------FLASH----------------------------------------*/

#define FLASH_BASE              0x08000000u
#define FLASH_ACR               *((volatile unsigned int*)(FLASH_BASE+0x00u))
#define FLASH_KEYR              *((volatile unsigned int*)(FLASH_BASE+0x04u))
#define FLASH_OPTKEYR           *((volatile unsigned int*)(FLASH_BASE+0x08u))
#define FLASH_SR                *((volatile unsigned int*)(FLASH_BASE+0x0Cu))
#define FLASH_CR                *((volatile unsigned int*)(FLASH_BASE+0x10u))
#define FLASH_AR                *((volatile unsigned int*)(FLASH_BASE+0x14u))
#define FLASH_OBR               *((volatile unsigned int*)(FLASH_BASE+0x1Cu))
#define FLASH_WRPR              *((volatile unsigned int*)(FLASH_BASE+0x20u))

/*-----------------------------------------------------------------------------*/



/*--------------------------------USART----------------------------------------*/
#define USART1_BASE             0x40013800u
#define USART_CR1               *((volatile unsigned int*)(USART1_BASE+0))
#define USART_CR2               *((volatile unsigned int*)(USART1_BASE+0x04u))
#define USART_BRR               *((volatile unsigned int*)(USART1_BASE+0x0Cu))
#define USART_ISR               *((volatile unsigned int*)(USART1_BASE+0x1Cu))
#define USART_TDR               *((volatile unsigned int*)(USART1_BASE+0x28u))


/*-----------------------------------------------------------------------------*/



/*---------------------------------function-----------------------------------------*/

void init_clk(unsigned int port);
void pin_set(unsigned int port,unsigned pin, unsigned int value);
unsigned int read_bit(unsigned int reg, unsigned int bit);
void delay_ms(unsigned int time);
void external_interrupt_init();
void pll_48_config();
void erase_flash(unsigned int* address);
void usart_init();
/*------------------------------------------------------------------------------*/



