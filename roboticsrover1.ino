#include<Servo.h>

Servo ser;


#define leftir 6
#define rightir 7
#define echo 8
#define trig 9
#define a1 10
#define a2 11
#define a3 12
#define a4 13

int distance;
void setup() {
  Serial.begin(9600);
  pinMode(leftir,INPUT);
  pinMode(rightir,INPUT);
  pinMode(echo,INPUT);
  pinMode(trig,OUTPUT);
  pinMode(a1,OUTPUT);
  pinMode(a2,OUTPUT);
  pinMode(a3,OUTPUT);
  pinMode(a4,OUTPUT);
 ser.attach(4);
  ser.write(90);
   
  //left 90 to 180
  for(int i = 90 ;i<=180;i++){
    ser.write(i);
    
    i=i+10;
  }
  delay(1000);
  //right 180 to 0
  for(int i = 180 ; i>=0;i--){
   ser.write(i);
   
   i=i-10;
  }
 ser.write(90);
}

void loop() {
  // Both IR
  int leftirdata = digitalRead(leftir);
  int rightirdata =digitalRead(rightir);

  // ultra sonic sensor

  digitalWrite(trig,HIGH);
  delayMicroseconds(10);
  digitalWrite(trig,LOW);

  int echodata = pulseIn(echo,HIGH);

  distance = 0.017*echodata;

  if(distance>=3 && distance<=7){
    backward();
  }else if( distance>=7 && distance<=15){
    forward();
  }else if(leftirdata==1){
    left();
  }else if(rightirdata==1){
    right();
  }
  
  else{
    stop();
  }
  delay(10);

}

void forward(){
  digitalWrite(a1,HIGH);
  digitalWrite(a2,LOW);
  digitalWrite(a3,HIGH);
  digitalWrite(a4,LOW);
  Serial.println("FOrward");
}
void backward(){
  digitalWrite(a1,LOW);
  digitalWrite(a2,HIGH);
  digitalWrite(a3,LOW);
  digitalWrite(a4,HIGH);
  Serial.println("BACKWARD");

}
void stop(){
  digitalWrite(a1,LOW);
  digitalWrite(a2,LOW);
  digitalWrite(a3,LOW);
  digitalWrite(a4,LOW);
  Serial.println("STOP");
}
void left(){
  digitalWrite(a1,HIGH);
  digitalWrite(a2,LOW);
  digitalWrite(a3,LOW);
  digitalWrite(a4,LOW);
  Serial.println("Left");
}
void right(){
  digitalWrite(a1,LOW);
  digitalWrite(a2,LOW);
  digitalWrite(a3,HIGH);
  digitalWrite(a4,LOW);
  Serial.println("Right");
}
