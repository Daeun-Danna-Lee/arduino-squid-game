/*
 서보모터 
 90 - 정지
 0 ~ 80 : 정방향으로 (0-빠르게 / 80-느리게)
 100 ~ 180 : 역방향으로 (180-빠르게 / 100-느리게)
*/
#include <Servo.h> // 서보모터 라이브러리 사용
Servo servo_9;
Servo servo_11;

int command = 0;
void setup()
{

  Serial.begin(9600);
  
  servo_9.attach(9);  // 서보모터 9번핀에 연결
  servo_11.attach(11); // 서보모터 11번핀에 연결
 
}

void loop()
{   
  if (Serial.available()) {
    command = Serial.read(); // 1

    switch (command) {
      case 49: // 1
        moveForward();
        Serial.println("forward");
        break;
      case 50: // 2
        moveBackward();
        Serial.println("backward");
        break;
      case 51: // 3
        turnRight();
        Serial.println("right");
        break;
      case 52: // 4
        turnLeft();
        Serial.println("left");
        break;
      case 53: // 5
        stopMoving();
        Serial.println("stop");
        break;
      default:
        break;
    }
  }
  
}

void moveForward() {
  // 전진
  servo_9.write(80);  // 정방향으로 가장 느리게 회전
  servo_11.write(110); // 역방향으로 진장 느리게 회전 
}

void moveBackward() {
  // 후진 
  servo_9.write(110);  // 역방향으로 가장 느리게 회전
  servo_11.write(80); // 정방향으로 진장 느리게 회전 
}

void turnRight() {
  // 우회전
  servo_9.write(90);  // 정지 
  servo_11.write(110); // 역방향으로 진장 느리게 회전
}

void turnLeft() {
  // 좌회전 
  servo_9.write(80);  // 정방향으로 가장 느리게 회전
  servo_11.write(90); // 정지 
}

void stopMoving() {
  // 정지 
  servo_9.write(90);  // 정지 
  servo_11.write(90); // 정지 
}
