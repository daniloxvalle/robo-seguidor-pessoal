#define 	FALSE	0
#define 	TRUE	-1

#define ADC_PRESCALE_DIV32		0x05	// 0x05 -> CPU clk/32
#define ADC_REFERENCE_AVCC		0x01	// 0x01 -> define a tensão de referência AREF=AVCC 5V

// inicializa o conversor a2d
void a2dInit(void);

// configura o clock da CPU por divisão
void a2dSetPrescaler(unsigned char prescale);

// configura a voltagem de referência
void a2dSetReference(unsigned char ref);

// retorna o valor da conversão em 10 bits
unsigned short a2dConvert10bit(unsigned char ch);

// retorna o valor da conversão em 8 bits
unsigned char a2dConvert8bit(unsigned char ch);
