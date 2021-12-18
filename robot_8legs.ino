#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>
 
Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver(0x40);

#define SERVOMIN 135    // this is the 'minimum' pulse length count (out of 4096)
#define SERVOMAX 430    // this is the 'maximum' pulse length count (out of 4096)

#define map_angle(angle) map(angle, 0, 165, SERVOMIN, SERVOMAX)

#define DEGMIN 0
#define DEGMAX 165

typedef enum {

  //left front leg
  servo_left_front_leg3 = 0,
  servo_left_front_leg2 = 1,
  servo_left_front_leg1 = 2,

  //left back leg
  servo_left_back_leg3 = 4,
  servo_left_back_leg2 = 5,
  servo_left_back_leg1 = 6,
  
  //right back leg
  servo_right_back_leg3 = 8,
  servo_right_back_leg2 = 9,
  servo_right_back_leg1 = 10,
  
  //right front leg
  servo_right_front_leg3 = 12,
  servo_right_front_leg2 = 13,
  servo_right_front_leg1 = 14,
  
}servo_name;

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

void setup() {

  leg1_servo_degs servo_left_front_leg1_deg   ={15, 60, 105};
  leg1_servo_degs servo_right_front_leg1_deg  ={150, 105, 60};
  leg1_servo_degs servo_left_back_leg1_deg    ={150, 105, 60};
  leg1_servo_degs servo_right_back_leg1_deg   ={15, 60, 105};
  
  leg2_servo_degs servo_left_front_leg2_deg   ={0, 90, 165};
  leg2_servo_degs servo_right_front_leg2_deg  ={0, 90, 165};
  leg2_servo_degs servo_left_back_leg2_deg    ={0, 90, 165};
  leg2_servo_degs servo_right_back_leg2_deg   ={0, 90, 165};
  
    pwm.begin();
    pwm.setPWMFreq(50);  // analog servos run at 50Hz updates

//前左脚
      pwm.setPWM(servo_left_front_leg2, 0, map_angle(servo_left_front_leg2_deg.down));
      pwm.setPWM(servo_left_front_leg1, 0, map_angle(servo_left_front_leg1_deg.straight));

//前右脚
      pwm.setPWM(servo_right_front_leg2, 0, map_angle(servo_right_front_leg2_deg.down));     
      pwm.setPWM(servo_right_front_leg1, 0, map_angle(servo_right_front_leg1_deg.straight));

//後ろ左脚
      pwm.setPWM(servo_left_back_leg2, 0, map_angle(servo_left_back_leg2_deg.down));//脚を上に
      pwm.setPWM(servo_left_back_leg1, 0, map_angle(servo_left_back_leg1_deg.straight));//脚を正面に
      
//後ろ右脚

      pwm.setPWM(servo_right_back_leg2, 0, map_angle(servo_right_back_leg2_deg.down));
      pwm.setPWM(servo_right_back_leg1, 0, map_angle(servo_right_back_leg1_deg.straight));


}
      
void loop() {
  // put your main code here, to run repeatedly:
//
////    //前脚を横にする
//    
//    //右前脚を前に
//    pwm.setPWM(servo_right_front_leg2, 0, map_angle(legup));//脚を下に
//    delay(500);
//    //pwm.setPWM(servo_right_front_leg1, 0, map_angle(150));
//    pwm.setPWM(servo_right_front_leg1, 0, map_angle(105));
//    delay(500);
//    pwm.setPWM(servo_right_front_leg2, 0, map_angle(legdown));//脚を下に
//    delay(1000);
//    
//    //左後ろ脚を横に
//    pwm.setPWM(servo_left_back_leg2, 0, map_angle(legup));//脚を下に
//        delay(500);
//    pwm.setPWM(servo_left_back_leg1, 0, map_angle(60));
//    delay(500);
//    pwm.setPWM(servo_left_back_leg2, 0, map_angle(legdown));//脚を下に
//    delay(1000);
//    
//    //左前脚を前に
//    pwm.setPWM(servo_left_front_leg2, 0, map_angle(legup));//脚を下に
//        delay(500);
//   // pwm.setPWM(servo_left_front_leg1, 0, map_angle(15));
//    pwm.setPWM(servo_left_front_leg1, 0, map_angle(60));
//    delay(500);
//    pwm.setPWM(servo_left_front_leg2, 0, map_angle(legdown));//脚を下に
//    delay(1000);
//    
//    //右後ろ脚を横に
//    pwm.setPWM(servo_right_back_leg2, 0, map_angle(legup));//脚を下に
//        delay(500);
//    pwm.setPWM(servo_right_back_leg1, 0, map_angle(105));
//    delay(500);
//    pwm.setPWM(servo_right_back_leg2, 0, map_angle(legdown));//脚を下に
//    delay(1000);
//    
////    //後ろ脚を前に
//
//    //胴体を前によいしょ/前脚をよこに/後ろ脚をストレートに
//    pwm.setPWM(servo_left_front_leg1, 0, map_angle(105));
//    pwm.setPWM(servo_right_front_leg1, 0, map_angle(60));
//    pwm.setPWM(servo_left_back_leg1, 0, map_angle(105));
//    pwm.setPWM(servo_right_back_leg1, 0, map_angle(15));
//    delay(1000);
//    
//}
//
//void front_with_back_legs_move(){
//
//  //前脚をちじめて
//   pwm.setPWM(servo_left_front_leg2, 0, map_angle(10));
//  delay(100);
// pwm.setPWM(servo_right_front_leg2, 0, map_angle(10));
// delay(1000);
//
// //後ろ脚を伸ばす
//    pwm.setPWM(servo_left_front_leg2, 0, map_angle(10));
//  delay(100);
// pwm.setPWM(servo_right_front_leg2, 0, map_angle(10));
// delay(1000);
//
// 
}


