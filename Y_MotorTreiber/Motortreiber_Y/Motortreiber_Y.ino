#include <ESP8266WiFi.h>  //ESP Type
#include <ArduinoJson.h>  

const int ENABLE = D0;
const int PULS = D2;
const int DIR =  D1;
//const int Ausgabe = D4;
//const int AnschlagA = D6;
//const int AnschlagD = D7;
//const int analogPin = A0;
#include "Motortreiber.h"

// Constant Zone
//Orginal Maschine
const char* ssid = "FRITZ!Box 7330";
const char* password = "03438357071785070961";
//In der Smartphone Zone
//const char* ssid = "Galaxy S1065b3";
//const char* password = "123456789";
//Bei Christian
//const char* ssid = "Chr.Network";
//const char* password = "2570419532734084";
StaticJsonDocument<200> doc;
 
WiFiServer wifiServer(9012);
 
void setup() {
  initMotors();
  pinMode(A0, INPUT);
  pinMode(D3, INPUT);
  
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
  wifiServer.begin();
  //MotorStuff
  attachInterrupt(digitalPinToInterrupt(D4), positionFunction, CHANGE);
}
 
void loop() {
 
  WiFiClient client = wifiServer.available();
 
  if (client) {
 
    while (client.connected()) {
         Serial.write(client.available());
      while (client.available()>0) {
        
        char c = client.read();
        Serial.println(c);
        if(c == 'V'){ //-> Anpassung der Variable auf die Reagiert werden soll auf V
          //Hier zum Beispiel
          doc["T"] = "Wassersensor";
          doc["V"] = analogRead(A0);
          char message[200];
          serializeJson(doc, message);
          client.println(message);
          Serial.println("Feuchtigkeit gemessen: ");
          Serial.println(analogRead(A0));
          }
        else if(c == 'L'){
          Serial.write("Ich will deinen Scheiß befehl nicht ausführen");
        }else if(c == 'A'){
          //Änderung zur Motor Ansteuerung in Motortreiber.h
          //Eingepflegt JKA und CKU -> 07.01.2021
          dirA(1000);
          client.println(position);
        }else if(c == 'D'){
          //Änderung zur Motor Ansteuerung in Motortreiber.h
          //Eingepflegt JKA und CKU -> 07.01.2021
          dirD(1000);
          client.println(position);
        }else{
         Serial.write(c);
        }
      }
      //delay(10);
    }
    client.stop();
    Serial.println("Client disconnected");
  }
}
