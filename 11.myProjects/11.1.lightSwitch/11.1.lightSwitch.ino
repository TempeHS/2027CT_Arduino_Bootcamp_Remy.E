/*
  Author:
  Learning Intention: Students will use a range of simple sensors to control an LED UI

  Student Notes:
  1. Make sure you include a copy of your schematic
  2. Students should use either the button or potentiometer in an unconventional way

  3. Suggested Grove ports: Button D4, Potentiometer A0, LED D6, Light sensor A3
*/

const int BUTTON_PIN = 4;  // Grove Button on D4
const int LED_PIN = 6;
const int TIME_TO_DOUBLE_PRESS = 600; // ms

void setup() {
  pinMode(LED_PIN, OUTPUT);
  pinMode(BUTTON_PIN, INPUT);
}

void loop() {
  if (digitalRead(BUTTON_PIN)) {
    int startTime = millis();
    while (millis() - startTime < TIME_TO_DOUBLE_PRESS) {
      if (digitalRead(BUTTON_PIN)) {
        digitalRead(LED_PIN) ? digitalWrite(LED_PIN, 0) : digitalWrite(LED_PIN, 1);
      }
    }
  }
}
