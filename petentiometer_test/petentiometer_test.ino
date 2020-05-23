const int DELAY_TIME = 150;
const int readPin = A11;
const int BROADBAND = 9600;

void setup() {
  pinMode(readPin, INPUT);
  Serial.begin(BROADBAND);
}

void loop() {
  int readSignal = analogRead(readPin);
  Serial.print("potentiometer voltage = ");
  Serial.println(getVoltage(readSignal));
  delay(DELAY_TIME);
}

float getVoltage(int analogSignalValue){
  const float MAX_VOLTAGE = 5;
  const float ANALOG_READ_RESOLUTION = 1023;
  return analogSignalValue * (MAX_VOLTAGE / ANALOG_READ_RESOLUTION);
}
