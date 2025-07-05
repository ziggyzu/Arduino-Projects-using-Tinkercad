// C++ code
#include<IRremote.h>
#include<Servo.h>
int recv=5;
IRrecv irrecv(recv);
decode_results results;
Servo myservo;
int pos=0;

void setup()
{
  Serial.begin(9600);
  Serial.println("Enabling IRin");
  irrecv.enableIRIn();
  Serial.println("Enabled IRin");
  myservo.attach(3);
  myservo.write(pos);
}

void loop()
{
  if(irrecv.decode(&results)){
    Serial.println(results.value,DEC);
    if(results.value==16582903){
       myservo.write(45);
      delay(1000);
    }
    else if(results.value==16615543)
    {
      myservo.write(90);
      delay(2000);
    }
    else if(results.value==16591063)
    {
      myservo.write(180);
      delay(2000);
    }
    else
    {
    }
    myservo.write(0);
    irrecv.resume();
    delay(100);
  }
}