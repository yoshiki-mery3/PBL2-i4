#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>
 
Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver(0x40);

#define SERVOMIN 135    // this is the 'minimum' pulse length count (out of 4096)
#define SERVOMAX 430    // this is the 'maximum' pulse length count (out of 4096)

#define map_angle(angle) map(angle, 0, 165, SERVOMIN, SERVOMAX)

typedef enum {

  //left front leg
  legLF3_pin = 0,
  legLF2_pin = 1,
  legLF1_pin = 2,

  //left back leg
  legLb3_pin = 4,
  legLb2_pin = 5,
  legLb1_pin = 6,
  
  //right back leg
  legRB3_pin = 8,
  legRB2_pin = 9,
  legRB1_pin = 10,
  
  //right front leg
  legRF3_pin = 12,
  legRF2_pin = 13,
  legRF1_pin = 14,
  
}servo_pin_num;

struct leg1_servo_degs {
  int straight;
  int middle;
  int side;
};


struct leg2_servo_degs {
  int up;
  int horaizontal;
  int down;
};

leg1_servo_degs legLF1_deg  ={15, 60, 105};
leg1_servo_degs legRF1_deg  ={150, 105, 60};
leg1_servo_degs legLB1_deg  ={150, 105, 60};
leg1_servo_degs legRB1_deg  ={15, 60, 105};

leg2_servo_degs legLF2_deg  ={0, 90, 165};
leg2_servo_degs legRF2_deg  ={0, 90, 165};
leg2_servo_degs legLB2_deg  ={0, 90, 165};
leg2_servo_degs legRB2_deg  ={0, 90, 165};

void setup() {
  
    pwm.begin();
    pwm.setPWMFreq(50);  // analog servos run at 50Hz updates

    //前左脚
    pwm.setPWM(legLF2_pin, 0, map_angle(legLF2_deg.down));
    pwm.setPWM(legLF1_pin, 0, map_angle(legLF1_deg.straight));

    //前右脚
    pwm.setPWM(legRF2_pin, 0, map_angle(legRF2_deg.down));     
    pwm.setPWM(legRF1_pin, 0, map_angle(legRF1_deg.straight));

    //後ろ左脚
    pwm.setPWM(legLb2_pin, 0, map_angle(legLB2_deg.down));
    pwm.setPWM(legLb1_pin, 0, map_angle(legLB1_deg.straight));
    
    //後ろ右脚
    pwm.setPWM(legRB2_pin, 0, map_angle(legRB2_deg.down));
    pwm.setPWM(legRB1_pin, 0, map_angle(legRB1_deg.straight));

}
      
void loop() {
  // put your main code here, to run repeatedly:
//
////    //前脚を横にする
//    
//    //右前脚を前に
//    pwm.setPWM(legRF2_pin, 0, map_angle(legup));//脚を下に
//    delay(500);
//    //pwm.setPWM(legRF1_pin, 0, map_angle(150));
//    pwm.setPWM(legRF1_pin, 0, map_angle(105));
//    delay(500);
//    pwm.setPWM(legRF2_pin, 0, map_angle(legdown));//脚を下に
//    delay(1000);
//    
//    //左後ろ脚を横に
//    pwm.setPWM(legLb2_pin, 0, map_angle(legup));//脚を下に
//        delay(500);
//    pwm.setPWM(legLb1_pin, 0, map_angle(60));
//    delay(500);
//    pwm.setPWM(legLb2_pin, 0, map_angle(legdown));//脚を下に
//    delay(1000);
//    
//    //左前脚を前に
//    pwm.setPWM(legLF2_pin, 0, map_angle(legup));//脚を下に
//        delay(500);
//   // pwm.setPWM(legLF1_pin, 0, map_angle(15));
//    pwm.setPWM(legLF1_pin, 0, map_angle(60));
//    delay(500);
//    pwm.setPWM(legLF2_pin, 0, map_angle(legdown));//脚を下に
//    delay(1000);
//    
//    //右後ろ脚を横に
//    pwm.setPWM(legRB2_pin, 0, map_angle(legup));//脚を下に
//        delay(500);
//    pwm.setPWM(legRB1_pin, 0, map_angle(105));
//    delay(500);
//    pwm.setPWM(legRB2_pin, 0, map_angle(legdown));//脚を下に
//    delay(1000);
//    
////    //後ろ脚を前に
//
//    //胴体を前によいしょ/前脚をよこに/後ろ脚をストレートに
//    pwm.setPWM(legLF1_pin, 0, map_angle(105));
//    pwm.setPWM(legRF1_pin, 0, map_angle(60));
//    pwm.setPWM(legLb1_pin, 0, map_angle(105));
//    pwm.setPWM(legRB1_pin, 0, map_angle(15));
//    delay(1000);
//    
//}
//
//void front_with_back_legs_move(){
//
//  //前脚をちじめて
//   pwm.setPWM(legLF2_pin, 0, map_angle(10));
//  delay(100);
// pwm.setPWM(legRF2_pin, 0, map_angle(10));
// delay(1000);
//
// //後ろ脚を伸ばす
//    pwm.setPWM(legLF2_pin, 0, map_angle(10));
//  delay(100);
// pwm.setPWM(legRF2_pin, 0, map_angle(10));
// delay(1000);
//
// 
}


