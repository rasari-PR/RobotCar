#include <AFMotor.h>

#define irPinML A4
#define irPinMR A2
#define echoPin A1 // attach pin D2 Arduino to pin Echo of HC-SR04
#define trigPin A0 //attach pin D3 Arduino to pin Trig of HC-SR04
#define bzzPin 9

// defines variables
long duration; // variable for the duration of sound wave travel
int distance; // variable for the distance measurement

AF_DCMotor FrontL(1);
AF_DCMotor BackL(2);
AF_DCMotor BackR(3);
AF_DCMotor FrontR(4);

void setup(){
  pinMode(bzzPin,OUTPUT);
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an OUTPUT
  pinMode(echoPin, INPUT); // Sets the echoPin as an INPUT
  Serial.begin(9600); // // Serial Communication is starting with 9600 of baudrate speed
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

 void ultraSonic(){
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  // Sets the trigPin HIGH (ACTIVE) for 10 microseconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);
  // Calculating the distance
  distance = duration * 0.034 / 2; // Speed of sound wave divided by 2 (go and back)
  // Displays the distance on the Serial Monitor
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");
  }
void ringBuzzer(){
  digitalWrite(bzzPin,HIGH);
  delay(100);
  digitalWrite(bzzPin, LOW);
  delay(100);
  digitalWrite(bzzPin,HIGH);
  delay(100);
  digitalWrite(bzzPin, LOW);
  delay(100);
  }
  void loop(){
    ultraSonic();
    if (distance<=10){
      moveStop();
      ringBuzzer();
      delay(100);
    }else{
      moveFront();
      delay(10);
    }
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
