#include <math.h>
#include <stdio.h>

/*
    MATHIMA : DOMHMENOS PROGRAMMATISMOS
    ERGASTHRIAKH ASKHSH : 5.5
*/

int main(void) {
    int a, b;
    printf("Dwse dyo arithmous a kai b: ");
    scanf("%d", &a);
    scanf("%d", &b);

    printf("a*b = %d", a*b);

    int p = 0;

    while (b > 0) {
        if (b % 2 == 1) {
                p = p + a;
        }
        a *= 2;
        b /= 2;

        printf("\na=%d, b=%d, p=%d", a, b ,p);
    }

    printf("\np=%d", p);

    return 0;
}