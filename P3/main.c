#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main(int argc,char* argv[])
{

    char s[] = "EDFD         ,  50,18.300,  10,13.600,01/01/2002,13:59:00,Bad Neustadt/Saale-Grasberg              ,  304,0";

    char icao[5];   // ICOA-Code
    short bg_grad;  // Vorkammanteil des Breitengrads in grad
    double bg_min;  // Nachkommaanteil des Breitengrads in Dezimalminuten
    short lg_grad;  // Vorkammanteil des L�ngengrads in grad
    double lg_min;  // Nachkommaanteil des L�ngengrads in Dezimalminuten
    char fpName[42];// Flugplatzname

    int ret;

    if(argc==2)
    {
        strcpy(s,argv[1]);
    }

    // ---- Start TODO ----
    char shorthelper[50];
    char doublehelper[50];
    //icao
    memcpy(icao,s,4);

    //BG GRAD
    memcpy(shorthelper,s+14,4);
    bg_grad=atoi(shorthelper);

    //BG MIN
    memcpy(doublehelper,s+19,6);
    bg_min=atof(doublehelper);

    //LG GRAD
    memcpy(shorthelper,s+26,4);
    lg_grad=atoi(shorthelper);

    //LG MIN
    memcpy(doublehelper,s+31,6);
    lg_min=atof(doublehelper);

    //FPNAME
    memcpy(fpName,s+58,41);
    fpName[41] = '\0';
    // ---- Ende TODO -----
    printf("icao = %s\n",icao);
    printf("bg_grad = %i\n",bg_grad);
    printf("bg_min = %.2f\n",bg_min);
    printf("lg_grad = %i\n",lg_grad);
    printf("lg_min = %.2f\n",lg_min);
    printf("fpName = %s\n",fpName);

    return 0;

}
