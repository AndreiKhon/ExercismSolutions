class JuiceMaker
  def initialize(fluid : Int32)
    @running = false
    @fluid = fluid
  end
  def self.debug_light_on?
    true
  end
  def start
    @running = true
  end
  def running?
    @running
  end
  def add_fluid(fluid)
    @fluid += fluid
  end
  FLUID_PER_MINUTE = 5
  def stop(minutes)
    @running = false
    @fluid -= FLUID_PER_MINUTE * minutes
  end
end