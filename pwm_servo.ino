// Kanad Patel
// The code is for second Arduino that controls the servo hand of I-See.
// Its also has a potentiometer that control the speed of I-See.

#include <Servo.h>
#define POTENTIOMETER_PIN A0
Servo myservo1;
Servo myservo2;
int enA = 3;
int enB = 5; 
int pos1 = 0;
int pos2 = 0; 
  
void setup() {
  Serial.begin(9600);
  myservo1.attach(9);
  myservo2.attach(10);
  pinMode(3,OUTPUT);
  pinMode(5,OUTPUT);  
}
void loop() {
  int data = analogRead(POTENTIOMETER_PIN);
  int speed1 = map(data, 0, 1023, 0, 255); // maps the potentiometer values to speed1 variable.
  analogWrite(enA,speed1);
  analogWrite(enB,speed1);
  // Both the servos move 180 degrees.
  for (pos1 = 0; pos1 <= 180; pos1 += 1) { 
    myservo1.write(pos1); 
    myservo2.write(pos1);             
    delay(5);                      
  }
  for (pos1 = 180; pos1 >= 0; pos1 -= 1) {
    myservo1.write(pos1);              
    myservo2.write(pos1); 
    delay(5);                      
  }
}
