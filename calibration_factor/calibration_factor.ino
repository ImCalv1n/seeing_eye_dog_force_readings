#include "HX711.h"
/*
    Values for CALT S-Type:
    grams: 155.28
*/


// HX711 circuit wiring
const int LOADCELL_DOUT_PIN = 3;
const int LOADCELL_SCK_PIN = 2;

HX711 scale;

// TODO: known weight paramter, do have program spit out calibration factor
// TODO: make program easier to understand for new users

void setup() {
  // put your setup code here, to run once:
  Serial.begin(38400);
  Serial.println("Calibration Program");

  Serial.println("Initializing the scale");
  scale.begin(LOADCELL_DOUT_PIN, LOADCELL_SCK_PIN);

  Serial.println("Calling tare()...");

  scale.set_scale();
  scale.tare();

  Serial.println("Place known weight on load cell");
  delay(5000);

  Serial.println("Measuring...");
  Serial.println(scale.get_units(10));

  Serial.println("Divide number above by known weight to get calibration factor");

}

void loop() {
  // put your main code here, to run repeatedly:

}
