
#define LS 10      // left sensor
#define RS 9       // right sensor
#define LM1 7      //motor Driver in1
#define LM2 6      //motor Driver in2
#define RM1 5      //motor Driver in3
#define RM2 4      //motor Driver in4

#define ENA 3      // Left Motor Enable Pin (PWM)
#define ENB 11     // Right Motor Enable Pin (PWM)

void setup()
{
  pinMode(LS, INPUT);
  pinMode(RS, INPUT);
  pinMode(LM1, OUTPUT);
  pinMode(LM2, OUTPUT);
  pinMode(RM1, OUTPUT);
  pinMode(RM2, OUTPUT);
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);
}

void loop()
{
  if (!digitalRead(LS) && !digitalRead(RS))  
  {
    // FORWARD
    digitalWrite(LM1, HIGH);
    digitalWrite(LM2, LOW);
    digitalWrite(RM1, HIGH);
    digitalWrite(RM2, LOW);
    analogWrite(ENA, 120); // Adjust the value for desired speed
    analogWrite(ENB, 120); // Adjust the value for desired speed
  }
  
  if (digitalRead(LS) && !digitalRead(RS))     
  {
    // Left turn
    digitalWrite(LM1, LOW);
    digitalWrite(LM2, HIGH);
    digitalWrite(RM1, HIGH);
    digitalWrite(RM2, LOW);
    analogWrite(ENA, 120); // Adjust the value for desired speed
    analogWrite(ENB, 70); // Adjust the value for desired speed
  }
  
  if (!digitalRead(LS) && digitalRead(RS))     
  {
    // turn right
    digitalWrite(LM1, HIGH);
    digitalWrite(LM2, LOW);
    digitalWrite(RM1, LOW);
    digitalWrite(RM2, HIGH);
    analogWrite(ENA, 70); // Adjust the value for desired speed
    analogWrite(ENB, 120); // Adjust the value for desired speed
  }
  
  if (digitalRead(LS) && digitalRead(RS))    
  {
    // Stop
    digitalWrite(LM1, HIGH);
    digitalWrite(LM2, LOW);
    digitalWrite(RM1, HIGH);
    digitalWrite(RM2, LOW);
    analogWrite(ENA, 60); // Stop left motor
    analogWrite(ENB, 60); // Stop right motor
  }
}
