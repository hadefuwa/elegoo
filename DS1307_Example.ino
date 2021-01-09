//www.elegoo.com
//2018.10.24
#include <Wire.h>
#include <DS3231.h>

DS3231 clock;
RTCDateTime dt;

void setup()
{
  Serial.begin(9600);

  Serial.println("Initialize RTC module");
  // Initialize DS1307
  clock.begin();

  
  // Manual (YYYY, MM, DD, HH, II, SS
  //clock.setDateTime(2016, 12, 9, 11, 46, 00);
  
  // Send sketch compiling time to Arduino
  clock.setDateTime(__DATE__, __TIME__);    
  /*
  Tips:This command will be executed every time when Arduino restarts. 
       Comment this line out to store the memory of DS3231 module
  */
}

void loop()
{
  dt = clock.getDateTime();

  // For leading zero look to DS3231_dateformat example

  Serial.print("Raw data: ");
  Serial.print(dt.year);   Serial.print("-");
  Serial.print(dt.month);  Serial.print("-");
  Serial.print(dt.day);    Serial.print(" ");
  Serial.print(dt.hour);   Serial.print(":");
  Serial.print(dt.minute); Serial.print(":");
  Serial.print(dt.second); Serial.println("");

  if (dt.hour == 8 && dt.minute == 57 && dt.second == 0)
  {
    Serial.print("Wake up fatty!\n");
  }

  if (dt.year == 2022)
  {
    Serial.print("How did we make it through 2021???");
  }

  delay(1000);
}
