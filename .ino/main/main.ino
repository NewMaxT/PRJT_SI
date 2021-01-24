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
#define MESSAGE "Message temporaire censé inclure les coordonnées d'une variable String"  /* ERREUR DE CONVERSION const* char to char. Modification librairies */

DFRobot_SIM808 sim808(&Serial);

/* Definition fonctions secondaires */

boolean getChute() {
  //verifie si on chute
  //plus tard
  return false;
};

void SendSMS() {
  sim808.sendSMS(PHONE_NUMBER,MESSAGE);
};

void Call() {
  Serial.println("Appel des services d'urgences en cours...");
   sim808.callUp(PHONE_NUMBER);
 
}


void updateGPS() {
    if(sim808.attachGPS()) {
        Serial.println("Le GPS s'active");
    }
    else  {
        Serial.println("ERREUR");
    }
  }
  }
}

void getGPS() { // https://github.com/DFRobot/DFRobot_SIM808/blob/e13db3d4b80bd60c18ead13607f72c9947c34491/examples/SIM808_GetGPS/SIM808_GetGPS.ino#L58
   if (sim808.getGPS()) {
     // Latitude
    sim808.latitudeConverToDMS();
    Serial.print(sim808.latDMS.degrees);
    Serial.print(sim808.latDMS.minutes);
    Serial.print(sim808.latDMS.seconds,6);
    Serial.println(sim808.GPSdata.lon,6);
     
    // Longitude
    sim808.LongitudeConverToDMS();
    Serial.print(sim808.longDMS.degrees);
    Serial.print(sim808.longDMS.minutes);
    Serial.print(sim808.longDMS.seconds,6);
}
  
int getSpeed() {
  return sim808.GPSdata.speed_kph
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
     fatal_error(true);
    break;
   }
}

bool fatal_error(bool state_value) {
  if state_value == true {
  } else if { 
    
  } else {
    
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
