// C++ code
//
#include<Adafruit_NeoPixel.h>
#define PIN 6
#define N_LEDS 4
Adafruit_NeoPixel strip=Adafruit_NeoPixel(N_LEDS,PIN,NEO_GRB+NEO_KHZ800);

void setup()
{
  strip.begin();
}

void loop()
{
  chase(strip.Color(255,0,0));
  chase(strip.Color(0,255,0));
  chase(strip.Color(0,0,255));
}
static void chase(uint32_t c){
  for(uint16_t i=0;i<strip.numPixels()+4;i++){
    strip.setPixelColor(i,c);
    strip.setPixelColor(i-4,0);
    strip.show();
    delay(25);
  }
}