/**************************************************
 * Programme aspect CAPTEURS
 **************************************************
 *  --------------------------
 * |CF1                    CF2|
 * |                          |
 * |                          |
 * |                          |
 * |CF4                    CF3|
 *  --------------------------
**************************************************/

//--------- Définition des broches des capteurs
#define CF1  A0       //Capteur de force n°1
#define CF2  A1       //Capteur de force n°2
#define CF3  A2       //Capteur de force n°3
#define CF4  A3       //Capteur de force n°4

//--------- Variables
float HG;            //Proportion force CF1 (Haut Gauche)
float HD;            //Proportion force CF2 (Haut Droite)
float BD;            //Proportion force CF3 (Bas Droite)
float BG;            //Proportion force CF4 (Bas Gauche)
float cooX;          //Coordonnées en X à un instant
float cooY;          //Coordonnées en Y à un instant

//--------- Fonctions
void mesure(){
  mesure = analogRead(FSR_Pin); 
  if(mesure > maxi){
    maxi = mesure;
  }
}


float getCooX(){
  HG = analogRead(CF1)/1023 + 1;
  HD = analogRead(CF2)/1023 + 1;
  BD = analogRead(CF3)/1023 + 1;
  BG = analogRead(CF4)/1023 + 1;
  cooX = (HD+BD)/(BG + HG);
  return cooX;
}

float getCooY(){
  HG = analogRead(CF1)/1023 + 1;
  HD = analogRead(CF2)/1023 + 1;
  BD = analogRead(CF3)/1023 + 1;
  BG = analogRead(CF4)/1023 + 1;
  cooY = (HG+HD)/(BD + BG);
  return cooY;
}
