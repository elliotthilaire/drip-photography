var five = require("johnny-five");
var board = new five.Board();

// The board's pins will not be accessible until
// the board has reported that it is ready
board.on("ready", function() {
  console.log("Ready!");

  // var led = new five.Led(12);
  //led.blink(1);
  // led.strobe(500);

  // this.pinMode(4, this.MODES.OUTPUT);
  // this.pinMode(13, this.MODES.OUTPUT);

  // this.wait(1000, function() {
  //   this.digitalWrite(4, 1);
  // });

  // this.wait(2000, function() {
  //   this.digitalWrite(12, 1);
  // });

  // The IR LED needs to flicker at a rate of 38Khz
  // Therefore we use the piezo API instead of the LED API
   var piezo = new five.Piezo(12);

   piezo.frequency(1000, 2);
   piezo.noTone(0,     28);
   piezo.tone(1000, 1);
  // piezo.tone(0,     1);
  // piezo.tone(38000, 1);
  // piezo.tone(0,     3);
  // piezo.tone(38000, 1);
  // piezo.tone(0,    63);

});



