//    wcmrra_animated_sign
//
//    Animate the WCMRRA street sign
//
//    Two RR crossing heads (each with two lights
//    Two crossing arms  (each with three lights - end is solid one and
//    others blink out of phase with each other)

#define FLASH_DELAY     1000         // time any phase is "on" in milliseconds

#define HEARTBEAT_PIN   13           // use the on board pin for a heartbeat - in sync with phase "A"


int PhaseAPins[] = { 3, 4, 11, 9 };  // Phase A and Phase B need equal number of lights
int PhaseBPins[] = { 5, 6, 10, 8 };

int PhasePinCount = sizeof(PhaseAPins) / sizeof(PhaseAPins[0]);


void setup() {
int i;

  for (i = 0 ; i < PhasePinCount ; i++) {
    pinMode(PhaseAPins[i], OUTPUT);
    digitalWrite(PhaseAPins[i], HIGH);  // start these "on"
    
    pinMode(PhaseBPins[i], OUTPUT);
    digitalWrite(PhaseBPins[i], LOW);   // start these "off"
  }

  pinMode(HEARTBEAT_PIN, OUTPUT);       // heartbeat - in sync with phase "A"
  digitalWrite(HEARTBEAT_PIN, HIGH);
}



void loop() {

  int i;
  
  delay(FLASH_DELAY);

  // Phase A "off" and Phase B "on"
    
  for (i = 0 ; i < PhasePinCount ; i++) {
    digitalWrite(PhaseAPins[i], LOW);
    digitalWrite(PhaseBPins[i], HIGH);
  }

  digitalWrite(HEARTBEAT_PIN, HIGH);

  delay(FLASH_DELAY);

  // Phase A "on" and Phase B "off"

  for (i = 0 ; i < PhasePinCount ; i++) {
    digitalWrite(PhaseAPins[i], HIGH);
    digitalWrite(PhaseBPins[i], LOW);
  }

  digitalWrite(HEARTBEAT_PIN, LOW);
}
