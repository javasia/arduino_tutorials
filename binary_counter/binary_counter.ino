const int LEFTMOST_PIN = 13;
const int GAP_BETWEEN_PINS = 3;
int numOfPins = 0;
const int PINS[] = {
  LEFTMOST_PIN - (GAP_BETWEEN_PINS * numOfPins++),
  LEFTMOST_PIN - (GAP_BETWEEN_PINS * numOfPins++),
  LEFTMOST_PIN - (GAP_BETWEEN_PINS * numOfPins++),
  LEFTMOST_PIN - (GAP_BETWEEN_PINS * numOfPins++),
};
const int DELAY_MS = 700;
const int START_FROM = 0;
const int FINISH_ON = 15;

int curNumber = START_FROM;

void setup() {
  // put your setup code here, to run once: 
  for(int i = 0; i < numOfPins; i++) {
    pinMode(PINS[i], OUTPUT);
  }
}

void loop() {
  if (curNumber > FINISH_ON){
    curNumber = START_FROM;
  }
  switchPins(curNumber++);
  delay(DELAY_MS);
}

void switchPins(int n) {
  resetPins();
  for (int i = numOfPins - 1; n > 0 && i >= 0; i--) {
    if (n & 1 == 1){
      turnPinOn(i);
    }
    n >>= 1;
  }
}

void resetPins(void) {
  for (int i = 0; i < numOfPins; i++) {
   digitalWrite(PINS[i], LOW); 
  }
}

void turnPinOn(int pinPosition) {
  digitalWrite(PINS[pinPosition], HIGH);
}
