#include"../inc/reg.h"

void Reserved_IRQHandler(void)
{
 while(1)
 {

 }
}

void NMI_Handler(void)
{
  while(1)
  {
    /* nothing to be run here */
  }
}

void HardFault_Handler(void)
{
  while(1)
  {
    /* nothing to be run here */
  }
}

void SVC_Handler(void)
{
  while(1)
  {
    /* nothing to be run here */
  }
}

void PendSV_Handler(void)
{
  while(1)
  {
    /* nothing to be run here */
  }
}

void SysTick_Handler(void)
{
  while(1)
  {
    /* nothing to be run here */
  }
}

void external_interrupt_init()
{
 
  SYSCFG_EXTICR1 &= 0xFFFFFFF0; 
  EXTI_RTSR |= 1;
  EXTI_IMR |= 1;
  ISER |= 1<<5;
}

void EXTI0_1_Handler()
{
  delay_ms(100);
  if(EXTI_PR == 1 && (EXTI_IMR & 1<<0)==1)
  {
    EXTI_PR |= 1<<0;

  }
}


void uart_interrupt_init()
{
  EXTI_RTSR |= 1;
  EXTI_IMR |= 1;
  ISER |= 1<<27;
}

void usart_init()
{

  //choose alternate function mode for pin PA9
  *((unsigned*)(GPIOA_BASE+0u)) &= ~(3<<18);
  *((unsigned*)(GPIOA_BASE+0u)) |= 1<<19;

 //choose alternate function mode for pin PA10
  *((unsigned*)(GPIOA_BASE+0u)) &= ~(3<<20);
  *((unsigned*)(GPIOA_BASE+0u)) |= 1<<21;

  //choose alternate function 1 (UART1) for pin PA9 (TX)
  GPIOA_AFRL &= ~(0xF0<<4);
  GPIOA_AFRL |= 1<<7;

   //choose alternate function 1 (UART1) for pin PA10 (RX)
  GPIOA_AFRH &= ~(0xF0<<8);
  GPIOA_AFRH |= 1<<11;


  //disabled USART1
  USART_CR1 |= 1<<0;

  //length data = 8 bit
  USART_CR1 &= ~(1<<28);
  USART_CR1 &= ~(1<<12);

  //no parity
  USART_CR1 &= ~(1<<10);

  //1 stop bit
  USART_CR2 &= ~(1<<12);

  //oversampling by 16
  USART_CR1 &= ~(1<<15);

//baudrate = 9600 ; f = 48M
  USART_BRR = 5000;

  //enable USART1, TX, RX 

  USART_CR1 &= ~(0xF<<0);
  USART_CR1 |= 0b1011;

}

void USART1_IRQHandler()
{

}