#ifndef Saat_h
#define Saat_h

void initSPins(){
    pinMode(D3, OUTPUT);
  
    digitalWrite(D3,HIGH); 
  }

void shootS(int t){
    digitalWrite(D3,LOW); 
    mill = millis();
  }
#endif
