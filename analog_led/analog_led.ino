const int ANALOG_PIN = 2;
const int DELAY_MS = 100;
const int MAX_SIGNAL_LEVEL = 255;
const int MIN_SIGNAL_LEVEL = 0;
int mod = 1;

int curSignalLevel = 1;

void setup() {
  // put your setup code here, to run once: 
    pinMode(ANALOG_PIN, OUTPUT);
}

void loop() {
  if (curSignalLevel <= MIN_SIGNAL_LEVEL || curSignalLevel >= MAX_SIGNAL_LEVEL){
    mod *= -1;
  }
  curSignalLevel += mod;
  analogWrite(ANALOG_PIN, curSignalLevel);
  delay(DELAY_MS);
}
