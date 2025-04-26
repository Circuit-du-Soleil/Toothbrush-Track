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

int delay = 500;

void setup() {
  Serial.begin(9600);
  //setting the pins for the motor
  pinMode(STEP_PIN, OUTPUT);
  pinMode(DIR_PIN, OUTPUT);

  //setting the pins for the buttons
  pinMode(7, INPUT_PULLUP);
  pinMode(8, INPUT_PULLUP);

  //setting the screen up
  if(!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
    Serial.println(F("SSD1306 allocation failed"));
    for(;;); // Don't proceed, loop forever
  }
  //this sets up a splash screen initially
  display.display();
  display.clearDisplay();
  display.print("The display is functioning, this message will disappear after 2 seconds.");
  delay(2000); 
  displayOnScreen(delay);

}

void loop() {
  //button logic
  if (digitalRead(7) == HIGH) {  //direction: forwards
    digitalWrite(DIR_PIN, HIGH);
    digitalWrite(STEP_PIN, HIGH);
    delayMicroseconds(delay);
    digitalWrite(STEP_PIN, LOW);
    delayMicroseconds(delay);
  } 
  else if (digitalRead(8) == HIGH) { //direction: backwards
    digitalWrite(DIR_PIN, LOW);
    digitalWrite(STEP_PIN, HIGH);
    delayMicroseconds(delay);
    digitalWrite(STEP_PIN, LOW);
    delayMicroseconds(delay);
  } else if (digitalRead(10) == HIGH){ //speed decreases as the delay increases
    delay += 1;
    displayOnScreen(delay);
  } else if (digitalRead(11) == HIGH){ //speed increases as delay decreases
    delay-=1;
    displayOnScreen(delay);
  }
}

void displayOnScreen(int number){ //shows the number on the screen.
  display.clearDisplay();
  display.print(number);
  display.setCursor(SCREEN_WIDTH/6, SCREEN_HEIGHT/6);
  display.setTextSize(5);
  display.display();
}
