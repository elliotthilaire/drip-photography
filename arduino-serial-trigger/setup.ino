


void loop() {
  sCmd.readSerial();
}

void setup() {
  pinMode(cameraPIN, OUTPUT);
  digitalWrite(cameraPIN, LOW);
  pinMode(flashPIN, OUTPUT);
  digitalWrite(flashPIN, LOW);
  pinMode(dripPIN, OUTPUT);
  digitalWrite(dripPIN, LOW);

  first_drip_delay = 0;
  first_drip_duration = 100;
  second_drip_delay = 300;
  second_drip_duration = 100;
  open_shutter_delay = 200;
  flash_delay = 500;
  
  Serial.begin(9600);
  
  sCmd.addCommand("shoot", shoot);
  sCmd.addCommand("setFirstDripDuration",  setFirstDripDuration);
  sCmd.addCommand("setSecondDripDelay",    setSecondDripDelay);
  sCmd.addCommand("setSecondDripDuration", setSecondDripDuration);
  sCmd.addCommand("setShutterDelay",       setShutterDelay);
  sCmd.addCommand("setFlashDelay",         setFlashDelay);

  sCmd.setDefaultHandler(unrecognized);
  Serial.println("Ready");
}

// This gets set as the default handler, and gets called when no other command matches.
void unrecognized(const char *command) {
  Serial.println("What?");
}

