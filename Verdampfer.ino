#include <math.h>

double convertRawToTemperature(int raw) 
{
 double temperatureInC;
 
 temperatureInC = log(10000.0*((1024.0/raw-1))); 
 temperatureInC = 1 / (0.001129148 + (0.000234125 + (0.0000000876741 * temperatureInC * temperatureInC ))* temperatureInC );
 temperatureInC = temperatureInC - 273.15;          
 
 
 return temperatureInC;
}


void setup() 
{
 Serial.begin(9600);
 pinMode(7, OUTPUT);
}

void loop() 
{             
  int rawTemperatur;
  double temperaturInC;   
           
  rawTemperatur = analogRead(A0);
        
  temperaturInC = convertRawToTemperature(rawTemperatur); 
  

  Serial.println(temperaturInC);   
  if (temperaturInC < 27)  {
    digitalWrite(7, HIGH);
  }
  if (temperaturInC > 35)  {
    digitalWrite(7, LOW);
  }
    

  delay(100);            
}
