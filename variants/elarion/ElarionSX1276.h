#pragma once

#include <helpers/radiolib/CustomSX1276.h>

class ElarionSX1276 : public CustomSX1276 {
public:
  ElarionSX1276(Module* mod) : CustomSX1276(mod) { }

  int16_t setOutputPower(int8_t dbm) override {
    if (dbm > SX1276_MAX_DRIVE_DBM) dbm = SX1276_MAX_DRIVE_DBM;
    return CustomSX1276::setOutputPower(dbm);
  }
};
