#ifndef Pumpensteuerung_h
#define Pumpensteuerung_h

 void getW(int t){
  
  digitalWrite(D1,LOW);
  digitalWrite(D2,LOW);  
  
  unsigned long currMillis = millis();
  unsigned long mill = currMillis;
  while(currMillis - mill < t){
    currMillis = millis();
    yield();
    }
  digitalWrite(D1,HIGH);
  digitalWrite(D2,HIGH);  
  
}



#endif
