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

  // Turn pin 13 ON.
  digitalWrite(13, HIGH);
  // Immediately turn pin 13 OFF.
  digitalWrite(13, LOW);

  // Turn pin 12 ON.
  digitalWrite(12, HIGH);
  // Immediately turn pin 12 OFF.
  digitalWrite(12, LOW);

  // Turn pin 11 ON.
  digitalWrite(11, HIGH);
  // Immediately turn pin 11 OFF.
  digitalWrite(11, LOW);

  // Turn pin 10 ON.
  digitalWrite(10, HIGH);
  // Immediately turn pin 10 OFF.
  digitalWrite(10, LOW);
}