#include <stdio.h>
#include <stdlib.h>

int main()
{
     /*Ausgabe von Hello World */

    for  (int zahl =1; zahl <=10; zahl++)

    {
        printf("%d\n", zahl);

        printf("%s", zahl % 2 ? "Ungerade\n" : "Gerade\n");

      /*  if (zahl % 2)
            printf("Ungerade\n");
        else
            printf("Gerade\n");

    */
    }



    return 0;
}

