#include"../inc/reg.h"

int main()
{
	init_clk(GPIOC_BASE);
	pll_48_config();
	usart_init();

	while(1);
	
}

