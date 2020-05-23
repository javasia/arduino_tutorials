const int DELAY_TIME = 500;
const int v1Pin = A11;
const int v2Pin = A3;
const int BROADBAND = 9600;

void setup() {
  pinMode(v1Pin, INPUT);
  pinMode(v2Pin, INPUT);
  Serial.begin(BROADBAND);
}

void loop() {
  int v1Signal = analogRead(v1Pin);
  int v2Signal = analogRead(v2Pin);
  Serial.print("V1 = ");
  Serial.println(getVoltage(v1Signal));
  Serial.print("V2 = ");
  Serial.println(getVoltage(v2Signal));
  delay(DELAY_TIME);
}

float getVoltage(int analogSignalValue){
  const float MAX_VOLTAGE = 5;
  const float ANALOG_READ_RESOLUTION = 1023;
  return analogSignalValue * (MAX_VOLTAGE / ANALOG_READ_RESOLUTION);
}
