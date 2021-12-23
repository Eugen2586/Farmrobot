#ifndef harke_h
#define harke_h

boolean harkeDenPunkt(){
  Serial.print("gefunden");
  DIR_ZD(35000);
  Serial.print("oben");
  DIR_ZA(35000);
  Serial.println("unten");
  }

#endif
