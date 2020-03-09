/*
htop
(c) 2013 Morgan Blackthorne
Released under the GNU GPL, see the COPYING file
in the source distribution for its full text.
*/

#include "FanRPMMeter.h"
#include "FanRPM.h"
#include "CRT.h"
#include "Platform.h"

/*{
#include "Meter.h"
}*/

int FanRPMMeter_attributes[] = {
   FAN_RPM
};

static void FanRPMMeter_updateValues(Meter* this, char* buffer, int size) {
   FanRPM_getData(this->values);
}

static void FanRPMMeter_display(Object* cast, RichString* out) {
   Meter* this = (Meter*)cast;
   char buffer[20];
   double hot_threshold = 4000.0; /* RPM */
   double warm_threshold = 3000.0; /* RPM */
   //double cold_threshold = 1000.0; /* RPM */
   double raw_rpm_1, raw_rpm_2, raw_rpm_3, raw_rpm_4;
   double max_rpm_1, max_rpm_2, max_rpm_3, max_rpm_4;

   raw_rpm_1 = this->values[0]; max_rpm_1 = this->values[1];
   raw_rpm_2 = this->values[2]; max_rpm_2 = this->values[3];
   raw_rpm_3 = this->values[4]; max_rpm_3 = this->values[5];
   raw_rpm_4 = this->values[6]; max_rpm_4 = this->values[7];

   if (raw_rpm_1 > 0) {
      snprintf(buffer, 20, "%.0f RPM", raw_rpm_1);
      if (raw_rpm_1 > hot_threshold) {
         RichString_append(out, CRT_colors[FAN_RPM_HOT], buffer);
      } else if (raw_rpm_1 > warm_threshold) {
         RichString_append(out, CRT_colors[FAN_RPM_WARM], buffer);
      } else {
         RichString_append(out, CRT_colors[FAN_RPM_NORMAL], buffer);
      }
   } else {
      snprintf(buffer, 20, "-.- RPM");
      RichString_append(out, CRT_colors[FAN_RPM_NORMAL], buffer);
   }

   if (raw_rpm_2 > 0) {
      snprintf(buffer, 20, ", %.0f RPM", raw_rpm_2);
      if (raw_rpm_2 > hot_threshold) {
         RichString_append(out, CRT_colors[FAN_RPM_HOT], buffer);
      } else if (raw_rpm_2 > warm_threshold) {
         RichString_append(out, CRT_colors[FAN_RPM_WARM], buffer);
      } else {
         RichString_append(out, CRT_colors[FAN_RPM_NORMAL], buffer);
      }
   }

   if (raw_rpm_3 > 0) {
      snprintf(buffer, 20, ", %.0f RPM", raw_rpm_3);
      if (raw_rpm_3 > hot_threshold) {
         RichString_append(out, CRT_colors[FAN_RPM_HOT], buffer);
      } else if (raw_rpm_3 > warm_threshold) {
         RichString_append(out, CRT_colors[FAN_RPM_WARM], buffer);
      } else {
         RichString_append(out, CRT_colors[FAN_RPM_NORMAL], buffer);
      }
   }

   if (raw_rpm_4 > 0) {
      snprintf(buffer, 20, ", %.0f RPM", raw_rpm_4);
      if (raw_rpm_4 > hot_threshold) {
         RichString_append(out, CRT_colors[FAN_RPM_HOT], buffer);
      } else if (raw_rpm_4 > warm_threshold) {
         RichString_append(out, CRT_colors[FAN_RPM_WARM], buffer);
      } else {
         RichString_append(out, CRT_colors[FAN_RPM_NORMAL], buffer);
      }
   }
}

MeterClass FanRPMMeter_class = {
   .super = {
      .extends = Class(Meter),
      .delete = Meter_delete,
      .display = FanRPMMeter_display
   },
   .updateValues = FanRPMMeter_updateValues,
   .defaultMode = TEXT_METERMODE,
   .total = 100.0,
   .maxItems = 8,
   .attributes = FanRPMMeter_attributes,
   .name = "FanRPM",
   .uiName = "Fan RPM",
   .caption = "Fan RPM: ",
};
