//Motor Driver
#define STEP_PIN 3
#define DIR_PIN 4
#define EN_PIN 8

int delayTime = 500;

void setup() {
  Serial.begin(9600);
  //setting the pins for the motor
  pinMode(STEP_PIN, OUTPUT);
  pinMode(DIR_PIN, OUTPUT);
  digitalWrite(EN_PIN, LOW); 

  //setting the pins for the buttons
  pinMode(7, INPUT_PULLUP);
  pinMode(6, INPUT_PULLUP);
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
  else if (digitalRead(6) == HIGH) { //direction: backwards
    digitalWrite(DIR_PIN, LOW);
    digitalWrite(STEP_PIN, HIGH);
    delayMicroseconds(delayTime);
    digitalWrite(STEP_PIN, LOW);
    delayMicroseconds(delayTime);
  }
}
