/* Programme principal de l'arduino dans X-STARS-BALL
 * --------------------------------------------------
 * V 1
 * 23-02-2024
 * Par Cloé et Luc
 * --------------------------------------------------
 * V 1 - En cours
 *  - Initialisation des capteurs de pression et de force
 * --------------------------------------------------
 *  V 2 - A venir
 *  - Communication avec l'application mobile et le bracelet
 *  -------------------------------------------------
 *  V 3 - A venir
 *  - Répertorier les variables de chaque lancé :
 *    - Force de la balle
 *    - Vitesse de la balle
 *    - Balle réussie ? 
 */

#include "capteur.h"
#include "bluetooth.h"
#include "debug.h"

//--------- Variables
int   nbTt,           //Nombre de balles lancées au total
      nbT;            //Nombre de balles touchées

class lance{
  public:
    bool touche;          //Tir touché ?
    float force,          //Force de la balle
          vitesse,        //Vitesse de la balle
          distance,       //Distance lanceur-cible
          x,              //Coordonnées en x
          y;              //Coordonnées en y
};

void setup() {
  Serial.begin(9600);
  Bluetooth.begin(9600);
}

void loop() {
  
}
