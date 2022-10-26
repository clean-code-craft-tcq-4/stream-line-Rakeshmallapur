#include <stdio.h>
#include <assert.h>
#include "BMS_Receiver.h"

void testFindMinAndMax()
{
  /*Test Case: 1*/
  float data = 3;
  float Min = 5;
  float Max = 7;
  FindMinAndMax(data, &Min, &Max);
  assert(Min == 3);
  assert(Max == 7);
  
  /*Test Case: 2*/
  data = 6;
  Min = 5;
  Max = 7;
  FindMinAndMax(data, &Min, &Max);
  assert(Min == 5);
  assert(Max == 7); 
  
  /*Test Case: 3*/
  data = 8;
  Min = 5;
  Max = 7;
  FindMinAndMax(data, &Min, &Max);
  assert(Min == 5);
  assert(Max == 8); 
}

void testFindSMA()
{
  for (int i=0; i<NUMBER_OF_SAMPLES_FOR_SMA; i++)
  {
    Temp_Array[i] = i;
    SOC_Array[i] = 1.5*i;
    ChargeRate_Array[i] = (float)i/NUMBER_OF_SAMPLES_FOR_SMA;
  }
  
  float Temp_Sum = 0, Temp_Avg;
  float SOC_Sum = 0, SOC_Avg;
  float ChargeRate_Sum = 0, ChargeRate_Avg;
  for (int i = 0; i < NUMBER_OF_SAMPLES_FOR_SMA; i++)
  {
      Temp_Sum +=Temp_Array[i];
      SOC_Sum +=SOC_Array[i];
      ChargeRate_Sum +=ChargeRate_Array[i];
  }
  
  Temp_Avg = Temp_Sum/NUMBER_OF_SAMPLES_FOR_SMA;
  SOC_Avg = SOC_Sum/NUMBER_OF_SAMPLES_FOR_SMA;
  ChargeRate_Avg = ChargeRate_Sum/NUMBER_OF_SAMPLES_FOR_SMA;
  FindSMA();
  
  assert(SMA_Temp == Temp_Avg);
  assert(SMA_SOC = SOC_Avg);
  assert(SMA_ChargeRate == ChargeRate_Avg);
  
}

int main()
{
  
  testFindMinAndMax();
  
  testFindSMA();
  
  ReadConsolePrintMinMaxSMA();
  
  return 0;
  
}
