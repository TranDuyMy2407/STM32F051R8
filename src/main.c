#include"../inc/reg.h"

int main()
{
	init_clk(GPIOC_BASE);
	pll_48_config();
	external_interrupt_init();

	while(1);
	
}

