#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int wahl;
char dateiname[] = "C:\\devisen\\Land.csv"; // Hier könnte der Pfad angepasst werden

typedef struct {
    char Land[30];
    char Wohnungskuerzel[5];
    double Kurs;
} devisen;

// Funktion, um nach einem bestimmten Kurs zu suchen
void suche(const char *dateiname, double gesuchterKurs) {
    FILE *fp;
    char zeile[100];
    devisen d;

    fp = fopen(dateiname, "r");
    if (fp == NULL) {
        printf("Fehler beim Öffnen der Datei!\n");
        return;
    }

    int gefunden = 0; // Flag, um zu überprüfen, ob der Kurs gefunden wurde

    // Datei zeilenweise lesen
    while (fgets(zeile, sizeof(zeile), fp)) {
        // Splitte die Zeile in Land, Wohnungskuerzel und Kurs
        sscanf(zeile, "%29[^;];%4[^;];%lf", d.Land, d.Wohnungskuerzel, &d.Kurs);

        // Vergleiche den aktuellen Kurs mit dem gesuchten Kurs
        if (d.Kurs == gesuchterKurs) {
            printf("Gefunden: Land: %s, Wohnungskuerzel: %s, Kurs: %.2f\n", d.Land, d.Wohnungskuerzel, d.Kurs);
            gefunden = 1;
        }
    }

    if (!gefunden) {
        printf("Kein Eintrag mit dem Kurs %.2f gefunden.\n", gesuchterKurs);
    }

    fclose(fp);
}

void newlineEntfernen(char *str) {
    size_t len = strlen(str);
    if (len > 0 && str[len - 1] == '\n') {
        str[len - 1] = '\0';
    }
}

void deviseEingebenUndSpeichern(const char *dateiname) {
    devisen d;
    FILE *fp;

    printf("Land: ");
    fgets(d.Land, sizeof(d.Land), stdin);
    newlineEntfernen(d.Land);

    printf("Wohnungskuerzel: ");
    fgets(d.Wohnungskuerzel, sizeof(d.Wohnungskuerzel), stdin);
    newlineEntfernen(d.Wohnungskuerzel);

    printf("Kurs: ");
    scanf("%lf", &d.Kurs);
    getchar(); // liest das '\n' nach scanf

    // Datei im Anhänge-Modus öffnen
    if ((fp = fopen(dateiname, "a")) != NULL) {
        fprintf(fp, "%s;%s;%.2lf\n", d.Land, d.Wohnungskuerzel, d.Kurs);
        fclose(fp);
        printf("Datensatz gespeichert.\n");
    } else {
        printf("Fehler beim Öffnen der Datei!\n");
    }
}

void devisenAnzeigen(const char *dateiname) {
    FILE *fp;
    char zeile[100];

    if ((fp = fopen(dateiname, "r")) != NULL) {
        printf("\n--- Gespeicherte Devisen ---\n");
        while (fgets(zeile, sizeof(zeile), fp)) {
            printf("%s", zeile);
        }
        fclose(fp);
    } else {
        printf("Keine Datei gefunden.\n");
    }
}

int main() {
    double gesuchterKurs;
    do {
        printf("\n==== Devisen Menü ====\n");
        printf("1. Neue Devise eingeben\n");
        printf("2. Alle Devisen anzeigen\n");
        printf("3. Nach einem Kurs suchen\n");
        printf("0. Beenden\n");
        printf("Auswahl: ");
        scanf("%d", &wahl);
        getchar(); // newline einlesen

        switch (wahl) {
        case 1:
            deviseEingebenUndSpeichern(dateiname);
            break;
        case 2:
            devisenAnzeigen(dateiname);
            break;
        case 3:
            printf("Geben Sie den Kurs ein, nach dem gesucht werden soll: ");
            scanf("%lf", &gesuchterKurs);
            suche(dateiname, gesuchterKurs);
            break;
        case 0:
            printf("Programm beendet.\n");
            break;
        default:
            printf("Ungültige Auswahl.\n");
        }
    } while (wahl != 0);

    return 0;
}







