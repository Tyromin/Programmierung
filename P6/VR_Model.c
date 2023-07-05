#include "VR_Model.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

double grad(short grad, double min)
{
    if(grad>0)
        return (double)grad + min/60.0;
    else
        return (double)grad - min/60.0;
}

// ---- Start TODO ----
// Fuegen Sie hier die Definition der Funktion konvertiereStringZuFlugplatz gemmaess der
// Spezifikation in der Header-Datei VR_Model.h ein.

int konvertiereStringZuFlugplatz(char* s, FlugplatzT* fp)
{
    char shorthelper[50];
    char doublehelper[50];
    short grad_;
    double minuten;

    //Icao

    memcpy(fp->icao,s,4);
    fp->icao[4]='/0';

    //Name

    memcpy(fp->name,s+58,41);
    fp->name[41] = '\0';

    //Position
    //Breitengrad
    memcpy(shorthelper,s+14,4);
    memcpy(doublehelper,s+19,6);
    grad_ = atoi(shorthelper);
    minuten = atof(doublehelper);

    fp->position.bgrad = grad(grad_,minuten);

    //Längengrad
    memcpy(shorthelper,s+26,4);
    memcpy(doublehelper,s+31,6);
    grad_ = atoi(shorthelper);
    minuten = atof(doublehelper);

    fp->position.lgrad = grad(grad_,minuten);

    return &fp;
};
// ---- Ende TODO -----

/*
    char shorthelper[50];
    char doublehelper[50];
    int grad;
    double minuten;
    //icao
    memcpy(fp->icao,s,4);

    //breitengrad
    memcpy(shorthelper,s+14,4);
    memcpy(doublehelper,s+19,6);
    grad = atoi(shorthelper);
    minuten = atof(doublehelper);

    fp->position.bgrad=grad(grad,minuten);

    //längengrad
    memcpy(shorthelper,s+26,4);
    memcpy(doublehelper,s+31,6);
    grad = atoi(shorthelper);
    minuten = atof(doublehelper);

    fp->position.lgrad = grad(grad,minuten);

    //name
    memcpy(fp->name+58,s,41);
    fp->name[41] = '\0';

    return fp;
*/

