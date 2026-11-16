#pragma once

#define RADIOLIB_STATIC_ONLY 1
#include <RadioLib.h>
#include <helpers/radiolib/RadioLibWrappers.h>
#include <helpers/radiolib/CustomSX1276Wrapper.h>
#include <helpers/ArduinoHelpers.h>
#include <helpers/SensorManager.h>
#include "ElarionBoard.h"
#include "ElarionSX1276.h"

#ifdef DISPLAY_CLASS
  #include <helpers/ui/NullDisplayDriver.h>
  extern NullDisplayDriver display;
#endif

extern ElarionBoard board;
extern WRAPPER_CLASS radio_driver;
extern VolatileRTCClock rtc_clock;
extern SensorManager sensors;

bool radio_init();
mesh::LocalIdentity radio_new_identity();
