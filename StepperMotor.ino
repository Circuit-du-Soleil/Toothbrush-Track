//Motor Driver
#define STEP_PIN 3
#define DIR_PIN 4
#define EN_PIN 8

bool isRunning = false;
bool lastButtonState = LOW;
int delayTime = 500;

void setup() {
  Serial.begin(9600);
  //setting the pins for the motor
  pinMode(STEP_PIN, OUTPUT);
  pinMode(DIR_PIN, OUTPUT);
  digitalWrite(EN_PIN, LOW); 

  //setting the pins for the buttons
  pinMode(7, INPUT_PULLUP);
  delay(100);
}

void loop() {
  ButtonState();
  if (isRunning){
    moveForward();
    moveBackwards();
  }
}

void ButtonState(){
  bool currentButtonState = digitalRead(7);

  if (lastButtonState == LOW && currentButtonState == HIGH) {
    isRunning = !isRunning;
  }

  lastButtonState = currentButtonState;
}

void moveForward(){
  for (int i = 0; i < 500; i++){
    ButtonState();
    if(isRunning){
    digitalWrite(DIR_PIN, HIGH);
    digitalWrite(STEP_PIN, HIGH);
    delayMicroseconds(delayTime);
    digitalWrite(STEP_PIN, LOW);
    delayMicroseconds(delayTime);
    } else {
      return;
    }
  }
  delay(200);
}
void moveBackwards(){
  for (int i = 0; i < 500; i++){
    ButtonState();
    if(isRunning){
    digitalWrite(DIR_PIN, LOW);
    digitalWrite(STEP_PIN, HIGH);
    delayMicroseconds(delayTime);
    digitalWrite(STEP_PIN, LOW);
    delayMicroseconds(delayTime);
    } else {
      return;
    }
  }
  delay(200);
}
