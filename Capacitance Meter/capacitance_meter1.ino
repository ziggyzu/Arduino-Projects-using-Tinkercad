int analog=0;
int charge=8;
int dis=9;

// resistor initialization
int resistor=10000;

// timer initialisation
unsigned long start;
unsigned long elapsed;

// capacitor variables initialization
float microF;
float nF;

void setup()
{
  pinMode(charge, OUTPUT);
  digitalWrite(charge,LOW);
  Serial.begin(9600);
}

void loop()
{
  digitalWrite(charge, HIGH); // begins charging the capaciot
  start= millis();// begins the timer
  
  while(analogRead(analog)<610)//648
  {
    //does nothing untill capaciot reches 63.2% of total voltage
  }
  unsigned long now=millis();
  elapsed=now-start; // determines the time it took to charge
  microF=((float)elapsed/resistor)*1000;
  Serial.print(elapsed);
  Serial.print("mS  ");
  
  if (microF>1)// determines if units should me micro or nano
  {
    Serial.print((long)microF);
    Serial.print("microF");
  }
  else
  {
    nF=microF*1000;
    Serial.print((long)nF);
    Serial.print("nF");
    delay(500);
  }
  
  digitalWrite(charge,LOW);// stops charging
  pinMode(dis,OUTPUT);
  digitalWrite(dis,LOW);// starts discharging
  
  while(analogRead(analog) > 0)
  {
    // do nothimg untill the capaciot is discharged
  }
  pinMode(dis,INPUT);// prevents from discharging
}

  
    
    