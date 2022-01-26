#include <ESP8266WiFi.h>     
#include <ArduinoJson.h>
#include "DHT.h"
long mill = millis();
WiFiClient client;

uint8_t DHTPin = D2; 
#define DHTTYPE DHT11         
// Initialize DHT sensor.
DHT dht(DHTPin, DHTTYPE); 

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
  Serial.print("halloWElt");
  //Wifi and Communication
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    yield();
  }
  Serial.print("Connected to WiFi. IP:");
  Serial.println(WiFi.localIP());
  wifiServer.begin(); 
}

void loop() {
  yield();
  boolean geschaltet = false;
  client = wifiServer.available();
  if (client) {
    while (client.connected()) {
      yield();
      Serial.write(client.available());
      while (client.available()>0) {
        yield();
        char c = client.read();
        Serial.write(c);
        if(c == 'V'){ //-> Anpassung der Variable auf die Reagiert werden soll auf V
          //Hier zum Beispiel
          doc["T"] = "WS_1";
          doc["V"] = analogRead(A0);
          Serial.println(analogRead(A0));
          char message[200];
          serializeJson(doc, message);
          Serial.println(message);
          client.println(message);
       }else if(c == 'T'){ //-> Anpassung der Variable auf die Reagiert werden soll auf V
          float t = 0;
          t = dht.readTemperature();
          //Hier zum Beispiel
          doc["T"] = "TP_1";
          doc["V"] = (int)t;
          Serial.println(t);
          char message[200];
          serializeJson(doc, message);
          Serial.println(message);
          client.println(message);
        }else if(c == 'L'){ //-> Anpassung der Variable auf die Reagiert werden soll auf V
          //Hier zum Beispiel
          float h = 0;
          h = dht.readHumidity();
          doc["T"] = "LF_1";
          doc["V"] = (int) h;
          Serial.println(h);
          char message[200];
          serializeJson(doc, message);
          Serial.println(message);
          client.println(message);
        }else{
       }
         Serial.write(c);
        }
        
      }
      yield();
      client.stop();
      Serial.println("Client disconnected");
      geschaltet = false;
    }
}
