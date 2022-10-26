#include <stdio.h>
#include <assert.h>
#include "BMS_Receiver.h"

int main()
{
  float temperature, SOC, ChargeRate;
  char titles[30];
  fgets(titles,30,stdin);
  puts(titles);
  for (int i=0; i<50; i++)
  {
    ReadFromConsoleInput(&temperature, &SOC, &ChargeRate);
    printf("%f;%f;%f\n",temperature, SOC, ChargeRate);
  }
  return 0;
  
}
