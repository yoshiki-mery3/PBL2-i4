#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver(0x40);

#define SERVOMIN 135    // this is the 'minimum' pulse length count (out of 4096)
#define SERVOMAX 430    // this is the 'maximum' pulse length count (out of 4096)

#define map_leg1_angle(angle) map(angle, 0, 165, SERVOMIN, SERVOMAX)
#define map_leg2_angle(angle) map(angle, 0, 165, SERVOMAX, SERVOMIN)

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

struct leg1_servo_angles {
  int straight;
  int middle;
  int side;
};

struct leg2_servo_angles {
  int down;
  int abovedown;
  int lowerhoraizontal;
  int horaizontal;
  int up;
};

leg1_servo_angles legLF1_angle  ={15, 60, 105};
leg1_servo_angles legRF1_angle  ={150, 105, 60};
leg1_servo_angles legLB1_angle  ={150, 105, 60};
leg1_servo_angles legRB1_angle  ={15, 60, 105};

leg2_servo_angles legLF2_angle  ={0, 30, 60, 90, 165};
leg2_servo_angles legRF2_angle  ={0, 30, 60, 90, 165};
leg2_servo_angles legLB2_angle  ={0, 30, 60, 90, 165};
leg2_servo_angles legRB2_angle  ={0, 30, 60, 90, 165};

void setup() {
  
    pwm.begin();
    pwm.setPWMFreq(50);  // analog servos run at 50Hz updates

    //front left leg state
    pwm.setPWM(legLF2_pin, 0, map_leg2_angle(legLF2_angle.down));
    pwm.setPWM(legLF1_pin, 0, map_leg1_angle(legLF1_angle.straight));

    //front right leg state
    pwm.setPWM(legRF2_pin, 0, map_leg2_angle(legRF2_angle.down));     
    pwm.setPWM(legRF1_pin, 0, map_leg1_angle(legRF1_angle.straight));

    //back left leg state
    pwm.setPWM(legLb2_pin, 0, map_leg2_angle(legLB2_angle.down));
    pwm.setPWM(legLb1_pin, 0, map_leg1_angle(legLB1_angle.straight));
    
    //back right leg state
    pwm.setPWM(legRB2_pin, 0, map_leg2_angle(legRB2_angle.down));
    pwm.setPWM(legRB1_pin, 0, map_leg1_angle(legRB1_angle.straight));

}
      
