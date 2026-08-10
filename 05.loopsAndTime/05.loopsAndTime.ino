/*
  Author:

  Learning Intention:
  The students will apply loop logic (count, pre-test and post-test loops) and manage
  time responsively with millis() instead of blocking with delay().

  Success Criteria:
    1.  I understand loop logic is repeating (or not) based on a true or false answer
    2.  I can apply comparison operators in count (for) and pre-test (while) loops
    3.  I understand a post-test (do while) loop runs its body at least once
    4.  I can iterate over an array with a for-each loop
    5.  I can detect and fix an infinite loop
    6.  I understand why delay() is blocking and not preferred for time event management
    7.  I can use millis() and binary logic to trigger events by time
    8.  I can seed and generate a random number
    9.  I understand micros() exists for microsecond timing
    10. I can read a simple logic flowchart

  Hardware (Grove cables to the base shield):
    Button module  -> D4
    LED module     -> D6
    Buzzer module  -> D5

  Student Notes:
    See the four loop flowcharts in this folder's Readme.md.

  Optional breadboard reference:
    Bootcamp-workingWithTime.png in this folder.

  Documentation:
    https://www.arduino.cc/reference/en/#structure
    https://www.arduino.cc/reference/en/language/functions/time/millis/
    https://www.arduino.cc/reference/en/language/functions/random-numbers/random/
*/

const int BUTTON_PIN = 4;  // Grove Button on D4
const int BUZZER_PIN = 5;  // Grove Buzzer on D5
const int LED_PIN = 6;     // Grove LED on D6
const int PRESSED_STATE = HIGH;

// `for (int i = 0; i < 10; i++) {` prints: 0-9
// `for (int i = 0; i <= 10; i++) {` prints: 0-10
// `for (int i = 10; i > 0; i = i - 2) {` prints: 10-2 in steps of 2

void setup() {
  randomSeed(analogRead(A1));
  Serial.begin(115200);

  pinMode(LED_PIN, OUTPUT);
  pinMode(BUTTON_PIN, INPUT);
}

void loop() {
  while (digitalRead(BUTTON_PIN) == PRESSED_STATE);

  unsigned long waitTime = random(2000, 5000);
  unsigned long waitStart = millis();

  while (millis() - waitStart < waitTime) {
    if (digitalRead(BUTTON_PIN) == PRESSED_STATE) {
      Serial.println("you lose");
      while (digitalRead(BUTTON_PIN) == PRESSED_STATE) {}
      return;
    }
  }

  unsigned long startTime = millis();
  digitalWrite(LED_PIN, HIGH);
  while (digitalRead(BUTTON_PIN) != PRESSED_STATE) {}
  Serial.println(String((millis() - startTime) / 1000.0) + "s");
  digitalWrite(LED_PIN, LOW);
}

