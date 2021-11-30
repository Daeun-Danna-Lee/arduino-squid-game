#include <Servo.h>
#include <LiquidCrystal.h>

int SERVO = 9;
int RS = 12, EN = 11, D4 = 7, D5 = 6, D6 = 5, D7 = 4;

Servo servo_9;
LiquidCrystal lcd(RS, EN, D4, D5, D6, D7);

signed short minutes=5, seconds=0;
char timeline;

void setup()
{
  Serial.begin(9600);
  servo_9.attach(SERVO, 500, 2500);
  lcd.begin(16, 2);
}

void loop()
{
  calculateTime();
  setTimerLCD();
  setDollMode();
  
  delay(1000);
}


void calculateTime() { // 시간 계산 로직
  if (seconds == 0)
  {
    if (minutes == 0) {
      Serial.println("time's up");
      return;
    }
    else {
      seconds = 60;
      minutes--;
    }
  }
  seconds--;
}


void setDollMode() { // 영희 고개 로직
  if ((seconds == 59) ||
      (seconds == 40) ||
      (seconds == 20)) {
    sayMode();
  } 
  else if ((seconds == 50) ||
           (seconds == 30) ||
           (seconds == 10)) {
    catchMode();
  }
}

void sayMode() { // 무궁화 꽃이 피었습니다 말하는 상태
  Serial.println("mugunghwa ggotchi pieotseupnida");
  servo_9.write(180);
}

void catchMode() { // 고개 돌려서 움직이는 사람 잡는 상태
  Serial.println("tang tang tang");
  servo_9.write(0);
}

void setTimerLCD() { // lcd 타이머 표출 로직
  lcd.setCursor(0, 0);
  lcd.print(minutes);
  lcd.setCursor(1, 0);
  lcd.print(":");
  
  if (seconds < 10) {
    lcd.setCursor(2, 0);
    lcd.print("0");
    lcd.setCursor(3, 0);
  	lcd.print(seconds);
  }
  else {
    lcd.setCursor(2, 0);
  	lcd.print(seconds);
  }
}
