#include <stdio.h>
#include <stdlib.h>


/** @brief Umrechnung grad/min in reinen Dezimalgrad-Wert
*
*   Ein in der Einheit Grad/Dezimalminute übergebener Winkel wird in die Einheit
*   Dezimalgrad (Grad mit Nachkommastellen) umgewandelt, d.h. der Minutenbereich [0,60[
*   wird abgebildet auf den Nachkommaanteil in grad [0,1[.
*   Beispiele:\n
*   23 grad, 30 min sind 23.5 grad\n
*   -6 grad, 20 min sind -6.33 grad\n
*
*   @param [in] grad grad-Anteil des Winkels (ganzzahlig)
*   @param [in] min min-Anteil des Winkels (reell)
*   @return grad-Wert mit Nachkommaanteil.
*/
double grad(short grad, double min)
{
    // ---- Start TODO ----
    double minkonv;

    min=min/60;

    if(grad<0)
    {
        minkonv=grad-min;
    }
    else
    {
        minkonv=grad+min;
    }

    return minkonv;
    // ---- Ende TODO -----
}


int main(int argc,char* argv[])
{
    short g = 5;
    double m = 52.23;

    if(argc==3)
    {
        g = atoi(argv[1]);
        m = atof(argv[2]);
    }

    printf("%i grad und %.2lf min sind %.2f grad",g,m,grad(g,m));

    return 0;
}
