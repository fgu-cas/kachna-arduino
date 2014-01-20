#include "headers.h"

#define M1 3
#define M2 5
#define M3 6
#define M4 9

#define S1 4

#define SPEED 128

void setup() {
  // Motor control (PWM)
  pinMode(M1, OUTPUT);
  pinMode(M2, OUTPUT);
  pinMode(M3, OUTPUT);
  pinMode(M4, OUTPUT);
  
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
    pinA = M1;
    pinB = M2;
  } else {
    pinA = M3;
    pinB = M4;
  }
  switch(direction){
    case FORWARD:
      analogWrite(pinA, SPEED);
      digitalWrite(pinB, LOW);
      break;
    case BACKWARD:
      digitalWrite(pinA, LOW);
      analogWrite(pinB, SPEED);
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
