#include "LPD8806.h"
#include "SPI.h"
int nLEDs = 96;
int dataPin  = 2;
int clockPin = 3;
int controlPin = 8; 
double w = .5 ;
int whiteness = 127;
int L;
LPD8806 strip = LPD8806(nLEDs, dataPin, clockPin);

void setup() {
  // Start up the LED strip
  strip.begin();
  pinMode(4,INPUT);
  digitalWrite(4,HIGH);
  pinMode(5,INPUT);
  digitalWrite(5,HIGH);
  // Update the strip, to start they are all 'off'
  strip.show();
}

void loop() {
  //colorPulseRev(strip.Color(127,0,0),strip.Color( 0*w, 0*w, 0*w),100);
  //colorPulse(strip.Color(127,0,0),strip.Color( 0*w, 0*w, 0*w),100);
  //colorPulse(strip.Color(0,0,80),strip.Color(120,0,0),20,0,-16,20);
 // colorLineFade(120,120,120,27,50,120,32,20,10);
  //delay (1000);
  //colorLineFade(27,50,120,120,120,120,32,20,10);
  //delay (1000);
  if((digitalRead(4)==LOW)&&(digitalRead(5)==LOW)){
  colorLineFade(120,120,120,27,50,120,32,20,10);
  colorLineFade(27,50,120,120,120,120,32,20,10);
  }
  else if((digitalRead(4)==HIGH)&&digitalRead(5)==LOW){
    colorOn(strip.Color(0,127,0),10);
  }
  else if((digitalRead(4)==LOW)&&digitalRead(5)==HIGH){
    colorOn(strip.Color(127,0,0),10);
  }
  else{
    colorOn(strip.Color(0,0,127),10);
  }
  
  //
  //colorLineFade(127,127,127,0,0,120,96,10,10);
  //delay (10);
 // colorFade(0,0,100,100,0,0,96,5.1,10);
  //colorOn(0,0);
  //randPixel(strip.Color(126,0,0),10,2);
}

void colorOn(uint32_t c, uint8_t wait) {
  int i;
  for (i=0; i < strip.numPixels(); i++) {
      strip.setPixelColor(i, c);
      delay(wait);
  }
  strip.show();
}

void colorPulseRev(uint32_t c, uint32_t d, uint8_t wait) {
  int i;
  int j;
  strip.show();
  for (i=0; i < strip.numPixels(); i++) {
    for (j=0; j<L; j++){
      if (i-j < strip.numPixels()){
        strip.setPixelColor(strip.numPixels()-i-j,c);
      }
      else{
      strip.setPixelColor(i-j, c);
      }
    }
      strip.show();
      delay(wait);
      for (j=nLEDs; j>0; j--){
        strip.setPixelColor(strip.numPixels()-j, d);
      }
  }
  strip.show();
}

void colorPulse(uint32_t c, uint32_t d,uint8_t R, uint8_t G, uint8_t B, uint8_t wait) {
  int i;
  int j;
  strip.show();
  for (i=L-1; i < strip.numPixels()+L; i++) {
    for (j=L-1; j>0; j--){
      if (i-j >strip.numPixels()){
        strip.setPixelColor(i-j-strip.numPixels()-1,c+strip.Color(j*R,j*G,j*B));
      }
      else{
      strip.setPixelColor(i-j, c+strip.Color(j*R,j*G,j*B));
      }
    }
      delay(wait);
      strip.show();
      for (j=L-1; j>0; j--){
        strip.setPixelColor(i-j, d);
      }
  }
  strip.show();
}

void randColoredFlash(uint8_t wait) {
  int i , b;
  strip.show();
  for (i=0; i < nLEDs; i++){
    b=strip.Color(int(random(0,30)),int(random(0,30)),int(random(0,30)));
    strip.setPixelColor(i,strip.Color(int(random(0,127)),int(random(0,127)),int(random(0,127))));
  } 
  strip.show();
  delay(wait);
}
void randPixel (uint32_t c, uint8_t d, uint8_t wait) {
  int i = int(random(0,nLEDs));
  int j;
  for(j=0; j<d; j++){
    strip.setPixelColor(i,c/j);
    delay(wait);
    strip.show();
  }
  strip.setPixelColor(i,0);
  delay(wait);
}


void colorLineFade(uint8_t Rone, uint8_t Gone, uint8_t Bone, uint8_t Rtwo, uint8_t Gtwo, uint8_t Btwo, uint8_t length, uint8_t fade, uint8_t wait) {
  int i;
  int j;
  int R = (Rtwo-Rone)/fade;
  int G = (Gtwo-Gone)/fade;
  int B = (Btwo-Bone)/fade;
  strip.show();
  for (i=0; i < length+fade; i++) {
    for (j=fade; j>=0; j--){
      if (i-j<length){
        strip.setPixelColor(i-j, strip.Color(Rone,Gone,Bone) + strip.Color(R*j,G*j,B*j));
      }
    }
      delay(wait);
      strip.show();
      for (j=fade-1; j>0; j--){
        if (i-j<length){
        strip.setPixelColor(i-j, strip.Color(Rtwo,Gtwo,Btwo));
        }
      }
  }
  strip.show();
}
/*void colorFade(uint8_t Rone, uint8_t Gone, uint8_t Bone, uint8_t Rtwo, uint8_t Gtwo, uint8_t Btwo, uint8_t length, uint8_t fadeDelay, uint8_t wait){
  
}*/

/*void colorFadeTo (uint8_t R,uint8_t G,uint8_t B,uint8_t fade){
 int i;
 int j;
 _oneR/fade;
 G/fade= G_one;
 B/fade= B_one;
 for(i=0; i<fade; i++){
   for(j=0;j<strip.numPixels; j++)
   strip.setPixleColor((strip.getPixelColor(j)-strip.Color(R_one,G_one,B_one)));
   
 }
}*/
