#ifndef Motortreiber_h
#define Motortreiber_h

//Komponenten Stuff
  int z; //Wert für z-Position
  boolean yend = false; 

  void zbew(int i){
    z += i; 
    }
  int getZ(){
      return z;
    }

//EingabeVariablen der Lichtschranke
boolean loch = false;
long position = 0;
unsigned long prevMillis = 0; //Zeitpunkt der letzten Zeitmessung
unsigned long currMillis = 0; //aktuelle Zeitmessung
const long intervalI = 500; //Uebergabeintervalllaenge
long interval = 0;
unsigned long prevMillisI = 0; //Zeitpunkt der letzten Zeitmessung
unsigned long currMillisI = 0; //aktuelle Zeitmessung
//int steps = 20;   //Uebergabeparameter steps, anzahl der Rechteckwellen
// Idee: int primSteps = 100; // Laenge eines Steps / Rechteckwellenanzahl (waere denkbar)

 const int PERIODLENGHT = 500; //Periodlenght of one rectangular wave (estimated)
 const int LENGTHUNIT = 100; //Defines a standard length


  ICACHE_RAM_ATTR void endyd(){
    yend = true;
    }

 
//Z-Richtungs Methoden:
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
      zbew(-1);
    }
    digitalWrite(DIR_Z, LOW);
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
      zbew(1);
    }
    digitalWrite(DIR_Z, LOW);
}

 void initMotors(){ //Motorsteuerung initialisieren, dabei Pinbelegung am Chip definieren
  pinMode(ENABLE_Z, OUTPUT); //ENABLE_Z
  pinMode(DIR_Z, OUTPUT); //DIR_Zection
  pinMode(PULS_Z, OUTPUT); //PULS_Ze
  position = 0;
  
}

void zurGrundpositionZ(){
   DIR_ZD(67000);
   z = 0;
}
#include "harke.h"
#endif
