//www.elegoo.com
//2016.12.08

int buzzer = 12;//the pin of the active buzzer
void setup()
{
 pinMode(buzzer,OUTPUT);//initialize the buzzer pin as an output
}
void loop()
{
 unsigned char i;
 while(1)
 {
   //output an frequency
   for(i=0;i<80;i++)
   {
    digitalWrite(buzzer,HIGH);
    delay(100);//wait for 1ms
    digitalWrite(buzzer,LOW);
    delay(100);//wait for 1ms
    }
    //output another frequency
     for(i=0;i<80;i++)
      {
        digitalWrite(buzzer,HIGH);
        delay(2);//wait for 2ms
        digitalWrite(buzzer,LOW);
        delay(2);//wait for 2ms
      }
     for(i=0;i<80;i++)
      {
        digitalWrite(buzzer,HIGH);
        delay(5);//wait for 2ms
        digitalWrite(buzzer,LOW);
        delay(5);//wait for 2ms
      }
  }
} 
