#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
    MATHIMA : DOMHMENOS PROGRAMMATISMOS
    ERGASTHRIAKH ASKHSH : 10.1
*/

typedef struct {
    char onoma[50];
    int am;
    int eidosPtyxiou;
    double yperories;
    double vasikosMisthos;
} Ypallhlos;

Ypallhlos gemismaPedion(char onoma[], int am, int eidosPtyxiou, double yperories, double vasikosMisthos) {
    Ypallhlos yp;

    strcpy(yp.onoma, onoma);
    yp.am = am;
    yp.eidosPtyxiou = eidosPtyxiou;
    yp.yperories = yperories;
    yp.vasikosMisthos = vasikosMisthos;

    return yp;
}

void findTMisthos(Ypallhlos yp) {
    double telikosMisthos = yp.vasikosMisthos + yp.yperories * 20;

    if (yp.eidosPtyxiou == 1) {
        telikosMisthos += 300;
    } else if(yp.eidosPtyxiou == 2) {
        telikosMisthos += 150;
    } else if (yp.eidosPtyxiou == 3) {
        telikosMisthos += 50;
    }

    printf("call findTMisthos() - tM = %lf \n", telikosMisthos);
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
            telikosMisthos += 50;
            break;
    }

    return telikosMisthos;
}

void emfanisiPedion(Ypallhlos yp) {
    printf("name : %s \n", yp.onoma);
    printf("aM : %d \n", yp.am);
    printf("ptyxio : %d \n", yp.eidosPtyxiou);
    printf("yperories : %lf \n", yp.yperories);
    printf("basikosMisthos : %lf \n", yp.vasikosMisthos);
}

void findMaxTM(double tm1, double tm2) {
    if (tm1 > tm2) {
        printf("TM yp1 = %lf > TM yp2 = %lf\n", tm1, tm2);
    } else {
        printf("TM yp2 = %lf > TM yp1 = %lf\n", tm2, tm1);
    }
}

void swapYp1Yp2(Ypallhlos yp1, Ypallhlos yp2) {
    Ypallhlos temp = yp1;
    yp1 = yp2;
    yp2 = temp;
}

int main(void) {
    printf("<-- ypallhlos yp1 : -->\n");
    Ypallhlos yp1 = gemismaPedion("ioannou", 191234, 1, 7, 600.0);
    emfanisiPedion(yp1);
    findTMisthos(yp1);
    double tMisthos1 = returnTMisthos(yp1);

    char onoma[50];
    int am;
    int eidosPtyxiou;
    double yperories;
    double vasikosMisthos;

    printf("\n<-- ypallhlos yp2 : -->\n");
    printf("Give name of ypallhlos 2 : ");
    scanf("%s", onoma);
    printf("Give aM of ypallhlos 2 : ");
    scanf("%d", &am);
    printf("Give ptyxio of ypallhlos 2 : ");
    scanf("%d", &eidosPtyxiou);
    printf("Give yperories of ypallhlos 2 : ");
    scanf("%lf", &yperories);
    printf("Give basikosMisthos of ypallhlos 2 : ");
    scanf("%lf", &vasikosMisthos);

    Ypallhlos yp2 = gemismaPedion(onoma, am, eidosPtyxiou, yperories, vasikosMisthos);
    emfanisiPedion(yp2);
    findTMisthos(yp2);
    double tMisthos2 = returnTMisthos(yp2);

    findMaxTM(tMisthos1, tMisthos2);

    Ypallhlos temp = yp1;
    yp1 = yp2;
    yp2 = temp;
    printf("\n<-- ypallhlos yp2 after swap yp1 yp2 : -->\n");
    emfanisiPedion(yp1);
    emfanisiPedion(yp2);

    swapYp1Yp2(yp1, yp2);
    printf("\n<-- ypallhlos yp1 after swap yp1 yp2 : -->\n");
    emfanisiPedion(yp1);
    emfanisiPedion(yp2);

    printf("\n");
    system("pause");
    return 0;
}