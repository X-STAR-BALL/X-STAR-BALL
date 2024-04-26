/**************************************************
 * Programme aspect BLUETOOTH
 **************************************************
 * NOM : HC-05
 * PINCODE : 1234
 * 
 */

#include <SoftwareSerial.h>
#include "debug.h"

SoftwareSerial Bluetooth(4,5);   //Port D4

void initBluetooth(){
  Bluetooth.begin(9600);
  pinMode(4, INPUT);
  pinMode(5, OUTPUT);
  if(DEBUGBLUETOOTH == true)
    Serial.print("Bluetooth configuré");
}