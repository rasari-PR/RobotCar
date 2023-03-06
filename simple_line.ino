#include <AFMotor.h>

#define irPinML A4
#define irPinMR A2
AF_DCMotor FrontL(1);
AF_DCMotor BackL(2);
AF_DCMotor BackR(3);
AF_DCMotor FrontR(4);

void setup(){
 Serial.begin(9600);
 pinMode(irPinML ,INPUT);
 pinMode(irPinMR ,INPUT);
 
 
 FrontL.setSpeed(150);
 
 FrontR.setSpeed(150);
 BackL.setSpeed(150);
 BackR.setSpeed(150);
}

void moveFront(){
 FrontL.run(FORWARD);
 FrontR.run(FORWARD);
 BackL.run(FORWARD);
 BackR.run(FORWARD); 
 }
void turnLeft(){
 FrontL.run(BACKWARD);
 FrontR.run(FORWARD);
 BackL.run(BACKWARD);
 BackR.run(FORWARD); 
 }
void turnRight(){
 FrontL.run(FORWARD);
 FrontR.run(BACKWARD);
 BackL.run(FORWARD);
 BackR.run(BACKWARD); 
 }
 void moveStop(){
 FrontL.run(RELEASE);
 FrontR.run(RELEASE);
 BackL.run(RELEASE);
 BackR.run(RELEASE);
  
 }
void loop(){
 int irML= digitalRead(irPinML);
 int irMR= digitalRead(irPinMR);
 Serial.print("left  is -");
 Serial.println(irML);
 Serial.print("Right is -");
 Serial.println(irMR);

  if(irML==HIGH && irMR==HIGH){
  moveFront();delay(2);
  }
  
  if(irML==HIGH && irMR==LOW){
  //adjust to left
  turnLeft();delay(75);
  moveFront();delay(3);
  }
  
 if(irML==LOW && irMR==HIGH){
 //adjust to right
 turnRight();delay(75);
 moveFront();delay(3);
  }
   if(irML==LOW && irMR==LOW){
 //stop the car
 moveStop();delay(2);
  }
}
