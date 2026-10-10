#include <stdio.h>
#include <stdlib.h>

/*
    MATHIMA : DOMHMENOS PROGRAMMATISMOS
    ERGASTHRIAKH ASKHSH : 6.2
*/

int main(void) {
    for (int i = 1; i<=10; i++) {
        for (int j = 1; j<=10; j++) {
            printf("%dx%d=%d ", i, j, i*j);
            if (j == 10) {
                printf("\n");
            }
        }
    }
    
    printf("\n");
    system("pause");
    return 0;
}