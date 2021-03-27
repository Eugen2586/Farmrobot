
//Constants:
const int lightPin = D1;
boolean loch = false;
int trigger = 0;
long position = 0;
unsigned long prevMillis = 0; //Zeitpunkt der letzten Zeitmessung
unsigned long currMillis = 0; //aktuelle Zeitmessung
const long intervalI = 500; //Uebergabeintervalllaenge
long interval = 0;
unsigned long prevMillisI = 0; //Zeitpunkt der letzten Zeitmessung
unsigned long currMillisI = 0; //aktuelle Zeitmessung
 

ICACHE_RAM_ATTR void positionFunction(){
  currMillis = millis(); //
  interval = currMillis - prevMillis;
    
    if(interval < 6){
      return;
      }
      Serial.println(interval);
    if( interval > 70 && loch == false ){  //Intervallprüfung
      loch = true;
      doStuff();  //Aufbage machen bzw. Infos weitergeben     
    } 
    if( interval < 70 && loch == true ){
      doStuff();  //Aufgabe machen bzw. Infos weitergeben
      loch = false;
      }
   prevMillis = currMillis;
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
  currMillisI = millis(); //
  if(currMillisI - prevMillisI >  intervalI){
    Serial.print("A:");
    Serial.print(position);
    Serial.print("\n");
    prevMillisI = currMillisI;
    }

}

void doStuff(){
  position++;
}
