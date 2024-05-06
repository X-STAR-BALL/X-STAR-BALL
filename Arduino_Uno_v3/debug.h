/****************************************
 * Liste des debug
*****************************************/


#define DEBUG             true              //Debug général
#define DEBUGBLUETOOTH    false              //Debug bluetooth
#define DEBUGCAP          true              //Debug capteur

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