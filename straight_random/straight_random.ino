#include "headers.h"

#define M1 0
#define M2 1
#define M3 2
#define M4 3

#define MA 5
#define MB 6

#define S1 A0

void setup() {
  // Motor control (PWM)
  pinMode(M1, OUTPUT);
  pinMode(M2, OUTPUT);
  pinMode(M3, OUTPUT);
  pinMode(M4, OUTPUT);
  
  pinMode(MA, OUTPUT);
  pinMode(MB, OUTPUT);
  
  // Microswitch pin
  pinMode(S1, INPUT);
  digitalWrite(S1, HIGH);
  
  // Seed the PRNG
  randomSeed(analogRead(0));
}


void setMotor(t_motor motor, t_direction direction){
  int pinA;
  int pinB;
  if (motor == A){
    pinA = M2;
    pinB = M1;
    analogWrite(MA, 200);
  } else {
    pinA = M3;
    pinB = M4;
    analogWrite(MB, 200);
  }
  
  switch(direction){
    case FORWARD:
      digitalWrite(pinA, HIGH);
      digitalWrite(pinB, LOW);
      break;
    case BACKWARD:
      digitalWrite(pinA, LOW);
      digitalWrite(pinB, HIGH);
      break;
    case STOP:
      digitalWrite(pinA, LOW);
      digitalWrite(pinB, LOW);
      break;
  }
}
      
void loop() {
  // Go forward
  setMotor(A, FORWARD);
  setMotor(B, FORWARD);
  
  // Wait until the switch is hit
  while (digitalRead(S1));
  
  // Stop
  setMotor(A, STOP);
  setMotor(B, STOP);
  
  // Give the rat a break
  delay(500);
  
  // Drive back a bit, so that we won't bump into the wall
  setMotor(A, BACKWARD);
  setMotor(B, BACKWARD);
  
  delay(250);
  
  // Which way do we turn?
  if (random(2)){
    setMotor(A, FORWARD);
  } else {
    setMotor(B, FORWARD);
  }
  
  // Random delay: 500-1500 ms
  delay(500+(random(11)*100)); 
}
