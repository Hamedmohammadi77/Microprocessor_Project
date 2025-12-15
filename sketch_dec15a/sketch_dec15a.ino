#include <Servo.h>

Servo servo;
int servoPin = 2;

int currentAngle = 90;  

int ir=9;
int irstate;
void setup() {
  Serial.begin(9600);
  servo.attach(servoPin);
  servo.write(currentAngle);
  Serial.println("Send 1 or 2");
  pinMode(ir,INPUT);
}


void loop() {
  irstate=digitalRead(ir);
  char cmd='3';
  if(irstate==HIGH){
    Serial.println("OpenGate");
    cmd = '1';
  }
  else{
        Serial.println("CloseGate");
        cmd = '2';
  }
  // if (Serial.available() > 0) {
    // cmd = Serial.read();

    if (cmd == '1') {
      currentAngle = 180;   // 90 درجه ساعت‌گرد
      servo.write(currentAngle);
      Serial.println("Rotate CW (90 degree)");
    }

    else if (cmd == '2') {
      currentAngle = 0;     // 90 درجه پادساعت‌گرد
      servo.write(currentAngle);
      Serial.println("Rotate CCW (90 degree)");
    }
  // }
}
