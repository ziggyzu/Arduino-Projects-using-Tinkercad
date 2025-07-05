// C++ code
//
int buttonState=0;
const int buttonPin=2;
int led1=13;
int led2=12;
int led3=8;
void setup()
{
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  buttonState=digitalRead(buttonPin);
  if(buttonState==1)
  {
  digitalWrite(led1,1);
  Serial.print("Stop\n");
  delay(2000); 
  digitalWrite(led1,0);
  delay(500);
    digitalWrite(led2,1);
  Serial.print("Get Ready\n");
  delay(2000); 
  digitalWrite(led2,0);
  delay(500);
    digitalWrite(led3,1);
  Serial.print("Bye\n");
  delay(2000); 
  digitalWrite(led3,0);
  }
    
}