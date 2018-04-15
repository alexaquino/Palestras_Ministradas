// Alex Aquino 14/03/18 - 15/03/18

/* INCLUDES */

/* CONSTANTS *******************************************************/

#define STIMULATION_FREQUENCY_HZ 20

#define FRONT_STIMULATION_SIMULATION_PERIOD 100      // GAMBIARRETION
#define STIMULATION_PERIOD 100

#define pinAntennaRight  9
#define pinAntennaLeft  11

/* GLOBAL VARIABLES ************************************************/

//uint16 stimulationPeriodInMilliseconds = 100;
//uint8 stimulationDutyCycle = 0;
char data = '0';

/* SETUP ***********************************************************/

void setup() {
  pinMode(pinAntennaRight, OUTPUT);
  pinMode(pinAntennaLeft,  OUTPUT);

  Serial.begin(9600);
}

/* LOOP ************************************************************/

void loop() {

  if(Serial.available()) {
    data = Serial.read();
    Serial.print("DATA: ");
    Serial.println(data);
  }

  switch(data) {
    case 'F':
      stimulateRightAndLeft();
      data = '0';
      break;
    case 'L':
      stimulateLeft();
      data = '0';
      break;
    case 'R':
      stimulateRight();
      data = '0';
      break;
    default:
      break;
  }
}


/* PUBLIC FUNCTIONS ************************************************/

// stimulates the cockroach's the two antennas -> cockroach moves on.
void stimulateRightAndLeft() {
  for(int i = 0; i < 3; i++) {
    Serial.println("RIGHT");
    tone(pinAntennaRight, STIMULATION_FREQUENCY_HZ);
    delay(FRONT_STIMULATION_SIMULATION_PERIOD);
    noTone(pinAntennaRight);

    Serial.println("LEFT");
    tone(pinAntennaLeft, STIMULATION_FREQUENCY_HZ);
    delay(FRONT_STIMULATION_SIMULATION_PERIOD);
    noTone(pinAntennaLeft);
  }
}

// stimulates the cockroach's left antenna -> cockroach turns right.
void stimulateLeft() {
    Serial.println("LEFT");
    tone(pinAntennaLeft, STIMULATION_FREQUENCY_HZ);
    delay(STIMULATION_PERIOD);
    noTone(pinAntennaLeft);
}

// stimulates the cockroach's right antenna -> cockroach turns left.
void stimulateRight() {
    Serial.println("RIGHT");
    tone(pinAntennaRight, STIMULATION_FREQUENCY_HZ);
    delay(STIMULATION_PERIOD);
    noTone(pinAntennaRight);
}
