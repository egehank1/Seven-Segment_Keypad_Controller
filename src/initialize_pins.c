/*
 * keys.c
 *
 * Created: 02.12.2024 
 * Author: EGEHAN KILIC
 * Description: Initialization for key/button input pins with pull-ups and interrupts.
 */

#include "initialize_pins.h"

// Define constants for bit masks
#define PIN_CHANGE_INTERRUPT_ENABLE (1 << PCIE1) // Enable pin change interrupt for PCINT[8:14]
// ATmega328/P seite 14. Einfach INTERRUPTS aktivieren reicht nicht mann mus die pins auch einzeln konfigurieren.
#define PIN_CHANGE_MASK (1 << PCINT8 | 1 << PCINT9) 

void keys_init() {
    DDRC = 0x00;     // Configure all PORTC pins as inputs
    PORTC = 0xFF;    // Enable pull-up resistors on all PORTC pins

    // Configure Pin Change Interrupts
    PCICR |= PIN_CHANGE_INTERRUPT_ENABLE; // Enable PCINT1 group
    PCMSK1 |= PIN_CHANGE_MASK;            // Warum nicht PCMSK2 oder 0 seite 95 ATmega328/p // PCINT 8 UND 9 benutzt welche zum msk1 gehören.
}
