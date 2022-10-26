#include <stdio.h>
#include <assert.h>
#include "BMS_Receiver.h"

int main()
{
  float temperature, SOC, ChargeRate;
  char titles[30];
  gets(titles);
  puts(titles);
  ReadFromConsoleInput(&temperature, &SOC, &ChargeRate);
  return 0;
  
}
