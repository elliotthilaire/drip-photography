// functions to read parameters from the serial interface and alter the variables
// For example on the serial interface send setFirstDripDuration 300

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

void setShutterDelay() {
  char *arg;
  arg = sCmd.next(); 
  if (arg != NULL) {
    Serial.print("Setting ShutterDelay to: ");
    Serial.println(arg);
    flash_delay = atoi(arg);
  }
  else {
    Serial.println("What?");
  }
}


void setFlashDelay() {
  char *arg;
  arg = sCmd.next(); 
  if (arg != NULL) {
    Serial.print("Setting FlashDelay to: ");
    Serial.println(arg);
    flash_delay = atoi(arg);
  }
  else {
    Serial.println("What?");
  }
}

