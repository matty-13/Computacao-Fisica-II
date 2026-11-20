#include <Arduino.h>
#include "Gesture.h"

constexpr uint8_t LED_PIN = 6;

paj7620 gestureSensor;
bool sensorReady = false;

void setup() {
    pinMode(LED_PIN, OUTPUT);
    digitalWrite(LED_PIN, LOW);

    Serial.begin(9600);
    sensorReady = gestureSensor.init();
    if (sensorReady) {
        Serial.println("PAJ7620 initialization successful");
    } else {
        Serial.println("PAJ7620 initialization failed. Check the I2C connection.");
    }
}

void loop() {
    if (!sensorReady) {
        return;
    }

    paj7620_gesture_t gesture;
    if (!gestureSensor.getResult(gesture)) {
        return;
    }

    if (gesture == UP) {
        digitalWrite(LED_PIN, HIGH);
        Serial.println("UP detected - LED ON");
    } else if (gesture == DOWN) {
        digitalWrite(LED_PIN, LOW);
        Serial.println("DOWN detected - LED OFF");
    } else if (gesture == LEFT) {
        Serial.println("LEFT detected");
    } else if (gesture == RIGHT) {
        Serial.println("RIGHT detected");
    } else if (gesture == PUSH) {
        Serial.println("PUSH detected");
    } else if (gesture == POLL) {
        Serial.println("POLL detected");
    } else if (gesture == CLOCKWISE) {
        Serial.println("CLOCKWISE detected");
    } else if (gesture == ANTI_CLOCKWISE) {
        Serial.println("ANTI-CLOCKWISE detected");
    } else if (gesture == WAVE) {
        Serial.println("WAVE detected");
    }
}
