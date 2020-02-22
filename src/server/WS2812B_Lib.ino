#include <Adafruit_NeoPixel.h>
#define PIN D3
#define NUMPIXELS 30
Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRBW + NEO_KHZ800);

void setup() {
  pixels.begin();
  pixels.clear();
}


void animationPingPongV2(int red, int green, int blue, int speed = 50){
  for(int j=0; speed-j!=0; j++){
    for(int i=0; i<NUMPIXELS; i++){
      pixels.setPixelColor(i, pixels.Color(red, green, blue));
      pixels.show();
      pixels.setPixelColor(i, pixels.Color(0, 0, 0));
      delay(speed-j);
    }
    for(int i=NUMPIXELS-2; i > 0; i--){
      pixels.setPixelColor(i, pixels.Color(red, green, blue));
      pixels.show();
      pixels.setPixelColor(i, pixels.Color(0, 0, 0));
      delay(speed-j);
    }
  }
}

void animationScrolling(int red=0, int green=0, int blue=0, int speed=100){
  for(int i=0; i<NUMPIXELS;i++){
    pixels.setPixelColor(i, pixels.Color(red, green, blue));
    pixels.show();
    pixels.setPixelColor(i, pixels.Color(0, 0, 0));
    delay(speed);
  }
}
void animationRainbow(int speed = 100, int power = 64, bool direction = false, int startLed = 0, int endLed = NUMPIXELS){
  int colorForRainbow = 0;
  for(int j=0; j < 12; j++){
    for(int i=startLed; i < endLed; i++){
        switch(colorForRainbow){
          case 0 :
            pixels.setPixelColor(i, pixels.Color(power, 0, 0));
            break;
          case 1 :
            pixels.setPixelColor(i, pixels.Color(power, power/2, 0));
            break;
          case 2 :
            pixels.setPixelColor(i, pixels.Color(power, power, 0));
            break;
          case 3 :
            pixels.setPixelColor(i, pixels.Color(power/2, power, 0));
            break;
          case 4 :
            pixels.setPixelColor(i, pixels.Color(0, power, 0));
            break;
          case 5 :
            pixels.setPixelColor(i, pixels.Color(0, power, power/2));
            break;
          case 6 :
            pixels.setPixelColor(i, pixels.Color(0, power, power));
            break;
          case 7 :
            pixels.setPixelColor(i, pixels.Color(0, power/2, power));
            break;
          case 8 :
            pixels.setPixelColor(i, pixels.Color(0, 0, power));
            break;
          case 9 :
            pixels.setPixelColor(i, pixels.Color(power/2, 0, power));
            break;
          case 10 :
            pixels.setPixelColor(i, pixels.Color(power, 0, power));
            break;
          case 11 :
            pixels.setPixelColor(i, pixels.Color(power, 0, power/2));
            break;
          default :
            pixels.setPixelColor(i, pixels.Color(0, 0, 0));
            break;
      }  
      colorForRainbow++;
      if(colorForRainbow>11){
        colorForRainbow -= 12;
      }
    }
    pixels.show();
    if(direction){
      colorForRainbow += 13 - (endLed - startLed)%12;
    }
    if(!direction){
      colorForRainbow += 11 - (endLed - startLed)%12;
    }
    if(colorForRainbow>11){
      colorForRainbow -= 12;
    }
    delay(speed);
  }
}

void loop() {
  animationPingPongV2(255, 0, 0);
  // animationPingPong(255, 0, 0);
  // animationRainbow(100,64,false);
  // animationRainbow(100,64,false);
  // animationRainbow(100,64,true);
  // animationRainbow(100,64,true);
}
