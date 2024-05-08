#include <SoftwareSerial.h>

#define     cap     4

SoftwareSerial XSB(4,3);

void setup() {
  pinMode(4, INPUT);
  pinMode(3, OUTPUT);
  Serial.begin(9600);
  XSB.begin(9600);

}

void loop() {
  if(digitalRead(cap) == 1){
    XSB.print(1);
  }
}
