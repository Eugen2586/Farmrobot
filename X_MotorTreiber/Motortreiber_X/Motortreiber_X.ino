#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include "Motortreiber.h"

// Constant Zone
const char* ssid = "Chr.Network";
const char* password = "2570419532734084";

//Deklaration Zone
WiFiServer wifiServer(9012);



void setup() {
  LEDsetup();
  Serial.begin(115200);
  delay(100);

  Serial.print("Connect to Wifi ");

  WiFi.begin( ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
}

void loop() {
        LEDloop();/*
  WiFi.begin( ssid, password);
    delay(100);
  while (WiFi.status() == WL_CONNECTED) {
      //Open a Socket sever to Communicate with Pi. :)
      wifiServer.begin();
      WiFiClient client = wifiServer.available();
      // Hier das JSON Object senden!
      String h = "";
      while (client.connected()) {
          while (client.available()>0) {
              char c = client.read();
              h = h + c;
          }          
          client.println("");
      }

   }*/
   //Implementiere hier weitere Logik! Schau ob irgendwas in h vorhanden ist!
}
