#include <stdio.h>
#include <stdlib.h>

/*
    MATHIMA : DOMHMENOS PROGRAMMATISMOS
    ERGASTHRIAKH ASKHSH : 6.1
*/

int main(void) {
    int i;

    do {
        printf("Give an integer in [1,10] : ");
        scanf("%d", &i);
    } while (i > 10 || i < 1);

    for (int j=1; j<=10; j++) {
        printf("%dx%d=%d ", i,j, i*j);
    }

    printf("\n");
    system("pause");
    return 0;
}