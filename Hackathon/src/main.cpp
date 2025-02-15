#include <Arduino.h>
#include "SparkFun_MMA8452Q.h"
#include "Wire.h"

MMA8452Q accel(0x1D); // Default MMA8452Q object create. (Address


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  accel.init(); // Default init: +/-2g and 800Hz ODR


  
}

void loop() {
  // put your main code here, to run repeatedly:
  accel.read(); // Update acceleromter data

  Serial.print("Acceleration on the x-axis is: ");
  Serial.print(accel.cx);
  Serial.println(" g's");

  Serial.print("Acceleration on the y-axis is: ");
  Serial.print(accel.cy);
  Serial.println(" g's");

  Serial.print("Acceleration on the z-axis is: ");
  Serial.print(accel.cz);
  Serial.println(" g's");
  delay(1000);


}