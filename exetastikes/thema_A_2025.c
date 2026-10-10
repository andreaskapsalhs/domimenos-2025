#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/*
    MATHIMA : DOMHMENOS PROGRAMMATISMOS
    ENDEIKTIKH LYSH EKSETASIS ERGASTHRIOU 15/1/2025 (THEMA A)
*/

typedef struct {
    int kwdikos;
    char onoma [50];
    int typos;
    int kathismata;
    double pwlhseis;
} Katastima;

void printstore(Katastima store) {
    printf("Kwdikos = %d\n", store.kwdikos);
    printf("Onoma = %s\n", store.onoma);
    printf("Typos = %d\n", store.typos);
    printf("Arithmos kathismatwn = %d\n", store.kathismata);
    printf("Arithmos imerision pwlhsewn = %lf\n", store.pwlhseis);
}

int seats(Katastima stores[]) {
    int sum = 0;

    for (int i = 0; i < 11; i++) {
        sum += stores[i].kathismata;
    }

    return sum;
}

double sales(int typos, Katastima stores[]) {
    double sum = 0;

    for (int i = 0; i < 11; i++) {
        if (stores[i].typos == typos) {
            sum += stores[i].pwlhseis;
        }
    }

    return sum;
}

int main(void) {
    Katastima AllStores[11];

    for (int i = 0; i < 11; i++) {
        printf("Dwse kwdiko katastimatos [%d]: ", i);
        scanf("%d", &AllStores[i].kwdikos);
        printf("Dwse onoma katastimatos [%d]: ", i);
        scanf("%s", AllStores[i].onoma);

        int typos;
        do {
            printf("Dwse typo katastimatos [%d]: ", i);
            scanf("%d", &typos);
        } while (typos != 1 && typos != 2 && typos != 3);

        AllStores[i].typos = typos;

        printf("Dwse arithmo kathismatwn katastimatos [%d]: ", i);
        scanf("%d", &AllStores[i].kathismata);
        printf("Dwse imerisies pwlhseis katastimatos [%d]: ", i);
        scanf("%lf", &AllStores[i].pwlhseis);
    }

    for (int i = 0; i < 11; i++) {
        printf("KATASTHMA [%d]\n", i);
        printstore(AllStores[i]);
    }

    int theseis = seats(AllStores);
    printf("Synolo kathismatwn: %d\n", theseis);

    int avgTheseis = theseis/2;
    printf("Mesos oros kathismatwn: %d\n", avgTheseis);

    int typos;
    do {
        printf("Dwse typo katastimatos: ");
        scanf("%d", &typos);
    } while (typos != 1 && typos != 2 && typos != 3);
    double pwlhseis = sales(typos, AllStores);
    printf("Pwlhseis typou [%d]: %lf\n", typos, pwlhseis);

    int apantisi;
    do {
        int kwdikos;
        printf("Dwse kwdikos katastimatos: ");
        scanf("%d", &kwdikos);

        bool found = false;
        int i = 0;

        while (found == false && i < 11) {
            if (AllStores[i].kwdikos == kwdikos) {
                found = true;
            } else {
                i++;
            }
        }

        if (found) {
            printstore(AllStores[i]);
        } else {
            printf("To katastima den vrethike \n");
        }

        do {
            printf("Thes na synexiseis me diaforetiko kwdiko? : ");
            scanf("%d", &apantisi);
        } while (apantisi != 0 && apantisi != 1);
    } while (apantisi != 0);

    system("pause");
    return 0;
}
