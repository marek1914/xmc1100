// Support code for the temperature sensor.
// All TSE events are handled through interrupt SCU_SR1.

#ifndef PERIPHERALS_TEMPERATURE_H
#define PERIPHERALS_TEMPERATURE_H

unsigned int tseEnable(void);
unsigned int tseDisable(void);
unsigned long tseRead(void);

// Firmware routines
unsigned long (*_CalcTemperature)(void) = (void *)0x0000010c;
unsigned long (*_CalcTSEVar)(unsigned long temperature) = (void *)0x00000120;

// SCU_SRMSK and SCU_SRRAW mask values for temperature sensor events.
#define TSE_DONE BIT29
#define TSE_HIGH BIT30
#define TSE_LOW BIT31

#endif
