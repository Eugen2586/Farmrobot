#include <ESP8266WiFi.h>  // Für die Wifi Anbindung und den Socket Port
#include <ArduinoJson.h>  // Für die JSON Verarbeitung
#include <OneWire.h>      //OneWire Anbindung des TempSonsors
#include <DallasTemperature.h> // Temperatursensorbibeothek


// Constant Zone
  const char* ssid = "Chr.Network";
  const char* password = "2570419532734084";
  WiFiServer wifiServer(9012);
  StaticJsonDocument<200> doc;
//Temperatursensor
  const int oneWireBus = D3;
  OneWire oneWire(oneWireBus);
  DallasTemperature sensors(&oneWire);
 
void setup() {

  //Sensoren
  //Wassersensor
  pinMode(A0, INPUT);//WasserSensorPin

  //Temperatursensor
  sensors.begin();
  
  //MotorStuff
  pinMode(D0, OUTPUT); //Enable
  pinMode(D1, OUTPUT); //Direction
  pinMode(D2, OUTPUT); //Pulse


  digitalWrite(D0,LOW); 
  digitalWrite(D1,LOW);
  
    
  //CommunicationsStuff Wifi
  Serial.begin(115200); 
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
  

}
 
void loop() {
 
  WiFiClient client = wifiServer.available();
 
  if (client) {
 
    while (client.connected()) {
 
      while (client.available()>0) {
        char c = client.read();
        if(c == 'W'){
          //Wassersensor
          doc["T"] = "Wassersensor";
          doc["V"] = analogRead(A0);
          char message[200];
          serializeJson(doc, message);
          client.println(message);
          }
        else if(c == 'T'){
          //Temperatursensor
           sensors.requestTemperatures(); 
           float temperatureC = sensors.getTempCByIndex(0);
           doc["T"] = "Temperatursensor";
           doc["V"] = temperatureC;
           char message[200];
           serializeJson(doc, message);
           client.println(message);
        }else if(c == 'A'){
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
