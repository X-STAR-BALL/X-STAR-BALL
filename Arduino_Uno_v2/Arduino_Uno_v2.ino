/* Programme principal de l'arduino dans X-STARS-BALL
 * --------------------------------------------------
 * V 1
 * 21-04-2024
 * Par Cloé et Luc
 * --------------------------------------------------
 * V 1 - TERMINÉE
 *  - Établi une connection bluetooth
 * --------------------------------------------------
 * V 2 - En cours
 *  - 
 */


#include "bluetooth.h"

//--------- Variables

void setup() {
  Serial.begin(9600);
  initBluetooth();
  debug("Init finie");
}

void loop() {
  capteursAZero();
  mesureCF();
  Bluetooth.print(getCooX());
  Bluetooth.print('/');
  Bluetooth.print(getCooY());
  Bluetooth.print('//');
  
  if(DEBUGBLUETOOTH){
    Serial.print(getCooX());
    Serial.print('/');
    Serial.print(getCooY());
    Serial.print("\n");
  }
  delay(2000);
}
