/****************************************************************************

	25/06/2008
	UFES - Universidade Federal do Espírito Santo
	Projeto de Graduação
	Robô Seguidor Pessoal
	Danilo Xavier Valle

****************************************************************************/

#include <avr/io.h>
#include <avr/interrupt.h>
#include "movimento.h"
#include "init.h"
#include "a2d.h"

int main()
{	
	int perto=70;
	int medio=40;
	int longe=20;
	int sensor_3=0,sensor_2=0,sensor_1=0;
	int sensor_frente=0;

	liga_sensores_distancia();
	liga_sensor_posicao();
	pwm_init();
	
	pisca_led();

	while(1){

	if (bit_is_clear(PIND,0)){ //se alvo na frente, mantém distancia
		sensor_1=a2dConvert8bit(5); // pino PC5	
		sensor_2=a2dConvert8bit(4); // pino PC4 Central
		sensor_3=a2dConvert8bit(3); // pino PC3

		sensor_frente=maximo3(sensor_1,sensor_2,sensor_3);

		if(sensor_frente < longe){
			frente();
		}
		else if(sensor_frente < medio){
			frente_lento();
		}
		else if(sensor_frente > perto){
			tras();
		}
		else{
			para();
		}
	}else if (bit_is_clear(PIND,2)){ //leste vira direita
		gira_direita();
	}
	else if(bit_is_clear(PIND,3) || bit_is_clear(PIND,1)){ //oeste ou sul vira esquerda
		gira_esquerda();
	}
	else{
		para();
	}
			
	} // fecha while(1)

return 0;
}
