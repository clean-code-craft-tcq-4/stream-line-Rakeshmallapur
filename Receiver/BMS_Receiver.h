#define NUMBER_OF_SAMPLES_FOR_SMA 5

int ReadFromConsoleInput(float* temperature, float* SOC, float* ChargeRate);
int FindMinAndMax(float data, float* Min, float* Max);
void FindSMA ();