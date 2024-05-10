#include <Arduino.h>

#ifndef Gyro_h
#define Gyro_h
#include <Arduino.h>
class Gyro
{
  private :
    float RateRoll,
          RatePitch,
          RateYaw;
    float RateCalibrationRoll, 
          RateCalibrationPitch,
          RateCalibrationYaw;
    int RateCalibrationNumber;
    float AccX,
          AccY,
          AccZ;
    float AngleRoll,
          AnglePitch;
    float AngleYaw = 0;
    float LoopTimer;
    int16_t AccXLSB,
            AccYLSB,
            AccZLSB;
    int16_t GyroX,
            GyroY,
            GyroZ;
    unsigned long lastUpdateTime = millis();
    
  public :
    void GyroSignals();
    void GyroCalibration();
    float GetAngleRoll();
    float GetAnglePitch();
    float GetAngleYaw();
    float GetRateRoll();
    float GetRatePitch();
    float GetRateYaw();
};
#endif
