#include <stdio.h>
#include <stdlib.h>

//Funktion Deklanarieren
void menu_ausgaben();
int auswahl_einlesen();
int preis_erfragen(int);
int geld_einwerfen (int);
void ruckgeld_ausgeben(int);


//Variables
int auswahl;
int zuzahlen;
int einwurf;
int gezahlt;
int preis;

int main()
{

    //rufen menu_ausgaben() auf
        menu_ausgaben();

    //auswahl einlesen
        auswahl = auswahl_einlesen();

    //rufen preis_erfragen auf
        preis= preis_erfragen(auswahl);

    //rufen geld_einwerfen auf
        int bezahltbetrag =  geld_einwerfen(preis);

    //rufen ruckgeld_ausgeben auf
        int zurueckgeld = bezahltbetrag-preis;
    //uberpruefen fuer das Ruckgeld
        if( zurueckgeld > 0){

            ruckgeld_ausgeben(zurueckgeld);

        }

        printf("Entnehmen Sie Ihr Getraenk.");

}

//
void menu_ausgaben (){
     // Menueausgabe
    printf("1 Cola  \t120 Cent\n");
    printf("2 Fanta  \t130 Cent\n");
    printf("3 Sprite\t150 Cent\n");
    printf("4 Eistee\t100 Cent\n");
    printf("\n");
}

int auswahl_einlesen(){

 // Auswahl einlesen
    do
    {
        printf("Ihre Auswahl: ");
        scanf("%d", &auswahl);
    } while( auswahl < 1 || auswahl > 4);


    return auswahl;

}

int preis_erfragen(int auswahl){

     // Geldanforderung
    printf("Zahlen Sie ");

    switch( auswahl)
    {
        case 1: printf("120 Cent\n");
                zuzahlen = 120;
                break;
        case 2: printf("130 Cent\n");
                zuzahlen = 130;
                break;
        case 3: printf("150 Cent\n");
                zuzahlen = 150;
                break;
        case 4: printf("100 Cent\n");
                zuzahlen = 100;
                break;
    }


    return zuzahlen;

}

int geld_einwerfen(int betrag){

 // Geldeingabe
    gezahlt = 0;

    do
    {

        printf("Einwurf (%d Cent): ", betrag - gezahlt);
        scanf("%d", &einwurf );
        gezahlt += einwurf;
    } while( gezahlt < zuzahlen);

    return gezahlt;

}

void ruckgeld_ausgeben (int gezahltgeld){

 // Geldr ckgabe

        printf("Sie erhalten %d zurueck.\n", gezahltgeld);

        printf("%d mal 200 Cent\n",gezahltgeld / 200 );
        gezahltgeld %= 200; // rueckgeld = rueckgeld % 200;

        printf("%d mal 100 Cent\n",gezahltgeld / 100 );
        gezahltgeld %= 100;

        printf("%d mal 50 Cent\n",gezahltgeld / 50 );
        gezahltgeld %= 50;

        printf("%d mal 20 Cent\n",gezahltgeld / 20 );
        gezahltgeld %= 20;

        printf("%d mal 10 Cent\n",gezahltgeld / 10 );


}

