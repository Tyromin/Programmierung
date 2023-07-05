#include <stdio.h>
#include <stdlib.h>
#include <math.h>
// Datentyp f�r Positions

typedef double LaengengradT;///< Einheit: Dezimalgrad, d.h. eine Grad mit dezimalen Nachkommaanteil; Wertebereich [-180.0 ... 180.0]
typedef double BreitengradT;///< Einheit: Dezimalgrad, d.h. eine Grad mit dezimalen Nachkommaanteil; Wertebereich [-90.0 ... 90.0]

/** @brief geografische Koordinaten
*
* Datentyp fuer Positionsangaben in geografischen Koordinaten, d.h. durch Angabe eines Breiten- und Laengengrads.
*/
typedef struct{
    BreitengradT bgrad;
    LaengengradT lgrad;
}PositionT;


/** @brief x-Abstand zwischen zwei geografischen Positi0nen
*
*   Berechnet den Ost-West-Abstand zwischen der geografischen Position p1
*   und der Position p2 unter Anwendung der Merkatortransformation.
*
*   @param [in] p1 Position in Breiten- und Laengengrad
*   @param [in] p2 Position in Breiten- und Laengengrad
*   @return Ost-West-Abstand zwischen p1und p2 in km
*/
double abstandX(PositionT p1, PositionT p2);


/** @brief y-Abstand zwischen zwei geografischen Positionen
*
*   Berechnet den Nord-Sued-Abstand zwischen der geografischen Position p1
*   und der Position p2 unter Anwendung der Merkatortransformation.
*
*   @param [in] p1 Position in Breiten- und Laengengrad
*   @param [in] p2 Position in Breiten- und Laengengrad
*   @return Nord-Sued-Abstand zwischen p1 und p2 in km
*/
double abstandY(PositionT p1, PositionT p2);


/** @brief Abstand zwischen zwei geografischen Positionen
*
*   Berechnet den NAbstand zwischen der geografischen Position p1
*   und der Position p2 unter Anwendung der Merkatortransformation.
*
*   @param [in] p1 Position in Breiten- und Laengengrad
*   @param [in] p2 Position in Breiten- und Laengengrad
*   @return Abstand zwischen p1 und p2 in km
*/
double abstand(PositionT p1, PositionT p2);

int main(int argc,char* argv[])
{
    PositionT a = {52.518611,13.408056};    // Berlin
    PositionT b = {51.4825,7.216944};       // Bochum
    double deltax,deltay,delta;

    if(argc==5)
    {
        a.bgrad = atof(argv[1]);
        a.lgrad = atof(argv[2]);
        b.bgrad = atof(argv[3]);
        b.lgrad = atof(argv[4]);
    }


    // ---- Start TODO ----
    // F�gen Sie hier die Anweisung ein, um mit Hilfe der Funktion abstandX den Ost-West-Abstand zwischen
    // den Punkten a und b zu berechnen und der Variablen deltax zuzuweisen

    deltax = abstandX(a, b);
    // ---- Ende TODO -----

    // ---- Start TODO ----
    // F�gen Sie hier die Anweisung ein, um mit Hilfe der Funktion abstandY den Nord-Sued-Abstand zwischen
    // den Punkten a und b zu berechnen und der Variablen deltay zuzuweisen

    deltay = abstandY(a, b);
    // ---- Ende TODO -----

    // ---- Start TODO ----
    // F�gen Sie hier die Anweisung ein, um mit Hilfe der Funktion abstand den Abstand zwischen
    // den Punkten a und b zu berechnen und der Variablen delta zuzuweisen

    delta = abstand(a, b);
    // ---- Ende TODO -----

    printf("x-Abstand b von a: %.1f km\n",deltax);
    printf("y-Abstand b von a: %.1f km\n",deltay);
    printf("Abstand b von a: %.1f km\n",delta);

    return 0;
}



// ---- Start TODO ----
// F�gen Sie hier die Funktion-Definitionen f�r die am Anfang der Datei deklarierten
// Funktionen abstandX und abstandY ein.
double abstandX(PositionT p1, PositionT p2)
{
    double pi = M_PI;
    double lat, dx;

    lat = (p1.bgrad+p2.bgrad)/2*pi/180.0; // mittlerer Breitengrad in Bogenmaß
    dx = 111.3*cos(lat)*(p1.lgrad-p2.lgrad); // Abstand in Ost-West-Richtung in km

    return dx;
};


double abstandY(PositionT p1, PositionT p2)
{
    double dy;

    dy = 111.3*(p1.bgrad-p2.bgrad); // Abstand in Nord-Süd-Richtung in km

    return dy;
};


double abstand(PositionT p1, PositionT p2)
{
    double dx, dy, d;

    dx = abstandX(p1, p2);
    dy = abstandY(p1, p2);

    d = sqrt(dx*dx + dy*dy); // Entfernung in km

    return d;
};

// ---- Ende TODO -----
