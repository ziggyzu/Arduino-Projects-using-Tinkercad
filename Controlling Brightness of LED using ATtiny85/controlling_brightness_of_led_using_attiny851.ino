// C++ code
//
int pot_value=0;
int ledpin=0;
int sensorpin=A3;
void setup()
{
  pinMode(ledpin, OUTPUT);
  pinMode(sensorpin, INPUT);
}

void loop()
{
  pot_value=analogRead(sensorpin);
  pot_value=map(pot_value,0,1023,0,255);
  analogWrite(ledpin,pot_value);
}