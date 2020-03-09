/*
htop - darwin/FanRPM.c
(C) 2004-2006 Hisham H. Muhammad
(c) 2013 Morgan Blackthorne
Released under the GNU GPL, see the COPYING file
in the source distribution for its full text.
*/

#include "smc.h"

void FanRPM_getData(double* rpm) {
  rpm[0] = SMCGetFanRPM("F0Ac");
  rpm[1] = SMCGetFanRPM("F0Mx");
  rpm[2] = SMCGetFanRPM("F1Ac");
  rpm[3] = SMCGetFanRPM("F1Mx");
  rpm[4] = SMCGetFanRPM("F2Ac");
  rpm[5] = SMCGetFanRPM("F2Mx");
  rpm[6] = SMCGetFanRPM("F3Ac");
  rpm[7] = SMCGetFanRPM("F3Mx");
}
