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
 const int LENGTHUNIT = 1000; //Defines a standard length

 void doStuff(){
  if(digitalRead(DIR_X) != 0){
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
      doStuff();  //Aufgage machen bzw. Infos weitergeben     
    } 
    if( interval < 70 && loch == true ){
      doStuff();  //Aufgabe machen bzw. Infos weitergeben
      loch = false;
      }
   prevMillis = currMillis;
   
}

// X-Richtungs Methoden
void DIR_XA(int steps) { //nach Links fahren
    digitalWrite(ENABLE_X, LOW);
    digitalWrite(DIR_X,LOW); //DIR_Xection
    for(int stepCount = 0; stepCount <= steps; stepCount++){ //Create rectangular wave
      digitalWrite(PULS_X,HIGH);
      delayMicroseconds(PERIODLENGHT/2);
      yield();
      digitalWrite(PULS_X,LOW);
      delayMicroseconds(PERIODLENGHT/2);
      yield();
  }
}
void DIR_XD(int steps) {
    digitalWrite(ENABLE_X, LOW);
    digitalWrite(DIR_X,HIGH); //DIR_Xection
    for(int stepCount = 0; stepCount <= steps; stepCount++){ //Create rectangular wave
      digitalWrite(PULS_X,HIGH);
      delayMicroseconds(PERIODLENGHT/2);
      yield();
      digitalWrite(PULS_X,LOW);
      delayMicroseconds(PERIODLENGHT/2);
      yield();
  }
}

//Z-Richtungs Methoden
void DIR_ZA(int steps) { //nach Links fahren
    digitalWrite(ENABLE_Z, LOW);
    digitalWrite(DIR_Z,LOW); //DIR_Zection
    for(int stepCount = 0; stepCount <= steps; stepCount++){ //Create rectangular wave
      digitalWrite(PULS_Z,HIGH);
      delayMicroseconds(PERIODLENGHT/2);
      yield();
      digitalWrite(PULS_Z,LOW);
      delayMicroseconds(PERIODLENGHT/2);
      yield();
  }
}
void DIR_ZD(int steps) {
    digitalWrite(ENABLE_Z, LOW);
    digitalWrite(DIR_Z,HIGH); //DIR_Zection
    for(int stepCount = 0; stepCount <= steps; stepCount++){ //Create rectangular wave
      digitalWrite(PULS_Z,HIGH);
      delayMicroseconds(PERIODLENGHT/2);
      yield();
      digitalWrite(PULS_Z,LOW);
      delayMicroseconds(PERIODLENGHT/2);
      yield();
  }
}

 void initMotors(){
  pinMode(ENABLE_X, OUTPUT); //ENABLE_X
  pinMode(DIR_X, OUTPUT); //DIR_Xection
  pinMode(PULS_X, OUTPUT); //PULS_Xe
  pinMode(ENABLE_Z, OUTPUT); //ENABLE_Z
  pinMode(DIR_Z, OUTPUT); //DIR_Zection
  pinMode(PULS_Z, OUTPUT); //PULS_Ze
  position = 0;
  
}



#endif
