#include <ESP8266WiFi.h>
#include <ArduinoJson.h>
long mill = millis();
#include "Pumpensteuerung.h"
WiFiClient client;
#include "Saat.h"
//const char* ssid = "FRITZ!Box 7330";
//const char* password = "03438357071785070961";

//const char* ssid = "FRITZ!Box 7430 MM";
//const char* password = "36002357151783325689";

//const char* ssid = "cku";
//const char* password = "123456789";

// Constant Zone
const char* ssid = "Chr.Network";
const char* password = "2570419532734084";
StaticJsonDocument<200> doc;
 
WiFiServer wifiServer(9012);

void setup() {
  //Doing Communication Stuff
  Serial.begin(115200);
  yield(); 
  delay(1000);
  //Wifi and Communication
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    yield();
  }
  Serial.print("Connected to WiFi. IP:");
  Serial.println(WiFi.localIP());
  wifiServer.begin();
  pinMode(A0, INPUT);
  //Doing Init
  initPinsWaterLimit();
  initWaterRelais();
  initSPins();
  
}

void loop() {
  yield();
  boolean geschaltet = false;
  client = wifiServer.available();
  if (client) {
    while (client.connected()) {
      yield();
      Serial.println(client.available());
        yield();
        char c = client.read();
        Serial.println(c);
       if(c == 'V'){ //-> Anpassung der Variable auf die Reagiert werden soll auf V
          //Hier zum Beispiel
          doc["T"] = "WS_1";
          doc["V"] = analogRead(A0);
          Serial.println(analogRead(A0));
          char message[200];
          serializeJson(doc, message);
          Serial.println(message);
          client.println(message);
       }else{
          Serial.write(c);
       }  
      }
      yield();
      client.stop();
      Serial.println("Client disconnected");
      geschaltet = false;
      }
}
