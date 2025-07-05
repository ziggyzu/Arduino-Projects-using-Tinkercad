#include <Servo.h>
Servo myservo;

#define trig 2
#define echo 3

float duration;
float distance;

void setup()
{
  myservo.attach(9);
  Serial.begin(9600);
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
}

void loop()
{
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
  
  duration=pulseIn(echo,HIGH);
  distance=(duration/20)*0.0343;
  Serial.print("\nDistance: ");
  
  if(distance>=4 || distance<=2)
  {
    Serial.print("\nout of Range");
    myservo.detach();
  }
  else
  {
    myservo.attach(9);
    myservo.write(0);
    delay(1000);
    myservo.write(90);
    
    Serial.print(distance);
    Serial.println( "cm");
    delay(500);
  }
  delay(500);
  myservo.detach();
}

  
            