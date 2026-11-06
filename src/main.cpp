/*
 * Basic Arduino Template - Blink
 * ------------------------------
 * Blinks an LED connected to pin 13, once per second.
 *
 * Wiring: plug the LED straight into the top header of the UNO.
 *   - long leg  (+, anode)   -> pin 13
 *   - short leg (-, cathode) -> GND (right next to pin 13)
 *   (a 220 ohm resistor in series is the safer habit for LEDs)
 * The UNO's built-in "L" LED is also on pin 13, so it blinks too.
 *
 *              _____
 *             /     \
 *             | LED |
 *             |_____|
 *              |   |
 *          (-) |   | (+)
 *       short  |   |  long leg
 *   +----------|---|--------------------------------+
 *   |  AREF  GND  13   12   11   10    9    8      |
 *   |                                               |
 *   |  [USB]          ARDUINO UNO                   |
 *   |                                               |
 *   |  [PWR]                                        |
 *   +-----------------------------------------------+
 *
 * Every Arduino sketch has two required functions:
 *   setup() -> runs ONCE when the board powers on or is reset
 *   loop()  -> runs AGAIN AND AGAIN, forever, after setup() finishes
 *
 * In PlatformIO (unlike the Arduino IDE) we must include Arduino.h
 * ourselves. It gives us pinMode(), digitalWrite(), delay(), etc.
 */
#include <Arduino.h>

#define sensLuz A0
#define ledPin 13

int valorSensLuz = 0;
int asEscuras = 200;

void setup() {
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, LOW);
}

void loop() {
  valorSensLuz = analogRead(sensLuz);
  Serial.println(valorSensLuz);
  if (valorSensLuz < asEscuras) {
    digitalWrite(ledPin, HIGH);
  } else {
    digitalWrite(ledPin, LOW);
  }
  delay(1);
}