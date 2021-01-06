/*
 * Motortreiber zur Ansteuerung der verschiedenen Stepper Motoren 
 * mit Hilfe von Arduino Mikrocontrollern
 * Damit lassen sich alle Motoren ansteuern.
 * 
 * ggf Pin Nummerierung anpassen
 */
 
#define ENABLE 6
#define PULS 5
#define DIR 4
 const int PERIODLENGHT = new int [600]; //Periodlenght of one rectangular wave (estimated)
 const int LENGTHUNIT = new int [1000]; //Defines a standard length
 
void setup() {
  //Pin Deklaration (Mikrocontroller):
  pinMode(ENABLE, OUTPUT); //Enable operation
  pinMode(PULS, OUTPUT); //Puls (frequency)
  pinMode(DIR, OUTPUT); //Direction

  digitalWrite(ENABLE,LOW); //Enabled movement  
}
void loop() {

}
void dir0(int steps) {
  digitalWrite(DIR,LOW); //Direction
  for(int stepCount = 0; stepCount <= steps; stepCount++){ //Create rectangular wave
  digitalWrite(PULS,HIGH);
  delayMicroseconds(PERIODLENGHT/2);
  digitalWrite(PULS,LOW);
  delayMicroseconds(PERIODLENGHT/2);
  }
}
void dir1(int steps) {
  digitalWrite(DIR,HIGH); //Direction
  for(int stepCount = 0; stepCount <= steps; stepCount++){ //Create rectangular wave
  digitalWrite(PULS,HIGH);
  delayMicroseconds(PERIODLENGHT/2);
  digitalWrite(PULS,LOW);
  delayMicroseconds(PERIODLENGHT/2);
  }
}

//Testmethods:
void dir0std(){
  dir0(LENGTHUNIT);
}
void dir1std(){
  dir1(LENGTHUNIT);
}
