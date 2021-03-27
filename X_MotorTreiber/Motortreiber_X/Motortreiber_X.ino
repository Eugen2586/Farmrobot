#include <ESP8266WiFi.h>
#include <ArduinoJson.h>

const int ENABLE = D0;
const int PULS = D2;
const int DIR =  D1;
const int Ausgabe = D4;
const int AnschlagA = D6;
const int AnschlagD = D7;
const int analogPin = A0;
#include "Motortreiber.h"

// Constant Zone
//const char* ssid = "Galaxy S1065b3";
//const char* password = "123456789";
const char* ssid = "Chr.Network";
const char* password = "2570419532734084";
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
        if(c == 'V'){ //-> Anpassung der Variable auf die Reagiert werden soll auf V
          //Hier zum Beispiel
          doc["T"] = "Wassersensor";
          doc["V"] = analogRead(A0);
          char message[200];
          serializeJson(doc, message);
          client.println(message);
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
          client.println("D");
        }else if(c == 'S'){
          //Änderung zur Motor Ansteuerung in Motortreiber.h
          //Eingepflegt JKA und CKU -> 07.01.2021
          dirS(20);
          client.println("S"); 
        }else if(c == 'W'){
          //Änderung zur Motor Ansteuerung in Motortreiber.h
          //Eingepflegt JKA und CKU -> 07.01.2021
          dirW(20);
          client.println("W");
        }else if(c == 'Q'){
          //Änderung zur Motor Ansteuerung in Motortreiber.h
          //Eingepflegt JKA und CKU -> 07.01.2021
          dirQ(20); 
          client.println("Q");
        }else if(c == 'E'){
          //Änderung zur Motor Ansteuerung in Motortreiber.h
          //Eingepflegt JKA und CKU -> 07.01.2021
          dirE(20);
          client.println("E");
        }else{
         Serial.write(c);
        }
      }
 
      delay(10);
    }
 
    client.stop();
    Serial.println("Client disconnected");
 
  }
}
