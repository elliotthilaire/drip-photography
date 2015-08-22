
int SOLENOID_VALVE_PIN = 2;
int IR_PIN = 12;
int STATUS_LED = 13;

boolean initial_drop_released;
boolean collision_drop_released;
boolean photo_taken;

void setup() {
  pinMode(SOLENOID_VALVE_PIN, OUTPUT);
  pinMode(IR_PIN, OUTPUT);
  pinMode(STATUS_LED, OUTPUT);
  
  initial_drop_released = false;
  collision_drop_released = false;
  photo_taken = false;
  
  Serial.begin(9600);
}

void loop() {
      
  if (millis() > 0 and initial_drop_released == false ) {
    log("Initial Drip started at: ", millis());
    
    drip();
    initial_drop_released = true;
    
    log("Initial Drip ended at: ", millis());
  }
  
  if (millis() > 80 and collision_drop_released == false) {
    log("Collision Drip started at: ", millis());

    drip();
    collision_drop_released = true;
    
    log("Collision Drip ended at: ", millis());
  }

  if (millis() > 300 and photo_taken == false) {
    log("Start take photo: ", millis());
    
    take_photo();
    photo_taken = true;
    
    log("End take photo: ", millis());
    digitalWrite(STATUS_LED, HIGH);
  }

}

void drip(){
  int OPEN_VALVE_DURATION = 70;

  digitalWrite(SOLENOID_VALVE_PIN, HIGH);
  delay(OPEN_VALVE_DURATION);
  digitalWrite(SOLENOID_VALVE_PIN, LOW); 
}

void take_photo(){

  for (int count = 0; count < 3; count++) {
    tone(IR_PIN, 38000);
    delay(2);
    noTone(IR_PIN);
    delay(28);
    tone(IR_PIN, 38000);
    delayMicroseconds(200);
    noTone(IR_PIN);
    delayMicroseconds(1500);
    tone(IR_PIN, 38000);
    delayMicroseconds(200);
    noTone(IR_PIN);
    delayMicroseconds(3300);
    tone(IR_PIN, 38000);
    delayMicroseconds(200);
    noTone(IR_PIN);
    delayMicroseconds(100);
    delay(63);
  }
}

// log method to correct concatinate different types
// i.e., string and int
void log(String message, int time){
  String output = message + time;
  Serial.println(output);
}

// Experimental
// http://www.instructables.com/id/two-ways-to-reset-arduino-in-software/step2/using-just-software/
void(* resetFunc) (void) = 0; //declare reset function @ address 0

