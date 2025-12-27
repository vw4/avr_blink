#include <avr/io.h>
#include <util/delay.h>

int main(void) {
    // Arduino Uno LED on PB5 (D13)
    DDRB |= (1 << DDB5);
    // 1Hz square signal generation
    while (1) {
        PINB = (1 << PINB5);
        _delay_ms(500);
    }
}
