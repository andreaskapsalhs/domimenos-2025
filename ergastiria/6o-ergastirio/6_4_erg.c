#include <stdio.h>
#include <stdlib.h>

/*
    MATHIMA : DOMHMENOS PROGRAMMATISMOS
    ERGASTHRIAKH ASKHSH : 6.4
*/

int main(void) {
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

    printf("%d! = %d", n, npar);

    printf("\n");
    system("pause");
    return 0;
}