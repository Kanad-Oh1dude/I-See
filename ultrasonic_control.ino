// Kanad Patel
// Arduino ultra sonic sensor code
// I have used the code from various online resources 
// And have amalgamated various function for our use case.
#include<Servo.h> 
const int frontEchoPin = 8;
const int frontTriggerPin = 9;
const int leftEchoPin = 11;
const int leftTriggerPin = 10;
const int rightEchoPin = 13;
const int rightTriggerPin = 12;
const int motorL1 = 3;
const int motorL2 = 4;
const int motorR1 = 5;
const int motorR2 = 6;
// Below variables are written in volatile variable beacuse their value is beyond the control of the code.
volatile float maxFrontDistance = 50.00;
volatile float frontDuration, frontDistanceCm, leftDuration, leftDistanceCm, rightDuration, rightDistanceCm;
volatile float maxLeftDistance, maxRightDistance = 50.00;

void setup() {
  // serial
 Serial.begin(9600);
  // ultrasonic
  pinMode(frontTriggerPin, OUTPUT);
  pinMode(frontEchoPin, INPUT);
  pinMode(leftTriggerPin, OUTPUT);
  pinMode(leftEchoPin, INPUT);
  pinMode(rightTriggerPin, OUTPUT);
  pinMode(rightEchoPin, INPUT);
  // motors
  pinMode(motorL1, OUTPUT);
  pinMode(motorL2, OUTPUT);
  pinMode(motorR1, OUTPUT);
  pinMode(motorR2, OUTPUT);
  
}
void loop() {
  // front distance check
  checkFrontDistance();
  // logic checks all the distance from all the three sensors.
  if (frontDistanceCm > maxFrontDistance) {
     Serial.println("Too close");
    checkLeftDistance();
//    delay(5);
    checkRightDistance();
//    delay(5);
    // If the leftdistance is less than the right distance and the right distance is less than the maximum right distance it moves right.
    if ((leftDistanceCm < rightDistanceCm)&&(rightDistanceCm > maxRightDistance))
      moveRight();
    // If the leftdistance is greater than the right distance and the left distance is less than the maximum left distance it moves left.
    else if ((leftDistanceCm > rightDistanceCm)&&( leftDistanceCm > maxLeftDistance))
    {
      moveLeft();
    }

  }
  // if the code does not enter any if statements then it move straight, that is it does not dectect anything on the left, right and in the forward direction.
  else {
    moveForward();
  }
 
}
void checkFrontDistance() {
  digitalWrite(frontTriggerPin, LOW);  
//  delayMicroseconds(4);
  digitalWrite(frontTriggerPin, HIGH);  // sends a pulse
//  delayMicroseconds(10);
  digitalWrite(frontTriggerPin, LOW);
  frontDuration = pulseIn(frontEchoPin, HIGH);  
  frontDistanceCm = frontDuration * 10 / 292 / 2;  // Converts pulses into distance in cm
  Serial.print("Distance: ");
  Serial.print(frontDistanceCm);
  Serial.println(" cm");
}
void checkLeftDistance() {
  digitalWrite(leftTriggerPin, LOW);  
//  delayMicroseconds(4);
  digitalWrite(leftTriggerPin, HIGH);  // sends a pulse
//  delayMicroseconds(10);
  digitalWrite(leftTriggerPin, LOW);
  leftDuration = pulseIn(leftEchoPin, HIGH);  
  leftDistanceCm = leftDuration * 10 / 292 / 2;  //Converts pulses into distance in cm
  Serial.print("Left distance: ");
  Serial.print(leftDistanceCm);
  Serial.println(" cm");
}
void checkRightDistance() {
  digitalWrite(rightTriggerPin, LOW);  
//  delayMicroseconds(4);
  digitalWrite(rightTriggerPin, HIGH);  // sends a pulse
//  delayMicroseconds(10);
  digitalWrite(rightTriggerPin, LOW);
  rightDuration = pulseIn(rightEchoPin, HIGH);  
  rightDistanceCm = rightDuration * 10 / 292 / 2;  //Converts pulses into distance in cm
  Serial.print("Right distance: ");
  Serial.print(rightDistanceCm);
  Serial.println(" cm");
}

// Movement functions for the L298N's to change the direction of the Robot. 
// We have written a move backward function but we donot use it in our code.
void moveBackward() {
  Serial.println("Backward.");
  digitalWrite(motorL1, HIGH);
  digitalWrite(motorL2, LOW);
  digitalWrite(motorR1, HIGH);
  digitalWrite(motorR2, LOW);
}
void moveForward() {
  Serial.println("Forward.");
  digitalWrite(motorL1, LOW);
  digitalWrite(motorL2, HIGH);
  digitalWrite(motorR1, LOW);
  digitalWrite(motorR2, HIGH);
}
void moveLeft() {
  Serial.println("Left.");
  digitalWrite(motorL1, LOW);
  digitalWrite(motorL2, HIGH);
  digitalWrite(motorR1, HIGH);
  digitalWrite(motorR2, LOW);
}
void moveRight() {
  Serial.println("Right.");
  digitalWrite(motorL1, HIGH);
  digitalWrite(motorL2, LOW);
  digitalWrite(motorR1, LOW);
  digitalWrite(motorR2, HIGH);
}
//void Stop()
//{
//  Serial.println("Stop.");
//  digitalWrite(motorL1, LOW);
//  digitalWrite(motorL2, LOW);
//  digitalWrite(motorR1, LOW);
//  digitalWrite(motorR2, LOW);
//  
//}
