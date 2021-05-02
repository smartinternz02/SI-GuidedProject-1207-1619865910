
#include<Servo.h>
Servo myservo;
// for Arduino microcontroller
int trigpin = 5;      // trigger pin
int echopin = 4;      // echo pin

void setup(){
pinMode(echopin,INPUT);
pinMode(trigpin,OUTPUT);
Serial.begin(9600);
myservo.attach(13);
}

void loop(){
digitalWrite(trigpin,HIGH);
delay(1000);
digitalWrite(trigpin,LOW);
int duration=pulseIn(echopin,HIGH);
int distance=duration*0.0343/2;
Serial.print("Distance: ");
Serial.println(distance);
delay(2000);
if(distance>2 || distance<400) {    

for(int pos=0;pos<=180;pos=pos+1){
  myservo.write(pos);
  delay(200);
  Serial.println(pos);  
}
for(int pos=180;pos>=0;pos=pos-1){
  myservo.write(pos);
  delay(200);
  Serial.println(pos);  

}
}
}
