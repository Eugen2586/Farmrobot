#include <ESP8266WiFi.h>
#include <ArduinoJson.h>

// Constant Zone
const char* ssid = "Chr.Network";
const char* password = "2570419532734084";
StaticJsonDocument<200> doc;
 
WiFiServer wifiServer(9012);
 
void setup() {
  pinMode(D0, OUTPUT); //Enable
  pinMode(D1, OUTPUT); //Direction
  pinMode(D2, OUTPUT); //Pulse

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

}
 
void loop() {
 
  WiFiClient client = wifiServer.available();
 
  if (client) {
 
    while (client.connected()) {
 
      while (client.available()>0) {
        char c = client.read();
        if(c == 'W'){
          //Hier zum Beispiel 
          doc["sensor"] = "gps";
          doc["time"] = 1351824120;
          char message[200];
          serializeJson(doc, message);
          client.println(message);
          }
        else if(c == 'A'){
          Serial.write("Ich will deinen Scheiß befehl nicht ausführen");
        }else if(c = 'L'){
          for(int index = 0; index < 10000; index++){
            digitalWrite(D2,HIGH);
            delayMicroseconds(300);
            digitalWrite(D2,LOW);
            delayMicroseconds(300);
          }
          client.println(c);
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
