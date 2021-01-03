//www.elegoo.com
//2016.12.9

int latchPin = 11;
int clockPin = 9;
int dataPin = 12;

byte leds = 0;
/*   The most common method of using 74CH595
 *   lctchPin->LOW : Begin transmitting signals.
 *   shiftOut(dataPin, clockPin, bitOrder, value)
 *   dataPin: the pin on which to output each bit. Allowed data types: int.
 *   clockPin: the pin to toggle once the dataPin has been set to the correct value. Allowed data types: int.
 *   bitOrder: which order to shift out the bits; either MSBFIRST or LSBFIRST. (Most Significant Bit First, or, Least Significant Bit First).
 *   value: the data to shift out. Allowed data types: byte. 
 *   lctchPin->HIch : The end of the transmission signal.
*/
void updateShiftRegister()
{
   digitalWrite(latchPin, LOW);
   shiftOut(dataPin, clockPin, LSBFIRST, leds);
   digitalWrite(latchPin, HIGH);
}
void setup() 
{
  pinMode(latchPin, OUTPUT);
  pinMode(dataPin, OUTPUT);  
  pinMode(clockPin, OUTPUT);
  updateShiftRegister();
  Serial.begin(9600);
  while (! Serial); // Wait untilSerial is ready - Leonardo
  Serial.println("Enter LED Number 0 to 7 or 'x' to clear");
}

void loop() 
{
  if (Serial.available())//judge the serial if receive data
  {
    char ch = Serial.read();//Read serial data and save it in "ch"
    
    if (ch >= '0' && ch <= '7')  //If the data of "ch" is the character'0'~character'7'
    {
      int led = ch - '0'; //Converting strings to binary numbers  example: '0' -> 0 or '1' -> 1
      bitSet(leds, led);
      updateShiftRegister();
      Serial.print("Turned on LED ");
      Serial.println(led);
    }
    if (ch == 'x')
    {
      leds = 0;
      updateShiftRegister();
      Serial.println("Cleared");
    }
  }
}
