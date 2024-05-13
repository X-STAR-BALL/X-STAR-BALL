/****************************************
 * Liste des DEBUG
*****************************************/


#define DEBUG             true              //Debug général
#define DEBUGBLUETOOTH    true              //Debug bluetooth
#define DEBUGCAP          true              //Debug capteur
#define DEBUGBRACELET     true              //Debug capteur

void debug(String str){
  if(DEBUG){
    Serial.println(str);
  }
}
void debugBluetooth(String str){
  if(DEBUGBLUETOOTH){
    Serial.println(str);
  }
}

void debugCap(String str){
  if(DEBUGCAP){
    Serial.print(str);
  }
}

void debugBracelet(String str){
  if(DEBUGBRACELET){
    Serial.print(str);
  }
}