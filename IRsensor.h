#define IRsensor1 16     //left  
#define IRsensor2 17
#define IRsensor3 18
#define IRsensor4 19     //right
#define IRsensor5 20     //left  
#define IRsensor6 21


int error = 0, pre_error = 0;

void sensor_init(){
  pinMode(IRsensor1,INPUT_PULLUP);
  pinMode(IRsensor2,INPUT_PULLUP);
  pinMode(IRsensor3,INPUT_PULLUP);
  pinMode(IRsensor4,INPUT_PULLUP);
  pinMode(IRsensor5,INPUT_PULLUP);
  pinMode(IRsensor6,INPUT_PULLUP);
}

void error_IRsensor(){
  int IRsensor[] = {IRsensor1,IRsensor2,IRsensor3,IRsensor4,IRsensor5,IRsensor6};

  if((digitalRead(IRsensor[0])==0) && (digitalRead(IRsensor[1])==1) && (digitalRead(IRsensor[2])==1) && (digitalRead(IRsensor[3])==1) && (digitalRead(IRsensor[4])==1) && (digitalRead(IRsensor[5])==1)){ error = -5; pre_error = error;}
  else if((digitalRead(IRsensor[0])==0) && (digitalRead(IRsensor[1])==0) && (digitalRead(IRsensor[2])==1) && (digitalRead(IRsensor[3])==1) && (digitalRead(IRsensor[4])==1) && (digitalRead(IRsensor[5])==1)){ error = -4; pre_error = error;}
  else if((digitalRead(IRsensor[0])==1) && (digitalRead(IRsensor[1])==0) && (digitalRead(IRsensor[2])==1) && (digitalRead(IRsensor[3])==1) && (digitalRead(IRsensor[4])==1) && (digitalRead(IRsensor[5])==1)){ error = -3; pre_error = error;}
  else if((digitalRead(IRsensor[0])==1) && (digitalRead(IRsensor[1])==0) && (digitalRead(IRsensor[2])==0) && (digitalRead(IRsensor[3])==1) && (digitalRead(IRsensor[4])==1) && (digitalRead(IRsensor[5])==1)){ error = -2; pre_error = error;}
  else if((digitalRead(IRsensor[0])==1) && (digitalRead(IRsensor[1])==1) && (digitalRead(IRsensor[2])==0) && (digitalRead(IRsensor[3])==1) && (digitalRead(IRsensor[4])==1) && (digitalRead(IRsensor[5])==1)){ error = -1; pre_error = error;}
  else if((digitalRead(IRsensor[0])==1) && (digitalRead(IRsensor[1])==1) && (digitalRead(IRsensor[2])==0) && (digitalRead(IRsensor[3])==0) && (digitalRead(IRsensor[4])==1) && (digitalRead(IRsensor[5])==1)){ error = 0; pre_error = error;}
  else if((digitalRead(IRsensor[0])==1) && (digitalRead(IRsensor[1])==1) && (digitalRead(IRsensor[2])==1) && (digitalRead(IRsensor[3])==0) && (digitalRead(IRsensor[4])==1) && (digitalRead(IRsensor[5])==1)){ error = 1; pre_error = error;}
  else if((digitalRead(IRsensor[0])==1) && (digitalRead(IRsensor[1])==1) && (digitalRead(IRsensor[2])==1) && (digitalRead(IRsensor[3])==0) && (digitalRead(IRsensor[4])==0) && (digitalRead(IRsensor[5])==1)){ error = 2; pre_error = error;}
  else if((digitalRead(IRsensor[0])==1) && (digitalRead(IRsensor[1])==1) && (digitalRead(IRsensor[2])==1) && (digitalRead(IRsensor[3])==1) && (digitalRead(IRsensor[4])==0) && (digitalRead(IRsensor[5])==1)){ error = 3; pre_error = error;}
  else if((digitalRead(IRsensor[0])==1) && (digitalRead(IRsensor[1])==1) && (digitalRead(IRsensor[2])==1) && (digitalRead(IRsensor[3])==1) && (digitalRead(IRsensor[4])==0) && (digitalRead(IRsensor[5])==0)){ error = 4; pre_error = error;}
  else if((digitalRead(IRsensor[0])==1) && (digitalRead(IRsensor[1])==1) && (digitalRead(IRsensor[2])==1) && (digitalRead(IRsensor[3])==1) && (digitalRead(IRsensor[4])==1) && (digitalRead(IRsensor[5])==0)){ error = 5; pre_error = error;}
  else if((digitalRead(IRsensor[0])==1) && (digitalRead(IRsensor[1])==1) && (digitalRead(IRsensor[2])==1) && (digitalRead(IRsensor[3])==1) && (digitalRead(IRsensor[4])==1) && (digitalRead(IRsensor[5])==1)){ error = 6; pre_error = error;}
  else{ error = pre_error;}
//  Serial.println(digitalRead(IRsensor[5]));
}
