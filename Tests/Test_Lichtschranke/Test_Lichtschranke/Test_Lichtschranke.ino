
//Constants:
const int lightPin = D1;
boolean b = false;
int trigger = 0;
long position = 0;
unsigned long prevMillis = 0; //Zeitpunkt der letzten Zeitmessung
unsigned long currMillis = 0; //aktuelle Zeitmessung
const long interval = 1000; //Uebergabeintervalllaenge
 

ICACHE_RAM_ATTR void positionFunction(){
     b = true;
     trigger++;
     Serial.print("Ich bin getriggert :/ : ");
     Serial.println(trigger);
}

void setup() {
  // put your setup code here, to run once:
  //pin-modes:
  Serial.begin(9600);
  pinMode(lightPin, INPUT);
  attachInterrupt(digitalPinToInterrupt(lightPin), positionFunction, RISING); //CHANGE; FALLING; RISING;
}

void loop() {
  // put your main code here, to run repeatedly:
  
  currMillis = millis(); //
    if(currMillis - prevMillis >= interval){  //Intervallprüfung
      doStuff();  //Aufbage machen bzw. Infos weitergeben
      prevMillis = currMillis;      
    } 
}

void doStuff(){
  if( b == true){
    position ++;
    b = false;
    Serial.println("Jetzt keine Pause :)");
    }
  Serial.print("Position: ");  
  Serial.println(position);
}
