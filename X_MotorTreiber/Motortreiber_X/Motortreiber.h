#ifndef Motortreiber_h
#define Motortreiber_h

void LEDsetup(){
  pinMode(D1, OUTPUT);
  pinMode(D2, OUTPUT);
  pinMode(D3, OUTPUT);
}

void machLED() {
  digitalWrite(D2, LOW);
  delay(1000);
  digitalWrite(D2, HIGH);
  Serial.print("hi");
}

void LEDloop(){
  machLED();
  delay(1000);
}



#endif
