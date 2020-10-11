#include <DFRobot_sim808.h>
#include <sim808.h>

#define number  "33643684909"

int x = 0;
int y = 0;
int z = 0;

DFRobot_SIM808 Sim(&Serial)
#define SMSToSend  "SOS SOS je suis tomb� à " + x +","+ y +","+ 
z + " depuis " + ms + "";


boolean getChute() {
  //verifie si on chute
  //plus tard
}

void SendSMS() {
  Sim.sendSMS(number,SMSToSend);
}

void Call() {
  Serial.println("Appelle en cours...");
   Sim.callUp(number);
 
}


void upddateGPS() {
    if( SIM.attachGPS()) {
        Serial.println("Le GPS s'active");
    else  {
        Serial.println("ERREUR");

  }
}
}

void getGPS() {
   if (SIM.getGPS()) {
      Serial.print(SIM.GPSdata.year);
      Serial.print("/");
      Serial.print(SIM.GPSdata.month);
      Serial.print("/");
      Serial.print(SIM.GPSdata.day);
      Serial.print(" ");
      Serial.print(SIM.GPSdata.hour);
      Serial.print(":");
      Serial.print(SIM.GPSdata.minute);
      Serial.print(":");
      Serial.print(SIM.GPSdata.second);
      Serial.print(":");
      Serial.println(SIM.GPSdata.centisecond);
      Serial.print("latitude :");
      Serial.println(SIM.GPSdata.lat);
      Serial.print("longitude :");
      Serial.println(SIM.GPSdata.lon);
      Serial.print("speed_kph :");
      Serial.println(SIM.GPSdata.speed_kph);
      Serial.print("heading :");
      Serial.println(SIM.GPSdata.heading);
      Serial.println();
      sim808.detachGPS();
}
}
bool upadteSim() {
      while(!sim808.init()) {
        delay(1000);
        Serial.print("Erreur avec l'initialisation de la sim\r\n");
        return false;
    }
    Serial.println("Initialisation de la sim avec succés");
    return true;
}

void setup() {
   Serial.begin(9600);
   updateSim();
   if updateSim() == false {
    // Activer LED ERREUR FATALE
    break;
   }
}
   
void loop() {
    if(!getChute()) {
      return;
    } else if {
      getGPS();
       SendSMS();
    delay(2000);
    if(button==false){
      Call();
    }
  }
 }
