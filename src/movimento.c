#include <avr/io.h>
#include <avr/interrupt.h>

void frente(){ //servo B é ligeiramente mais forte que servo A
	OCR1A = 2000;
	OCR1B = 1050;
}

void frente_lento(){
	OCR1A = 1700;
	OCR1B = 1350;
}

void tras(){
	OCR1A = 1220;
	OCR1B = 1800;
}

void para(){
	OCR1A = 1500;
	OCR1B = 1500;
}

void gira_direita(){
	OCR1A = 1900;
	OCR1B = 1900;
}

void gira_esquerda(){
	OCR1A = 1150;
	OCR1B = 1150;
}
