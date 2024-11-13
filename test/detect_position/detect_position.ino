/*
  Arduino LSM6DS3 - Accelerometer Application

  This example reads the acceleration values as relative direction and degrees,
  from the LSM6DS3 sensor and prints them to the Serial Monitor or Serial Plotter.

  The circuit:
  - Arduino Nano 33 IoT

  Created by Riccardo Rizzo
  Modified by Jose García
  27 Nov 2020

  This example code is in the public domain.
*/

#include <Arduino_LSM6DS3.h>

float x, y, z;
// int degreesX = 0;
// int degreesY = 0;

void setup() {
  Serial.begin(9600);
  while (!Serial)
    ;

  Serial.println("Started");

  // Initialize the IMU
  if (!IMU.begin()) {
    Serial.println("Failed to initialize IMU!");
    while (1); // Halt if IMU initialization fails
  }

  Serial.println();
  Serial.println("Acceleration in G's");
  Serial.println("X\tY\tZ");

  // // Print the sample rate for the accelerometer
  // Serial.print("Accelerometer sample rate = ");
  // Serial.print(IMU.accelerationSampleRate());
  // Serial.println(" Hz");
}

void loop() {
  // Check if acceleration data is available
  if (IMU.accelerationAvailable()) {
    IMU.readAcceleration(x, y, z);
    
    // // Convert acceleration in x-axis to degrees for tilt
    // if (x > 0.1) {
    //   degreesX = map(x * 100, 0, 97, 0, 90); // Tilting up
    //   Serial.print("Tilting up ");
    //   Serial.print(degreesX);
    //   Serial.println(" degrees");
    // }
    // else if (x < -0.1) {
    //   degreesX = map(x * 100, 0, -100, 0, 90); // Tilting down
    //   Serial.print("Tilting down ");
    //   Serial.print(degreesX);
    //   Serial.println(" degrees");
    // }

    // // Convert acceleration in y-axis to degrees for tilt
    // if (y > 0.1) {
    //   degreesY = map(y * 100, 0, 97, 0, 90); // Tilting left
    //   Serial.print("Tilting left ");
    //   Serial.print(degreesY);
    //   Serial.println(" degrees");
    // }
    // else if (y < -0.1) {
    //   degreesY = map(y * 100, 0, -100, 0, 90); // Tilting right
    //   Serial.print("Tilting right ");
    //   Serial.print(degreesY);
    //   Serial.println(" degrees");
    // }

    // Print the raw acceleration values
    Serial.print(x);
    Serial.print('\t');
    Serial.print(y);
    Serial.print('\t');
    Serial.println(z);
  }

  delay(1000); // Delay to control the data print rate
}
