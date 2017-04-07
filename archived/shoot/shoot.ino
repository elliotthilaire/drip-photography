
int CAMERA_PIN = 2;
int STATUS_LED = 13;

void setup() {
  pinMode(CAMERA_PIN, OUTPUT);
}

void loop() {
  
  digitalWrite(CAMERA_PIN, HIGH);
  delay(500);
  digitalWrite(CAMERA_PIN, LOW);
  delay(10000);

}



