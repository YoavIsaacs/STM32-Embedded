#define PERIPH_BASE			(0x40000000UL)

#define AHB1_PERIPH_OFFSET	(0x00020000UL)

#define RCC_OFFSET			(0x1000UL)
#define RCC_BASE			(PERIPH_BASE + AHB1_PERIPH_OFFSET + RCC_OFFSET)

#define AHB2_PERIPH_OFFSET 	(0x08000000UL)
#define AHB2_PERIPH_BASE	(PERIPH_BASE + AHB2_PERIPH_OFFSET)

#define GPIOB_OFFSET		(0x00000400UL)
#define GPIOB_BASE			(AHB2_PERIPH_BASE + GPIOB_OFFSET)

#define AHB2EN_R_OFFSET		(0x4CUL)
#define RCC_AHB2RN_R		(*(volatile unsigned int *)(RCC_BASE + AHB2EN_R_OFFSET))

#define MODE_R_OFFSET		(0x00000000UL)
#define GPIOB_MODE_R		(*(volatile unsigned int *)(GPIOB_BASE + MODE_R_OFFSET))

#define OD_R_OFFSET			(0x14UL)
#define GPIOB_OD_R			(*(volatile unsigned int *)(GPIOB_BASE + OD_R_OFFSET))

#define GPIOBEN				(1U<<1)
#define PIN3				(1U<<3)
#define LED_PIN				PIN3



int main(void) {
	RCC_AHB2RN_R |= GPIOBEN;

	GPIOB_MODE_R |= (1U<<6);
	GPIOB_MODE_R &=~(1U<<7);


	while (1) {
		GPIOB_OD_R ^= LED_PIN;
		for (int i = 0; i < 100000; i++);
	}


}



