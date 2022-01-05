#include <WiFi.h>  //ESP Type
#include <ArduinoJson.h>  

//
boolean A = false;
boolean D = false;

ICACHE_RAM_ATTR void higha(){
  A = true;
}
ICACHE_RAM_ATTR void lowa(){
  A = false;
}

ICACHE_RAM_ATTR void highd(){
  D = true;
}
ICACHE_RAM_ATTR void lowd(){
  D = false;
}

// Constant Zone
//-> Client für die Signalübertragung
const char* ssid = "JKallweidt_Home";
const char* password = "47064827496195704080";
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
const int SensorA = 34;
const int SensorD = 35;

void setup() {
  Serial.begin(115200);
  initPins();
  
  //Wenn wir High bekommen, haben wir den Sensor nicht erreicht
  // ein High führt zur Freigabe y, ein low führt zum Sperren n
  if(digitalRead(SensorA) == HIGH){
      A = true;
  }else{
      A = false;
  }
  if(digitalRead(SensorD) == HIGH){
      D = true;
  }else{
      D = false;
  };
  //Nachdem wir einmal die Sensoren initialisiert haben, reagieren wir jetzt auf Änderungen.
  
  //attachInterrupt(digitalPinToInterrupt(SensorA), higha, HIGH);
  //attachInterrupt(digitalPinToInterrupt(SensorA), lowa, LOW);
  //attachInterrupt(digitalPinToInterrupt(SensorD), highd, HIGH);
  //attachInterrupt(digitalPinToInterrupt(SensorD), lowd, LOW);
  
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting..");
  }
  Serial.print("Connected to WiFi. IP:");
  Serial.println(WiFi.localIP());
  wifiServer.begin();
}

void initPins(){
  pinMode(SensorA, INPUT); //Enable
  pinMode(SensorD, INPUT); //Direction
  A = false;
  D = false;
}

void loop() {
 
  WiFiClient client = wifiServer.available();
  if (client) {
    Serial.println("Client zugeschaltet");
    while (client.connected()) {
      Serial.write(client.available());
      yield();
      while (client.available()>0) {
        char c = client.read();
        Serial.print("Anfrage: ");
        Serial.println(c);
        switch ( c ){
          case 'G':
          case 'A':
             if(digitalRead(SensorA) == HIGH){
                A = true;
             }else{
                A = false;
             };
            if(A == false){
              client.println("n,");
              Serial.println("Antwort: n,");
              client.stop();
            }else{
              client.println("y,");
              Serial.println("Antwort: y,");
              client.stop();
            }
            break;
          case 'D':
            if(D == false){
              client.println("n,");
              Serial.println("Antwort: n,");
              client.stop();
            }else{
              client.println("y,");
              Serial.println("Antwort: y,");
              client.stop();
            }
            break;
          default:
            Serial.write(c);
            client.stop();
            break;
          }
      }
      delay(100);
    }
    client.stop();
    Serial.println("Client disconnected");
  }
}
