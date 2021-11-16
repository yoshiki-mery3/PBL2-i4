#include <Wire.h>                     
#include <Adafruit_PWMServoDriver.h>
 
Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver(0x40);  
 
#define SERVOMIN 150    // this is the 'minimum' pulse length count (out of 4096)
#define SERVOMAX 600    // this is the 'maximum' pulse length count (out of 4096)
 

 
void setup() {

    pwm.begin();        
    pwm.setPWMFreq(50);  // analog servos run at 50Hz updates
    for (int i=0; i<16;i++){
        servo_write(i,90);
        delay(50);
    }
}
 
void loop() {
    for(int i=0; i<16; i++){
        servo_write(i,170);
        delay(300);
    }
}

void servo_write(int n, int ang){ // 'n' is servo number. 'ang' is angle of servo.
    ang = map(ang, 0, 180, SERVOMIN, SERVOMAX); // convert angle(0~180) to pulse(150~600)
    pwm.setPWM(n, 0, ang);
}