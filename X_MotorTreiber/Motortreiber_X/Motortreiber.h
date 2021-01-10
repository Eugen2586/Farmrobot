#ifndef Motortreiber_h
#define Motortreiber_h




 const int PERIODLENGHT = 800; //Periodlenght of one rectangular wave (estimated)
 const int LENGTHUNIT = 1000; //Defines a standard length

 void initMotors(){
  pinMode(ENABLE, OUTPUT); //Enable
  pinMode(DIR, OUTPUT); //Direction
  pinMode(PULS, OUTPUT); //Pulse
  pinMode(AnschlagA, INPUT);// Anschlag linke Seite
  pinMode(AnschlagD, INPUT);// Anschlag rechte Seite
  }

void dirA(int steps) {
  Serial.println(digitalRead(AnschlagA));
  if(!digitalRead(AnschlagA) == 0){  
    Serial.println("Stimmt");
    digitalWrite(ENABLE,LOW);
    digitalWrite(DIR,LOW); //Direction
    for(int stepCount = 0;stepCount <= steps; stepCount++){ //Create rectangular wave 
      if(digitalRead(AnschlagA) == 0){
        break;
      }
      digitalWrite(PULS,HIGH);
      delayMicroseconds(PERIODLENGHT/2);
      digitalWrite(PULS,LOW);
      delayMicroseconds(PERIODLENGHT/2);
    }
    digitalWrite(ENABLE,HIGH);
    digitalWrite(DIR,LOW);
  }
}
void dirD(int steps) {
  Serial.println(digitalRead(AnschlagD));
  if(!digitalRead(AnschlagD) == 0){ 
    digitalWrite(DIR,HIGH); //Direction
    digitalWrite(ENABLE,LOW);
    Serial.println("DirD");
    for(int stepCount = 0; stepCount <= steps; stepCount++){ //Create rectangular wave
      if(digitalRead(AnschlagD) == 0){
        break;
      }
      digitalWrite(PULS,HIGH);
      delayMicroseconds(PERIODLENGHT/2);
      digitalWrite(PULS,LOW);
      delayMicroseconds(PERIODLENGHT/2);
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



#endif
