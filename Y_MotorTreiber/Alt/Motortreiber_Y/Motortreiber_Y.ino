#include <ESP8266WiFi.h>  //ESP Type
#include <ArduinoJson.h>  

const int ENABLE = D0;
const int PULS = D2;
const int DIR =  D1;
#include "Motortreiber.h"

// Constant Zone
//Netzwerk Jonas:
const char* ssid = "JKallweidt_Home";
const char* password = "47064827496195704080";
//Orginal Maschine
//const char* ssid = "FRITZ!Box 7330";
//const char* password = "03438357071785070961";
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
  //attachInterrupt(digitalPinToInterrupt(D4), positionFunction, CHANGE);
}
 
void loop() {
 
  WiFiClient client = wifiServer.available();
 
  if (client) {
 
    while (client.connected()) {
      Serial.write(client.available());
      while (client.available()>0) {
        
        char c = client.read();
        Serial.println(c);
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
            Serial.write(c);
            break;
          }
      }
      //delay(10);
    }
    client.stop();
    Serial.println("Client disconnected");
  }
}
