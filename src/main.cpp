#include <Arduino.h>

enum measure_state 
{
  st_measure,
  st_switch,
};

enum switchvalue 
{
  sw_OFF  = 0,
  sw_LED0 = 6,
  sw_LED1 = 7,
  sw_LED2 = 8,
  sw_LED3 = 9,
};

// put function declarations here:
int screenvalue = 0;

void setup() {
  Serial.begin(115200);
  pinMode(A0, INPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  // put your setup code here, to run once:
  //ADMUX = (1 << REFS1) | (1<<REFS0) | 
  
}

measure_state currentstate = st_measure;

switchvalue previousvalue = sw_OFF; //LED
switchvalue currentvalue = sw_OFF;

void setLED(switchvalue lednum) {  
  uint8_t led_number = static_cast<uint8_t>(lednum);
  Serial.println("numbers");
  for (uint8_t x = 6; x < 10; x++ ) {      
      digitalWrite(x, (led_number == x) ? HIGH : LOW);      
      Serial.print(x);
      Serial.print("-");
      Serial.print(led_number);
      Serial.print("-");
      Serial.print((led_number == x));
      Serial.println("-");
  }    

}

switchvalue getvalue() {
    screenvalue = analogRead(A0);
    if(screenvalue < 75) return sw_OFF;
    
    else if (screenvalue > 74 && screenvalue < 275) return sw_LED0;
    else if (screenvalue > 274 && screenvalue < 475) return sw_LED1;
    else if (screenvalue > 474 && screenvalue < 675) return sw_LED2;
    return sw_LED3;
}

void loop() {
  
  switch (currentstate)
  {
    case st_measure:
      delay(100);
      currentvalue = getvalue();
      Serial.println(currentvalue);

      if(currentvalue == previousvalue) {
        currentstate = st_switch;
      }      
      previousvalue = currentvalue;      
      break;
    
    case st_switch:
      setLED(currentvalue);
      currentstate = st_measure;
      break;
  }
 
   
  
}

