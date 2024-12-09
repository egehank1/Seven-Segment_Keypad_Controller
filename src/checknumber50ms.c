#include "checknumber50ms.h"

// Define constants for clarity
#define SEVEN_SEG_PORT DDRD
#define SEVEN_SEG_OUTPUT PORTD
#define CONTROL_PORT DDRB
#define CONTROL_OUTPUT PORTB
#define TIMER1_COMPARE_VALUE 1249  // Compare value for 80Hz (16MHz / 256 / 1250)

// Initialize 7-segment display and Timer1
void sevenseg_init() {
    // Configure 7-segment display port as output
    SEVEN_SEG_PORT = 0xFF;
    SEVEN_SEG_OUTPUT = 0x00; // Turn off all segments initially

    // Configure control port (optional, depending on hardware setup)
    CONTROL_PORT = 0xFF;
    CONTROL_OUTPUT = 0x00; // Initialize control port to off

    TCCR1B |= (1 << WGM12) | (1 << CS12); // CTC(clear timer on compare match) mode, prescaler 256
    TIMSK1 |= (1 << OCIE1A);  // seite 184 ATmega328/P
    OCR1A = TIMER1_COMPARE_VALUE;  // max value einsetzen
}
