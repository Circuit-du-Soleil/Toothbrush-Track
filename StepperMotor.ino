#define STEP_PIN 3
#define DIR_PIN 4

void setup() {
  pinMode(STEP_PIN, OUTPUT);
  pinMode(DIR_PIN, OUTPUT);
  Serial.begin(9600);
  pinMode(7, INPUT_PULLUP);
  pinMode(8, INPUT_PULLUP);

}

void loop() {
   if (digitalRead(7) == HIGH){
    digitalWrite(DIR_PIN, HIGH);
    digitalWrite(STEP_PIN, HIGH);
    Serial.println("Forward");

  } else if (digitalRead(8) == HIGH){
    digitalWrite(DIR_PIN, LOW);
    digitalWrite(STEP_PIN, HIGH);
    Serial.println("Backwards");
  }

}
