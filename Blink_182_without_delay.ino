


void setup() {
  // Set digital pins 13, 12, 11, and 10 as outputs.
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(10, OUTPUT);
}

//In this part we have a loop 
void loop() {
  
  digitalWrite(13, HIGH);  //Allow the power for the pin function to on the led

  digitalWrite(13, LOW); //Disactivate the power for the pin function to off the led

       

    digitalWrite(12, HIGH);  //Allow the power for the pin function to on the led
                      
  digitalWrite(12, LOW);  //Disactivate the power for the pin function to off the led
           

    digitalWrite(11, HIGH);  
                    
  digitalWrite(11, LOW);  
   

    digitalWrite(10, HIGH);  
                     
  digitalWrite(10, LOW);  
 

}


