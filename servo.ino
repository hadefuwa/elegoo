//www.elegoo.com
//2018.12.19
#include <Servo.h>
/* After including the corresponding libraries,
   we can use the "class" like "Servo" created by the developer for us.
   We can use the functions and variables created in the libraries by creating 
   objects like the following "myservo" to refer to the members in ".".*/

Servo myservo;
//it created an object called myservo.
/*  you can see Servo as a complex date type(Including functions and various data types)
    and see myservo as variables.               */

void setup(){
  /*"attach" and "write" are both functions,
     and they are members contained in the complex structure of "Servo". 
     We can only use them if we create the object "myservo" for the complex structure of "Servo".
  */
  myservo.attach(9);//connect pin 9 with the control line(the orange line of Servo) 
  myservo.write(90);// move servos to center position -> 90°
} 
void loop(){
  //myservo.write(90);// move servos to center position -> 90°
  //delay(50);
  myservo.write(0);// move servos to center position -> 60°
  delay(500);
  myservo.write(3);// move servos to center position -> 90°
  delay(500);
  //myservo.write(150);// move servos to center position -> 120°
  //delay(500);
}
