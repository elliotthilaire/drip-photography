

int SOLENOID_PIN = 2;
int IR_PIN = 12;
int STATUS_LED = 13;


// the setup routine runs once when you press reset:
void setup() {
  pinMode(SOLENOID_PIN, OUTPUT);
  pinMode(IR_PIN, OUTPUT);
  pinMode(STATUS_LED, OUTPUT);
}

// the loop routine runs over and over again forever:
int count = 0;

void loop() {
  while(count<2){
    drip();
    wait_for_gravity();
    take_photo();
    wait_for_next_photo();
    count ++;
  }
  
  digitalWrite(STATUS_LED, HIGH);
}

void wait_for_gravity(){
  // about 300ms to fall 50cm
  // as taken from here http://www.gravitycalc.com/
  delay(300);
}

void wait_for_next_photo(){
  delay(10000);
}

void drip(){
  int SMALLEST_DROP = 70;
  int SMALLEST_DELAY = 120;

  digitalWrite(SOLENOID_PIN, HIGH);
  delay(SMALLEST_DROP);
  digitalWrite(SOLENOID_PIN, LOW);
  delay(SMALLEST_DELAY);

  digitalWrite(SOLENOID_PIN, HIGH);
  delay(SMALLEST_DROP);
  digitalWrite(SOLENOID_PIN, LOW);
}


void take_photo(){

  int count = 0;

  while(count<3) {
    tone(IR_PIN,38000);
    delay(2);
    noTone(IR_PIN);
    delay(28);
    tone(IR_PIN,38000);
    delayMicroseconds(200);
    noTone(IR_PIN);
    delayMicroseconds(1500);
    tone(IR_PIN,38000);
    delayMicroseconds(200);
    noTone(IR_PIN);
    delayMicroseconds(3300);
    tone(IR_PIN,38000);
    delayMicroseconds(200);
    noTone(IR_PIN);
    delayMicroseconds(100);
    delay(IR_PIN);
    count++;
  }
}


