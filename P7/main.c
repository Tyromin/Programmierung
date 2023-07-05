#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SPALTEN_FP_DATEI 120

/** @brief Einlesen einer Textdatei
*
*   Der Inhalt einer Textdatei wird zeilenweise gelesen und in einem zweidimenensionalem
*   Feld von char zurueckgegben.
*   @param [in] dateiname Name und Pfad der einzulesenden Datei
*   @param [out] text Zeilenweiser Inhalt der Textdatei
*   @return Anzahl der gelesenen Zeilen. 0 wird zurueckgegeben, falls
*   die Datei nicht geoeffnet werden konnte oder keine Datensaetze vorhanden waren
*/
int ladeTextDatei(char* dateiname, char text[][MAX_SPALTEN_FP_DATEI]);

int main(int argc,char* argv[])
{

    char dateiName[] = "flugplatz.dat";
    char fpString[500][MAX_SPALTEN_FP_DATEI];
    int m=1,o=0,n,i;

    if(argc==3)
    {
        strcpy(dateiName,"flughafen.dat");
        m = atoi(argv[1]);
        o = atoi(argv[2]);
    }

    n = ladeTextDatei(dateiName,fpString);
    if(n==0)
    {
        printf("Keine Flugplatzdaten vorhanden.\n");
    }else
    {
        for(i=o;i<n;i=i+m)
        {
            printf(" %s ",fpString[i]);
        }
        printf("\n%i Flugplatzdatensaetze\n",n);
    }


    return 0;
}


// ---- Start TODO ----
// Fuegen Sie hier die Definition der Funktion ladeTextDatgei gemmaess der
// Spezifikation am Anfang der Datei ein.


int ladeTextDatei(char* dateiname, char text[][MAX_SPALTEN_FP_DATEI])
{
    FILE *fp;
    int zeilen = 0;

    //Datei öffnen

    fp = fopen(dateiname, "r");

    //Existenz der Datei überprüfen
    if (fp == NULL)
    {
        return 0;
    };


    while (fgets(text[zeilen], MAX_SPALTEN_FP_DATEI, fp) != NULL)
    {
        zeilen++;
    }


    fclose(fp);

    return zeilen;
};

// ---- Ende TODO -----
