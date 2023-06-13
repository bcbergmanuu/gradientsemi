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
  pinMode(A0, INPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
}

measure_state currentstate = st_measure;

switchvalue previousvalue = sw_OFF; //LED
switchvalue currentvalue = sw_OFF;

void setLED(switchvalue lednum) {  

  //PINB4-7 are biosemi pin 0-3
  switch (lednum)
  {
  case sw_OFF:
    PORTB = 0b00000000;
    break;  
  case sw_LED0:
    PORTB = 0b00010000;
    break;  
  case sw_LED1:
    PORTB = 0b00100000;
    break;  
  case sw_LED2:
    PORTB = 0b01000000;
    break;
  case sw_LED3:
    PORTB = 0b10000000;
    break;
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

