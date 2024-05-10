// Define GPIO pins for IBT-2

#define APWM_OutputL 10  // motor A pin l
#define APWM_OutputR 9  // motor A pin r
#define A_brake 11

#define BPWM_OutputL 3
#define BPWM_OutputR 4
#define B_brake 5

#define CPWM_OutputL 7
#define CPWM_OutputR 6
#define C_brake 8

float VA, VB, VC, VAA, VBB, VCC, CP;
float ToRadian = PI / 180;
int max_speed = 255;


void MotorSetup() {
  pinMode(APWM_OutputL, OUTPUT);
  pinMode(APWM_OutputR, OUTPUT);
  pinMode(BPWM_OutputL, OUTPUT);
  pinMode(BPWM_OutputR, OUTPUT);
  pinMode(CPWM_OutputL, OUTPUT);
  pinMode(CPWM_OutputR, OUTPUT);
}

void Togo(float V, float Theta, float w) {
  float c = V * cos(Theta * ToRadian);
  float s = V * sin(Theta * ToRadian);

  VC = c * cos(270 * ToRadian) - s * sin(270 * ToRadian) + w ;
  VB = c * cos(150 * ToRadian) - s * sin(150 * ToRadian) + w; //+ output;
  VA = c * cos(30 * ToRadian) - s * sin(30 * ToRadian) + w; //- output ;

  return VA,VB,VC;

  //    Motor_A(VA);
  //    Motor_B(VB);
  //    Motor_C(VC);
}

void Motor_A(float x) {
  analogWriteResolution(8);
  if (x > 0) { // Forward
    digitalWrite(APWM_OutputL, HIGH);
    digitalWrite(APWM_OutputR, LOW);
//    digitalWrite(A_brake, LOW);
    analogWrite(APWM_OutputL, abs(x));
  } else if (x < 0) { // Backward
    digitalWrite(APWM_OutputL, LOW);
    digitalWrite(APWM_OutputR, HIGH);
//    digitalWrite(A_brake, LOW);
    analogWrite(APWM_OutputR, abs(x));
  } else { // Stop
    digitalWrite(APWM_OutputL, LOW);
    digitalWrite(APWM_OutputR, LOW);
    digitalWrite(A_brake, HIGH);
    analogWrite(APWM_OutputL, 0);
    analogWrite(APWM_OutputR, 0);
  }
}

void Motor_B(float x) {
  analogWriteResolution(8);
  if (x > 0) {
    digitalWrite(BPWM_OutputL, HIGH);
    digitalWrite(BPWM_OutputR, LOW);
//    digitalWrite(B_brake, LOW);
    analogWrite(BPWM_OutputL, abs(x));
  } else if (x < 0) {
    digitalWrite(BPWM_OutputL, LOW);
    digitalWrite(BPWM_OutputR, HIGH);
//    digitalWrite(B_brake, LOW);
    analogWrite(BPWM_OutputR, abs(x));
  } else {
    digitalWrite(BPWM_OutputL, LOW);
    digitalWrite(BPWM_OutputR, LOW);
    digitalWrite(B_brake, HIGH);
    analogWrite(BPWM_OutputL, 0);
    analogWrite(BPWM_OutputR, 0);
  }
}

void Motor_C(float x) {
  analogWriteResolution(8);
  if (x > 0) {
    digitalWrite(CPWM_OutputL, HIGH);
    digitalWrite(CPWM_OutputR, LOW);
//    digitalWrite(C_brake, LOW);
    analogWrite(CPWM_OutputL, abs(x));
  } else if (x < 0) {
    digitalWrite(CPWM_OutputL, LOW);
    digitalWrite(CPWM_OutputR, HIGH);
//    digitalWrite(C_brake, LOW);
    analogWrite(CPWM_OutputR, abs(x));
  } else {
    digitalWrite(CPWM_OutputL, LOW);
    digitalWrite(CPWM_OutputR, LOW);
    digitalWrite(C_brake, HIGH);
    analogWrite(CPWM_OutputL, 0);
    analogWrite(CPWM_OutputR, 0);
  }
}
