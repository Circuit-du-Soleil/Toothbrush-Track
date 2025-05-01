//Screen
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

#define OLED_RESET     -1 
#define SCREEN_ADDRESS 0x3C
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

//Motor Driver
#define STEP_PIN 3
#define DIR_PIN 4

int delayTime = 500; //this is the delay in between each step in micro seconds

void setup() {
  Serial.begin(9600);
  //setting the pins for the motor
  pinMode(STEP_PIN, OUTPUT);
  pinMode(DIR_PIN, OUTPUT);

  //setting the pins for the buttons
  pinMode(7, INPUT_PULLUP);
  pinMode(8, INPUT_PULLUP);
  pinMode(10, INPUT_PULLUP);
  pinMode(11, INPUT_PULLUP);
  //setting the screen up
  if(!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
    Serial.println(F("SSD1306 allocation failed"));
    for(;;); // Don't proceed, loop forever
  }
  //this sets up the splash screen
  delay(1000);
  display.clearDisplay();

  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0,0);
  display.println("Starting...");
  displayOnScreen(delayTime);

}

void loop() {
  //button logic
  if (digitalRead(7) == HIGH) {  //direction: forwards
    digitalWrite(DIR_PIN, HIGH);
    digitalWrite(STEP_PIN, HIGH);
    delayMicroseconds(delayTime);
    digitalWrite(STEP_PIN, LOW);
    delayMicroseconds(delayTime);
  } 
  else if (digitalRead(8) == HIGH) { //direction: backwards
    digitalWrite(DIR_PIN, LOW);
    digitalWrite(STEP_PIN, HIGH);
    delayMicroseconds(delayTime);
    digitalWrite(STEP_PIN, LOW);
    delayMicroseconds(delayTime);
  } else if (digitalRead(10) == HIGH){ //speed decreases as the delay increases
    delayTime += 100;
    displayOnScreen(delayTime);
    delay(500);
  } else if (digitalRead(11) == HIGH){ //speed increases as delay decreases
    delayTime-=100;
    displayOnScreen(delayTime);
    delay(500);
  }
}

void displayOnScreen(int number){
  display.clearDisplay();
  display.setCursor(SCREEN_WIDTH/6, SCREEN_HEIGHT/6);
  display.setTextSize(5);
  display.print(number);
  display.display();
  delay(100);
}
