#include <stdio.h>
#include "BMS_Receiver.h"
float Min_Temp = 0;
float Max_Temp = 0;
float SMA_Temp = 0;
float Temp_Array[NUMBER_OF_SAMPLES_FOR_SMA] = {0};
float Min_SOC = 0;
float Max_SOC = 0;
float SMA_SOC = 0;
float SOC_Array[NUMBER_OF_SAMPLES_FOR_SMA] = {0};
float Min_ChargeRate = 0;
float Max_ChargeRate = 0;
float SMA_ChargeRate = 0;
float ChargeRate_Array[NUMBER_OF_SAMPLES_FOR_SMA] = {0};

int ReadFromConsoleInput(float* temperature, float* SOC, float* ChargeRate)
{
  char dummy;
  int x = scanf("%f%c%f%c%f", temperature, &dummy, SOC, &dummy, ChargeRate);
  
  /*Shifting the elements in the array for Moving Average calculation*/
  for(int i = 0; i<NUMBER_OF_SAMPLES_FOR_SMA-1; i++)
  {
    Temp_Array[i] = Temp_Array[i+1];
    SOC_Array[i] = SOC_Array[i+1];
    ChargeRate_Array[i] = ChargeRate_Array[i+1];
  }
  
  /*Inserting the latest data into the last element of array*/
  Temp_Array[NUMBER_OF_SAMPLES_FOR_SMA-1] = *temperature;
  SOC_Array[NUMBER_OF_SAMPLES_FOR_SMA-1] = *SOC;
  ChargeRate_Array[NUMBER_OF_SAMPLES_FOR_SMA-1] = *ChargeRate;
    
  return x;
}

void FindMinAndMax(float data, float* Min, float* Max)
{
   if (data < *Min)
   {
     *Min = data;
   }
   else if (data > *Max)
   {
     *Max = data;
   }
   else
   {
     /*Do nothing*/
   }
}

void FindSMA ()
{
  float Temp_Sum = 0;
  float SOC_Sum = 0;
  float ChargeRate_Sum = 0;
    for (int i = 0; i < NUMBER_OF_SAMPLES_FOR_SMA; i++)
    {
      Temp_Sum +=Temp_Array[i];
      SOC_Sum +=SOC_Array[i];
      ChargeRate_Sum +=ChargeRate_Array[i];
    }
  SMA_Temp = Temp_Sum/NUMBER_OF_SAMPLES_FOR_SMA;
  SMA_SOC = SOC_Sum/NUMBER_OF_SAMPLES_FOR_SMA;
  SMA_ChargeRate = ChargeRate_Sum/NUMBER_OF_SAMPLES_FOR_SMA;
}

int PrintMinMaxSMA()
{
    printf("Temperature: Min = %f, Max = %f, SMA = %f\n", Min_Temp, Max_Temp, SMA_Temp);
    printf("SOC: Min = %f, Max = %f, SMA = %f\n", Min_SOC, Max_SOC, SMA_SOC);
    printf("ChargeRate: Min = %f, Max = %f, SMA = %f\n\n", Min_ChargeRate, Max_ChargeRate, SMA_ChargeRate);
  
  return 1;
}

void ReadConsolePrintMinMaxSMA()
{
  float temperature, SOC, ChargeRate;
  char title[30];
  fgets(title,30,stdin);
  puts(title);
  for (int i=0; i<50; i++)
  {
    ReadFromConsoleInput(&temperature, &SOC, &ChargeRate);
    FindMinAndMax(temperature, &Min_Temp, &Max_Temp);
    FindMinAndMax(SOC, &Min_SOC, &Max_SOC);
    FindMinAndMax(ChargeRate, &Min_ChargeRate, &Max_ChargeRate);
    FindSMA();
  }
}
