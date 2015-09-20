
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
  second_drip_delay = 100;
  second_drip_duration = 100;
  camera_delay = 400;

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
  
  digitalWrite(dripPIN, HIGH);
  delay(first_drip_duration);
  digitalWrite(dripPIN, LOW);
  
  delay(second_drip_delay);
  digitalWrite(dripPIN, HIGH);
  delay(second_drip_duration);
  digitalWrite(dripPIN, LOW);
  
  delay(camera_delay);
  digitalWrite(cameraPIN, HIGH);
  delay(50); // 50ms is enough to trigger camera
  digitalWrite(cameraPIN, LOW);    
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
