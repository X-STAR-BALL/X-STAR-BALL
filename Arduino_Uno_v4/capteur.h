/**************************************************
 * Programme aspect CAPTEURS
 * ------------------------------------------------
 *  --------------------------
 * |CF1                    CF2|
 * |                          |
 * |                          |
 * |                          |
 * |CF3                    CF4|
 *  --------------------------
**************************************************/

#include "debug.h"
#include <math.h>

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
float cooX;          //Coordonnées en X à un instant
float cooY;          //Coordonnées en Y à un instant
uint32_t temps = 0;
int maxi = 0;

//--------- Target
class TargetTracker {
  private:
    int cote_cible;
    int range_capteurs;

  public:
    TargetTracker(int cote_cible = 100, int range_capteurs = 1024) {
      this->cote_cible = cote_cible;
      this->range_capteurs = range_capteurs;
    }

    int calculate_hit_position(int pressure_sensor1, int pressure_sensor2, int pressure_sensor3, int pressure_sensor4) {
      int corner_x[4] = {0, cote_cible, 0, cote_cible};
      int corner_y[4] = {cote_cible, cote_cible, 0, 0};

      int min_x = 0;
      int max_x = cote_cible;
      int min_y = 0;
      int max_y = cote_cible;

      double pressures[4] = {
        (double)pressure_sensor1 / range_capteurs,
        (double)pressure_sensor2 / range_capteurs,
        (double)pressure_sensor3 / range_capteurs,
        (double)pressure_sensor4 / range_capteurs
      };

      double min_sum_distance = INFINITY;
      int best_x = 0;
      int best_y = 0;

      for (int x = min_x; x <= max_x; x++) {
        for (int y = min_y; y <= max_y; y++) {
          double sum_distance = calculate_distance(x, y, corner_x, corner_y, pressures);
          if (sum_distance < min_sum_distance) {
            min_sum_distance = sum_distance;
            best_x = x;
            best_y = y;
          }
        }
      }

      return best_x + (best_y << 8); // Combine x and y into a single int
    }

  private:
    double calculate_distance(int x, int y, int corner_x[], int corner_y[], double pressures[]) {
      double total_distance = 0;
      double weighted_distance = 0;
      for (int i = 0; i < 4; i++) {
        double distance = sqrt(pow(corner_x[i] - x, 2) + pow(corner_y[i] - y, 2));
        weighted_distance = pow(distance * pressures[i], 2);
        total_distance += weighted_distance;
      }
      return total_distance;
    }
};

//--------- Fonctions
void capteursAZero(){
  CF1.maxi   = CF2.maxi   = CF3.maxi   = CF4.maxi   = 0;
  CF1.mesure = CF2.mesure = CF3.mesure = CF4.mesure = 0;
}

void maxCap(){
  maxi = 0;
  temps = millis();
  while(millis() < temps + 2000){
    if(analogRead(CF1.broche) > CF1.maxi){
      CF1.maxi = analogRead(CF1.broche);
    }
    if(analogRead(CF2.broche) > CF2.maxi){
      CF2.maxi = analogRead(CF2.broche);
    }
    if(analogRead(CF3.broche) > CF3.maxi){
      CF3.maxi = analogRead(CF3.broche);
    }
    if(analogRead(CF4.broche) > CF4.maxi){
      CF4.maxi = analogRead(CF4.broche);
    }
  } 
    debugCap("CF1 = " + String(CF1.maxi) +"\t |" +
             "CF2 = " + String(CF2.maxi) +"\t |" +
             "CF3 = " + String(CF3.maxi) +"\t |" +
             "CF4 = " + String(CF4.maxi) +"\t |\n");
}

void getCoo() {
  TargetTracker tracker;
      int hit_position = tracker.calculate_hit_position(CF1.maxi, CF2.maxi, CF3.maxi, CF4.maxi);
      cooX = hit_position & 0xFF; // Extract x
      cooY = hit_position >> 8; // Extract y
      debugCap("Coordonnées optimales (x, y) où la balle a touché la cible : (" +
               String(cooX) + ", " + String(cooY)+") \n");
}

