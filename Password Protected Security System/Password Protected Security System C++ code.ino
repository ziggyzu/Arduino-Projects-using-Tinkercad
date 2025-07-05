// C++ code
//
#include<Keypad.h>
const byte row=4;
const byte col=4;
const int redLED=10;
const int greenLED=11;
const int piezo=12;
char numPad[row][col]={
  {'1','2','3'},{'4','5','6'},
  {'7','8','9'},{'*','0','#'}
};
byte rowPin[row]={9,8,7,6};
byte colPin[col]={5,4,3,2};
String password="6556";
String vstup="";
Keypad cKeypad=Keypad(makeKeymap(numPad),rowPin,colPin,row,col);
void setup()
{
  pinMode(redLED, OUTPUT);
  pinMode(greenLED, OUTPUT);
  pinMode(piezo, OUTPUT);
  digitalWrite(redLED,HIGH);
  Serial.begin(9600);
  Serial.print("Enter Password:");
}

void loop()
{
  char cKey=cKeypad.getKey();
  if(cKey){
    if(vstup.length()<4){
    Serial.print("*");
    vstup +=cKey;
    }
  }
  if(vstup.length()==4){
    delay(1500);
    if(password==vstup){
      Serial.println("\nEnter");
      digitalWrite(redLED,LOW);
      digitalWrite(greenLED,HIGH);
      tone(piezo,500);
      delay(100);
      noTone(piezo);
    }
    else{
      Serial.println("\nWrong Password");
      digitalWrite(redLED,HIGH);
      digitalWrite(greenLED,LOW);
      tone(piezo,1000);
      delay(800);
      tone(piezo,1000);
      delay(800);
      noTone(piezo);
    }
    delay(1500);
    vstup="";
    Serial.println("Enter Password:");
    digitalWrite(redLED,HIGH);
      digitalWrite(greenLED,LOW);
  }
}
    
    
  