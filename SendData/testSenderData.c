#include <stdio.h>
#include <assert.h>
#define BMS_SENDER_BUFFER_SIZE 50
float Temp[50] = {0};
float SOC[50] = {0};
float ChargeRate[50] = {0};

int main()
{
  printf("Temperature;SOC;ChargeRate\n");
  for (int i = 0; i < BMS_SENDER_BUFFER_SIZE; i++)
  {
    Temp[i] = i;
    SOC[i] = 1.5*i;
    ChargeRate[i] = (float)i/BMS_SENDER_BUFFER_SIZE;
  }
  for (int i = 0; i < BMS_SENDER_BUFFER_SIZE; i++)
  {
    printf("%f;%f;%f\n",Temp[i],SOC[i],ChargeRate[i]);
  }
  
  return 0;
}
