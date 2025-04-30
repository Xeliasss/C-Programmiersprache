#include <stdio.h>
#include <stdlib.h>

// Funktionsdeklaration
int potenz(int, int);

int main() {
    int basis, exponent;

    printf("Basis Zahl: ");
    scanf("%d", &basis);

    printf("Exponent Zahl: ");
    scanf("%d", &exponent);

    int ergebnis = potenz(basis, exponent);  // ✅ Jetzt korrekt berechnet

    printf("%d hoch %d ist: %d\n", basis, exponent, ergebnis);

    return 0;
}

// Funktionsdefinition
int potenz(int basis, int exponent) {
    int ergebnis = 1;
    for (int i = 1; i <= exponent; i++) {
        ergebnis *= basis;
    }
    return ergebnis;
}
