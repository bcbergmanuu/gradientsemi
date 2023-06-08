#include <Arduino.h>

// put function declarations here:
int screenvalue = 0;

void setup() {
  //Serial.begin(115200);
  pinMode(A0, INPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  // put your setup code here, to run once:
  //ADMUX = (1 << REFS1) | (1<<REFS0) | 
  
}

void loop() {
  screenvalue = analogRead(A0);
 // Serial.println(screenvalue);
  
    if(screenvalue < 75) {
      digitalWrite(6, LOW);
      digitalWrite(7, LOW);
      digitalWrite(8, LOW);
      digitalWrite(9, LOW);
    } 
    else if (screenvalue > 74 && screenvalue < 275)
    {      
      digitalWrite(6, HIGH);
      digitalWrite(7, LOW);
      digitalWrite(8, LOW);
      digitalWrite(9, LOW);
    } 
    else if (screenvalue > 274 && screenvalue < 475)
    {        
      digitalWrite(6, LOW);
      digitalWrite(7, HIGH);
      digitalWrite(8, LOW);
      digitalWrite(9, LOW);
    } 
    else if (screenvalue > 474 && screenvalue < 675)
    {
      digitalWrite(6, LOW);
      digitalWrite(7, LOW);
      digitalWrite(8, HIGH);
      digitalWrite(9, LOW);
    }
    else if (screenvalue > 674)
    {
      digitalWrite(6, LOW);
      digitalWrite(7, LOW);
      digitalWrite(8, LOW);
      digitalWrite(9, HIGH);      
    }
  //delay(1000);
}

