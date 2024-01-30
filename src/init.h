//Inicializa o PWM
void pwm_init();

//Inicializa Sensores de Distância
void liga_sensores_distancia();

//Inicializa Sensor de Posição
void liga_sensor_posicao();

//Espera o numero de ciclos
void delay(unsigned long int cycles);

//Pisca o LED
void pisca_led();

//Retorna o maximo de 3 numeros, usado para sensores de posição
int maximo3(int a,int b,int c);
