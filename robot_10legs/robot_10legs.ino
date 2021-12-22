#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver(0x40);

#define SERVOMIN 135    // this is the 'minimum' pulse length count (out of 4096)
#define SERVOMAX 430    // this is the 'maximum' pulse length count (out of 4096)

#define map_leg1_angle(angle) map(angle, 0, 165, SERVOMIN, SERVOMAX)
#define map_front_leg2_angle(angle) map(angle, 15, 180, SERVOMIN, SERVOMAX)
#define map_front_leg3_angle(angle) map(angle, 180, 345, SERVOMIN, SERVOMAX)
#define map_back_leg2_angle(angle) map(angle, 0, 165, SERVOMIN, SERVOMAX)

typedef enum {

  //left front leg
  legLF3_pin = 0,
  legLF2_pin = 1,
  legLF1_pin = 2,

  //left back leg
  legLB3_pin = 4,
  legLB2_pin = 5,
  legLB1_pin = 6,
  
  //right back leg
  legRB3_pin = 8,
  legRB2_pin = 9,
  legRB1_pin = 10,
  
  //right front leg
  legRF3_pin = 12,
  legRF2_pin = 13,
  legRF1_pin = 14,
  
}servo_pin_num;

struct leg1_servo_angles {
  int straight;
  int lowerstraight;
  int middle;
  int lowerside;
  int side;
};

struct front_leg2_servo_angles {
  int beyond_up;
  int up;
  int lower_up;
  int horizontal;
};

struct front_leg3_servo_angles {
  int horizontal;
  int down;
  int beyond_down;
};

struct back_leg2_servo_angles {
  int down; 
  int horizontal;
  int up;
};

leg1_servo_angles legLF1_angle  ={15, 45, 60, 75, 105};
leg1_servo_angles legRF1_angle  ={150, 120, 105, 90, 60};
leg1_servo_angles legLB1_angle  ={150, 120, 105, 90, 60};
leg1_servo_angles legRB1_angle  ={15, 45, 60, 75, 105};

front_leg2_servo_angles legLF2_angle  ={75, 90, 105, 180};
front_leg2_servo_angles legRF2_angle  ={75, 90, 105, 180};

front_leg3_servo_angles legLF3_angle  ={180, 270, 345};
front_leg3_servo_angles legRF3_angle  ={180, 270, 345};

back_leg2_servo_angles legLB2_angle  ={165, 90, 0};
back_leg2_servo_angles legRB2_angle  ={165, 90, 0};


void setup() {
  
    pwm.begin();
    pwm.setPWMFreq(50);  // analog servos run at 50Hz updates

    //if you want to set servo degree to zero , comment out here.
    //initialize_servo_degree();

    //front left leg state
    pwm.setPWM(legLF3_pin, 0, map_front_leg3_angle(legLF3_angle.beyond_down));
    pwm.setPWM(legLF2_pin, 0, map_front_leg2_angle(legLF2_angle.lower_up));
    pwm.setPWM(legLF1_pin, 0, map_leg1_angle(legLF1_angle.side));

    //front right leg state
    pwm.setPWM(legRF3_pin, 0, map_front_leg3_angle(legRF3_angle.beyond_down));     
    pwm.setPWM(legRF2_pin, 0, map_front_leg2_angle(legRF2_angle.lower_up));     
    pwm.setPWM(legRF1_pin, 0, map_leg1_angle(legRF1_angle.side));

    //back left leg state
    pwm.setPWM(legLB2_pin, 0, map_back_leg2_angle(legLB2_angle.up));
    pwm.setPWM(legLB1_pin, 0, map_leg1_angle(legLB1_angle.side));
    
    //back right leg state
    pwm.setPWM(legRB2_pin, 0, map_back_leg2_angle(legRB2_angle.up));
    pwm.setPWM(legRB1_pin, 0, map_leg1_angle(legRB1_angle.side));



}
      
