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

#include "debug.h"

//--------- Définition des capteurs
typedef struct{
  int broche;
  int maxi;
  int mesure;
} CF;

CF CF1 = {A0, 0, 0};
CF CF2 = {A1, 0, 0};
CF CF3 = {A2, 0, 0};
CF CF4 = {A3, 0, 0};



//--------- Variables
float HG;            //Proportion force CF1 (Haut Gauche)
float HD;            //Proportion force CF2 (Haut Droite)
float BD;            //Proportion force CF3 (Bas Droite)
float BG;            //Proportion force CF4 (Bas Gauche)
float cooX;          //Coordonnées en X à un instant
float cooY;          //Coordonnées en Y à un instant

//--------- Fonctions
void capteursAZero(){
  CF1.maxi   = CF2.maxi   = CF3.maxi   = CF4.maxi   = 0;
  CF1.mesure = CF2.mesure = CF3.mesure = CF4.mesure = 0;
}

void mesureCF(){
  while((analogRead(CF1.broche) == 0)&&(analogRead(CF2.broche) == 0)&&(analogRead(CF3.broche) == 0)&&(analogRead(CF4.broche) == 0)){
  delay(100);
  }
    CF1.mesure = analogRead(CF1.broche); 
    if(CF1.mesure > CF1.maxi){
      CF1.maxi = CF1.mesure;
    }

    debugCap("CF1 = " + String(CF1.maxi) + "\t |");

    CF2.mesure = analogRead(CF2.broche); 
    if(CF2.mesure > CF2.maxi){
      CF2.maxi = CF2.mesure;
    }

    debugCap(" CF2 = " + String(CF2.maxi) + "\t |");

    CF3.mesure = analogRead(CF3.broche); 
    if(CF3.mesure > CF3.maxi){
      CF3.maxi = CF3.mesure;
    }

    debugCap(" CF3 = " + String(CF3.maxi) + "\t |");

    CF4.mesure = analogRead(CF4.broche); 
    if(CF4.mesure > CF4.maxi){
      CF4.maxi = CF4.mesure;
    }

    debugCap(" CF4 = " + String(CF4.maxi) + "\n");

  
}

float getCooX(){
  HG = CF1.maxi;
  debugCap("HG = " + String(HG) + "\t |");
  HD = CF2.maxi;
  debugCap(" HD = " + String(HD) + "\t |");
  BD = CF3.maxi;
  debugCap(" BD = " + String(BD) + "\t |");
  BG = CF4.maxi;
  debugCap(" BG = " + String(BG) + "\t |");
  cooX = (HD + BD + 1)/(BG + HG + 1);
  debugCap("cooX = " + String(cooX) + "\n");
  return cooX;
}

float getCooY(){
  HG = CF1.maxi;
  debugCap("HG = " + String(HG) + "\t |");
  HD = CF2.maxi;
  debugCap(" HD = " + String(HD) + "\t |");
  BD = CF3.maxi;
  debugCap(" BD = " + String(BD) + "\t |");
  BG = CF4.maxi;
  debugCap(" BG = " + String(BG) + "\t |");
  cooY = (HG + HD + 1)/(BD + BG + 1);
  debugCap("cooY = " + String(cooY) + "\n \n");
  return cooY;
}

