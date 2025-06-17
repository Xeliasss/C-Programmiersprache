#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void passwortverschluss(char *);
void passwordentschluss(char *);

char passwort[30];



void passwortverschluss(char p[]){


        printf("Verschlüsselte Passwort ist: ");


       for (int i = 0;i<strlen(p); i++){

        //printf("%c", p[i]+1);
        p[i] = p[i]+1;


       }
printf("%s", p);
}

void passwordentschluss(char p[]){

       printf("\nEnchlüsseltes Passwort ist: ");


     for (int i = 0;i<strlen(p); i++){

       // printf("%c", p[i]);

        p[i] = p[i]-1;
       }


printf("%s", p);


}





int main()
{
      printf("Geben sie Passwort ein habibi: ");
      scanf("%s",  passwort);


    passwortverschluss(passwort);
    printf("\n main: Verschlüsselte Passwort ist: %s\n", passwort);
    passwordentschluss(passwort);
    printf("\n main: Endschlüsselte Passwort ist: %s", passwort);
    return 0;
}
