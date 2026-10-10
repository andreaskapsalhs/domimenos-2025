#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
    MATHIMA : DOMHMENOS PROGRAMMATISMOS
    ERGASTHRIAKH ASKHSH : 10.2
*/

typedef struct {
    char onoma[50];
    int am;
    int eidosPtyxiou;
    int yperories;
    double vasikosMisthos;
    double tM;
} Ypallhlos;

Ypallhlos gemismaPedion(char onoma[], int am, int eidosPtyxiou, int yperories, double vasikosMisthos) {
    Ypallhlos yp;

    strcpy(yp.onoma, onoma);
    yp.am = am;
    yp.eidosPtyxiou = eidosPtyxiou;
    yp.yperories = yperories;
    yp.vasikosMisthos = vasikosMisthos;

    return yp;
}

double returnTMisthos(Ypallhlos yp) {
    double telikosMisthos = yp.vasikosMisthos + yp.yperories * 20;

    switch (yp.eidosPtyxiou) {
        case 1:
            telikosMisthos += 300;
            break;
        case 2:
            telikosMisthos += 150;
            break;
        case 3:
            telikosMisthos += 100;
            break;
        default:
            telikosMisthos += 50;
    }

    return telikosMisthos;
}

void setTMAll(Ypallhlos yp[], int n) {
    for (int i = 0; i < n; i++) {
        yp[i].tM = returnTMisthos(yp[i]);
    }
}

void emfanisiPedion(Ypallhlos yp) {
    printf("name = %s \n", yp.onoma);
    printf("aM = %d \n", yp.am);
    printf("ptyxio = %d \n", yp.eidosPtyxiou);
    printf("yperories = %lf \n", yp.yperories);
    printf("basikosMisthos = %lf \n", yp.vasikosMisthos);
    printf("telikosMisthos = %lf \n", yp.tM);
}

int returnThesiMaxTM(Ypallhlos yp[], int n) {
    double max = yp[0].tM;
    int thesiMax = 0;

    for (int i = 1; i < n; i++) {
        if (yp[i].tM > max) {
            max = yp[i].tM;
            thesiMax = i;
        }
    }

    return thesiMax;
}

void swapYp1Yp2(Ypallhlos yp1, Ypallhlos yp2) {
    Ypallhlos temp = yp1;
    yp1 = yp2;
    yp2 = temp;
}

int main(void) {
    int n;

    do {
        printf("Give n <= 50 : ");
        scanf("%d", &n);
    } while (n > 50);

    char onoma[50];
    int am;
    int eidosPtyxiou;
    int yperories;
    double vasikosMisthos;

    Ypallhlos yp[n];

    for (int i = 0; i < n; i++) {
        printf("<-- EISAGWGH STOIXEIWN YPALLHLOY [%d] -->\n", i);

        printf("Give name of ypallhlos yp[%d] : ", i);
        scanf("%s", onoma);
        printf("Give aM of ypallhlos yp[%d] : ", i);
        scanf("%d", &am);
        printf("Give ptyxio of ypallhlos yp[%d] : ", i);
        scanf("%d", &eidosPtyxiou);
        printf("Give yperories of ypallhlos yp[%d] : ", i);
        scanf("%lf", &yperories);
        printf("Give basikosMisthos of ypallhlos yp[%d] : ", i);
        scanf("%lf", &vasikosMisthos);
        printf("\n");

        yp[i] = gemismaPedion(onoma, am, eidosPtyxiou, yperories, vasikosMisthos);
    }

    setTMAll(yp, n);
    for (int i = 0; i < n; i++) {
        printf("<-- STOIXEIA YPALLHLOY [%d] -->\n", i);
        emfanisiPedion(yp[i]);
        printf("\n");
    }

    int index = rand() % (n-1);
    swapYp1Yp2(yp[index], yp[index+1]);
    printf("\npinakas after Swap yp[%d] <--> yp[%d]\n", index, index+1);
    for (int i = 0; i < n; i++) {
        printf("<-- STOIXEIA YPALLHLOY [%d] -->\n", i);
        emfanisiPedion(yp[i]);
        printf("\n");
    }

    printf("<-- STOIXEIA YPALLHLOY ME MEGISTO MISTO -->\n");
    int thesiMax = returnThesiMaxTM(yp, n);
    emfanisiPedion(yp[thesiMax]);

    printf("\n");
    system("pause");
    return 0;
}
