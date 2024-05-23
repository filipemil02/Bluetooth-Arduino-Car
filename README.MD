# BMW.ino

This Arduino sketch is designed to control a simple robot car with four motors, a buzzer, and two LEDs. The car can be controlled via Bluetooth using specific commands.

## Features

- **Motor Control**: The car can move forward, backward, turn left, and turn right.
- **Buzzer**: The car can play a sound using the buzzer.
- **LED**: The car has two LEDs that can flash at two different voltage levels.
- **Bluetooth Control**: The car can be controlled via Bluetooth using specific app.

## Components
- Arduino Uno
- L298N Motor Driver
- HC-05 Bluetooth Module
- Buzzer
- LEDs
- Robot Car Chassis
- 4 DC Motors
- wires
- 9V Battery or 4 * 1.5V AA Batteries

## Installation
Install the application to your Android device, and connect to the Bluetooth module using the default password `1234`. Once connected, you can send commands to the Arduino to control the car.
 
## Commands

The car is controlled by sending single character commands via Bluetooth:

- `'F'` - Move Forward
- `'B'` - Move Backward
- `'L'` - Turn Left
- `'R'` - Turn Right
- `'H'` - Play the Buzzer
- `'S'` - Stop all actions
- `'1'` - Make the LED flash at a high voltage level

## Pin Configuration

The following pins are used in this sketch:

- Motors: `In1` (7), `In2` (6), `In3` (5), `In4` (4)
- Buzzer: `buzzer` (12)
- LED: `led` (11)
- Motor Speed Control: `ENA` (8), `ENB` (9)

## Setup

The `setup()` function initializes the pins as OUTPUT and starts the Serial communication at 9600 baud rate for Bluetooth communication.

## Loop

The `loop()` function continuously checks for available commands from the Serial port. Depending on the received command, it controls the motors, the buzzer, or the LED.

## Note

This code is written for Arduino and should be uploaded using the Arduino IDE. Ensure that the correct board and port is selected in the IDE before uploading the code.