/*
  AnalogInToSerial_Time3Chan

  Reads 3 analog input pins, and prints the time and results to the Serial Monitor.

  Created 1/15/21 by DJ based on AnalogInToSerial.
  Updated 3/6/21 by DJ - make sampling rate more constant
  Updated 6/8/21 by DJ - renamed from AnalogInToSerial_Time3Chan_v2
*/

// Declare Constants & Initialize Variables
const int inputPins[] = {A0, A1, A2};           // Analog input pins
unsigned long currentTime = 0;                  // time
unsigned long nextTime = 0;                     // time to record sample
int sensorValue = 0;                            // value read from the analog input pin
int i = 0;                                      // counter
const unsigned int fs = 500;                    // sampling rate in Hz (max should be 500)
const unsigned int delayTimeMs = (1000/fs);     // ms to wait between samples


// Run once on startup
void setup() {
  // initialize serial communications at 500000 bps:
  Serial.begin(500000);
  currentTime = millis(); 
}


// Run repeatedly
void loop() {

  // get the current time
  while (currentTime<nextTime) {
    currentTime = millis(); 
  }

  // print the time to the Serial Monitor
  Serial.print(currentTime);
  Serial.print(" ");

  // read and print the analog input values
  for (i=0; i<3; i++) {
    // read the analog in value:
    sensorValue = analogRead(inputPins[i]);
    // print the value
    Serial.print(sensorValue);
    Serial.print(" ");
  }
  // print the results to the Serial Monitor:
  Serial.println();

  // wait to keep the sampling rate constant:
  nextTime = nextTime+delayTimeMs;
}
