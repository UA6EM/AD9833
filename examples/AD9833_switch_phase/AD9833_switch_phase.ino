//
//    FILE: AD9833_switch_phase.ino
//  AUTHOR: Rob Tillaart
// PURPOSE: demo AD9833 wave form generator

#include "AD9833.h"

AD9833 AD;
uint32_t lastTime = 0;
uint8_t  channel = 0;

void setup()
{
  Serial.begin(115200);
  Serial.println(__FILE__);

  AD.begin(10);  //  HW SPI, select = pin 10
  AD.setWave(AD9833_SINE);
  AD.setFrequency(440, 0);    //  A0
  AD.setPhase(0, 0);
  AD.setPhase(90, 1); 
  AD.setPhaseChannel(channel);   

  AD.setWave(AD9833_SQUARE1);
  Serial.println(AD.getWave());
}


void loop()
{
  uint32_t now = millis();
  if (now - lastTime >= 1000)
  {
    lastTime = now;
    //  toggle channel.
    if (channel == 0) channel = 1;
    else channel = 0;
    AD.setPhaseChannel(channel); 
  }
}


//  -- END OF FILE --
