
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

void setup() {
  // put your setup code here, to run once:
  initPinsWaterLimit();
  Serial.begin(115200);

}

void loop() {
  String t(getWaterLimit(), 2);
  Serial.println(t);
  delay(300);
  // put your main code here, to run repeatedly:

}
