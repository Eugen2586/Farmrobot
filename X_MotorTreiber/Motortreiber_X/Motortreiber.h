#ifndef Motortreiber_h
#define Motortreiber_h
int now;
long position = 0;
int lastAnalog = 0;
int steps = 20;   //Uebergabeparameter steps, anzahl der Rechteckwellen
// Idee: int primSteps = 100; // Laenge eines Steps / Rechteckwellenanzahl (waere denkbar)

 const int PERIODLENGHT = 700; //Periodlenght of one rectangular wave (estimated)
 const int LENGTHUNIT = 1000; //Defines a standard length


 int alt = 0;
long pos(int dir){
  now = analogRead(analogPin);
  if(lastAnalog == 0){
    lastAnalog = now;
    return position;
  }
  if(lastAnalog - now > 5 || now - lastAnalog > 5){
      position = position + dir;
      if(alt == 1) {
        digitalWrite(Ausgabe, LOW);
        alt--;
      }else{
        digitalWrite(Ausgabe, HIGH);  
        alt++;
    }
  }
  lastAnalog = now;
  Serial.println(position);
  return position;
}


void dirA(int steps) {
  Serial.println(digitalRead(AnschlagA));
  if(!digitalRead(AnschlagA) == 0){  
    Serial.println("Stimmt");
    digitalWrite(ENABLE,LOW);
    digitalWrite(DIR,LOW); //Direction
    int posAlt = pos(1);
    for(int stepCount = 0; stepCount <= steps; stepCount++){ //Create rectangular wave //Create rectangular wave 
      if(digitalRead(AnschlagA) == 0){
        break;
      }
      //if(posAlt != pos(1)){
      //  break;  
      //}
      digitalWrite(PULS,HIGH);
      pos(1);
      delayMicroseconds(PERIODLENGHT/4);
      pos(1);
      delayMicroseconds(PERIODLENGHT/4);
      digitalWrite(PULS,LOW);
      pos(1);
      delayMicroseconds(PERIODLENGHT/4);
      pos(1);
      delayMicroseconds(PERIODLENGHT/4);
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
      pos(-1);
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
