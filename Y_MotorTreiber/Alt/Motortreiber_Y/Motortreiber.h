#ifndef Motortreiber_h
#define Motortreiber_h

//EingabeVariablen der Lichtschranke
boolean loch = false;
long position = 0;
unsigned long prevMillis = 0; //Zeitpunkt der letzten Zeitmessung
unsigned long currMillis = 0; //aktuelle Zeitmessung
const long intervalI = 500; //Uebergabeintervalllaenge
long interval = 0;
unsigned long prevMillisI = 0; //Zeitpunkt der letzten Zeitmessung
unsigned long currMillisI = 0; //aktuelle Zeitmessung
int steps = 20;   //Uebergabeparameter steps, anzahl der Rechteckwellen
// Idee: int primSteps = 100; // Laenge eines Steps / Rechteckwellenanzahl (waere denkbar)

 const int PERIODLENGHT = 500; //Periodlenght of one rectangular wave (estimated)
 const int LENGTHUNIT = 30; //Defines a standard length

 boolean doRequestforEnding(char t){
      WiFiClient client1;
      String line;
      //bei Jonas
      const char* host ="192.168.100.58";
      //im Gewächshaus
      //const char* host ="192.168.188.32";
      const int httpPort = 9012;
      if (!client1.connect(host, httpPort)) {
        Serial.println("connection failed");
        return false;
      }
      client1.print(String(t));
      String h = "";
      h = client1.readStringUntil(',');
      Serial.print("Zeichen: ");   
      Serial.println(h);
      if(h.equals("y")){
        Serial.println("true erreicht");
        return false;
      }
      if(h.equals("n")){
        Serial.println("false erreicht");
        return true;
      }
  }

 void doStuff(){
  if(digitalRead(DIR) != 0){
    position++;  
  }else{
    position--;
  }
  
  }
/*
 ICACHE_RAM_ATTR void positionFunction(){
  yield();
  currMillis = millis(); //
  interval = currMillis - prevMillis;
    
    if(interval < 6){
      return;
      }
    if( interval > 70 && loch == false ){  //Intervallprüfung
      loch = true;
      doStuff();  //Aufbage machen bzw. Infos weitergeben     
    } 
    if( interval < 70 && loch == true ){
      doStuff();  //Aufgabe machen bzw. Infos weitergeben
      loch = false;
      }
   prevMillis = currMillis;
   
}
*/
void dirA(int steps) { //nach Links fahren
    digitalWrite(ENABLE, LOW);
    digitalWrite(DIR,LOW); //Direction
    for(int stepCount = 0; stepCount < steps; stepCount++){ //Create rectangular wave
      digitalWrite(PULS,HIGH);
      delayMicroseconds(PERIODLENGHT/2);
      yield();
      digitalWrite(PULS,LOW);
      delayMicroseconds(PERIODLENGHT/2);
      boolean betrieb = doRequestforEnding('A');
      if(betrieb){
        Serial.print(betrieb);
        return;
      }
      position++;
      yield();
  }
  Serial.println("Alle Schritte abgearbeitet.");
}
void dirD(int steps) {
    digitalWrite(ENABLE, LOW);
    digitalWrite(DIR,HIGH); //Direction
    for(int stepCount = 0; stepCount <= steps; stepCount++){ //Create rectangular wave
      digitalWrite(PULS,HIGH);
      delayMicroseconds(PERIODLENGHT/2);
      yield();
      digitalWrite(PULS,LOW);
      delayMicroseconds(PERIODLENGHT/2);
      boolean betrieb = doRequestforEnding('D');
      if(betrieb){
        Serial.print(betrieb);
        return;
      }
      yield();
  }
}

 void initMotors(){
  pinMode(ENABLE, OUTPUT); //Enable
  pinMode(DIR, OUTPUT); //Direction
  pinMode(PULS, OUTPUT); //Pulse
  position = 0;
  
}


#endif
