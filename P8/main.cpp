// 0. include-Direktiven
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <graphics.h>

// 1. Konstanten
#define M_PI		3.14159265358979323846
#define MAX_SPALTEN_FP_DATEI 120
#define MAX_FLUGPLAETZE 500
#define KANTENLAENG_KARTE 100       // Standardgr��e des darzustellenden Kartenbereichs (Kantenl�nge in km)
#define BREITE_FENSTER 700          // Breite des Fensters f�r die Darstellung der Karte (Einheit: Pixel)
#define HOEHE_FENSTER  700          // Hoehe des Fensters f�r die Darstellung der Karte (Einheit: Pixel)
// 2. Datentypen
typedef char ICAOT[5];
typedef char FlugplatznameT[43];
typedef double LaengengradT;
typedef double BreitengradT;

typedef struct{
    BreitengradT bgrad;
    LaengengradT lgrad;
}PositionT;

typedef struct{
    ICAOT icao;
    FlugplatznameT name;
    PositionT position;
}FlugplatzT;

//-- neu in P8 --*/
typedef struct{
    int anzahl;
    FlugplatzT fp[MAX_FLUGPLAETZE];
}FlugplatzListeT;


// 3. Funktionsdeklarationen
double grad(short grad, double min);
int konvertiereStringZuFlugplatz(char* s, FlugplatzT* fp);
int ladeTextDatei(char* dateiname, char text[][MAX_SPALTEN_FP_DATEI]);
double abstandX(PositionT p1, PositionT p2);
double abstandY(PositionT p1, PositionT p2);

//-- neu in P8 --*/
void clrscr();
//-- neu in P8 --*/
void initialisiereKarte();
//-- neu in P8 --*/
void entferneKarte();
//-- neu in P8 --*/
int ladeFlugplatzdaten(char* dateiname, FlugplatzListeT* fpl);
//-- neu in P8 --*/
void anzeigenFlugplatzliste(FlugplatzListeT fpl);
//-- neu in P8 --*/
void anzeigenKarte(FlugplatzListeT fpl, PositionT mitte, double massstab);

// 4. Funktionsdefinitionen
// 4.1 main-Funktion

int main(int argc,char* argv[])
{
    // Hilfsvariablen
	int ret;

    //Anwendungsvariablen
    char dateiname[100] = "flughafen.dat";
    FlugplatzListeT flugplaetze;
    PositionT POI = {51.5,10.0};     // Bochum

    // 1. Flugplatzdaten laden
    ret = ladeFlugplatzdaten(dateiname,&flugplaetze);
    if(ret==0)
    {
        printf("FEHLER: Flugplatzdaten konnten nicht geladen werden.\n");
        return 0;
    }

    // 2. Flugplaetze anzeigen
    anzeigenFlugplatzliste(flugplaetze);

    // 3. Karte initialisieren
    initialisiereKarte();

    // 4. Karte anzeigen
    anzeigenKarte(flugplaetze,POI,9);

    // 5. Warten auf Beenden
    ret = getchar();

    // 6. Grafik beenden
    entferneKarte();

    return 1;
}

// 4.2 weitere-Funktion

double grad(short grad, double min)
{
    return (double)grad+min/60.0;
}

double abstandX(PositionT p1, PositionT p2)
{
    double mBGrad = (p1.bgrad+p2.bgrad)/2.0;
    return 111.3 * cos(M_PI/180.0*mBGrad) * (p1.lgrad-p2.lgrad);
}

double abstandY(PositionT p1, PositionT p2)
{
    return 111.3 * (p1.bgrad- p2.bgrad);
}

int konvertiereStringZuFlugplatz(char* s, FlugplatzT* fp)
{
    ICAOT icao;
    short bg_grad;
    double bg_min;
    short lg_grad;
    double lg_min;
    FlugplatznameT fpName;
    int ret;

    ret = sscanf(s,
                 "%4s , %hi,%lf,%hi,%lf,01/01/2002,13:59:00,%42[^,]",
                 icao,&bg_grad,&bg_min,&lg_grad,&lg_min,fpName);

    if(ret!=6)
    {
        printf("StringZuFlugplatz::Fehler im Datensatz\n%s\n",s);
        return 0;
    }
    else
    {
        strcpy(fp->icao,icao);
        fp->position.bgrad = grad(bg_grad,bg_min);
        fp->position.lgrad = grad(lg_grad,lg_min);
        strcpy(fp->name,fpName);
        return 1;
    }
}

int ladeTextDatei(char* dateiname, char text[][MAX_SPALTEN_FP_DATEI])
{
    FILE* datei;
    int anz=0;

    datei=fopen(dateiname,"r");
    if(!datei)
    {
        printf("Datei <%s> konnte nicht geoeffnet werden.\n",dateiname);
        return 0;
    }
    while(fgets(text[anz++],MAX_SPALTEN_FP_DATEI,datei));
    fclose(datei);
    return anz-1;
}

//-- neu in P8 --*/
void clrscr()
{
    system("cls");
}

// ---- Start TODO ----
// Implementieren Sie hier die noch fehlenden Funktionen.

int ladeFlugplatzdaten(char* dateiname, FlugplatzListeT* fpl)
{
    int anz=0;    // Anzahl gelesener Flugplaetze

    char fpString[MAX_FLUGPLAETZE][MAX_SPALTEN_FP_DATEI];

    fpl->anzahl = ladeTextDatei(dateiname,fpString);

    //Converter-loop
    while(anz < fpl->anzahl)
    {
        konvertiereStringZuFlugplatz(fpString[anz],&(fpl->fp[anz]));
        anz++;
    }

    return anz;
}

void anzeigenFlugplatzliste(FlugplatzListeT fpl)
{
    int i;

    printf("Nr. | ICAO | Breite | Laenge | Name\n");
    for(i = 0; i<fpl.anzahl; i++)
    {
        printf("%3i | %4s | %6.2f | %6.2f | %s\n", i+1, fpl.fp[i].icao, fpl.fp[i].position.bgrad, fpl.fp[i].position.lgrad, fpl.fp[i].name);
    }
}

void initialisiereKarte()
{
    initwindow(BREITE_FENSTER,HOEHE_FENSTER,"Radarschrirm");
}

void entferneKarte()
{
    closegraph();
}

void plotFlugplatz(int x, int y, FlugplatzT fp)
{
    circle(x,y,2);
}

void anzeigenKarte(FlugplatzListeT fpl, PositionT mitte, double massstab)
{
    double KantenM;
    int i;
    double XAbstandPOI, YAbstandPOI;
    int SKoordinate, ZKoordinate;

    //Maßstab
    KantenM = KANTENLAENG_KARTE * massstab;

    for(i = 0; i<=fpl.anzahl; i++)
    {
        //Abstandsberechnung per Merkator-Transformation
        XAbstandPOI = abstandX(fpl.fp[i].position,mitte);
        YAbstandPOI = abstandY(fpl.fp[i].position,mitte);

        //lineare Transformation
        SKoordinate = (XAbstandPOI/KantenM) * BREITE_FENSTER + BREITE_FENSTER/2;
        ZKoordinate = -(YAbstandPOI/KantenM) * HOEHE_FENSTER + HOEHE_FENSTER/2;

        //Überprüft Clipping
        if (0<=SKoordinate && SKoordinate<=HOEHE_FENSTER && 0<=ZKoordinate && ZKoordinate<=BREITE_FENSTER)
        {
            plotFlugplatz(SKoordinate,ZKoordinate,fpl.fp[i]);
        }


    }
}
// ---- Ende TODO -----
