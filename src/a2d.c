#include <avr/io.h>
#include <avr/interrupt.h>

void a2dInit(void)
{
	// ADCSR = Analog Comparator Control and Status Register 8 bits
	ADCSR |= (1<<ADEN);			// liga o ADC
	ADCSR &= ~(1<<ADFR);			// define tipo de conversão simples
	a2dSetPrescaler(0x06);			// 0x06 -> CPU clk/64
	a2dSetReference(0x01);			// define AREF=AVCC 5V
	ADMUX &= ~(1<<ADLAR);		// ADLAR=0 ajuste a direita, ADCH e ADCL
	ADCSR |= (1<<ADIE);			// habilita interrupções do conversor
}

// configura o clock da CPU
void a2dSetPrescaler(unsigned char prescale)
{
	ADCSR = ((ADCSR & ~0x07) | prescale);
}

// configura a voltagem de referência
void a2dSetReference(unsigned char ref)
{
	ADMUX = ((ADMUX & ~0xC0) | (ref<<6));
}

unsigned short a2dConvert10bit(unsigned char ch)
{
	ADMUX = ((ADMUX & ~0x1F) | (ch & 0x1F)); // endereça o pino (ch)
	ADCSR |= (1<<ADIF);	// ADIF = 1 informa que a conversão terminou, no caso não iniciou
	ADCSR |= (1<<ADSC);	// ADSC = 1 inicia conversão
	while(bit_is_set(ADCSR, ADSC));		// espera até ADSC = 0 (conversão terminada)	
	return (ADCL | (ADCH<<8));		// retorna o valor da conversão (10 bits)
}

unsigned char a2dConvert8bit(unsigned char ch)
{
	return a2dConvert10bit(ch)>>2;		// shift left para pegar os 8 bits mais significativos
}
