#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


int main()
{
int i;
char hilf;
int getauscht;
char text[100];

    getauscht =-1;

    printf("gib ein wort ein: ");
    scanf("%s" , text);


int anzahl = strlen(text);


    printf("Text Laenge:%d", anzahl);

    while (getauscht == -1) {

            getauscht = 0;
    for (int i = 0; i<anzahl - 1; i++){

        if (tolower(text[i])>tolower(text[i+1])){
            hilf = text[i];
            text[i]=text[i+1];
            text[i+1]= hilf;

            getauscht = -1;
        }
    }


    }

printf("\nSortiert : %s\n", text);









}



























