void front_legs_shrink(){

  //脚を上げて
   pwm.setPWM(servo_left_front_leg3, 0, map_angle(90));
  delay(100);
 pwm.setPWM(servo_right_front_leg3, 0, map_angle(90));
 delay(1000);

 //脚をちじめて
   pwm.setPWM(servo_left_front_leg2, 0, map_angle(10));
  delay(100);
 pwm.setPWM(servo_right_front_leg2, 0, map_angle(10));
 delay(1000);
 
 //脚を降ろす
  pwm.setPWM(servo_left_front_leg3, 0, map_angle(160));
   delay(100);
 pwm.setPWM(servo_right_front_leg3, 0, map_angle(160));
  delay(1000);
  
}

void front_legs_expand(){

    //脚を上げて
   pwm.setPWM(servo_left_front_leg3, 0, map_angle(90));
  delay(100);
 pwm.setPWM(servo_right_front_leg3, 0, map_angle(90));
 delay(1000);

 //脚を伸ばして
   pwm.setPWM(servo_left_front_leg2, 0, map_angle(75));
  delay(100);
 pwm.setPWM(servo_right_front_leg2, 0, map_angle(75));
 delay(1000);

 //脚を降ろす
  pwm.setPWM(servo_left_front_leg3, 0, map_angle(160));
   delay(100);
 pwm.setPWM(servo_right_front_leg3, 0, map_angle(160));
  delay(1000);
  
}

void back_legs_shrink(){

      //脚を上げて
   pwm.setPWM(servo_left_back_leg3, 0, map_angle(90));
  delay(100);
 pwm.setPWM(servo_right_back_leg3, 0, map_angle(90));
 delay(1000);

 //脚を伸ばして
   pwm.setPWM(servo_left_back_leg2, 0, map_angle(10));
  delay(100);
 pwm.setPWM(servo_right_back_leg2, 0, map_angle(10));
 delay(1000);

 //脚を降ろす
  pwm.setPWM(servo_left_back_leg3, 0, map_angle(160));
   delay(100);
 pwm.setPWM(servo_right_back_leg3, 0, map_angle(160));
  delay(1000);
  
}

void back_legs_expand(){

      //脚を上げて
   pwm.setPWM(servo_left_back_leg3, 0, map_angle(90));
  delay(100);
 pwm.setPWM(servo_right_back_leg3, 0, map_angle(90));
 delay(1000);

 //脚を伸ばして
   pwm.setPWM(servo_left_back_leg2, 0, map_angle(75));
  delay(100);
 pwm.setPWM(servo_right_back_leg2, 0, map_angle(75));
 delay(1000);

 //脚を降ろす
  pwm.setPWM(servo_left_back_leg3, 0, map_angle(160));
   delay(100);
 pwm.setPWM(servo_right_back_leg3, 0, map_angle(160));
  delay(1000);
  
}

//////
void front_legs_move_forward(){



//前脚を進行方向に、あげて、伸ばしながら、前面におく

//脚を上げる
 pwm.setPWM(servo_left_front_leg3, 0, map_angle(90));
  delay(100);
 pwm.setPWM(servo_right_front_leg3, 0, map_angle(90));
 delay(1000);
 
//脚を前に
 pwm.setPWM(servo_right_front_leg1, 0, map_angle(150));
 delay(100);
 pwm.setPWM(servo_left_front_leg1, 0, map_angle(15));
 delay(1000);


 //降ろす
 pwm.setPWM(servo_left_front_leg3, 0, map_angle(160));
   delay(100);
 pwm.setPWM(servo_right_front_leg3, 0, map_angle(160));
  delay(1000);



}

void back_legs_move_forward(){

}

void front_legs_move_side(){

   //脚を上げる
   pwm.setPWM(servo_left_front_leg3, 0, map_angle(90));
    delay(100);
   pwm.setPWM(servo_right_front_leg3, 0, map_angle(90));
   delay(1000);

    //まずは、左右前脚をサイドに90度固定しておく。初期位置とする
   pwm.setPWM(servo_right_front_leg1, 0, map_angle(60));
   delay(100);
   pwm.setPWM(servo_left_front_leg1, 0, map_angle(105));
   delay(1000);
  
   //降ろす
   pwm.setPWM(servo_left_front_leg3, 0, map_angle(160));
     delay(100);
   pwm.setPWM(servo_right_front_leg3, 0, map_angle(160));
    delay(1000);

}

void back_legs_move_side(){

}
