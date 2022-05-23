#include <ESP8266WiFi.h>  //ESP Type
#include <ArduinoJson.h>  
//bei Jonas
//const char* host1 ="192.168.100.58";
//im Gewächshaus
const char* host1 ="192.168.188.37"; // IP Adresse geändert! CKU -> 17.02.2022

//debug
boolean debug = false;

const int ENABLE = D0;
const int PULS = D2;
const int DIR =  D1;
#include "Motortreiber.h"

// Constant Zone
//Netzwerk Jonas:
//const char* ssid = "JKallweidt_Home";
//const char* password = "47064827496195704080";
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
  
  if(debug){
    Serial.begin(115200);
    Serial.print("Motor initialisiert!"); 
  }
  delay(1000);
  //Wifi and Communication
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    if(debug){
      Serial.println("Connecting..");
    }
  }
  if(debug){
    Serial.print("Connected to WiFi. IP:");
    Serial.println(WiFi.localIP());
  }
  wifiServer.begin();
  //MotorStuff
  //attachInterrupt(digitalPinToInterrupt(D4), positionFunction, CHANGE);
}
 
void loop() {
  WiFiClient client = wifiServer.available();
  if (client) {
    while (client.connected()) {
      if(debug){
        Serial.write(client.available());
      }
      while (client.available()>0) {
        
        char c = client.read();
        if(debug){
          Serial.println(c);
        }
        switch ( c ){
          case 'A':
            dirA(LENGTHUNIT);
            client.println(position);
            break;
          case 'D':
            dirD(LENGTHUNIT);
            client.println(position);  
            break;
          case 'G':
            
            break;
          default:
            if(debug){
              Serial.write(c);
            }
            break;
          }
      }
      //delay(10);
    }
    client.stop();
    if(debug){
    Serial.println("Client disconnected");
    }
  }
}
