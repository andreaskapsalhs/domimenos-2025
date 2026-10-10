#include <stdio.h>
#include <stdlib.h>

/*
    MATHIMA : DOMHMENOS PROGRAMMATISMOS
    ERGASTHRIAKH ASKHSH : 9
*/

void fillPin2D(int n, int pin[][n]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= n-1; j++) {
            pin[i][j] = rand() % 10 + 1;
        }
    }
}

void showPin2D(int n, int pin[n][n]) {
    printf("p =");
    for (int i = 0; i < n; i++) {
        printf("\n");
        for (int j = 0; j <= n-1; j++) {
            printf("%d ", pin[i][j]);
        }
    }
}

void findMeanLine(int n, float avgLine[n], int pin[][n]) {
    for (int i = 0; i < n; i++) {
        int sum = 0;
        for (int j = 0; j < n; j++) {
            sum += pin[i][j];
        }
        avgLine[i] = (float) sum/n;
    }
}

void findMeanCol(int n, float avgCol[n], int pin[][n]) {
    for (int j = 0; j < n; j++) {
        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += pin[i][j];
        }
        avgCol[j] = (float) sum/n;
    }
}

void showPinfloat1D(int n, float pin[]) {
    for (int i = 0; i < n; i++) {
        printf("%f ", pin[i]);
    }
}

int findDSum(int n, int pin[][n]) {
	int sum1D = 0;
	int sum2D = 0;
	
	for(int i = 0; i < n; i++) {
        sum1D += pin[i][i];
        sum2D += pin[i][n - 1 - i];
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

    int my2DArray[n][n];
    
    fillPin2D(n, my2DArray);
    showPin2D(n, my2DArray);

    float avgLine[n];
    float avgCol[n];
	
	findMeanLine(n, avgLine, my2DArray);
    printf("\navgLine = ");
    showPinfloat1D(n, avgLine);
    
    findMeanCol(n, avgCol, my2DArray);
    printf("\navgCol = ");
    showPinfloat1D(n, avgCol);
    
	int dSum = findDSum(n, my2DArray);
	printf("\nsum1D + sum2D = %d", dSum);

    printf("\n");
    system("pause");
    return 0;
}