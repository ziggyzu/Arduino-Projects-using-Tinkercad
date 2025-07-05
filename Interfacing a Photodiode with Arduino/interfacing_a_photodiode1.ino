int sensor=A0;
int sensorValue=0;
void setup()
{
  pinMode(sensor, INPUT);
  Serial.begin(9600);
}

void loop()
{
  sensorValue=analogRead(sensor);
  Serial.println(sensorValue);
}