#include <ESP8266WiFi.h>  //ESP Type
#include <ArduinoJson.h>  

//Vorsicht-> Anpassung der Chips.
const int ENABLE_Y = D0;
const int DIR_Y =  D1;
const int PULS_Y = D2;
const int ENABLE_Z = D5;
const int DIR_Z =  D6;
//D5 wird bewusst freigehalten D5
const int PULS_Z = D7;
const int EndYD = D4;
const int EndYA = D3;

#include "Motortreiber.h"
// Constant Zone
//Orginal Maschine
//const char* ssid = "FRITZ!Box 7330";
//const char* password = "03438357071785070961";
//In der Smartphone Zone
const char* ssid = "cku";
const char* password = "123456789";
//Bei Christian
//const char* ssid = "Chr.Network";
//const char* password = "2570419532734084";
StaticJsonDocument<200> doc;
WiFiServer wifiServer(9012);
 
void setup(){ 
  initMotors();  
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
  attachInterrupt(digitalPinToInterrupt(EndYD), endyd, HIGH);
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
            DIR_YA(LENGTHUNIT);
            client.println(getY());
            break;
          case 'D':
            DIR_YD(LENGTHUNIT);
            client.println(getY());
            break;
          case 'Q':
            DIR_ZA(LENGTHUNIT);
            client.println(getZ());
            break;
          case 'E':
            DIR_ZD(LENGTHUNIT);
            client.println(getZ());
            break;
          case 'G':
            zurGrundpositionZ();
            zurGrundpositionY();
            client.println(getZ());
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
