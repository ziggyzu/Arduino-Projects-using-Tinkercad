#define pir 13
#define led 12
bool pir_val=0;

void setup() 
{
  Serial.begin(9600);
  pinMode(led, OUTPUT);
  pinMode(pir, INPUT);
}
void loop() {
  pir_val = digitalRead(pir);
  if(pir_val==HIGH)
  {
    Serial.println("Motion Detected");
    digitalWrite(led, HIGH);
  }
  else
  {
    Serial.println("No Motion Detected");
    digitalWrite(led,LOW);
  }
}