# seeing_eye_dog_force_readings

Code to grab force readings from CALT S-Type Load Cell with Sparkfun HX711 Amplifier for readings for seeing eye dataset.

Arduino requires each file to be in a folder named after the file.

# Use Instructions for Binghamton AIR Lab
- Required hardware:
  - Load cell
  - Arduino board
  - HX711 load cell amplifier
  - 4 Arduino wires
- Pin connections:
  - HX711 to Arduino:
    - VDD to 5v
    - DAT to pin 3
    - CLK to pin 2
    - GND to GND
  - Load Cell to HX711:
    - Match the colors, if using Bing AIR cell, bare wire = yellow

# Capture Output
- Download PuTTY
- Under category "Session", choose "Serial" connection type. Match serial line and baud to those used in Arduino IDE.
- Under "Session" -> "Logging"
  - Choose "All Session Output"
  - Enter log file path and name
- Select "Open", and PuTTY should display the output from the program.
- Once finished, close the PuTTY window. You should be able to view the log file.
