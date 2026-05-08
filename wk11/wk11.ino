void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(12, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  digitalWrite(12, HIGH); 
  delay(1000);                      // wait for a second
  digitalWrite(12, LOW);  
  delay(1000);                      // wait for a second
}
