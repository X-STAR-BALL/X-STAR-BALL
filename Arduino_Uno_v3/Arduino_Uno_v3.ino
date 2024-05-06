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
  maxCap();
  if((CF1.maxi !=0)||(CF2.maxi !=0)||(CF3.maxi !=0)||(CF4.maxi !=0)){
    getCoo();
    String message = String(cooX) + "/" + String(cooY);
    debugBluetooth("message = " + message); 
  }
}
