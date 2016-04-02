require "rubyserial"

class DripAndShootSequence

  def initialize(serial_string:)
    @serial_port = Serial.new serial_string, 9600
  end

  def run
    @serial_port.write("shoot\n")

    while true
      data = @serial_port.read(1)
      print data
      # A quick and dirty hack to brack the loop.
      # This is the last character returned in the sequence.
      break if data.include?"*"
    end
 end
end
