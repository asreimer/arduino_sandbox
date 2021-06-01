// Which pin to use for PWM
// valid options: 3, 5, 6, 9, 10, and 11
// these are digital pins
// pin 11 is timer 2 output A (https://www.arduino.cc/en/Tutorial/SecretsOfArduinoPWM#using-the-atmega-pwm-registers-directly)
const int PWMPIN = 11;
// set the time to dwell on each the duty cycle
const int TIMEDWELL = 100;

void setup() {
  // we don't need to configure the pin
  // but we will just to be explicit
  pinMode(PWMPIN,OUTPUT);

  // Configure Timer 2, which controls the PWM on pin 11
  TCCR2A = 0b1; // Phase-Correct PWM, note: this is the default configuration
  //TCCR2A = 0b11; // Fast PWM
  // Set prescaler to 1, default is 64: TCCR2B = 0b100
  TCCR2B = 0b1;
}

void loop() {
  // run through different duty cycles waiting 1 second before moving to
  // the next.
  while (true)
  {
    for (int i = 0; i < 256; i = i + 5)
    {
      analogWrite(PWMPIN,i);
      //delay in ms
      delay(TIMEDWELL);
    }
    for (int i = 250; i > -1; i = i - 5)
    {
      analogWrite(PWMPIN,i);
      //delay in ms
      delay(TIMEDWELL);
    }
  }
}
