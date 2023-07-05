#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "VR_Model.h"


int main(int argc,char* argv[])
{

    char s[] = "EDKA         ,  50,49.400,   6,11.200,01/01/2002,13:59:00,Aachen-Merzbrueck                        ,  190,0";
    FlugplatzT fp;

    if(argc==2)
    {
        strcpy(s,argv[1]);
    }

    if(konvertiereStringZuFlugplatz(s,&fp)==0)
    {
        printf("Konvertierung fehlgeschlagen.\n");
    }else
    {
        printf("icao = %s\n",fp.icao);
        printf("bgrad= %.2f\n",fp.position.bgrad);
        printf("lgrad= %.2f\n",fp.position.lgrad);
        printf("name = %s\n",fp.name);
    }

    return 0;
}