//here is movement of creepgates
void loop() {
  
  //state　number 1//
  delay(1000); 
  //front left leg state
  pwm.setPWM(legLF1_pin, 0, map_leg1_angle(legLF1_angle.middle));
  pwm.setPWM(legLF2_pin, 0, map_leg2_angle(legLF2_angle.down));
  //front right leg state
  pwm.setPWM(legRF1_pin, 0, map_leg1_angle(legRF1_angle.side));
  pwm.setPWM(legRF2_pin, 0, map_leg2_angle(legRF2_angle.down));     
  //back left leg state
  pwm.setPWM(legLb1_pin, 0, map_leg1_angle(legLB1_angle.middle));
  pwm.setPWM(legLb2_pin, 0, map_leg2_angle(legLB2_angle.down));
  //back right leg state 
  //<= this leg state will change =>
  pwm.setPWM(legRB2_pin, 0, map_leg2_angle(legRB2_angle.lowerhoraizontal));
  pwm.setPWM(legRB1_pin, 0, map_leg1_angle(legRB1_angle.side));
  delay(500);
  pwm.setPWM(legRB2_pin, 0, map_leg2_angle(legRB2_angle.down));
  //<= this leg state will change =>

  //state　number 2//
  delay(1000); 
  //front left leg state
  pwm.setPWM(legLF1_pin, 0, map_leg1_angle(legLF1_angle.middle));
  pwm.setPWM(legLF2_pin, 0, map_leg2_angle(legLF2_angle.down));
  //front right leg state
  //<= this leg state will change =>
  pwm.setPWM(legRF2_pin, 0, map_leg2_angle(legRF2_angle.lowerhoraizontal));     
  pwm.setPWM(legRF1_pin, 0, map_leg1_angle(legRF1_angle.middle));
  delay(500);
  pwm.setPWM(legRF2_pin, 0, map_leg2_angle(legRF2_angle.abovedown));     
  //<= this leg state will change =>
  //back left leg state
  pwm.setPWM(legLb1_pin, 0, map_leg1_angle(legLB1_angle.middle));
  pwm.setPWM(legLb2_pin, 0, map_leg2_angle(legLB2_angle.down));
  //back right leg state
  pwm.setPWM(legRB1_pin, 0, map_leg1_angle(legRB1_angle.side));
  pwm.setPWM(legRB2_pin, 0, map_leg2_angle(legRB2_angle.down));

  //state　number 3//
  delay(1000); 
    //front right leg state
  pwm.setPWM(legRF2_pin, 0, map_leg2_angle(legRF2_angle.lowerhoraizontal));  
  pwm.setPWM(legLb2_pin, 0, map_leg2_angle(legLB2_angle.lowerhoraizontal));   
  delay(500);
  pwm.setPWM(legRF1_pin, 0, map_leg1_angle(legRF1_angle.middle));
  pwm.setPWM(legLb1_pin, 0, map_leg1_angle(legLB1_angle.middle));
  delay(500);
  pwm.setPWM(legRF2_pin, 0, map_leg2_angle(legRF2_angle.down));     
  pwm.setPWM(legLb2_pin, 0, map_leg2_angle(legLB2_angle.abovedown));
  //back left leg state
//  pwm.setPWM(legLb2_pin, 0, map_leg2_angle(legLB2_angle.lowerhoraizontal));
//  delay(200);
//  pwm.setPWM(legLb1_pin, 0, map_leg1_angle(legLB1_angle.middle));
//  delay(200);
//  pwm.setPWM(legLb2_pin, 0, map_leg2_angle(legLB2_angle.abovedown));
  delay(500);
  
  //front left leg state
  pwm.setPWM(legLF2_pin, 0, map_leg2_angle(legLF2_angle.lowerhoraizontal));
  pwm.setPWM(legRB2_pin, 0, map_leg2_angle(legRB2_angle.lowerhoraizontal));
  delay(500);
  pwm.setPWM(legLF1_pin, 0, map_leg1_angle(legLF1_angle.side));
  pwm.setPWM(legRB1_pin, 0, map_leg1_angle(legRB1_angle.middle));
  delay(500);
  pwm.setPWM(legLF2_pin, 0, map_leg2_angle(legLF2_angle.down));
  pwm.setPWM(legRB2_pin, 0, map_leg2_angle(legRB2_angle.down));
  //back right leg state
  //pwm.setPWM(legRB2_pin, 0, map_leg2_angle(legRB2_angle.lowerhoraizontal));
  //delay(200);
  //pwm.setPWM(legRB1_pin, 0, map_leg1_angle(legRB1_angle.middle));
  //delay(200);
  //pwm.setPWM(legRB2_pin, 0, map_leg2_angle(legRB2_angle.down));
  delay(500);
    



  // //state　number 4//

  // //front left leg state
  // pwm.setPWM(legLF2_pin, 0, map_leg2_angle(legLF2_angle.down));
  // pwm.setPWM(legLF1_pin, 0, map_leg1_angle(legLF1_angle.side));
  // //front right leg state
  // pwm.setPWM(legRF2_pin, 0, map_leg2_angle(legRF2_angle.down));     
  // pwm.setPWM(legRF1_pin, 0, map_leg1_angle(legRF1_angle.middle));
  // //back left leg state
  // pwm.setPWM(legLb2_pin, 0, map_leg2_angle(legLB2_angle.down));
  // pwm.setPWM(legLb1_pin, 0, map_leg1_angle(legLB1_angle.side));
  // //back right leg state
  // pwm.setPWM(legRB2_pin, 0, map_leg2_angle(legRB2_angle.down));
  // pwm.setPWM(legRB1_pin, 0, map_leg1_angle(legRB1_angle.middle));
  // delay(1000); 

  // //state　number 5//

  // //front left leg state
  // pwm.setPWM(legLF2_pin, 0, map_leg2_angle(legLF2_angle.abovedown));
  // pwm.setPWM(legLF1_pin, 0, map_leg1_angle(legLF1_angle.middle));
  // //front right leg state
  // pwm.setPWM(legRF2_pin, 0, map_leg2_angle(legRF2_angle.down));     
  // pwm.setPWM(legRF1_pin, 0, map_leg1_angle(legRF1_angle.middle));
  // //back left leg state
  // pwm.setPWM(legLb2_pin, 0, map_leg2_angle(legLB2_angle.down));
  // pwm.setPWM(legLb1_pin, 0, map_leg1_angle(legLB1_angle.side));
  // //back right leg state
  // pwm.setPWM(legRB2_pin, 0, map_leg2_angle(legRB2_angle.down));
  // pwm.setPWM(legRB1_pin, 0, map_leg1_angle(legRB1_angle.middle));
  // delay(1000); 

  // //state　number 6//

  // //front left leg state
  // pwm.setPWM(legLF2_pin, 0, map_leg2_angle(legLF2_angle.down));
  // pwm.setPWM(legLF1_pin, 0, map_leg1_angle(legLF1_angle.middle));
  // //front right leg state
  // pwm.setPWM(legRF2_pin, 0, map_leg2_angle(legRF2_angle.down));     
  // pwm.setPWM(legRF1_pin, 0, map_leg1_angle(legRF1_angle.side));
  // //back left leg state
  // pwm.setPWM(legLb2_pin, 0, map_leg2_angle(legLB2_angle.down));
  // pwm.setPWM(legLb1_pin, 0, map_leg1_angle(legLB1_angle.middle));
  // //back right leg state
  // pwm.setPWM(legRB2_pin, 0, map_leg2_angle(legRB2_angle.abovedown));
  // pwm.setPWM(legRB1_pin, 0, map_leg1_angle(legRB1_angle.middle));
  // delay(1000); 

}
