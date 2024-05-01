/* Programme principal de l'arduino dans X-STARS-BALL
 * --------------------------------------------------
 * V 1
 * 21-04-2024
 * Par Cloé et Luc
 * --------------------------------------------------
 * V 1 - TERMINÉE
 *  - Établi une connection bluetooth
 */

#include "bluetooth.h"

//--------- Variables

void setup() {
  Serial.begin(9600);
  initBluetooth();
}

void loop() {
  if(Serial.available())
    Bluetooth.write(Serial.read());
  if(Bluetooth.available())
    Serial.write(Bluetooth.read());
}
