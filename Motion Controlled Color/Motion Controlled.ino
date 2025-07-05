
int buzz=3;
int pir=7;
int r=9;
int g=11;
int b=10;

void setup()
{
  pinMode(pir, INPUT);
  pinMode(buzz,OUTPUT);
  pinMode(r, OUTPUT);
  pinMode(g,OUTPUT);
  pinMode(b, OUTPUT);
  
  digitalWrite(pir, LOW);
  digitalWrite(buzz,LOW);
  digitalWrite(r,LOW);
  digitalWrite(g,LOW);
  digitalWrite(b, LOW);
}

void loop()
{
  if(digitalRead(pir)==HIGH)
  {
    digitalWrite(buzz, HIGH);
    RGB_color(0,0,255); // blue
    while(digitalRead(pir)==HIGH);
  }
  else
  {
    digitalWrite(buzz,LOW);
    RGB_color(255,0,255);// magenta
  }
}

void RGB_color (int r_value, int g_value, int b_value)
{
  analogWrite(r, r_value);
  analogWrite(g, g_value);
  analogWrite(b, b_value);
}

      
 
  
