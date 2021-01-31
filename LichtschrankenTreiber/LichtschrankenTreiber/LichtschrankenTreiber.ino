#include <ESP8266WiFi.h>
#include <ArduinoJson.h>

//Positionserkennung:
long position = 0;  // Zustandswert
int now;            // aktuell gemessener Ist-(Mess-)Wert
int lastAnalog = 0; // Vorheriger Ist-(Mess-)Wert
int alt = 0;        // Kann 0 oder 1 annehmen, representiert High(1) und Low(0)
int merker = 0;
//Ende Positionserkennung

const int ENABLE = D0;
const int PULS = D2;
const int DIR =  D1;
const int Ausgabe = D4;
const int AnschlagA = D6;
const int AnschlagD = D7;
const int analogPin = A0;
//#include "Motortreiber.h"
//#include "LichtschrankenTreiber.h"
// Constant Zone
const char* ssid = "Chr.Network";
const char* password = "2570419532734084";
StaticJsonDocument<200> doc;
 
WiFiServer wifiServer(9012);
 
void setup() {
  //pin-modes:
  pinMode(analogPin, INPUT);
  pinMode(Ausgabe, OUTPUT);
  digitalWrite(D0,LOW); 
  digitalWrite(D1,LOW);
    
  //Com Serial
  Serial.begin(115200);
  Serial.print("Motor initialisiert!"); 
  delay(1000);
  //Wifi and Communication
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting..");
  }
  Serial.print("Connected to WiFi. IP:");
  Serial.println(WiFi.localIP());
  //wifiServer.begin();
}
 
void loop() {
 
  //WiFiClient client = wifiServer.available();
 
  //if (client) {
 
    //while (client.connected()) {
        //Serial.write(client.available());
      //while (client.available()>0) {
        //char c = client.read();
        //Serial.write(position);
       
      pos(1); //in positive Laufrichtung zählen
        
      //}
      delay(5);
    //}
    //client.stop();
    //Serial.println("Client disconnected");
  //}
}



long pos(int dir){
  now = analogRead(analogPin);
  //Initialisierung:
  if(lastAnalog == 0){  //Test ob schon Messung vorhanden
    lastAnalog = now;   //Initialisierung 
    return position;
  }
  Serial.println(position);
  if( now - lastAnalog > 3 && merker == 0){ //Prüfen auf Abweichung der Lichintensität
      position = position + dir;  //In vorgegebene Richtung weiter zählen
      if(alt == 1) {  //
        digitalWrite(Ausgabe, LOW); //Von High auf Low gewechselt
        alt = 0;
        Serial.println("H2L");
      }else{
        digitalWrite(Ausgabe, HIGH); //Von Low auf High gewechselt  
        alt = 1;
        Serial.println("L2H");
    }
    lastAnalog = now; //Ist Wert wird neuer alt Wert für die naechste Messung
    merker ++;
    return position;
  }
    if( lastAnalog - now > 3 && merker == 1){ //Prüfen auf Abweichung der Lichintensität
      position = position + dir;  //In vorgegebene Richtung weiter zählen
      if(alt == 1) {  //
        digitalWrite(Ausgabe, LOW); //Von High auf Low gewechselt
        alt = 0;
        Serial.println("H2L");
      }else{
        digitalWrite(Ausgabe, HIGH); //Von Low auf High gewechselt  
        alt = 1;
        Serial.println("L2H");
    }
    merker --;
    lastAnalog = now; //Ist Wert wird neuer alt Wert für die naechste Messung
    return position;
  }
  
  Serial.println(position);
  return position;
}
