#include "dynamixel_servo_control.h"
#include "IRsensor.h"
#include "motorcontrol.h"
#include "MPU6050_tockn.h"
#include "Wire.h"
#include "blushlesscontrol.h"
#include <Arduino.h>
// Define GPIO pins for IBT-2

#define MAIN_PROGRAM
//#define Test
//#define Stop_
//#define Test_brushless

unsigned long timer = 0;
unsigned long timer1 = 0;
unsigned long timer2 = 0;
unsigned long timer3 = 0;
unsigned long timer4 = 0;

String inputString = "";         
bool stringComplete = false; 

int X,Y,x,y,t,b,B,d;
int X2,Y2,Z2,x2,y2,t2,b2;

bool state1 = false;
bool state2 = false;
bool state3 = false;
bool state4 = false;

bool check1 = false;
bool check2 = false;
bool check3 = false;
bool RB = false;

int countB1 = 0,holdB1 = 0;
int countB2 = 0,holdB2 = 0;
int countB3 = 0,holdB3 = 0;
int countB4 = 0,holdB4 = 0;
int countB5 = 0,holdB5 = 0;
int countB6 = 0,holdB6 = 0;
int countB7 = 0,holdB7 = 0;

unsigned long timeout = 0;

void setup() 
{
  Serial.begin(115200);
  Serial1.begin(115200);

  Wire.begin();
  MotorSetup();
  brushless_setup();
  sensor_init();
  dynamixel_init();
  
  DX_Motor2.rotate(3,210);
  delay(10);
  DX_Motor2.rotate(3,210);
  delay(10);
  DX_Motor1.rotate(5,150);
  delay(10);
  DX_Motor1.rotate(5,150);
  delay(10);
  DX_Motor4.rotate(2,10);
  delay(10);
  DX_Motor4.rotate(2,10);
  delay(10);
  DX_Motor5.rotate(3,100);
  delay(10);
  DX_Motor5.rotate(3,100);
  delay(10);
  DX_Motor3.rotate(3,87);
  delay(10);
  DX_Motor3.rotate(3,87);
  delay(10);
  DX_Motor6.rotate(3,50);
  delay(10);

}




