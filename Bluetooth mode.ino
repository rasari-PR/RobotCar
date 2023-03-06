#include <AFMotor.h>

#define irPinML A4
#define irPinMR A2
AF_DCMotor FrontL(1);
AF_DCMotor BackL(2);
AF_DCMotor BackR(3);
AF_DCMotor FrontR(4);
char val;// for bluetooth
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
 void moveBack(){
 FrontL.run(BACKWARD);
 FrontR.run(BACKWARD);
 BackL.run(BACKWARD);
 BackR.run(BACKWARD); 
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
if(Serial.available()){
  val=Serial.read();
  Serial.print(val);
  }
  switch(val){
    case 'F':
      moveFront();
      delay(1000);
      moveStop();
      
      break;
    case 'B':
      moveBack();
      delay(800);
      moveStop();
      break;
    case 'R':
      turnRight();
      delay(500);
      moveStop();
      break;
    case 'L':
      turnLeft();
      delay(500);
      moveStop();
      break;
     default:
      moveStop();
    }
    val='S';
}
