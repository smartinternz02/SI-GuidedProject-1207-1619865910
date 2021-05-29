#include "BluetoothSerial.h"
#include <Wire.h>//wire.h is for( i to c )communication of the oled screen
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels
// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

BluetoothSerial SerialBT;

void setup() {
  Serial.begin(115200);
   delay(1000);
  Serial.println("data");
  SerialBT.begin("ESP32test"); //Bluetooth device name
  Serial.println("The device has started, now you can pair it with bluetooth!");

  Serial.println("oled test");
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { 
    Serial.println("SSD1306 allocation failed");
    for(;;);
  }
  delay(1000);
  display.clearDisplay();
  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(0, 10);

 
}

void loop() {
  String s;
   
   if (SerialBT.available()) {
     Serial.write(SerialBT.read());
  }
  if(Serial.available()){
    
   // s = Serial.readString();
    s = Serial.readString();
     // Display static text
     display.println("s");
     display.display(); 
     display.println("\n");
     //delay(1000);
  } 
}
