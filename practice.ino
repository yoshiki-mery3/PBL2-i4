#include <Wire.h>                      // ライブラリのインクルード
#include <Adafruit_PWMServoDriver.h>
 
 Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver(0x40);  // PCA9685のI2Cアドレスを指定
 
#define SERVOMIN 110    // 最小パルス幅(~4096の範囲)
#define SERVOMAX 480    // 最大パルス幅(~4096の範囲)
 
 int angle;
 
 void setup() {

   pwm.begin();         // 初期設定
   pwm.setPWMFreq(50);  // PWM周期を50Hzに設定
 
   for(int i=0; i<=15; i++){  // 全てのサーボを90度の位置に動かす
     servo_move(i, 90);
     delay(100);
   }

   delay(1000);
 
}
 
 void loop() {
   angle = 0;                 // 0~15番の順にサーボを0度の位置に動かす
   for(int i=0; i<=15; i++){
     servo_move(i, angle);
     delay(70);
   }
 
 delay(500);
 
   angle = 180;               // 15~0番の順にサーボを180度の位置に動かす
   for(int i=15; i>=0; i--){
     servo_move(i, angle);
     delay(70);
   }
 
 delay(500);
 
}
 
// 指定角度にサーボを動かす
 void servo_move(int n, int angle){
   angle = map(angle, 0, 180, SERVOMIN, SERVOMAX);
   pwm.setPWM(n, 0, angle);
}