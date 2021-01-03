//www.elegoo.com
//2016.12.09

// Arduino pin numbers
const int SW_pin = 2; // digital pin connected to switch output
const int X_pin = 0; // analog pin connected to X output
const int Y_pin = 1; // analog pin connected to Y output

void setup() {
  pinMode(SW_pin, INPUT);
  digitalWrite(SW_pin, HIGH);
  Serial.begin(9600);
}

void loop() {
  Serial.print("Switch:  ");
  Serial.print(digitalRead(SW_pin));
  Serial.print("\n");
  Serial.print("X-axis: ");
  Serial.print(analogRead(X_pin));
  Serial.print("\n");
  Serial.print("Y-axis: ");
  Serial.println(analogRead(Y_pin));
  Serial.print("\n\n");

    if (digitalRead(SW_pin) == 0)
  {
    Serial.print("\nFLIP!!\n");
  }

  if (analogRead(X_pin) > 800)
  {
    Serial.print("\nRIGHT!!\n");
  }
  else if(analogRead(X_pin) < 400)
  {
    Serial.print("LEFT!!\n");
  }

    if (analogRead(Y_pin) < 100)
  {
    Serial.print("\nFORWARD!!\n");
  }
  else if(analogRead(Y_pin) > 600)
  {
    Serial.print("REVERSE!!\n");
  }
  delay(1000);
}
