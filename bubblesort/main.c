#include <stdio.h>
#include <stdlib.h>

int main()
{
    int ai[5];
    int i;
    int anzahl = sizeof(ai) / sizeof(int);
    int tausch;
    int getauscht;

    // Eingabe der Zahlen
    for (i = 0; i < anzahl; i++)
    {
        printf("%d. Zahl eingeben: ", i + 1);
        scanf("%d", &ai[i]);
    }

    // Bubble Sort
    do
    {
        getauscht = 0; // Setze anfangs "nicht getauscht"

        for (i = 0; i < anzahl - 1; i++)
        {
            if (ai[i] > ai[i + 1])
            {
                // Tausch der Werte
                tausch = ai[i];
                ai[i] = ai[i + 1];
                ai[i + 1] = tausch;

                // Markiere, dass ein Tausch stattgefunden hat
                getauscht = 1;
            }
        }
    } while (getauscht); // Wiederhole solange getauscht wurde

    // Ausgabe der sortierten Zahlen
    printf("Sortierte Zahlen:\n");
    for (i = 0; i < anzahl; i++)
    {
        printf("%d\n", ai[i]);
    }

    return 0;
}







































































