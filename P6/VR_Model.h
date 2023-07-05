#ifndef VR_MODEL
#define VR_MODEL

#define MAX_FLUGPLAETZE 417

typedef double LaengengradT;///< Einheit: Dezimalgrad, d.h. eine Grad mit dezimalen Nachkommaanteil; Wertebereich [-180.0 ... 180.0]
typedef double BreitengradT;///< Einheit: Dezimalgrad, d.h. eine Grad mit dezimalen Nachkommaanteil; Wertebereich [-90.0 ... 90.0]
typedef char ICAOT[5];
typedef char FlugplatznameT[43];

/** @brief geografische Koordinaten
*
* Datentyp fuer Positionsangaben in geografischen Koordinaten, d.h. durch Angabe eines Breiten- und Laengengrads.
*/
typedef struct{
    BreitengradT bgrad;
    LaengengradT lgrad;
}PositionT;

typedef struct{
    ICAOT icao;
    FlugplatznameT name;
    PositionT position;
}FlugplatzT;


/** @brief Konvertiere Flugplatzdatensatz in einen Flugplatz-Wert
*
*   Konvertiert einer Flugplatz-Zeichenkette (Datensatz aus der Flugplatz-Datei)
*   in einen Wert des Typs FlugplatzT.
*   Beispiel:
*
*   EDSA         ,  48,15.000,   9, 3.600,01/01/2002,13:59:00,Albstadt-Degerfeld                       ,  878,0
*
*   Fuer den Datentyp FlugplatzT sind nur die Komponenten ICAO, Breiten- und Laengengrad sowie der Name relevant.
*   Alle anderen Informationen werden verworfen. Breiten- und Laengengrad werden von
*   der Einheit grad,min in die die Einheit grad mit Nachkommastelle konvertiert.
*   @param [in] s Flugplatzdatensatz
*   @param [out] fp Flugplatzdaten. Falls die Konvertierung fehlschlaegt, wird
*   der Inhalt der uebergebenen Variable nicht geaendert.
*   @retval 0 Datensatz konnte nicht in eine Flugplatz-Wert konvertiert werden.
*   Die Konvertierung ist nur erfolgreich, wenn alle fuer FlugplatzT notwendigen Informationen ermittelt werden konnten.
*   Dies sind der ICAO-Code, der Name sowie die geografische Position in Dezimalgrad.
*   @retval 1 Datensatz konnte erfolgreich konvertiert werden.
*   Alle fuer einen Flugplatz notwendigen Informationen konnten ermittelt werden.
*/
int konvertiereStringZuFlugplatz(char* s, FlugplatzT* fp);
#endif

