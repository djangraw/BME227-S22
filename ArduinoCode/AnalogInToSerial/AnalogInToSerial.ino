/*
  AnalogInToSerial

  Reads an analog input pin, and prints the results to the Serial Monitor.

  Created 9/29/20 by DJ based on the Arduino example AnalogInOutSerial.
  Updated 1/15/21 by DJ - changed baud rate to 500k
*/

// These constants won't change. They're used to give names to the pins used:
const int analogInPin = A0;  // Analog input pin that the potentiometer is attached to
int sensorValue = 0;        // value read from the analog input pin

void setup() {
  // initialize serial communications at 500000 bps:
  Serial.begin(500000);
}

void loop() {
  // read the analog in value:
  sensorValue = analogRead(analogInPin);

  // print the results to the Serial Monitor:
  Serial.println(sensorValue);

  // wait 2 milliseconds before the next loop for the analog-to-digital
  // converter to settle after the last reading:
  delay(2);
}
