#include <DFRobot_sim808.h>
#include <SoftwareSerial.h>

/* Definition post-process des modules */
int gps_hours = 0;
int gps_minutes = 0;
int gps_seconds = 0;
String tpe_sport = "Velo";
String gps_loc = "N° JKJFGD";
String message_Content = String("J'ai chuté à :") + tpe_sport + String("GPS : ") + gps_loc + String(" Ceci est un message automatisée par un système de détection de chute expérimental");
char message_CharContent = message_Content.c_str();
#define PHONE_NUMBER  "+33643684909"
#define MESSAGE  message_CharContent

/* Definition post-process des modules */


DFRobot_SIM808 sim808(&Serial);




boolean getChute() {
  //verifie si on chute
  //plus tard
};

void SendSMS() {
  sim808.sendSMS(PHONE_NUMBER,MESSAGE);
};

void Call() {
  Serial.println("Appel des services d'urgences en cours...");
   sim808.callUp(PHONE_NUMBER);
 
}


void upddateGPS() {
    if(sim808.attachGPS()) {
        Serial.println("Le GPS s'active");
    }
    else  {
        Serial.println("ERREUR");
    }
  }
  }
}

void getGPS() {
   if (sim808.getGPS()) {
      Serial.print(sim808.GPSdata.year);
      Serial.print("/");
      Serial.print(sim808.GPSdata.month);
      Serial.print("/");
      Serial.print(sim808.GPSdata.day);
      Serial.print(" ");
      Serial.print(sim808.GPSdata.hour);
      Serial.print(":");
      Serial.print(sim808.GPSdata.minute);
      Serial.print(":");
      Serial.print(sim808.GPSdata.second);
      Serial.print(":");
      Serial.println(sim808.GPSdata.centisecond);
      Serial.print("latitude :");
      Serial.println(sim808.GPSdata.lat);
      Serial.print("longitude :");
      Serial.println(sim808.GPSdata.lon);
      Serial.print("speed_kph :");
      Serial.println(sim808.GPSdata.speed_kph);
      Serial.print("heading :");
      Serial.println(sim808.GPSdata.heading);
      Serial.println();
      sim808.detachGPS();
}
}
bool updateSim() {
      while(!sim808.init()) {
        delay(1000);
        Serial.print("Erreur avec l'initialisation de la sim808\r\n");
        return false;
    }
    Serial.println("Initialisation de la sim808 avec succés");
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
