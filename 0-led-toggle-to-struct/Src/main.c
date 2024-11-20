// LED is at:
// Port B
// Pin  3

#include <stdint.h>

#define PERIPH_BASE			(0x40000000UL)

#define AHB1_PERIPH_OFFSET	(0x00020000UL)

#define RCC_OFFSET			(0x1000UL)
#define RCC_BASE			(PERIPH_BASE + AHB1_PERIPH_OFFSET + RCC_OFFSET)

#define AHB2_PERIPH_OFFSET 	(0x08000000UL)
#define AHB2_PERIPH_BASE	(PERIPH_BASE + AHB2_PERIPH_OFFSET)

#define GPIOB_OFFSET		(0x00000400UL)
#define GPIOB_BASE			(AHB2_PERIPH_BASE + GPIOB_OFFSET)


#define GPIOBEN				(1U<<1)
#define PIN3				(1U<<3)
#define LED_PIN				PIN3

typedef struct {
	volatile uint32_t MODER;
	volatile uint32_t PADDING_FOR_ADDRESSES[4];
	volatile uint32_t ODR;

}GPIO_TypeDef;

typedef struct {
	volatile uint32_t PADDING_FOR_RCC[19];
	volatile uint32_t RCC_AHB2ENR;
}RCC_TypeDef;


#define RCC					((RCC_TypeDef*) RCC_BASE)
#define GPIOB				((GPIO_TypeDef*)GPIOB_BASE)


int main(void) {

	RCC->RCC_AHB2ENR |= GPIOBEN;

	GPIOB->MODER |= (1U<<6);
	GPIOB->MODER &=~(1U<<7);

	while (1) {

		GPIOB->ODR ^= LED_PIN;
		for (int i = 0; i < 100000; i++);
	}


}



