#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/*
    MATHIMA : DOMHMENOS PROGRAMMATISMOS
    ERGASTHRIAKH ASKHSH : 6.7
*/

int findAthroismaPeritton() {
    int n;

    do {
        printf("Give an integer in [5,20] : ");
        scanf("%d", &n);
    } while(n < 5 || n > 20);

    int tetragwno = n*n;
    int sum = 0;

    for (int i = 1; i <= 2*n-1; i+=2) {
        if (i == 2*n-1) {
            sum += i;
            printf("(2*%d-1)=%d=%d^2=%d \n", n, sum, n, tetragwno);
        } else {
            sum += i;
            printf("%d+", i);
        }
    }

    return sum;
}

int findParagontiko() {
    int n;

    do {
        printf("Give an integer in [0,10] : ");
        scanf("%d", &n);
    } while(n < 0 || n > 10);

    int npar;

    if (n != 0 && n != 1) {
        npar = 1;
        for (int i = 2; i <= n; i++) {
            npar *= i;
        }
    } else {
        npar = 1;
    }

    printf("%d! = %d \n", n, npar);

    return npar;
}

bool isProtos() {
    int n;

    do {
        printf("Give an integer in [2,100] : ");
        scanf("%d", &n);
    } while(n < 2 || n > 100);

    bool protos = true;

    for (int i = 2; i <= n/2; i++) {
        if (n % i == 0) {
            protos = false;
        }
    }

    if (protos == true) {
        printf("n = %d einai protos \n", n);
    } else {
        printf("n = %d den einai protos \n", n);
    }

    return protos;
}

int main(void) {

    findAthroismaPeritton();
    findParagontiko();
    isProtos();

    printf("\n");
    system("pause");
    return 0;
}