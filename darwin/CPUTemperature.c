/*
htop - darwin/CPUTemperature.c
(C) 2004-2006 Hisham H. Muhammad
(c) 2013 Morgan Blackthorne
Released under the GNU GPL, see the COPYING file
in the source distribution for its full text.
*/

#include "smc.h"

void CPUTemperature_getData(double* values) {
  double temp[2];

  if ((temp[0] = SMCGetTemperature("TC0P")) != 0.0) { // Newer iMacs
      values[0] = temp[0];
      values[1] = 0;
  } else
  // Some Mac Pros have two sensors, since they are SMP
  if ((temp[0] = SMCGetTemperature("TCAH")) != 0.0 &&
      (temp[1] = SMCGetTemperature("TCBH")) != 0.0) {
      values[0] = temp[0];
      values[1] = temp[1];
  } else if ((temp[0] = SMCGetTemperature("TC0D")) != 0.0) { // Older MBPs
      values[0] = temp[0];
      values[1] = 0;
  } else if ((temp[0] = SMCGetTemperature("TC0F")) != 0.0) { // Newer MBPs
      values[0] = temp[0];
      values[1] = 0;
  } else if ((temp[0] = SMCGetTemperature("TC0H")) != 0.0) { // Some iMacs
      values[0] = temp[0];
      values[1] = 0;
  } else {
      // Couldn't retrieve sensor information...
      values[0] = 0;
      values[1] = 0;
  }
}
