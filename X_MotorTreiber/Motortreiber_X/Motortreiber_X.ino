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
  pinMode(A0, INPUT);

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
        if(c == 'V'){
          //Hier zum Beispiel
          doc["T"] = "Wassersensor";
          doc["V"] = analogRead(A0);
          char message[200];
          serializeJson(doc, message);
          client.println(message);
          }
        else if(c == 'L'){
          Serial.write("Ich will deinen Scheiß befehl nicht ausführen");
        }else if(c = 'A'){
          //Änderung zur Motor Ansteuerung in Motortreiber.h
          //Eingepflegt JKA und CKU -> 07.01.2021
          dirA(20); 
        }else if(c == 'D'){
          //Änderung zur Motor Ansteuerung in Motortreiber.h
          //Eingepflegt JKA und CKU -> 07.01.2021
          dirD(20);
        }else if(c = 'S'){
          //Änderung zur Motor Ansteuerung in Motortreiber.h
          //Eingepflegt JKA und CKU -> 07.01.2021
          dirS(20); 
        }else if(c == 'W'){
          //Änderung zur Motor Ansteuerung in Motortreiber.h
          //Eingepflegt JKA und CKU -> 07.01.2021
          dirW(20);
        }else if(c = 'Q'){
          //Änderung zur Motor Ansteuerung in Motortreiber.h
          //Eingepflegt JKA und CKU -> 07.01.2021
          dirQ(20); 
        }else if(c == 'E'){
          //Änderung zur Motor Ansteuerung in Motortreiber.h
          //Eingepflegt JKA und CKU -> 07.01.2021
          dirE(20);
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
