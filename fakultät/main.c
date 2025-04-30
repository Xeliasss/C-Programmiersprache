#include <stdio.h>
#include <stdlib.h>

// Funktionsprototyp
int fakultaet(int zahl);

int main()
{
    int zahl;

    // Benutzer nach einer Zahl fragen
    printf("Gib eine Zahl ein: ");
    scanf("%d", &zahl);

    // Fakult�t berechnen
    int ergebnis = fakultaet(zahl);

    // Ergebnis ausgeben
    printf("Die Fakult�t von %d ist: %d\n", zahl, ergebnis);

    return 0;
}

// Funktionsdefinition zur Berechnung der Fakult�t
int fakultaet(int zahl) {
    int ergebnis = 1;

    // Fakult�t berechnen: 5! = 5 * 4 * 3 * 2 * 1
    for (int i = 1; i <= zahl; i++) {
        ergebnis *= i;
    }

    return ergebnis;
}

