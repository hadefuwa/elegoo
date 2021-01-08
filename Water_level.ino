//www.elegoo.com
//2016.12.9

int adc_id = 0;
int HistoryValue = 0;
char printBuffer[128];

void setup()
{
  Serial.begin(9600);
}

void loop()
{
    int value = analogRead(adc_id); // get adc value

    if(((HistoryValue>=value) && ((HistoryValue - value) > 50)) || ((HistoryValue<value) && ((value - HistoryValue) > 50)))
    {
      sprintf(printBuffer,"ADC %d level is %d\n",adc_id, value);
    //Convert binary numbers "adc_id" and "value" into strings, and store the whole string "ADC "adc_id" level is "value"\n"in C.
      Serial.print("\nBring Clothes In");
      Serial.print("\nClothes Line Motor Activated");
      Serial.print(printBuffer);
      HistoryValue = value;
    }
}
