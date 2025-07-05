// C++ code
//
int temp=A0;
float temp_celsius;
float volt;
float analog;
float temp_far;
void setup()
{
  pinMode(A0, INPUT);
  Serial.begin(9600);
}

void loop()
{
  analog=analogRead(A0);
  Serial.print("Analog reading:");
  Serial.println(analog);
  volt=analog*5/1024;
  Serial.print("Voltage reading:");
  Serial.println(volt);
  temp_celsius=100*(volt-0.5);
  Serial.println("Celsius reading:"+String(temp_celsius)+("C"));
  temp_far=(temp_celsius*9/5)+32;
  Serial.println("Fehrenheit reading:"+String(temp_far)+("F\n"));
  delay(3000);
  
}