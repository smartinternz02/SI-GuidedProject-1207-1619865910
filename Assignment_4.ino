
#include "BluetoothSerial.h"
BluetoothSerial SerialBT;
int echopin=5;
int trigpin=4;

void setup() {
  pinMode(echopin,INPUT);
  pinMode(trigpin,OUTPUT);//ultrasound

  pinMode(2,OUTPUT);//led
  
  Serial.begin(115200);
  
  delay(3000);
  Serial.println("data");
  SerialBT.begin("ESP32test"); //Bluetooth device name
  Serial.println("The device has started, now you can pair it with bluetooth!");//for starting bluetooth connection
}

void loop() {
digitalWrite(trigpin,HIGH);
delay(100);
digitalWrite(trigpin,LOW);
int duration=pulseIn(echopin,HIGH);
int distance=duration*0.0343/2;
//Serial.print("the distance is");

//delay(1000);
  //if (Serial.available()) {
    //SerialBT.write(Serial.read());
  //}
  
  
  if (SerialBT.available()) {//for availability of blut_app
    Serial.write(SerialBT.read());
  
  
  if (SerialBT.read() == '0'){//led off
    digitalWrite(2,LOW);

  }
  if (SerialBT.read() == '1'){//led on
    digitalWrite(2,HIGH);
  }
  delay(1000);
}
Serial.println(distance);
SerialBT.write(distance);
  delay(1000);

}
