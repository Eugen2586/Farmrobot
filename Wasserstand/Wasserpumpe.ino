#include <ESP8266WiFi.h>
#include <ArduinoJson.h>

const int ENABLE = D0;
const int PULS = D2;
const int DIR =  D1;
const int Ausgabe = D4;
const int AnschlagA = D6;
const int AnschlagD = D7;
const int analogPin = A0;

#include "Pumpensteuerung.h"

const char* ssid = "FRITZ!Box 7330";
const char* password = "03438357071785070961";

//const char* ssid = "cku";
//const char* password = "123456789";

// Constant Zone
//const char* ssid = "Chr.Network";
//const char* password = "2570419532734084";
StaticJsonDocument<200> doc;
 
WiFiServer wifiServer(9012);
 
void setup() {
  pinMode(D1, OUTPUT);
  pinMode(D2, OUTPUT);
  digitalWrite(D1,HIGH); 
  digitalWrite(D2,HIGH);  
  //Com Serial
  Serial.begin(115200);
  yield(); 
  delay(1000);
  //Wifi and Communication
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    yield();
   // Serial.println("Connecting..");
  }
  Serial.print("Connected to WiFi. IP:");
  Serial.println(WiFi.localIP());
  wifiServer.begin();
}
 
void loop() {
  yield();
  WiFiClient client = wifiServer.available();
  if (client) {
    boolean geschaltet = false;
    while (client.connected()) {
      yield();
         Serial.write(client.available());
      while (client.available()>0) {
         yield();
        char c = client.read();
        Serial.write(c);
        if(c == 'V'){ //-> Anpassung der Variable auf die Reagiert werden soll auf V
          //Hier zum Beispiel
          doc["T"] = "Wassersensor";
          doc["V"] = analogRead(A0);
          char message[200];
          serializeJson(doc, message);
          client.println(message);
          }
        else if(c == 'W'){
          yield();
          if(geschaltet == true){
              getW(240);
            }else{
              getW(210);
            }
          geschaltet = true;
          client.println("W");
        }else{
         Serial.write(c);
        }
        
      }
 
      delay(10);
    }
 
    client.stop();
    Serial.println("Client disconnected");
    geschaltet = false;
  }
}
