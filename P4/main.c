#include <stdio.h>
#include <string.h>

// ---- Start TODO ----


typedef struct
{
    float lgrad;
    float bgrad;
}fpposition;

typedef struct
{
    char icao[5];
    char fpname[42];
    fpposition position;
}fplatz;


// ---- Ende TODO -----

int main(int argc,char* argv[])
{

    char s[5][109] =
    {
        "EDKA         ,  50,49.400,   6,11.200,01/01/2002,13:59:00,Aachen-Merzbr�ck                         ,  190,0",
        "EDPA         ,  48,46.700,  10,15.900,01/01/2002,13:59:00,Aalen-Heidenheim/Elchingen               ,  584,0",
        "EDXA         ,  52,22.700,   7,54.800,01/01/2002,13:59:00,Achmer                                   ,   54,0",
        "EDHO         ,  53,42.000,   9,44.700,01/01/2002,13:59:00,Ahrenlohe                                ,   10,0",
        "EDGA         ,  50,35.600,   7,56.700,01/01/2002,13:59:00,Ailertchen                               ,  470,0"
    };

    char icao[5];   // ICAO-Code
    short bg_grad;  // Vorkammanteil des Breitengrads in grad
    double bg_min;  // Nachkommaanteil des Breitengrads in Minuten
    short lg_grad;  // Vorkammanteil des L�ngengrads in grad
    double lg_min;  // Nachkommaanteil des L�ngengrads in Minuten
    char fpName[42];// Flugplatzname

    int ret,i;

    // ---- Start TODO ----
    
    fplatz flugplatz[417];

    // ---- Ende TODO -----

    for(i=0;i<5;i++)
    {
        ret = sscanf(s[i],
                    "%4s , %hi,%lf,%hi,%lf,01/01/2002,13:59:00,%41[^,]",
                    icao,&bg_grad,&bg_min,&lg_grad,&lg_min,fpName);

        // ---- Start TODO ----

        fplatz fphelfer;
        strcpy(fphelfer.icao, icao);
        strcpy(fphelfer.fpname, fpName);
        fphelfer.position.lgrad=lg_grad + lg_min/60;
        fphelfer.position.bgrad=bg_grad + bg_min/60;

        flugplatz[i]=fphelfer;
        // ---- Ende TODO -----
    }

    // ---- Start TODO ----
    
    printf("Nr.|ICAO|Längengrad|Breitengrad|Name\n");

    for(i=0;i<5;i++)
    {
        printf("%3i|%4s|  %6.2lf  |  %6.2lf   |%s\n", i+1, flugplatz[i].icao, flugplatz[i].position.lgrad, flugplatz[i].position.bgrad,flugplatz[i].fpname);
    };

    // ---- Ende TODO -----
    return 0;

}
