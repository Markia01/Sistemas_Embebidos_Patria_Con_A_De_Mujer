/*
 * The setup() function runs only once at the beginning of the program,
 * right after the Arduino is powered on or is reset.
 * It's the perfect place to perform initial configurations.
*/
void setup() {
  // Set digital pin 13 as an OUTPUT.
  // This means the Arduino can send a voltage (5V) signal through this pin.
  pinMode(13, OUTPUT);

  // Set digital pin 12 as an OUTPUT as well.
  pinMode(12, OUTPUT);

  // Set digital pin 11 as an OUTPUT.
  pinMode(11, OUTPUT);

  // Set digital pin 10 as an OUTPUT.
  pinMode(10, OUTPUT);
}

/*
 * After setup() finishes, the program enters the loop() function,
 * which will execute continuously over and over again.
 * (It's currently empty, but the main program logic would go here).
*/
void loop() {
  // The code to control these pins would go here.
}  
  digitalWrite(13, HIGH);  //Allow the power for the pin function to on the led

  digitalWrite(13, LOW); //Disactivate the power for the pin function to off the led

       

    digitalWrite(12, HIGH);  //Allow the power for the pin function to on the led
                      
  digitalWrite(12, LOW);  //Disactivate the power for the pin function to off the led
           

    digitalWrite(11, HIGH);  
                    
  digitalWrite(11, LOW);  
   

    digitalWrite(10, HIGH);  
                     
  digitalWrite(10, LOW);  
 

}



