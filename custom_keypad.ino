//www.elegoo.com
//2016.12.9

/* @file CustomKeypad.pde
|| @version 1.0
|| @author Alexander Brevig
|| @contact alexanderbrevig@gmail.com
||
|| @description
|| | Demonstrates changing the keypad size and key values.
|| #
*/
#include <Keypad.h>

const byte ROWS = 4; //four rows
const byte COLS = 4; //four columns
//define the two-dimensional array on the buttons of the keypads
char hexaKeys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};
byte rowPins[ROWS] = {9, 8, 7, 6}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {5, 4, 3, 2}; //connect to the column pinouts of the keypad

//initialize an instance of class NewKeypad
Keypad customKeypad = Keypad( makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS); 

void setup(){
  Serial.begin(9600);
  digitalWrite(LED_BUILTIN, LOW);
}

int x = 0;
  
void loop()
  {
    char customKey = customKeypad.getKey();
   
    if (customKey == '6')
    {
      x = 1;
      Serial.println("\n*");
    }

    while(x == 1)
    {
      char customKey2 = customKeypad.getKey();
      if (customKey2 == '5')
      {
        Serial.println("\nPassword Correct\n");
        x = 0;
      }
    }
    x = 0;
  }


/*
  digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)   
  digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
  */