void front_legs_shrink(){

  //脚を上げて
   pwm.setPWM(legLF3_pin, 0, map_angle(90));
  delay(100);
 pwm.setPWM(legRF3_pin, 0, map_angle(90));
 delay(1000);

 //脚をちじめて
   pwm.setPWM(legLF2_pin, 0, map_angle(10));
  delay(100);
 pwm.setPWM(legRF2_pin, 0, map_angle(10));
 delay(1000);
 
 //脚を降ろす
  pwm.setPWM(legLF3_pin, 0, map_angle(160));
   delay(100);
 pwm.setPWM(legRF3_pin, 0, map_angle(160));
  delay(1000);
  
}

void front_legs_expand(){

    //脚を上げて
   pwm.setPWM(legLF3_pin, 0, map_angle(90));
  delay(100);
 pwm.setPWM(legRF3_pin, 0, map_angle(90));
 delay(1000);

 //脚を伸ばして
   pwm.setPWM(legLF2_pin, 0, map_angle(75));
  delay(100);
 pwm.setPWM(legRF2_pin, 0, map_angle(75));
 delay(1000);

 //脚を降ろす
  pwm.setPWM(legLF3_pin, 0, map_angle(160));
   delay(100);
 pwm.setPWM(legRF3_pin, 0, map_angle(160));
  delay(1000);
  
}

void back_legs_shrink(){

      //脚を上げて
   pwm.setPWM(legLb3_pin, 0, map_angle(90));
  delay(100);
 pwm.setPWM(legRB3_pin, 0, map_angle(90));
 delay(1000);

 //脚を伸ばして
   pwm.setPWM(legLb2_pin, 0, map_angle(10));
  delay(100);
 pwm.setPWM(legRB2_pin, 0, map_angle(10));
 delay(1000);

 //脚を降ろす
  pwm.setPWM(legLb3_pin, 0, map_angle(160));
   delay(100);
 pwm.setPWM(legRB3_pin, 0, map_angle(160));
  delay(1000);
  
}

void back_legs_expand(){

      //脚を上げて
   pwm.setPWM(legLb3_pin, 0, map_angle(90));
  delay(100);
 pwm.setPWM(legRB3_pin, 0, map_angle(90));
 delay(1000);

 //脚を伸ばして
   pwm.setPWM(legLb2_pin, 0, map_angle(75));
  delay(100);
 pwm.setPWM(legRB2_pin, 0, map_angle(75));
 delay(1000);

 //脚を降ろす
  pwm.setPWM(legLb3_pin, 0, map_angle(160));
   delay(100);
 pwm.setPWM(legRB3_pin, 0, map_angle(160));
  delay(1000);
  
}

//////
void front_legs_move_forward(){



//前脚を進行方向に、あげて、伸ばしながら、前面におく

//脚を上げる
 pwm.setPWM(legLF3_pin, 0, map_angle(90));
  delay(100);
 pwm.setPWM(legRF3_pin, 0, map_angle(90));
 delay(1000);
 
//脚を前に
 pwm.setPWM(legRF1_pin, 0, map_angle(150));
 delay(100);
 pwm.setPWM(legLF1_pin, 0, map_angle(15));
 delay(1000);


 //降ろす
 pwm.setPWM(legLF3_pin, 0, map_angle(160));
   delay(100);
 pwm.setPWM(legRF3_pin, 0, map_angle(160));
  delay(1000);



}

void back_legs_move_forward(){

}

void front_legs_move_side(){

   //脚を上げる
   pwm.setPWM(legLF3_pin, 0, map_angle(90));
    delay(100);
   pwm.setPWM(legRF3_pin, 0, map_angle(90));
   delay(1000);

    //まずは、左右前脚をサイドに90度固定しておく。初期位置とする
   pwm.setPWM(legRF1_pin, 0, map_angle(60));
   delay(100);
   pwm.setPWM(legLF1_pin, 0, map_angle(105));
   delay(1000);
  
   //降ろす
   pwm.setPWM(legLF3_pin, 0, map_angle(160));
     delay(100);
   pwm.setPWM(legRF3_pin, 0, map_angle(160));
    delay(1000);

}

void back_legs_move_side(){

}
