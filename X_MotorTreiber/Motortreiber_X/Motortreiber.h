#ifndef Motortreiber_h
#define Motortreiber_h

//EingabeVariablen der Lichtschranke
boolean loch = false;
int trigger = 0;
long position = 0;
unsigned long prevMillis = 0; //Zeitpunkt der letzten Zeitmessung
unsigned long currMillis = 0; //aktuelle Zeitmessung
const long intervalI = 500; //Uebergabeintervalllaenge
long interval = 0;
unsigned long prevMillisI = 0; //Zeitpunkt der letzten Zeitmessung
unsigned long currMillisI = 0; //aktuelle Zeitmessung

int now;
int lastAnalog = 0;
int steps = 20;   //Uebergabeparameter steps, anzahl der Rechteckwellen
// Idee: int primSteps = 100; // Laenge eines Steps / Rechteckwellenanzahl (waere denkbar)

 const int PERIODLENGHT = 500; //Periodlenght of one rectangular wave (estimated)
 const int LENGTHUNIT = 1000; //Defines a standard length

 void doStuff(){
  if(digitalRead(DIR) != 0){
    position++;  
  }else{
    position--;
  }
  
  }

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

void dirA(int steps) {
  yield();
  if(!digitalRead(AnschlagA) == 0){  
    digitalWrite(ENABLE,LOW);
    digitalWrite(DIR,LOW); //Direction
    unsigned long cc = 0;
    for(int stepCount = 0; stepCount <= steps; stepCount++){ //Create rectangular wave //Create rectangular wave 
      if(digitalRead(AnschlagA) == 0){
        break;
      }
      
      digitalWrite(PULS,HIGH);
      cc = millis();
      unsigned long d = cc + PERIODLENGHT/2;
      while(d < millis()){
        yield();
        // Wird genutzt um Zeiten abzuwarten ohne das System zu sperren.
        }
      
      digitalWrite(PULS,LOW);
      cc = millis();
      d = cc + PERIODLENGHT/2;
      while(d < millis()){
        yield();
        // Wird genutzt um Zeiten abzuwarten ohne das System zu sperren.
        }
    }
    digitalWrite(ENABLE,HIGH);
    digitalWrite(DIR,LOW);
  }
}
void dirD(int steps) {
  yield();
  if(!digitalRead(AnschlagD) == 0){ 
    digitalWrite(DIR,HIGH); //Direction
    digitalWrite(ENABLE,LOW);
    unsigned long cc = 0;
    
    for(int stepCount = 0; stepCount <= steps; stepCount++){ //Create rectangular wave
      yield();
      if(digitalRead(AnschlagD) == 0){
        break;
      }

       
      digitalWrite(PULS,HIGH);
      cc = millis();
      unsigned long d = cc + PERIODLENGHT/2;
      while((d) < millis()){
        // Wird genutzt um Zeiten abzuwarten ohne das System zu sperren.
        yield();
        }
      
      digitalWrite(PULS,LOW);
      cc = millis();
      d = cc + PERIODLENGHT/2;
      while((cc + PERIODLENGHT/2) < millis()){
        yield();
        // Wird genutzt um Zeiten abzuwarten ohne das System zu sperren.
        }
    }
    digitalWrite(ENABLE,HIGH);
    digitalWrite(DIR,LOW);
  }
}
void dirS(int steps) {
  digitalWrite(DIR,LOW); //Direction
  for(int stepCount = 0; stepCount <= steps; stepCount++){ //Create rectangular wave
  digitalWrite(PULS,HIGH);
  delayMicroseconds(PERIODLENGHT/2);
  digitalWrite(PULS,LOW);
  delayMicroseconds(PERIODLENGHT/2);
  }
}
void dirW(int steps) {
  digitalWrite(DIR,HIGH); //Direction
  for(int stepCount = 0; stepCount <= steps; stepCount++){ //Create rectangular wave
  digitalWrite(PULS,HIGH);
  delayMicroseconds(PERIODLENGHT/2);
  digitalWrite(PULS,LOW);
  delayMicroseconds(PERIODLENGHT/2);
  }
}
void dirQ(int steps) {
  digitalWrite(DIR,LOW); //Direction
  for(int stepCount = 0; stepCount <= steps; stepCount++){ //Create rectangular wave
  digitalWrite(PULS,HIGH);
  delayMicroseconds(PERIODLENGHT/2);
  digitalWrite(PULS,LOW);
  delayMicroseconds(PERIODLENGHT/2);
  }
}
void dirE(int steps) {
  digitalWrite(DIR,HIGH); //Direction
  for(int stepCount = 0; stepCount <= steps; stepCount++){ //Create rectangular wave
  digitalWrite(PULS,HIGH);
  delayMicroseconds(PERIODLENGHT/2);
  digitalWrite(PULS,LOW);
  delayMicroseconds(PERIODLENGHT/2);
  }
}


 void initMotors(){
  pinMode(Ausgabe, OUTPUT);
  pinMode(ENABLE, OUTPUT); //Enable
  pinMode(DIR, OUTPUT); //Direction
  pinMode(PULS, OUTPUT); //Pulse
  pinMode(AnschlagA, INPUT);// Anschlag linke Seite
  pinMode(AnschlagD, INPUT);// Anschlag rechte Seite
  //while(digitalRead(AnschlagA) == 0){
  //    dirA(20);
  //}
  position = 0;
  
}



#endif
