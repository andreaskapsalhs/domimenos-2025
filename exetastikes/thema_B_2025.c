#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
    MATHIMA : DOMHMENOS PROGRAMMATISMOS
    ENDEIKTIKH LYSH EKSETASIS ERGASTHRIOU 15/1/2025 (THEMA B)
*/

typedef struct {
    int code;
    char custName [50];
    int custType;
    int kWH;
    double pP;
} DeiCust;

DeiCust fillCust(int kwdikos, char onomateponymo[], int eidosPelati, double katanalwsi) {
    DeiCust pelatis;

    pelatis.code = kwdikos;
    pelatis.custType = eidosPelati;
    pelatis.kWH = katanalwsi;
    // Apo tin vivliothiki: string.h (!)
    strcpy(pelatis.custName, onomateponymo);

    return pelatis; 
}

double computePoso(DeiCust customer) {
    // pagio = 5
    double poso = 5;

    switch (customer.custType) {
        case 0:
            if (customer.kWH <= 100) poso += 0.1 * customer.kWH;
            else if (customer.kWH <= 600) poso += (0.1 * 100) + (0.2 * (customer.kWH-100));
            else if (customer.kWH <= 1000) poso += (0.1 * 100) + (0.2 * 500);
            else poso += (0.1 * 100) + (0.2 * 500) + (0.3 * (customer.kWH-1000));
            break;
        case 1:
            if (customer.kWH <= 100) poso += 0.2 * customer.kWH;
            else if (customer.kWH <= 600) poso += (0.2 * 100) + (0.5 * (customer.kWH-100));
            else if (customer.kWH <= 1000) poso += (0.2 * 100) + (0.5 * 500);
            else poso += (0.2 * 100) + (0.5 * 500) + (0.8 * (customer.kWH-1000));
            break;
        case 2:
            if (customer.kWH <= 100) poso += 0.3 * customer.kWH;
            else if (customer.kWH <= 600) poso += (0.3 * 100) + customer.kWH-100;
            else if (customer.kWH <= 1000) poso += (0.3 * 100) + 500;
            else poso += (0.3 * 100) + 500 + (1.5 * (customer.kWH-1000));
            break;
    }

    return poso;
}

void showCust(DeiCust customer) {
    printf("Kwdikos= %d\n", customer.code);
    printf("Onomateponymo = %s\n", customer.custName);
    printf("Eidos = %d\n", customer.custType);
    printf("Katanalwsi = %d\n", customer.kWH);
    printf("Poso plirwmis = %lf\n", customer.pP);
}

int main(void) {
    int n;

    do {
        printf("Dwse arithmo pelatwn: ");
        scanf("%d", &n);
    } while (n < 2 || n > 15);
    
    DeiCust customers[n];

    for (int i = 0; i < n; i++) {
        int kwdikos = i+1;
        char onomateponymo[50];
        int eidosPelati;
        int katanalwsi;
        double pP;

        printf("Dwse onomateponymo pelati #%d : ", kwdikos);
        scanf("%s", onomateponymo);

        do {
            printf("Dwse eidos pelati #%d : ", kwdikos);
            scanf("%d", &eidosPelati);
        } while (eidosPelati != 0 && eidosPelati != 1 && eidosPelati != 2);

        printf("Dwse katanalwsi pelati #%d : ", kwdikos);
        scanf("%d", &katanalwsi);

        customers[i] = fillCust(kwdikos, onomateponymo, eidosPelati, katanalwsi);
    }

    for (int i = 0; i < n; i++) {
        customers[i].pP = computePoso(customers[i]);

        printf("<-- STOIXEIA PELATI #%d -->\n", customers[i].code);
        showCust(customers[i]);
    }

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (customers[j].pP < customers[j + 1].pP) {
                DeiCust temp = customers[j];
                customers[j] = customers[j + 1];
                customers[j + 1] = temp;
            }
        }
    }

    printf("\n<-- STOIXEIA SORTED PELATWN -->\n\n");
    for (int i = 0; i < 2; i++) {
        printf("<-- STOIXEIA PELATI #%d -->\n", customers[i].code);
        showCust(customers[i]);
    }

    system("pause");
    return 0;
}