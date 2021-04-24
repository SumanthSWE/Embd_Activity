#include <avr/io.h>
#include<util/delay.h>
#include<avr/interrupt.h>

unsigned volatile FLAG = 0;
unsigned volatile FLAG1 = 0;

int main(void)
{
DDRB|=(1<<PB0); // set B0 for LED

DDRD&=~(1<<PD2); //clear bit
PORTD|=(1<<PD2); // set bit

DDRD&=~(1<<PD3); //clear bit
PORTD|=(1<<PD3);

EICRA|=(1<<ISC01)|(1<<ISC11);
//EICRA|=(0<<ISC01)|(0<<ISC11)|(0<<ISC00)|(0<<ISC10);
EIMSK|=(1<<INT0)|(1<<INT1);

sei();

    while(1){
            if(FLAG==1&&FLAG1==1) // press switch
            {
            PORTB|=(1<<PB0); // glow LED
            _delay_ms(6000);
            FLAG = 0;
            FLAG1 = 0;
            }
            else{
            PORTB&=~(1<<PB0); // turn off LED
            _delay_ms(1000);
            }
    }
    return 0;
}

ISR(INT0_vect)
{

    FLAG = 1;
}
ISR(INT1_vect)
{
    FLAG1 = 1;
}
