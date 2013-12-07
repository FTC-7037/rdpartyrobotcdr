#pragma config(Sensor, S1,     MSLSA,          sensorI2CCustomFastSkipStates9V)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

/*
 * $Id: mindsensors-ligthsensorarray-test1.c 133 2013-03-10 15:15:38Z xander $
 */

/**
 * mindsensors-lightsensorarray.h provides an API for the Mindsensors LightSensorArray Sensor.  This program
 * demonstrates how to use that API.
 *
 * Changelog:
 * - 0.1: Initial release
 *
 * Credits:
 * - Big thanks to Mindsensors for providing me with the hardware necessary to write and test this.
 *
 * License: You may use this code as you wish, provided you give credit where it's due.
 *
 * THIS CODE WILL ONLY WORK WITH ROBOTC VERSION 3.59 AND HIGHER. 

 * Xander Soldaat (xander_at_botbench.com)
 * 30 September 2012
 * version 0.1
 */

#include "drivers/mindsensors-lightsensorarray.h"

task main {
  tByteArray signalstr;

  while (true) {
    if (!MSLSAreadSensors(MSLSA, &signalstr[0]))
    {
      eraseDisplay();
      PlaySound(soundException);
      nxtDisplayCenteredTextLine(4, "error!");
      wait1Msec(5000);
    }

    // This clears the entire area occupied by the small rectangles
    nxtEraseRect(6,62, 91, 43);
    for (int i = 0; i < 8; i++) {
      // Draw the rectangles for the signal strength first
      nxtDrawRect(6+(i*11),62, 14+(i*11), 50);
      nxtFillRect(6+(i*11),51+signalstr[i]/10, 14+(i*11), 50);
    }
    // Display the actual signal strength for each sensor
    for (int i = 0; i < 7; i+=2) {
      nxtDisplayTextLine(i/2+3, "S: %3d S: %3d", (int)signalstr[i], (int)signalstr[i+1]);
    }
    wait1Msec(50);
  }
}

/*
 * $Id: mindsensors-ligthsensorarray-test1.c 133 2013-03-10 15:15:38Z xander $
 */
