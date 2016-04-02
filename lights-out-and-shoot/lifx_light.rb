require 'lifx'

class LifxLight
  def initialize
    @client = LIFX::Client.lan
    @client.lights.set_color LIFX::Color.white(brightness: 1.0, kelvin: 2500)
  end

  def turn_on
    @client.lights.turn_on
  end

  def turn_off
    @client.lights.turn_off
  end
end
