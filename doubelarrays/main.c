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

char geliste[][20] = {" Cola","Fanta","Sprite","Eistee"};
int gelistegrosse =sizeof(geliste)/sizeof(geliste[0]);

int  gepreis[]={120,130,150,100};
int gepreisgrosse =sizeof(gepreis)/sizeof(int);

int muenze[] = {200,100,50,20,10};
int m_grosse= sizeof(muenze)/sizeof(int);

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


    for(int i = 0;i<gelistegrosse;i++)
        printf("%d %s \t %d Cent \n",i+1, geliste[i],gepreis[i]);




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
    zuzahlen = ge
    preis[auswahl-1];

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

 // Geldr�ckgabe

        for(int i = 0; i<m_grosse;i++){


            int anzahl = gezahltgeld /muenze[i];

            if(anzahl>0){
                    printf("%d mal %d Cent\n", anzahl,muenze[i]);
            gezahltgeld%=muenze[i];

            }



        }


}



