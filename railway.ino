#include <Servo.h>
const int buzzer = 5; //buzzer to arduino pin 5
int servoPinL = 9;
int servoPinR = 6;
int LED = 13; // Use the onboard Uno LED
int isObstaclePinL = 7;  // This is our input pin
int isObstacleL = LOW;  // HIGH MEANS OBSTACLE
int isObstaclePinR = 8;  // This is our input pin
int isObstacleR = LOW;  // HIGH MEANS OBSTACLE
Servo servoL;  
Servo servoR; 
int servoAngle = 0;   // servo position in degrees
int c=0;
void setup() {
   pinMode(buzzer, OUTPUT);
  pinMode(LED, OUTPUT);
  pinMode(isObstaclePinL, INPUT);
    pinMode(isObstaclePinR, INPUT);
   servoL.attach(servoPinL);
   servoR.attach(servoPinR);
   Serial.begin(9600);
   
}

void loop() {
  isObstacleL = digitalRead(isObstaclePinL);
  isObstacleR = digitalRead(isObstaclePinR);  
  if (isObstacleL||isObstacleR == HIGH)
  { 
    Serial.println("OBSTACLE!!, OBSTACLE!!");
    digitalWrite(LED, HIGH);
    servoL.write(0);      // Turn SG90 servo back to 0 degrees (center position)
    servoR.write(0);
   
    if(c<4)
    {
  tone(buzzer, 1000); // Send 1KHz sound signal...
  delay(1000);
   noTone(buzzer);
   delay(1000);          // Wait 1 second
    }
    c++; 
   }
  else
  {
    Serial.println("clear");
    digitalWrite(LED, LOW);
    servoL.write(90);      // Turn SG90 servo back to 90 degrees (center position)
    servoR.write(90); 
   delay(1000);          // Wait 1 second
 c=0;
  }
}
