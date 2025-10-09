


void setup() {
 
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(10, OUTPUT);
}


void loop() {
  
  digitalWrite(13, HIGH);  //Allow the power for the pin function to on the led

  digitalWrite(13, LOW); //Disactivate the power for the pin function to off the led

       

    digitalWrite(12, HIGH);  
                      
  digitalWrite(12, LOW);  
           

    digitalWrite(11, HIGH);  
                    
  digitalWrite(11, LOW);  
   

    digitalWrite(10, HIGH);  
                     
  digitalWrite(10, LOW);  
 

}

