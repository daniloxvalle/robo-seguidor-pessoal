#include <avr/io.h>
#include <avr/interrupt.h>
#include "a2d.h"

void pwm_init() {
	//seta o contador 1 (16 bits) para funcionar como gerador de PWM de dois canais
	TCCR1A = _BV(COM1A1)
       | _BV(COM1B1)
       | _BV(WGM11);
	TCCR1B = _BV(WGM13)
       	| _BV(WGM12)
	   	| _BV(CS10);
	ICR1 = 18182; //PWM de 55 Hz, periodo de 18,18ms
	OCR1A = 1500;
	OCR1B = 1500;
	DDRB = _BV(PB1)
    	| _BV(PB2); //seta pinos como saida (output)
}

void liga_sensores_distancia(){

	DDRC = 0x00;  // define todas as portas PC como input
	PORTC = 0x00; // desliga os "pull-up resistors"
	a2dInit(); 	// inicializa o conversor AD
	a2dSetPrescaler(ADC_PRESCALE_DIV32); // configura o clock da CPU
	a2dSetReference(ADC_REFERENCE_AVCC); // configura a voltagem de referência

}

void liga_sensor_posicao(){

	DDRD = 0x00;  // define todas as portas PD como input
	PORTD = 0x00; // desliga os "pull-up resistors"

}

void delay(unsigned long int cycles){
	while(cycles > 0)
		cycles--;
}

void pisca_led(){
	DDRD |= (1<<4); //liga pino 6 = PD4
	delay(70000);
	DDRD &= ~(1<<4); //desliga pino 6 = PD4
	delay(10000);
}

int maximo3(a,b,c){
	int i=0;
	if (a>=b) i=a; else i=b;
	if (c>=i) i=c;
	return i;
}

