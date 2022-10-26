#define NUMBER_OF_SAMPLES_FOR_SMA 5
extern float Min_Temp;
extern float Max_Temp;
extern float SMA_Temp;
extern float Temp_Array[NUMBER_OF_SAMPLES_FOR_SMA];
extern float Min_SOC;
extern float Max_SOC;
extern float SMA_SOC;
extern float SOC_Array[NUMBER_OF_SAMPLES_FOR_SMA];
extern float Min_ChargeRate;
extern float Max_ChargeRate;
extern float SMA_ChargeRate;
extern float ChargeRate_Array[NUMBER_OF_SAMPLES_FOR_SMA];

int ReadFromConsoleInput(float* temperature, float* SOC, float* ChargeRate);
void FindMinAndMax(float data, float* Min, float* Max);
void FindSMA ();
void ReadConsolePrintMinMaxSMA();
