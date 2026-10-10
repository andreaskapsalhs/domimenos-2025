#include <stdio.h>
#include <stdlib.h>

/*
    MATHIMA : DOMHMENOS PROGRAMMATISMOS
    ERGASTHRIAKH ASKHSH : 6.3
*/

int main(void) {
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
            printf("(2*%d-1)=%d=%d^2=%d", n, sum, n, tetragwno);
        } else {
            sum += i;
            printf("%d+", i);
        }
    }

    printf("\n");
    system("pause");
    return 0;
}