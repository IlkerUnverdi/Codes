int IN1 = 3;   
int IN2 = 2;    
int ENA = 9;
 
void setup() {
  pinMode(IN1, OUTPUT);    
  pinMode(IN2, OUTPUT);
}
 
void loop() {
  analogWrite(ENA, 75);     
  digitalWrite(IN1, HIGH);  
  digitalWrite(IN2, LOW);   
  delay(4000);              
  digitalWrite(IN1, LOW);   
  digitalWrite(IN2, LOW);
  delay(1000);             
 
  analogWrite(ENA, 150);    
  digitalWrite(IN1, LOW);   
  digitalWrite(IN2, HIGH);  
  delay(2000);              
  digitalWrite(IN1, LOW);   
  digitalWrite(IN2, LOW);  
  delay(1000);              
}