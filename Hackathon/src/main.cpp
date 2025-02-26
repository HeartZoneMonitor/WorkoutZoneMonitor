#include <Arduino.h>
#include "SparkFun_MMA8452Q.h"
#include "PulseSensorPlayground.h"
#include "Wire.h"

MMA8452Q accel(0x1D); // Default MMA8452Q object create.

PulseSensorPlayground pulseSensor;

int Threshold = 470; 


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  accel.init(); // Default init: +/-2g and 800Hz ODR
  pulseSensor.analogInput(0);
  pulseSensor.setThreshold(Threshold);
  pulseSensor.begin();


  
}

void loop() {
  // put your main code here, to run repeatedly:
  // accel.read(); // Update acceleromter data

  // Serial.print("Acceleration on the x-axis is: ");
  // Serial.print(accel.cx);
  // Serial.println(" g's");

  // Serial.print("Acceleration on the y-axis is: ");
  // Serial.print(accel.cy);
  // Serial.println(" g's");

  // Serial.print("Acceleration on the z-axis is: ");
  // Serial.print(accel.cz);
  // Serial.println(" g's");

  if(pulseSensor.sawStartOfBeat()) {
    int myBPM = pulseSensor.getBeatsPerMinute();
    Serial.println("Heartrate:" );
    Serial.println(myBPM);
  }
  //delay(2000);


}