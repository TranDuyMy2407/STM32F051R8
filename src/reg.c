#include "../inc/reg.h"

void pll_48_config()
{
  
  
  /*use HSI */
  RCC_CR |= 1<<0;


  /*wait for HSI switched  */       
  while( !read_bit(RCC_CR,1) ) ;   
  

  /*disable PLL*/
  RCC_CR &= ~(1<<24);


  /*set PLL muiltiplier to 12 */
  RCC_CFGR &= ~(0xF<<18);
  RCC_CFGR |= 0xA<<18;

  /*enable PLL*/
  RCC_CR |= 1<<24;

  /*wait PLL flag set*/
  while(!read_bit(RCC_CR,25));

  /*use PLL as system clock*/
  RCC_CFGR &= ~(3<<0);   
  RCC_CFGR |= 1<<1;

  /*wait*/
  while((RCC_CFGR & 3<<2) != (2<<2));

}

unsigned int read_bit(unsigned int reg, unsigned int bit)
{
    unsigned int level = reg & (1<<bit);

    if(level > 0)
      return 1;

    else
      return 0;
}

void delay_ms(unsigned int time)
{
 
  STK_RVR = 47999-time;
  STK_CVR = 0;
  STK_CSR = 0x05;
  while(time--)
  {  
     
      while( !read_bit(STK_CSR,16));
  }
}

void init_clk(unsigned int port)
{
  if(port == GPIOA_BASE)
    RCC_AHBENR |= 1<<17;

  else if(port == GPIOB_BASE)
    RCC_AHBENR |= 1<<18;

  else if(port == GPIOC_BASE)
    RCC_AHBENR |= 1<<19;

  else if(port == GPIOD_BASE)
    RCC_AHBENR |= 1<<20;

  else if(port == GPIOE_BASE)
    RCC_AHBENR |= 1<<21;

  else if(port == GPIOF_BASE)
    RCC_AHBENR |= 1<<22;
}

void pin_set(unsigned int port,unsigned int pin, unsigned int value)
{
  
  unsigned int* moder = (unsigned int*)port, *odr = (unsigned int*)(port + 0x14);
  *moder |= 1<<(pin*2);

  if(value>0)
    *odr |= 1<<pin;
  else if(value == 0)
    *odr &= ~(1<<pin);
  
  
}

void erase_flash(unsigned int* address)
{
  //set OPTER bit in FLASH_CR
  FLASH_CR |= 1<<5;

  //set STRT to start erase
  FLASH_CR |= 1<<6;

  //wait until BSY bit is reset
  while(!read_bit(FLASH_SR,0));

  while (!read_bit(FLASH_SR,5))
  {
    FLASH_SR |= 1<<5;
  }

  FLASH_CR &= ~(1<<5);
}


void send_byte(unsigned char c)
{
  if(read_bit(USART_ISR,7))
    USART_TDR = (unsigned int)c;
}

void send_string(unsigned char *str)
{
    while (*str)
    {
      if(read_bit(USART_ISR,7))
      {
        send_byte(*str);
        str++;
      }
    }
    
}

