#pragma once

#include <Arduino.h>
#include <helpers/stm32/STM32Board.h>

class ElarionBoard : public STM32Board {
public:
  void begin() override {
    STM32Board::begin();

#ifdef P_PA_DAC
    analogWriteResolution(12);
    analogWrite(P_PA_DAC, PA_DAC_VALUE);
#endif

#ifdef P_MUX_S1
    pinMode(P_RS485_DE, OUTPUT); digitalWrite(P_RS485_DE, LOW);
    pinMode(P_MUX_S1, OUTPUT);   digitalWrite(P_MUX_S1, HIGH);
    pinMode(P_MUX_S2, OUTPUT);   digitalWrite(P_MUX_S2, LOW);
    pinMode(P_MUX_S3, OUTPUT);   digitalWrite(P_MUX_S3, LOW);
#endif

    pinMode(P_LED_TX, OUTPUT);
    digitalWrite(P_LED_TX, LOW);
  }

  void onBeforeTransmit() override { digitalWrite(P_LED_TX, HIGH); }
  void onAfterTransmit() override  { digitalWrite(P_LED_TX, LOW); }

  const char* getManufacturerName() const override { return ELARION_BOARD_NAME; }
};
