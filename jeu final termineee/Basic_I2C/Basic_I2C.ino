/*
Basic_I2C.ino
Brian R Taylor
brian.taylor@bolderflight.com

Copyright (c) 2017 Bolder Flight Systems

Permission is hereby granted, free of charge, to any person obtaining a copy of this software 
and associated documentation files (the "Software"), to deal in the Software without restriction, 
including without limitation the rights to use, copy, modify, merge, publish, distribute, 
sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is 
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or 
substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING 
BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND 
NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, 
DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, 
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/

#include "MPU9250.h"

// an MPU9250 object with the MPU-9250 sensor on I2C bus 0 with address 0x68
MPU9250 IMU(Wire,0x68);
int status;
int v=0;

void setup() {
  // serial to display data
  Serial.begin(115200);
  while(!Serial) {}

  // start communication with IMU 
  status = IMU.begin();
 /* if (status < 0) {
    Serial.println("IMU initialization unsuccessful");
    Serial.println("Check IMU wiring or try cycling power");
    Serial.print("Status: ");
    Serial.println(status);
    while(1) {}
  }*/
}

void loop() {
  // read the sensor
  IMU.readSensor();
  // display the data
  //Serial.println(IMU.getAccelX_mss(),6);
  if (v==0){
     if ((IMU.getAccelX_mss())<-4){
 // Serial.print(IMU.getAccelX_mss(),6);
  Serial.println("1");
  }
  if ((IMU.getAccelX_mss())>4){
  //Serial.print(IMU.getAccelX_mss(),6);
  Serial.println("2");
  }
  if ((IMU.getAccelY_mss())>4){
  //Serial.print(IMU.getAccelY_mss(),6);
  Serial.println("3");
  }
  if ((IMU.getAccelY_mss())<-4){
  //Serial.print(IMU.getAccelY_mss(),6);
  Serial.println("4");
  }
  if (((IMU.getAccelY_mss())>-4)&&((IMU.getAccelY_mss())<4)&&((IMU.getAccelX_mss())<4)&&((IMU.getAccelX_mss())>-4)){
  //Serial.print(IMU.getAccelY_mss(),6);
  Serial.println("0");
  }
  if (((IMU.getAccelX_mss())<-15)||((IMU.getAccelX_mss())>15)||((IMU.getAccelY_mss())>15)||((IMU.getAccelY_mss())<-15))
  v=1;
  }
  
  if (v==1){
  //Serial.println(IMU.getAccelX_mss(),6);
  if ((IMU.getAccelX_mss())<-40){
 // Serial.print(IMU.getAccelX_mss(),6);
  Serial.println("1");
  }
  if ((IMU.getAccelX_mss())>40){
  //Serial.print(IMU.getAccelX_mss(),6);
  Serial.println("2");
  }
  if ((IMU.getAccelY_mss())>40){
  //Serial.print(IMU.getAccelY_mss(),6);
  Serial.println("3");
  }
  if ((IMU.getAccelY_mss())<-40){
  //Serial.print(IMU.getAccelY_mss(),6);
  Serial.println("4");
  }
  if (((IMU.getAccelY_mss())>-40)&&((IMU.getAccelY_mss())<40)&&((IMU.getAccelX_mss())<40)&&((IMU.getAccelX_mss())>-40)){
  //Serial.print(IMU.getAccelY_mss(),6);
  Serial.println("0");
  }
  }
  /*Serial.print(IMU.getAccelZ_mss(),6);
  Serial.print("\t");
  Serial.print(IMU.getGyroX_rads(),6);
  Serial.print("\t");
  Serial.print(IMU.getGyroY_rads(),6);
  Serial.print("\t");
  Serial.print(IMU.getGyroZ_rads(),6);
  Serial.print("\t");
  Serial.print(IMU.getMagX_uT(),6);
  Serial.print("\t");
  Serial.print(IMU.getMagY_uT(),6);
  Serial.print("\t");
  Serial.print(IMU.getMagZ_uT(),6);
  Serial.print("\t");
  Serial.println(IMU.getTemperature_C(),6);*/
  //delay(40);
  
   digitalWrite(13,HIGH);
}
