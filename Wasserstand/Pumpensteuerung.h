#ifndef Pumpensteuerung_h
#define Pumpensteuerung_h

void initWaterRelais(){
    pinMode(D1, OUTPUT);
  
    digitalWrite(D1,HIGH);  
}


void initPinsWaterLimit(){
  pinMode(D5, OUTPUT);
  pinMode(D6, INPUT);
  digitalWrite(D5, HIGH);
}

float getWaterLimit(){
    float entfernung=0;
    long zeit=0;
      digitalWrite(D5, LOW);
      delay(3);
      noInterrupts();
      digitalWrite(D5, HIGH);
      delay(10);
      digitalWrite(D5, LOW);
      zeit = pulseIn(D6, HIGH);
      interrupts();
      entfernung = ((float)zeit * (0.03434/ 2));
    return(entfernung);
  }

void getW(){
  digitalWrite(D1,LOW);
  mill = millis();
}

#endif
