#define brushless_l 23
#define brushless_r 22

void brushless_setup(){
 pinMode(brushless_l,OUTPUT);
 pinMode(brushless_r,OUTPUT);
 analogWriteFrequency(brushless_l, 50);       //(pin,frequency)
 analogWriteFrequency(brushless_r, 50);
 analogWriteResolution(12);  // 4065
 analogWrite(brushless_l,182);      //duty cycle ขวา 95.5%[182] , 91.5% ตัวซ้าย  
 delay(3000);
 analogWrite(brushless_l,325);    //ซ้าย เปิดรอบที่ 2
 delay(3000);
 analogWrite(brushless_r,182);    //ขวา เปิด
 delay(3000);
}
void brushless_spin(){
  analogWriteResolution(12);
  analogWrite(brushless_r,250);    //220-230 ลดค่าเพื่อเพิ่ม duty cycle(slower) 235
  analogWrite(brushless_l,355);    //หมุนทวนเข็ม 91.75% 340
}
void brushless_stop(){
  analogWriteResolution(12);
  analogWrite(brushless_r,0);    //220-230 ลดค่าเพื่อเพิ่ม duty cycle 
  analogWrite(brushless_l,0);    //หมุนทวนเข็ม 91.75% 340
}