//here is movement of creepgates
void loop() {
  
// delay(1000); 
// //初期セッティング

// delay(1000);
// //前左脚を前に
// pwm.setPWM(legLF2_pin, 0, map_leg2_angle(legLF3_angle.horaizontal));
// delay(500);
// pwm.setPWM(legLF2_pin, 0, map_leg2_angle(legLF2_angle.horaizontal));
// delay(500);
// pwm.setPWM(legLF1_pin, 0, map_leg1_angle(legLF1_angle.lowerstraight));
// delay(500);
// pwm.setPWM(legLF2_pin, 0, map_leg2_angle(legLF2_angle.down));

// delay(1000);
// //前右脚を前に
// pwm.setPWM(legRF2_pin, 0, map_leg2_angle(legRF2_angle.horaizontal));
// delay(500);
// pwm.setPWM(legRF1_pin, 0, map_leg1_angle(legRF1_angle.lowerstraight));
// delay(500);
// pwm.setPWM(legRF2_pin, 0, map_leg2_angle(legRF2_angle.down));

// delay(1000);
// //後ろ左脚を胴体横に
// pwm.setPWM(legLB2_pin, 0, map_leg2_angle(legLB2_angle.horaizontal));
// delay(500);
// pwm.setPWM(legLB1_pin, 0, map_leg1_angle(legLB1_angle.side));
// delay(500);
// pwm.setPWM(legLB2_pin, 0, map_leg2_angle(legLB2_angle.down));

// delay(1000);
// //後ろ右脚を胴体斜め後ろに
// pwm.setPWM(legRB2_pin, 0, map_leg2_angle(legRB2_angle.horaizontal));
// delay(500);
// pwm.setPWM(legRB1_pin, 0, map_leg1_angle(legRB1_angle.side));
// delay(500);
// pwm.setPWM(legRB2_pin, 0, map_leg2_angle(legRB2_angle.down));


// delay(1000); 
// //前進移動

// //同時
// //前右脚を斜め後ろに
// pwm.setPWM(legRF1_pin, 0, map_leg1_angle(legRF1_angle.lowerside));
// //前左脚を斜め後ろに
// pwm.setPWM(legLF1_pin, 0, map_leg1_angle(legLF1_angle.lowerside));
// //後ろ左脚を斜め後ろ
// pwm.setPWM(legLB1_pin, 0, map_leg1_angle(legLB1_angle.lowerstraight));
// //後ろ右脚を斜め後ろ
// pwm.setPWM(legRB1_pin, 0, map_leg1_angle(legRB1_angle.lowerstraight));

}


void initialize_servo_degree(){
  while(true){
    //front left leg state
    pwm.setPWM(legLF3_pin, 0, map_front_leg3_angle(legLF3_angle.horizontal));
    pwm.setPWM(legLF2_pin, 0, map_front_leg2_angle(legLF2_angle.horizontal));
    pwm.setPWM(legLF1_pin, 0, map_leg1_angle(legLF1_angle.straight));

    //front right leg state
    pwm.setPWM(legRF3_pin, 0, map_front_leg3_angle(legRF3_angle.horizontal));     
    pwm.setPWM(legRF2_pin, 0, map_front_leg2_angle(legRF2_angle.horizontal));     
    pwm.setPWM(legRF1_pin, 0, map_leg1_angle(legRF1_angle.straight));

    //back left leg state
    pwm.setPWM(legLB2_pin, 0, map_back_leg2_angle(legLB2_angle.beyond_horizontal));
    pwm.setPWM(legLB1_pin, 0, map_leg1_angle(legLB1_angle.straight));
    
    //back right leg state
    pwm.setPWM(legRB2_pin, 0, map_back_leg2_angle(legRB2_angle.beyond_horizontal));
    pwm.setPWM(legRB1_pin, 0, map_leg1_angle(legRB1_angle.straight));

    delay(1000);
    }
}
