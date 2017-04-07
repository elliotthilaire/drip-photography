
#include <SerialCommand.h>

#define dripPIN   4
#define flashPIN  2
#define cameraPIN 12

SerialCommand sCmd;

int first_drip_delay;
int first_drip_duration;
int second_drip_delay;
int second_drip_duration;
int open_shutter_delay;
int flash_delay;

void shoot(){
  
  Serial.println("\nCapturing awesome shot!");
  
  boolean first_drip_released = false;
  boolean second_drip_released = false;
  boolean shutter_opened = false;
  boolean flash_fired = false;
  boolean sequence_finished = false;

  unsigned long start_time = millis();
  
  while(sequence_finished == false){

    // open shutter
    if (millis()-start_time >= open_shutter_delay and shutter_opened == false){
      Serial.print(millis()-start_time); Serial.println(" Opening Shutter"); 
      digitalWrite(cameraPIN, HIGH);    
      shutter_opened = true;
    }

    // release first drip
    if (first_drip_released == false) {
      Serial.print(millis()-start_time); Serial.println(" Start first drip"); 
      
      digitalWrite(dripPIN, HIGH);
      delay(first_drip_duration);
      digitalWrite(dripPIN, LOW);
      first_drip_released = true;
      
      Serial.print(millis()-start_time); Serial.println(" End first drip"); 
    }

    // release second drip
    if (millis()-start_time >= second_drip_delay and second_drip_released == false){
      Serial.print(millis()-start_time); Serial.println(" Start second drip"); 
      
      digitalWrite(dripPIN, HIGH);
      delay(second_drip_duration);
      digitalWrite(dripPIN, LOW);
      second_drip_released = true;
      
      Serial.print(millis()-start_time); Serial.println(" End second drip"); 
    }

    // fire flash
    if (millis()-start_time >= flash_delay and flash_fired == false){
      Serial.print(millis()-start_time); Serial.println(" Firing flash"); 
      digitalWrite(flashPIN, HIGH);
      delay(10); // 10ms is enough to trigger flash
      digitalWrite(flashPIN, LOW);     
      flash_fired = true;
    }

    // close shutter
    if (flash_fired == true){
      Serial.print(millis()-start_time); Serial.println(" Closing shutter");
      delay(10); // make sure exposure is finished
      digitalWrite(cameraPIN, LOW);     
      shutter_opened = false;
      sequence_finished = true;
      Serial.print('*'); 
    }  
  }
}

