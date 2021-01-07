#ifndef Motortreiber_h
#define Motortreiber_h


#define ENABLE 6
#define PULS 5
#define DIR 4

 const int PERIODLENGHT = new int [600]; //Periodlenght of one rectangular wave (estimated)
 const int LENGTHUNIT = new int [1000]; //Defines a standard length

void dirA(int steps) {
  digitalWrite(DIR,LOW); //Direction
  for(int stepCount = 0; stepCount <= steps; stepCount++){ //Create rectangular wave
  digitalWrite(PULS,HIGH);
  delayMicroseconds(PERIODLENGHT/2);
  digitalWrite(PULS,LOW);
  delayMicroseconds(PERIODLENGHT/2);
  }
}
void dirD(int steps) {
  digitalWrite(DIR,HIGH); //Direction
  for(int stepCount = 0; stepCount <= steps; stepCount++){ //Create rectangular wave
  digitalWrite(PULS,HIGH);
  delayMicroseconds(PERIODLENGHT/2);
  digitalWrite(PULS,LOW);
  delayMicroseconds(PERIODLENGHT/2);
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
