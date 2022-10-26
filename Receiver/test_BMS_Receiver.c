#include <stdio.h>
#include <assert.h>
#include "BMS_Receiver.h"

int main()
{
  float temperature, SOC, ChargeRate;
  char titles[30];
  fgets(titles,30,stdin);
  puts(titles);
  ReadFromConsoleInput(&temperature, &SOC, &ChargeRate);
  return 0;
  
}
