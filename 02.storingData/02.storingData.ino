/*
  Author: Remy E

  Learning Intention:
  The students will learn the different data types used in the C++ language,
  watch an integer overflow live, and understand variable scope.

  Success Criteria:
    1.  I understand and can store variables in the datatypes String, int, float, long and bool
    2.  I know how to access more information about the different datatypes in the documentation
    3.  I understand how (1, HIGH and true) and (0, LOW and false) all represent the same concept
    4.  I can convert an int, float and bool to a String and print it to the serial monitor
    5.  I understand the difference between an int and an unsigned int, and a long and an unsigned long
    6.  I understand the difference between a global variable and a function (local) variable

  Hardware:
    None needed. Serial Monitor at 115200 baud.

  Documentation:
    https://www.arduino.cc/reference/en/#variables
    https://www.arduino.cc/reference/en/language/variables/data-types/stringobject/
*/

int    counter       = 3000;
float  temperature = 23.5;
long   bigNumber   = 100000;
bool   isOn        = HIGH;
String deviceName  = "My Arduino";

void setup() {
  Serial.begin(115200);
  Serial.println("Name: " + deviceName);
  Serial.println("Count: " + String(counter));
  Serial.println("Temperature: " + String(temperature));
  Serial.println("Big number: " + String(bigNumber));
  Serial.println("Switched on: " + String(isOn));
}

void loop() {
  counter = counter + 1000;
  Serial.println(counter);
  delay(300);
}
