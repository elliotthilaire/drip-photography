
#include <SerialCommand.h>

#define dripPIN   2
#define cameraPIN 4

SerialCommand sCmd;

int first_drip_duration;  
int second_drip_delay;    
int second_drip_duration; 
int camera_delay;         

void setup() {
  pinMode(cameraPIN, OUTPUT);
  digitalWrite(cameraPIN, LOW);
  pinMode(dripPIN, OUTPUT);
  digitalWrite(dripPIN, LOW);
  
  first_drip_duration = 100;
  second_drip_delay = 300;
  second_drip_duration = 100;
  camera_delay = 500;

  Serial.begin(9600);
  
  sCmd.addCommand("shoot",    shoot);
  sCmd.addCommand("setFirstDripDuration",  setFirstDripDuration);
  sCmd.addCommand("setSecondDripDelay",    setSecondDripDelay);
  sCmd.addCommand("setSecondDripDuration", setSecondDripDuration);
  sCmd.addCommand("setCameraDelay",        setCameraDelay);

  sCmd.setDefaultHandler(unrecognized);
  Serial.println("Ready");
}

void loop() {
  sCmd.readSerial();
}

void shoot(){
  Serial.println("Capturing awesome shot!");
  
  boolean first_drip_released = false;
  boolean second_drip_released = false;
  boolean photo_taken = false;
  
  unsigned long start_time = millis();
  
  while(photo_taken == false){
    if (first_drip_released == false) {
      Serial.print(millis()-start_time); Serial.println(" Start first drip"); 
      
      digitalWrite(dripPIN, HIGH);
      delay(first_drip_duration);
      digitalWrite(dripPIN, LOW);
      first_drip_released = true;
      
      Serial.print(millis()-start_time); Serial.println(" End first drip"); 
    }
    
    if (millis()-start_time >= second_drip_delay and second_drip_released == false){
      Serial.print(millis()-start_time); Serial.println(" Start second drip"); 
      
      digitalWrite(dripPIN, HIGH);
      delay(second_drip_duration);
      digitalWrite(dripPIN, LOW);
      second_drip_released = true;
      
      Serial.print(millis()-start_time); Serial.println(" End second drip"); 
    }
    
    if (millis()-start_time >= camera_delay and photo_taken == false){
      Serial.print(millis()-start_time); Serial.println(" Taking Photo"); 
      digitalWrite(cameraPIN, HIGH);
      delay(50); // 50ms is enough to trigger camera
      digitalWrite(cameraPIN, LOW);    
      photo_taken = true;
    }
  }
}

void setFirstDripDuration() {
  char *arg;
  arg = sCmd.next(); 
  if (arg != NULL) {
    Serial.print("Setting FirstDripDuration to: ");
    Serial.println(arg);
    first_drip_duration = atoi(arg);
  }
  else {
    Serial.println("What?");
  }
}

void setSecondDripDelay() {
  char *arg;
  arg = sCmd.next(); 
  if (arg != NULL) {
    Serial.print("Setting SecondDripDelay to: ");
    Serial.println(arg);
    second_drip_delay = atoi(arg);
  }
  else {
    Serial.println("What?");
  }
}

void setSecondDripDuration() {
  char *arg;
  arg = sCmd.next(); 
  if (arg != NULL) {
    Serial.print("Setting SecondDripDuration to: ");
    Serial.println(arg);
    second_drip_duration = atoi(arg);
  }
  else {
    Serial.println("What?");
  }
}

void setCameraDelay() {
  char *arg;
  arg = sCmd.next(); 
  if (arg != NULL) {
    Serial.print("Setting CameraDelay to: ");
    Serial.println(arg);
    camera_delay = atoi(arg);
  }
  else {
    Serial.println("What?");
  }
}

// This gets set as the default handler, and gets called when no other command matches.
void unrecognized(const char *command) {
  Serial.println("What?");
}

