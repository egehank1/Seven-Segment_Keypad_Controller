/*
 * P4_SteuerungSevenSeg.c
 *
 * Created: 02.12.2024
 * Author : EGEHAN KILIC
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>
#include "checknumber50ms.h"
#include "initialize_pins.h"

// Constants for better readability
#define BUTTON_UP PINC0
#define BUTTON_DOWN PINC1
#define SEGMENT_ERROR 0b11111111

volatile int number = 0;

// Function to get the segment data for a given digit
uint8_t get_digit_segments(int digit) {
    switch (digit) {
        case 0: return 0b01000000;
        case 1: return 0b01111001;
        case 2: return 0b00100100;
        case 3: return 0b00110000;
        case 4: return 0b00011001;
        case 5: return 0b00010010;
        case 6: return 0b00000010;
        case 7: return 0b01111000;
        case 8: return 0b00000000;
        case 9: return 0b00010000;
        default: return 0b11111111; // All off or error
    }
}


int main(void)
{
    // Initialize peripherals
    keys_init();
    sevenseg_init();
    sei(); // Enable global interrupts

    while (1) {
        // Main loop can remain empty as all work is done in ISRs
    }

    return 0;
}

// TIMER 1 COMPARE MATCH A Interrupt
ISR(TIMER1_COMPA_vect) {
    // Toggle segment selection (e.g., between tens and ones place)
    PORTB ^= 0x01;

    // Display tens or ones digit based on the state of PORTB
    if (PORTB & 0x01) {
        PORTD = get_digit_segments(number / 10); // Tens place
    } else {
        PORTD = get_digit_segments(number % 10); // Ones place
    }
}

// Pin Change Interrupt for buttons
ISR(PCINT1_vect) {
    // PC0 is pressed.
    if (!(PINC & (1 << BUTTON_UP))) {
        number = (number < 99) ? number + 1 : (number-99);
    }
    // Check the state of the DOWN button
    if (!(PINC & (1 << BUTTON_DOWN))) {
        number = (number > 0) ? number - 1 : (number+99);
    }
}
