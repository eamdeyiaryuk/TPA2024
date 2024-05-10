#include "Arduino.h"
#include "Gyro.h"
#include "Wire.h"

void Gyro::GyroSignals() {       //always use in void loop
    Wire.beginTransmission(0x68);
    Wire.write(0x1A);
    Wire.write(0x05);
    Wire.endTransmission();
    Wire.beginTransmission(0x68);
    Wire.write(0x1C);
    Wire.write(0x10);
    Wire.endTransmission();
    Wire.beginTransmission(0x68);
    Wire.write(0x3B);
    Wire.endTransmission(); 
    Wire.requestFrom(0x68,6);
    AccXLSB = Wire.read() << 8 | Wire.read();
    AccYLSB = Wire.read() << 8 | Wire.read();
    AccZLSB = Wire.read() << 8 | Wire.read();
    Wire.beginTransmission(0x68);
    Wire.write(0x1B); 
    Wire.write(0x8);
    Wire.endTransmission();                                                   
    Wire.beginTransmission(0x68);
    Wire.write(0x43);
    Wire.endTransmission();
    Wire.requestFrom(0x68,6);
    GyroX=Wire.read()<<8 | Wire.read();
    GyroY=Wire.read()<<8 | Wire.read();
    GyroZ=Wire.read()<<8 | Wire.read();

    RateRoll=(float)GyroX/65.5;
    RatePitch=(float)GyroY/65.5;
    RateYaw=(float)GyroZ/65.5;        //deegree per second
    AccX=(float)AccXLSB/4096;         //ความเร่ง
    AccY=(float)AccYLSB/4096;
    AccZ=(float)AccZLSB/4096;
    
    
  }

void Gyro::GyroCalibration(){
    Wire.setClock(400000);        //use to calibration in void SETUP 400000
    Wire.begin();
    delay(250);
    Wire.beginTransmission(0x68); 
    Wire.write(0x6B);
    Wire.write(0x00);
    Wire.endTransmission();
    for (RateCalibrationNumber=0;
           RateCalibrationNumber<2000; 
           RateCalibrationNumber ++) {
      GyroSignals();
      RateCalibrationRoll+=RateRoll;
      RateCalibrationPitch+=RatePitch;
      RateCalibrationYaw+=RateYaw;
      delay(1);
    }
    digitalWrite(13, HIGH);
    RateCalibrationRoll/=2000;
    RateCalibrationPitch/=2000;
    RateCalibrationYaw/=2000; 
  }

float Gyro::GetAngleRoll(){
    AngleRoll=atan(AccY/sqrt(AccX*AccX+AccZ*AccZ))*1/(3.142/180);
    return AngleRoll;
}

float Gyro::GetAnglePitch(){
    AnglePitch=-atan(AccX/sqrt(AccY*AccY+AccZ*AccZ))*1/(3.142/180);
    return AnglePitch;
}

float Gyro::GetAngleYaw(){
    RateRoll-=RateCalibrationRoll;
    RatePitch-=RateCalibrationPitch;
    RateYaw-=RateCalibrationYaw;

    unsigned long currentTime = millis();
    float elapsedTime = (currentTime - lastUpdateTime) / 1000.0; // เวลาที่ผ่านไปในหน่วยวินาที
    lastUpdateTime = currentTime;

    // คำนวณค่า AngleYaw โดยบวกค่า RateYaw คูณกับเวลาที่ผ่านไป
    AngleYaw += RateYaw * elapsedTime;

    return AngleYaw;
  }
float Gyro::GetRateRoll(){
  RateRoll=(float)GyroX/65.5;
  return RateRoll;
}
float Gyro::GetRatePitch(){
  RatePitch=(float)GyroY/65.5;
  return RatePitch;
}
float Gyro::GetRateYaw(){
  RateYaw=(float)GyroZ/65.5;
  return RateYaw;
}
