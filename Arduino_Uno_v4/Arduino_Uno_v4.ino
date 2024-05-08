/******************************************************************************************************
 * Programme principal de l'arduino dans X-STARS-BALL
 * ----------------------------------------------------------------------------------------------------
 * V 4
 * 08-05-2024
 * Par Cloé et Luc
 * ----------------------------------------------------------------------------------------------------
 * V 1 - TERMINÉE
 *  - Établie une connection bluetooth
 * ----------------------------------------------------------------------------------------------------
 * V 2 - TERMINÉE
 *  - Calcule les coordonnées à l'aide de la formule déduite par Luc
 * ----------------------------------------------------------------------------------------------------
 * V 3 - TERMINÉE
 *  - Calcule les coordonnées à l'aide d'un algorithme plus complexe
 * ----------------------------------------------------------------------------------------------------
 * V 4 - En cours
 *  - Calcule les coordonnées à l'aide de l'algorithme plus complexe, et fonctionne avec le timer de la liaison série / du bracelet
 ******************************************************************************************************/


#include "bluetooth.h"
#include "bracelet.h"

void setup() {
  Serial.begin(9600);
  initBluetooth();
  debug("Init finie");
}

void loop() {
  capteursAZero();
  maxCap();
  checkTimer();
  if((CF1.maxi !=0)||(CF2.maxi !=0)||(CF3.maxi !=0)||(CF4.maxi !=0)){
    getCoo();
    calculVit();
    String message = String(cooX) + "/" + String(cooY) + "/" + String(vit);
    debugBluetooth("message = " + message); 
    Bluetooth.print(message);
  }
}
