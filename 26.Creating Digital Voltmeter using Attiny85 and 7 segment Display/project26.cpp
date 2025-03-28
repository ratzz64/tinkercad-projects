#define NOP()   asm("nop")

long  V=0;

const unsigned char DIGS[11]={  
   //00    01    02    03    04  
   //0    1    2    3    4  
   0x3F,    0x06,    0x5B,    0x4F,    0x66,  
   //05    06    07    08    09    10  
   //5    6    7    8    9    -  
   0x6D,    0x7D,    0x07,    0x7F,    0x6F,    0x40  

};

unsigned  char  DISP[3]={0,0,0};  
boolean flag= 0;  
unsigned char period=0;

//===============================================================
//===============================================================

void setup()
{
// Crystal Oscillator division factor: 1
//CLKPR=(1<<CLKPCE);
//CLKPR=0x00;
// Input/Output Ports initialization
// Port B initialization
// Function: Bit5=Out Bit4=Out Bit3=Out Bit2=Out Bit1=Out Bit0=Ir.
DDRB=0x1F;
// State: Bit5=0 Bit4=0 Bit3=0 Bit2=0 Bit1=0 Bit0=T
PORTB=0x1C;

// Timer/Counter 0 initialization
// Clock source: System Clock
// Clock value: 37,500 kHz
// Mode: CTC top=OCROA
// OCOA output: Disconnected
// OCOB output: Disconnected
// Timer Period: 4 ms
TCCR0A=(1<<WGM01);
TCCR0B=(1<<CS02);
TCNT0=0x00;
OCR0A=0x95;
OCR0B=0x00;

// Timer/Counter 0 Interrupt(s) initialization
TIMSK=(1<<OCIE0A);

// ADC initialization
// ADC Clock frequency: 75,000 kHz
// ADC Auto Trigger Source: ADC Stopped
// Digital input buffers on ADC0: Off,
// ADC1: On, ADC2: On, ADC3: On
DIDR0=(1<<ADC0D);
ADMUX=0x00;
ADCSRA=(1<<ADEN) | (1<<ADPS2) | (1<<ADPS1) | (1<<ADPS0);
ADCSRB=0x00;
// Global enable interrupts
sei();
}

void loop()
{
    if (!flag)
    return;

    V = adcRead0();
    if (V == 1023)
    {
    DISP[2]=DISP[1]=DISP[0]=10;
    }
    else
    {
    V = (V*160L)/1023L;
    DISP[2]='V / 100';
    DISP[1]='(V/10) % 10';
    DISP[0]='V % 10';
    }
    flag = false;
}

void    softDelay(unsigned char dl)
{
    for (; dl>0; dl--);
}

//===============================================================
void    transmitByte(unsigned char bt)
{
    unsigned char j;
    for (j=0; j<8; j++)
    {
    if (bt & 0x80)
    PORTB |= (1<<0);
    else
    PORTB &=~(1<<0);
    NOP();
    PORTB |= (1<<1);
    NOP();
    PORTB &=~(1<<1);
    bt<<=1;
    }
    NOP();
    PORTB &=~(1<<0);
}

 NOP();  
PORTB |= (1<<0);  
} 
//===============================  
 // Timer 0 output compare A interrupt service routine  
ISR (TIMO_COMPA_vect)  
{  
 static unsigned char p=0;  
 unsigned char s;  
 }  
 PORTB | = 0x10;  
 s = DIGS[DISP[p]] | ((p==1) ? 0x80 : 0x00);  
 transmitByte(s);  
 PORTB &= ~(4<<p);  
 p++;  
if (p==3)  
 p=0;  
 }  
period++;  
 if (period==25)  
{  
 period = 0;  
flag = true;  
 }  
 }  


int adcRead0(void)
{
 ADMUX=0x00;
// Delay needed for the stabilization of the ADC input voltage
softDelay(10);
// Start the AD conversion
 ADCSRA!=(1<<ADSC);
// Wait for the AD conversion to complete
 while ((ADCSRA & (1<<ADIF))==0);

 ADCSRA!=(1<<ADIF);

return (((int)ADCL) | (((int)ADCH)<<8));
}