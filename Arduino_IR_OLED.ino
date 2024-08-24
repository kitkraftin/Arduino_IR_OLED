#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define OLED_WIDTH 128 // OLED display width,  in pixels
#define OLED_HEIGHT 64 // OLED display height, in pixels

const int IR_Pin=2; 

int ir;

int count=0;

// declare an SSD1306 display object connected to I2C
Adafruit_SSD1306 oled(OLED_WIDTH, OLED_HEIGHT, &Wire, -1);

void setup() {
  Serial.begin(9600);
  // put your setup code here, to run once:
  pinMode(IR_Pin, INPUT);
  
  // initialize OLED display with address 0x3C for 128x64
  if (!oled.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println(F("SSD1306 allocation failed"));
    while (true);
  }

  delay(2000);         // wait for initializing
  oled.clearDisplay(); // clear display

  oled.setTextSize(1);          // text size
  oled.setTextColor(WHITE);     // text color
  oled.setCursor(0, 10);        // position to display
  oled.println("IR counter"); // text to display
  oled.display();
  oled.clearDisplay(); // clear display
}

void loop() {
  // put your main code here, to run repeatedly:
  ir = digitalRead(IR_Pin);
  Serial.print("ir status: "); 
  Serial.println(ir); 
  if (!ir){
    count++;
  }
  Serial.print("count: "); 
  Serial.println(count); 
  oled.clearDisplay(); // clear display
  oled.setTextSize(3); 
  oled.setCursor(0, 20);
  oled.println(count); // text to display
  oled.display();
  delay(1000);
}
