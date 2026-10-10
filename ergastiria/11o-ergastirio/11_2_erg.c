#include <stdio.h>
#include <stdlib.h>

/*
    MATHIMA : DOMHMENOS PROGRAMMATISMOS
    ERGASTHRIAKH ASKHSH : 11.2
*/

void fillPin2D(int n, int **pin) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= n-1; j++) {
            *(*(pin + i) + j) = rand() % 10 + 1;
        }
    }
}

void showPin2D(int n, int **pin) {
    printf("p =");
    for (int i = 0; i < n; i++) {
        printf("\n");
        for (int j = 0; j <= n-1; j++) {
            printf("%d ", *(*(pin + i) + j));
        }
    }
}

void findMeanLine(int n, double *avgLine, int **pin) {
    for (int i = 0; i < n; i++) {
        int sum = 0;
        for (int j = 0; j < n; j++) {
            sum += *(*(pin + i) + j);
        }
        *(avgLine + i) = (double) sum / n;
    }
}

void findMeanCol(int n, double *avgCol, int **pin) {
    for (int j = 0; j < n; j++) {
        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += *(*(pin + i) + j);
        }
        *(avgCol + j) = (double) sum / n;
    }
}

void showPinDouble1D(int n, double *pin) {
    for (int i = 0; i < n; i++) {
        printf("%lf ", *(pin + i));
    }
}

int findDSum(int n, int **pin) {
    int sum1D = 0;
    int sum2D = 0;

    for (int i = 0; i < n; i++) {
        sum1D += *(*(pin + i) + i);
        sum2D += *(*(pin + i) + n - 1 - i);
    }

    printf("\nsum1D = %d , sum2D = %d", sum1D, sum2D);
    return sum1D + sum2D;
}

int main(void) {
    int n;

    do {
        printf("Give an integer n > 5 : ");
        scanf("%d", &n);
    } while (n <= 5);

    int **my2DArray = malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++) {
        *(my2DArray + i) = malloc(n * sizeof(int));
    }

    fillPin2D(n, my2DArray);
    showPin2D(n, my2DArray);

    double *avgLine = malloc(n * sizeof(double));
    double *avgCol = malloc(n * sizeof(double));

    findMeanLine(n, avgLine, my2DArray);
    printf("\navgLine = ");
    showPinDouble1D(n, avgLine);

    findMeanCol(n, avgCol, my2DArray);
    printf("\navgCol = ");
    showPinDouble1D(n, avgCol);

    int dSum = findDSum(n, my2DArray);
    printf("\nsum1D + sum2D = %d", dSum);

    for (int i = 0; i < n; i++) {
        free(*(my2DArray + i));
    }
    free(my2DArray);
    free(avgLine);
    free(avgCol);

    printf("\n");
    system("pause");
    return 0;
}
