#include<stdio.h>
int main()
{
    FILE *fptr;
    fptr= fopen("/home/varun/Desktop/thermo/input.txt","r");
    if(fptr == NULL)
   {
      printf("Error!");   
      exit(1);             
   }
    float pressure [76], temp[76], Vf[76];
    for (int i = 0; i < 76; i++)
    {
        fscanf(fptr," %f",&temp[i]);
        fscanf(fptr," %f",&pressure[i]);
        fscanf(fptr," %f",&Vf[i]);
    }
    //printf("input complete\n");
    //printf("first value of temp %f and pessure %f \n and final vaue of temp %f and of pressure %f", temp[0], pressure[0], temp[75], pressure[75]);
    fclose(fptr);
    float inputTemp, inputPress;
    printf(" enter the value of temperature(k) and pressure(kPa)\n");
    scanf(" %f", &inputTemp);
    scanf(" %f", &inputPress);
    int i;
    for(i=0; i<76; i++)
    {
        if(inputTemp>temp[75])
        {
            printf("super critical fluid \n");
            break;
        }
        else
        if(inputTemp>=temp[i] && inputTemp<=temp[i+1])
        {
            float calPressure;
            calPressure= pressure[i] + ((pressure[i+1]-pressure[i])/(temp[i+1]-temp[i]))*(inputTemp-temp[i]);
            if(calPressure>inputPress)
            {
                printf("super heated vapour \n");
            }
            else
            if(calPressure<inputPress)
            {
                printf("subcooled liquid \n");
            }
            else
            if(calPressure=inputPress)
            {
                printf("saturated liquid and saturated vapor mixture \n");
            }
            break;
        }
    }
    return 0;
}
