/*
  SMART TRAFFIC LIGHT CONTROLLER - ESP32
  ----------------------------------------
  Simulates a 4-way / single junction traffic light using
  RED, YELLOW, GREEN LEDs. Includes a pedestrian request button
  (optional) that shortens the green phase for a safe crossing.

  WIRING:
    RED    LED -> GPIO 25  (through 220ohm resistor) -> GND
    YELLOW LED -> GPIO 26  (through 220ohm resistor) -> GND
    GREEN  LED -> GPIO 27  (through 220ohm resistor) -> GND
    PUSH BUTTON -> GPIO 14 to GND (uses internal pull-up)

  Upload via Arduino IDE with "ESP32 Dev Module" board selected.
*/

const int RED_PIN    = 25;
const int YELLOW_PIN = 26;
const int GREEN_PIN  = 27;
const int BUTTON_PIN = 14;   // pedestrian crossing request (optional)

// Timings (in milliseconds) - adjust to taste
const unsigned long GREEN_TIME   = 8000;
const unsigned long YELLOW_TIME  = 2000;
const unsigned long RED_TIME     = 8000;
const unsigned long PED_GREEN_TIME = 4000; // shortened green if button pressed

volatile bool pedestrianRequest = false;

void IRAM_ATTR handleButtonPress() {
  pedestrianRequest = true;
}

void setup() {
  Serial.begin(115200);

  pinMode(RED_PIN, OUTPUT);
  pinMode(YELLOW_PIN, OUTPUT);
  pinMode(GREEN_PIN, OUTPUT);
  pinMode(BUTTON_PIN, INPUT_PULLUP);

  attachInterrupt(digitalPinToInterrupt(BUTTON_PIN), handleButtonPress, FALLING);

  // Start in RED state
  setLights(true, false, false);
  Serial.println("Smart Traffic Light Controller started.");
}

void loop() {
  // ---- GREEN PHASE ----
  setLights(false, false, true);
  Serial.println("GREEN");
  unsigned long greenDuration = pedestrianRequest ? PED_GREEN_TIME : GREEN_TIME;
  waitOrInterrupt(greenDuration);
  pedestrianRequest = false; // reset request after serving it

  // ---- YELLOW PHASE ----
  setLights(false, true, false);
  Serial.println("YELLOW");
  delay(YELLOW_TIME);

  // ---- RED PHASE ----
  setLights(true, false, false);
  Serial.println("RED");
  waitOrInterrupt(RED_TIME);
}

void setLights(bool red, bool yellow, bool green) {
  digitalWrite(RED_PIN, red);
  digitalWrite(YELLOW_PIN, yellow);
  digitalWrite(GREEN_PIN, green);
}

// Waits for 'duration' ms, but can be used later to react early to events
void waitOrInterrupt(unsigned long duration) {
  delay(duration);
}
