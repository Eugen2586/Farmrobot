#include <ESP8266WiFi.h>  //ESP Type
#include <ArduinoJson.h>  

const int ENABLE_X = D0;
const int PULS_X = D2;
const int DIR_X =  D1;
const int ENABLE_Z = D3;
const int PULS_Z = D4;
//D5 wird bewusst freigehalten D5
const int DIR_Z =  D6;

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
 
void setup(){ 
  initMotors();
  pinMode(A0, INPUT);
  //pinMode(D3, INPUT);
  
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
        if(c == 'A'){
          //Änderung zur Motor Ansteuerung in Motortreiber.h
          //Eingepflegt JKA und CKU -> 07.01.2021
          DIR_XA(LENGTHUNIT);
          client.println(position);
        }else if(c == 'D'){
          //Änderung zur Motor Ansteuerung in Motortreiber.h
          //Eingepflegt JKA und CKU -> 07.01.2021
          DIR_XD(LENGTHUNIT);
          client.println(position);
        }else if(c == 'Q'){
          //Änderung zur Motor Ansteuerung in Motortreiber.h
          //Eingepflegt JKA und CKU -> 04.11.2021
          DIR_ZD(LENGTHUNIT);
          client.println(position);
         }else if(c == 'E'){
          //Änderung zur Motor Ansteuerung in Motortreiber.h
          //Eingepflegt JKA und CKU -> 04.11.2021
          DIR_ZD(LENGTHUNIT);
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
