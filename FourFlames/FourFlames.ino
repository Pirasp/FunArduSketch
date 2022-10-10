/*
this sketch controlls four leds and gives them a flame flickering effect

It is released under the MIT license by
Johannes Hofer
https://github.com/Pirasp/FunArduSketch
*/

const int flame1 = 13;
const int flame2 = 12;
const int flame3 = 11;
const int flame4 = 10; // the PWM pin the LEDs are attached to
float flameFrequency = 5; //approximate flicker frequency of the flame

int baseBrightness = 50;
int maxBrightness = 100;
int maxBrightnessVariationLow = 15;
int maxBrightnessVariationHigh = 30; 

int updateFreqMillis = 10;

unsigned long lastTime = 0;
unsigned long nowTime = 0;

float stepSize;

// the setup routine runs once when you press reset:
void setup() {
  
  pinMode(flame1, OUTPUT);
  pinMode(flame2, OUTPUT);
  pinMode(flame3, OUTPUT);
  pinMode(flame4, OUTPUT);

  
}

// the loop routine runs over and over again forever:
void loop() {

  //maybe I will finish this more physically accurate part some time, but the hack below already looks quite good :D
 /* nowTime = millis();
  unsigned long t = nowTime - lastTime;
  if (t >= updateFreqMillis){//at least ten milliseconds have passed since last update
    
  }*/

//hacky and not physically accurate, but looks nice enough
int L1, L2, L3;
L1 = random(100) ;
L2 = random(100) ;
L3 = random(100) ;
L4 = random(100);
analogWrite(flame1, 255 - L1);
analogWrite(flame2, 255 - L2);
analogWrite(flame3, 255 - L3);
analogWrite(flame4, 255-L4);
delay(80 + random(80));
}
