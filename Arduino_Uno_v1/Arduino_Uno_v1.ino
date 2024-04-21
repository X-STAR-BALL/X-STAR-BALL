/* Programme principal de l'arduino dans X-STARS-BALL
 * --------------------------------------------------
 * V 1.1
 * 21-04-2024
 * Par Cloé et Luc
 * --------------------------------------------------
 * V 1 - TERMINÉE
 *  - Établi une connection bluetooth
 */

#include "capteur.h"
#include "bluetooth.h"
#include "debug.h"

//--------- Variables

void setup() {
  Serial.begin(9600);
  Bluetooth.begin(9600);
}

void loop() {
  if(Serial.available)
    Bluetooth.print(Serial.read);
  if(Bluetooth.available)
    Serial.print(Bluetooth.read);
}