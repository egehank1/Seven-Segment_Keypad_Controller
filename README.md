# Seven Segment Keypad Controller 

A simple embedded systems project that connects a keypad input to a 7-segment display, allowing numeric input to be displayed in real time. Built to practice low-level hardware control, input handling, and embedded C/Arduino-style programming logic.

## Overview

This project demonstrates how a numeric keypad can be used to control a 7-segment display. Each key press is mapped to the corresponding segment pattern and rendered directly on the display.

The goal was to understand how input devices (keypads) and output components (7-segment displays) communicate through a microcontroller.

## Features

- Reads input from a matrix keypad
- Displays pressed digits on a 7-segment display
- Direct segment control (no heavy abstraction libraries)
- Real-time response to user input
- Clean mapping between keypad values and segment encoding

## How It Works

1. Keypad scans for pressed key
2. Input is decoded into a numeric value
3. Value is mapped to a 7-segment pattern
4. Corresponding segments are activated on the display

## Hardware Used

- Arduino Uno (or compatible board)
- 4x4 / 3x4 matrix keypad
- Common cathode / anode 7-segment display
- Resistors (220Ω recommended)
- Jumper wires
- Breadboard

## Wiring Concept

Keypad rows and columns are connected to digital input pins.  
Each segment (A–G, DP if used) is mapped to output pins on the microcontroller.

> The display is driven by activating specific combinations of pins depending on the number.

## Project Structure

```
src/
├── keypad.cpp / .ino
├── segment_map.h
└── main.ino
```

*(Structure may vary depending on version)*

## What I Learned

- How keypad matrix scanning works
- How 7-segment displays are driven at pin level
- How to map input values to hardware outputs
- Importance of clean pin management in embedded systems
- Handling hardware logic without relying heavily on libraries

## Possible Improvements

- Add multi-digit support (multiplexing)
- Use shift registers (74HC595) to reduce pin usage
- Add debounce handling for keypad input
- Convert into a timer / calculator / counter system
- Replace direct wiring with a driver IC (like MAX7219)

## Getting Started

Clone the repository:

```bash
git clone https://github.com/egehank1/Seven-Segment_Keypad_Controller.git
```

Open the project in Arduino IDE or your preferred embedded development environment, then upload to the board.

## Author

**Egehan Kılıç**

- GitHub: https://github.com/egehank1
- Portfolio: https://egehankilic.com
