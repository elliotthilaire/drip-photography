require_relative 'lifx_light'
require_relative 'drip_and_shoot_sequence'

def lights_out_and_shoot
  light = LifxLight.new
  drip_and_shoot_sequence = DripAndShootSequence.new(serial_string: '/dev/cu.usbmodem1421')

  light.turn_off
  drip_and_shoot_sequence.run
  light.turn_on
end

lights_out_and_shoot
