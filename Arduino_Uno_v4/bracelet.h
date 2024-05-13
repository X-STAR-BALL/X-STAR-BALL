/**************************************************
 * Programme aspect BRACELET
 **************************************************/

#define BRACELET   false      //Si on utilise le bracelet : true / Si on utilise la liaison au PC : false

SoftwareSerial Bracelet(2,3);   //Port D2

//--------- Variables
uint32_t timer = 0;
int duree;                //Durée en millisecondes
int distance = 5;         //Distance en mètres
float vit;                //Vitesse en m/s
bool lance = false;

void initBracelet(){
  if(BRACELET){
  Bracelet.begin(9600);
  pinMode(2, INPUT);
  pinMode(3, OUTPUT);
  debugBracelet("Liaison bracelet configuré");
  }
}

void checkTimer(){
  
  if(BRACELET){
    if(Bracelet.read()){
      timer = millis();
      if(lance){
        Bluetooth.print("r");
        debugBracelet("r");
      }
      else{
        lance = true;
      }
    }
  }
  else{
    String mes = String(Serial.read());
    //debugBracelet(mes);
    if(mes=="49"){
      timer = millis();
      if(lance){
        Bluetooth.print("r");
        debugBracelet("r");
      }
      else{
        lance = true;
      }
    }
  }
}

void calculVit(){
  duree = millis() - timer;
  vit = distance / (duree/100);
  lance = false;
}