void loop() 
{
  #ifdef MAIN_PROGRAM
  if(Serial1.available())
  {
  //  timeout = 0;            //set timeout = 0
//    while (Serial1.available()) 
//    {
      // get the new byte:
//      timeout++;
      char inChar = Serial1.read();
      // add it to the inputString:
      //if(isDigit(inChar))
//      {
      inputString += (char)inChar;
      // if the incoming character is a newline, set a flag so the main loop can
      // do something about it:
//      }
      if (inChar == '\n') {
        stringComplete = true;
      }
//    } 
  }

  if (stringComplete) 
  {
    if(inputString.startsWith("X"))
    {
//     Serial.print("X:");
     inputString.replace("X","");
     X=inputString.toInt();
//     Serial.println(X);
     inputString = "";
     stringComplete = false;
    }
    else if(inputString.startsWith("Y"))
    {
//     Serial.print("Y:");
     inputString.replace("Y","");
     Y=inputString.toInt();   // Y
//     Serial.println(Y);
     inputString = "";
     stringComplete = false;
    }
    else if(inputString.startsWith("x"))
    {
//      Serial.print("x:");
     inputString.replace("x","");
     x=inputString.toInt();
//      Serial.println(x);
     inputString = "";
     stringComplete = false;
    }
    else if(inputString.startsWith("y"))
    {
//     Serial.print("y:");
     inputString.replace("y","");
     y=inputString.toInt();
//     Serial.println(y);
     inputString = "";
     stringComplete = false;
    }else if(inputString.startsWith("b"))
    {
//     Serial.print("b:");
     inputString.replace("b","");
     b=inputString.toInt();
//     Serial.println(b);
     inputString = "";
     stringComplete = false;
    }
    else if(inputString.startsWith("t"))
    {
//     Serial.print("t:");
     inputString.replace("t","");
     t=inputString.toInt();
//     Serial.println(t);
     inputString = "";
     stringComplete = false;
    }
    else if(inputString.startsWith("B"))
    {
//     Serial.print("B:");
     inputString.replace("B","");
     B=inputString.toInt();
//     Serial.println(B);
     inputString = "";
     stringComplete = false;
    }
    else if(inputString.startsWith("d"))
    {
//     Serial.print("d:");
     inputString.replace("d","");
     d=inputString.toInt();
//     Serial.println(B);
     inputString = "";
     stringComplete = false;
    }

  }
//    Togo(0, 0, 0);
    if(X<-35){X2=((X*-1)/2);Y2=0;Z2=0;}     //left axial --->right
    else if(X>35){X2=(X/2);Y2=180;Z2=0;}    
    else if(y<-20){X2=(y/2);Y2=90;Z2=0;}    //right axial 
    else if(y>20){X2=(y*-1/2);Y2=270;Z2=0;}
    else if(b>10){X2=0;Y2=0;Z2= b*1/5;}  //{Z2=(b*1/4);}
    else if(t>10){X2=0;Y2=0;Z2=t*-1/5;}  //{Z2=(t*-1/4);}
//    else if(B==16){ }  // LB
//    else if(B==32){brushless_spin(); delay(3000); brushless_stop();delay(100);}  // RB
    else {X2=0;Y2=0;Z2=0;}

    Togo(X2, Y2, Z2);
    
    Motor_A(constrain(VA,-228,228));
    Motor_B(constrain(VB,-228,228));
    Motor_C(constrain(VC,-228,228));

//    Serial.println(check3);


    if((holdB1 == 1 || B == 1) &&(check2==false)&&(check3 == false)){
        holdB1 = 1;

        if(state1 == false)
        {
          IRsensor_gripper();
        }
        else if(state1 == true)
        {
        DX_Motor1.rotate(0);          
        countB1++;
        
        if((countB1==20))
        {
//            Serial.println("step1");
         DX_Motor3.rotate(3,10);     //down
         DX_Motor3.rotate(3,10);
         DX_Motor3.rotate(3,10);
        }
        else if((countB1==30)){
//             Serial.println("step1");
         DX_Motor3.rotate(3,10);     //down
         DX_Motor3.rotate(3,10);
         DX_Motor3.rotate(3,10);
        }
        else if((countB1==50)){
//             Serial.println("step2");
         DX_Motor2.rotate(3,282);   //down
         DX_Motor2.rotate(3,282);
         DX_Motor2.rotate(3,282);
        }
        else if((countB1==60)){
//             Serial.println("step2.5");
         DX_Motor2.rotate(3,292);     //down
        }
        else if((countB1==80000)){
//          Serial.println("step3");
         DX_Motor5.rotate(3,12);         //closed ถ้าอยากให้หนีบแน่นขึ้น - ค่าเข้าไป
        }
        else if((countB1==80000)){
//          Serial.println("step3.5");
         DX_Motor5.rotate(3,12);         //closed ถ้าอยากให้หนีบแน่นขึ้น - ค่าเข้าไป
        }
        else if((countB1==106000)){
//          Serial.println("step4");
         DX_Motor4.rotate(3,104);      //closed ถ้าอยากให้หนีบแน่นขึ้น + ค่าเข้าไป
          
        }
        else if((countB1==106000)){
//          Serial.println("step4.5");
         DX_Motor4.rotate(3,104);      //closed ถ้าอยากให้หนีบแน่นขึ้น + ค่าเข้าไป
          
        }
        else if((countB1==300000)){
//          Serial.println("step3");
         DX_Motor2.rotate(3,210);         //up 
        }
        else if((countB1==301000)){
//          Serial.println("step3");
          DX_Motor3.rotate(3,90);         //up
          countB1 = 0;
          holdB1 = 0;
          state1=false;
          check2=true;
          check3=true;
        }

        }
    }

    if((holdB2 == 1 || B == 4)&&(check2 == true)){      //A button
      holdB2 = 1;
      countB2++;
      if(countB2 == 10){
        DX_Motor2.rotate(5,280);
      }
      else if(countB2 == 80000){
        DX_Motor4.rotate(3,10);
      }
      else if(countB2 == 200000){
        DX_Motor2.rotate(3,210);
        holdB2 = 0;
        countB2 = 0;
        check2 = false;
      }
    }
    
      

     if((holdB3 == 1 || B == 2)&&(check3 == true)){       //B button
      holdB3 = 1;
      countB3++;
      if(countB3 == 10){
        DX_Motor3.rotate(5,10);     //down
      }
      else if(countB3 == 80000){
        DX_Motor5.rotate(3,100);    //opened
      }
      else if(countB3 == 200000){
        DX_Motor3.rotate(5,90);     //up
      }
      else if(countB3 == 600000){
        DX_Motor1.rotate(5,150);    //rotated to center
        holdB3 = 0;
        countB3 = 0;
        check3 = false;
      }
    }

    if(holdB4 == 1 || B == 32){      //RB button
      holdB4 = 1;
      countB4++;
      if(countB4 == 10){
        DX_Motor3.rotate(5,10);     //arm down
//        DX_Motor6.rotate(3,120);
      }
      else if(countB4 == 30){
        DX_Motor2.rotate(5,280);    //arm down
      }
      else if(countB4 == 5000){
        brushless_spin();     //
      }
      else if(countB4 == 10000){
        DX_Motor7.rotate(-1000);    // brushless stop
        holdB4 = 0;
        countB4 = 0;
        
      }
    }

    if(holdB5 == 1 || B == 16){      //LB button
      holdB5 = 1;
      countB5++;
      if(countB5 == 10){
       DX_Motor2.rotate(3,210);     //arm up
//       DX_Motor6.rotate(3,120);     //back arm up
      }
      else if(countB5 == 30){
        DX_Motor3.rotate(5,90);    //arm up
//        DX_Motor6.rotate(3,243);
      }
      else if(countB5 == 100){
        brushless_stop();     
        holdB5 = 0;
        countB5 = 0;
      }
    }

    if(holdB6 == 1 || d == 2){      //Y button
      holdB6 = 1;
      countB6++;
      if(countB6 == 100){
          DX_Motor6.rotate(3,243);
          DX_Motor6.rotate(3,243);
          DX_Motor6.rotate(3,243);
          countB6 = 0;
          holdB6 = 0;

      }
    }

    if(holdB7 == 1 || d == 1){
      holdB7 = 1;
      countB7++;
      if(countB7 == 100){
        DX_Motor6.rotate(3,120);
        DX_Motor6.rotate(3,120);
        countB7 = 0;
        holdB7 = 0;
      }
    }

    
//  if (millis() - timer > 100) 
//  {
//    Serial.print("d = "); Serial.print("\t"); Serial.println(d);
////    Serial.print("VA = "); Serial.print(VAA); Serial.print("\t");
////    Serial.print("VB = "); Serial.print(VBB); Serial.print("\t");
////    Serial.print("VC = "); Serial.println(VCC);
//    timer = millis();
//  }

  #endif
  
  #ifdef Test
//  error_IRsensor();
  Togo(0,0,0);
  DX_Motor1.rotate(5,150);
  Motor_A(VA);
  Motor_B(VB);
  Motor_C(VC);
  #endif

  #ifdef Test_brushless
  brushless_spin();
  #endif

  #ifdef Stop_
  Motor_A(0);
  Motor_B(0);
  Motor_C(0);
  #endif
}

  
void IRsensor_gripper(){
  error_IRsensor();
//  Serial.print("error = "); Serial.print("\t"); Serial.println(error);
  if(error == -5){ DX_Motor1.rotate(5,300); state1 = false; }
  else if(error == -4){ DX_Motor1.rotate(3,300); state1 = false; }
  else if(error == -3){ DX_Motor1.rotate(1,300);  state1 = false;}
  else if(error == -2){ DX_Motor1.rotate(3,300); state1 = false; }
  else if(error == -1){ DX_Motor1.rotate(1,300);  state1 = false;}
  else if(error == 0){ DX_Motor1.rotate(0); state1 = true;}
  else if(error == 1){ DX_Motor1.rotate(1,0);  state1 = false;}
  else if(error == 2){ DX_Motor1.rotate(3,0);  state1 = false;}
  else if(error == 3){ DX_Motor1.rotate(5,0);  state1 = false;}
  else if(error == 4){ DX_Motor1.rotate(5,0);  state1 = false;}
  else if(error == 5){ DX_Motor1.rotate(5,0);  state1 = false;}
  else if(error == 6){ DX_Motor1.rotate(0);  state1 = false;}
  
}
