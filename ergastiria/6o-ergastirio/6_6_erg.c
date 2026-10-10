#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/*
    MATHIMA : DOMHMENOS PROGRAMMATISMOS
    ERGASTHRIAKH ASKHSH : 6.6
*/

int main(void) {
    int num;

    do {
        printf("Give an integer in [0,10] : ");
        scanf("%d", &num);
    } while(num < 0 || num > 10);

    int npar = 1;

    if (num != 0 && num != 1) {
        for (int i = 2; i <= num; i++) {
            npar *= i;
        }
    }

    printf("%d! = %d\n", num, npar);

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
        printf("n = %d einai protos", n);
    } else {
        printf("n = %d den einai protos", n);
    }

    printf("\n");
    system("pause");
    return 0;
}