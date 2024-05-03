#include "HX711.h"
#include <string.h>

using namespace std;

// HX711 circuit wiring
const int LOADCELL_DAT_PIN = 3;
const int LOADCELL_CLK_PIN = 2;

HX711 scale;

// TODO: get more robust grams cal factor, add more cal factors
/* 
    Set calibration factor.
    Values by output:
        grams: 155.28
*/
// float CAL_FACTOR = 155.28;
float CAL_FACTOR = -145943.860;
// String UNITS = "g";
String UNITS = "kg";

/*
    Set amount of delay between readings (ms).
*/
int DELAY = 100;

// TODO: file name
String OUT_FILE = "";

int iterator = 0;

void setup(){
    Serial.begin(57600);
    
    Serial.println("SEEING EYE FORCE DATA COLLECION");

    Serial.println("Scale setup in 5 seconds");

    delay(5000);

    Serial.println("Setting up scale...");

    scale.begin(LOADCELL_DAT_PIN, LOADCELL_CLK_PIN);

    // set scale with global calibration factor
    // CAL_FACTOR calculated using ./calibration_factor.ino
    scale.set_scale(CAL_FACTOR);
    scale.tare();

    Serial.println("READINGS, KGs:");

    // TODO: check if file name given, if not, make unique file

}

void loop(){

    // Serial.print("Reading ");
    // Serial.print(iterator);
    // Serial.print(": ");

    // TODO: decide if we should take an average here
    float reading = scale.get_units();

    Serial.print(reading);
    Serial.print(" ");
    Serial.println(millis());
    // Serial.println(UNITS);

    // TODO: print value to file

    // TODO: is this worth it with low delay
    // scale.power_down();
    delay(DELAY);
    // scale.power_up();

    iterator++;

    // testing
    // if(iterator == 200){
    //   exit(0);
    // }

    // TODO: exit condition?

}