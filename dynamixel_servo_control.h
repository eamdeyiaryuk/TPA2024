#include "Dynamixel_for_Arduino.h"
#include <SoftwareSerial.h>

SoftwareSerial DX_SERIAL(15,14); // rx,tx  15,14
// Object Define
DX DX_Motor1;
DX DX_Motor2;
DX DX_Motor4;
DX DX_Motor3;
DX DX_Motor5;
DX DX_Motor6;
DX DX_Motor7;

// Setting  
#define DX_SERIAL_BAUD 115200 //57600
#define DRIVE_SPD_RANGE 1000
#define JOINT_SPD_RANGE 10
// Set ID
#define DX_MOTOR1_ID 1
#define DX_MOTOR2_ID 2    //right gripper (looked from front) 
#define DX_MOTOR4_ID 4    //right gripper upper (looked from front) 

#define DX_MOTOR3_ID 3    //left gripper (looked from front) 
#define DX_MOTOR5_ID 5    //left gripper upper (looked from front)

#define DX_MOTOR6_ID 6    //hook backside
#define DX_MOTOR7_ID 7    //roller backside

void dynamixel_init()
{
  DX_Motor1.begin(&DX_SERIAL, DX_SERIAL_BAUD);
  DX_Motor1.setMode("JOINT");
  DX_Motor1.setID(DX_MOTOR1_ID);
  DX_Motor1.setSpeedRange(-DRIVE_SPD_RANGE, DRIVE_SPD_RANGE);
  DX_Motor1.setSpeedMax(JOINT_SPD_RANGE);
  DX_Motor1.setPosRange(0,300);
  DX_Motor1.setPosLimit(0,300);

  DX_Motor2.begin(&DX_SERIAL, DX_SERIAL_BAUD);
  DX_Motor2.setMode("JOINT");
  DX_Motor2.setID(DX_MOTOR2_ID);
  DX_Motor2.setSpeedRange(-DRIVE_SPD_RANGE, DRIVE_SPD_RANGE);
  DX_Motor2.setSpeedMax(JOINT_SPD_RANGE);
  DX_Motor2.setPosRange(0,300);
  DX_Motor2.setPosLimit(0,300);

  DX_Motor4.begin(&DX_SERIAL, DX_SERIAL_BAUD);
  DX_Motor4.setMode("JOINT");
  DX_Motor4.setID(DX_MOTOR4_ID);
  DX_Motor4.setSpeedRange(-DRIVE_SPD_RANGE, DRIVE_SPD_RANGE);
  DX_Motor4.setSpeedMax(JOINT_SPD_RANGE);
  DX_Motor4.setPosRange(0,300);
  DX_Motor4.setPosLimit(0,300);

  DX_Motor3.begin(&DX_SERIAL, DX_SERIAL_BAUD);
  DX_Motor3.setMode("JOINT");
  DX_Motor3.setID(DX_MOTOR3_ID);
  DX_Motor3.setSpeedRange(-DRIVE_SPD_RANGE, DRIVE_SPD_RANGE);
  DX_Motor3.setSpeedMax(JOINT_SPD_RANGE);
  DX_Motor3.setPosRange(0,300);
  DX_Motor3.setPosLimit(0,300);

  DX_Motor5.begin(&DX_SERIAL, DX_SERIAL_BAUD);
  DX_Motor5.setMode("JOINT");
  DX_Motor5.setID(DX_MOTOR5_ID);
  DX_Motor5.setSpeedRange(-DRIVE_SPD_RANGE, DRIVE_SPD_RANGE);
  DX_Motor5.setSpeedMax(JOINT_SPD_RANGE);
  DX_Motor5.setPosRange(0,300);
  DX_Motor5.setPosLimit(0,300);

  DX_Motor6.begin(&DX_SERIAL, DX_SERIAL_BAUD);
  DX_Motor6.setMode("JOINT");
  DX_Motor6.setID(DX_MOTOR6_ID);
  DX_Motor6.setSpeedRange(-DRIVE_SPD_RANGE, DRIVE_SPD_RANGE);
  DX_Motor6.setSpeedMax(JOINT_SPD_RANGE);
  DX_Motor6.setPosRange(0,300);
  DX_Motor6.setPosLimit(0,300);

  DX_Motor7.begin(&DX_SERIAL, DX_SERIAL_BAUD);
  DX_Motor7.setMode("WHEEL");
  DX_Motor7.setID(DX_MOTOR7_ID);
  DX_Motor7.setSpeedRange(-DRIVE_SPD_RANGE, DRIVE_SPD_RANGE);
  
}
