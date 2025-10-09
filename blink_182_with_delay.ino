void setup()
{

  // Set digital pins 13, 12, 11, and 10 as outputs.
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(10, OUTPUT);
}

// This function runs over and over again in a loop, forever.
void loop()
{

  digitalWrite(13, HIGH); //Allow the current flow to the pin to light the Led
  delay(1000); //Determinates when going to turn on
  digitalWrite(13, LOW); //Desactivate the current flow to switch-off the led
  delay(1000); //Determinates when going to turn off

  digitalWrite(12, HIGH);//Allow the power for the pin function to on the led
  delay(1000);//Determinates when going to turn off
  digitalWrite(12, LOW);//Desactivate the current flow to switch-off the led
  delay(1000);

  digitalWrite(11, HIGH);
  delay(1000);
  digitalWrite(11, LOW);
  delay(1000);

  digitalWrite(10, HIGH);
  delay(1000);
  digitalWrite(10, LOW);
  delay(1000);  
}
