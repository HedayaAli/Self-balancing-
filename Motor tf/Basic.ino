/* Encoder Library - Basic Example
 * http://www.pjrc.com/teensy/td_libs_Encoder.html
 *
 * This example code is in the public domain.
 */

#include <Encoder.h>

// Change these two numbers to the pins connected to your encoder.
//   Best Performance: both pins have interrupt capability
//   Good Performance: only the first pin has interrupt capability
//   Low Performance:  neither pin has interrupt capability
Encoder myEnc(5, 6);
//   avoid using pins with LEDs attached
int Motor1 = 7;
int Motor2 = 8;
void setup() {
  pinMode(Motor1, OUTPUT);
  pinMode(Motor2, OUTPUT);
  
  Serial.begin(9600);
  Serial.println("Basic Encoder Test:");
  digitalWrite(Motor1, LOW);
  digitalWrite(Motor2, HIGH);
}

long oldPosition  = -999;

void loop() {
  long newPosition = myEnc.read();
  if (newPosition != oldPosition) {
    oldPosition = newPosition;
    Serial.println(newPosition);
  }
}
