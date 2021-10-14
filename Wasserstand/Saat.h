#ifndef Saat_h
#define Saat_h

void initSPins(){
    pinMode(D3, OUTPUT);
    pinMode(D4, OUTPUT);
  
    digitalWrite(D3,HIGH); 
    digitalWrite(D4,HIGH);  
  }

void shootS(int t){
    digitalWrite(D3,LOW);
    digitalWrite(D4,LOW);  
  
    unsigned long currMillis = millis();
    unsigned long mill = currMillis;
    while(currMillis - mill < t){
      currMillis = millis();
      yield();
    }
    digitalWrite(D3,HIGH);
    digitalWrite(D4,HIGH);
  }


#endif
