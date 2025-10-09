// This function runs once when the Arduino board is reset or powered on.
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

  digitalWrite(13, HIGH); //Allow the power for the pin function to on the led

  digitalWrite(13, LOW); //Disactivate the power for the pin function to off the led

  digitalWrite(12, HIGH);

  digitalWrite(12, LOW);

  digitalWrite(11, HIGH);

  digitalWrite(11, LOW);

  digitalWrite(10, HIGH);

  digitalWrite(10, LOW);

}
