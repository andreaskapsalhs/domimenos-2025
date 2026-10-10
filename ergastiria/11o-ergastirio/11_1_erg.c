#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/*
	MATHIMA : DOMHMENOS PROGRAMMATISMOS
	ERGASTHRIAKH ASKHSH : 11.1
*/

void swapPin(int i, int j, int *p) {
	int temp = *(p + i);
	*(p + i) = *(p + j);
	*(p + j) = temp;
}

void bubbleDesc(int n, int *pin) {
	int i, j;

	for (i = n-1; i >= 1; i--) {
		for (j = 0; j <= i-1; j++) {
			if (*(pin + j) < *(pin + j + 1)) {
				swapPin(j, j+1, pin);
			}
		}
	}
}

int searchPThesiNum(int n, int *pin, int num) {
	for (int i = 0; i <= n-1; i++) {
		if (*(pin + i) == num) {
			return i;
		}
	}

	return -1;
}

int countAvg(int n, int *pin) {
	int sum = 0;
	int plithos = 0;
	double avg;

	for (int i = 0; i <= n-1; i++) {
		sum += *(pin + i);
	}

	avg = (double) sum / n;

	for (int i = 0; i <= n-1; i++) {
		if (*(pin + i) > avg) {
			plithos++;
		}
	}

	return plithos;
}

int findThesiMin(int n, int *pin) {
	int thesMin = 0;
	int min = *pin;

	for (int i = 1; i <= n-1; i++) {
		if (*(pin + i) < min) {
			min = *(pin + i);
			thesMin = i;
		}
	}

	return thesMin;
}

int findThesiMax(int n, int *pin) {
	int thesMax = 0;
	int max = *pin;

	for (int i = 1; i <= n-1; i++) {
		if (*(pin + i) > max) {
			max = *(pin + i);
			thesMax = i;
		}
	}

	return thesMax;
}

void showPin(int n, int *pin) {
	printf("p = ");

	for (int i = 0; i <= n-1; i++) {
		printf("%d ", *(pin + i));
	}
}

void fillPin(int n, int *pin) {
	for (int i = 0; i <= n-1; i++) {
		*(pin + i) = (rand() % 10) + 1;
	}
}

int binarySearchPThesiNum(int arxi, int telos, int n, int *pin, int num) {
	int mesi;
	int thesi = -1;

	while (arxi <= telos && thesi == -1) {
		mesi = (arxi + telos) / 2;
		if (num == *(pin + mesi)) {
			thesi = mesi;
		} else if (num > *(pin + mesi)) {
			telos = mesi - 1;
		} else {
			arxi = mesi + 1;
		}
	}

	return thesi;
}

int binarysearchPThesiNumRec(int arxi, int telos, int *pin, int num) {
	if (arxi > telos) {
		return -1;
	}

	int mesi = (arxi + telos) / 2;
	if (num == *(pin + mesi)) {
		return mesi;
	} else if (num > *(pin + mesi)) {
		return binarysearchPThesiNumRec(arxi, mesi - 1, pin, num);
	} else {
		return binarysearchPThesiNumRec(mesi + 1, telos, pin, num);
	}
}

int binarysearchPThesiNumREcPointers(int *pin, int n, int thesi, int num) {
	if (n <= 0) {
		return -1;
	}

	int mesi = n / 2;
	if (num == *(pin + mesi)) {
		return thesi + mesi;
	} else if (num > *(pin + mesi)) {
		return binarysearchPThesiNumREcPointers(pin, mesi, thesi, num);
	} else {
		return binarysearchPThesiNumREcPointers(pin + mesi + 1, n - mesi - 1, thesi + mesi + 1, num);
	}
}

int main(void) {
	int n;

	do {
		printf("Give an integer n > 5 : ");
		scanf("%d", &n);
	} while (n <= 5);

	int *pin = malloc(n * sizeof(int));

	fillPin(n, pin);
	showPin(n, pin);

	int sum = 0;
	for (int i = 0; i < n; i++) {
		sum += *(pin + i);
	}

	int thesiMax = findThesiMax(n, pin);
	int thesiMin = findThesiMin(n, pin);
	int plithos = countAvg(n, pin);
	double avg = (double) sum / n;

	printf("\nmax = %d thesiMax = %d", *(pin + thesiMax), thesiMax);
	printf("\nmin = %d thesiMin = %d", *(pin + thesiMin), thesiMin);
	printf("\navg = %lf", avg);
	printf("\ncount avg = %d", plithos);

	int num;
	printf("\nGive an integer num : ");
	scanf("%d", &num);
	int thesi = searchPThesiNum(n, pin, num);
	if (thesi != -1) {
		printf("Found num = %d in position %d, p[%d] = %d", num, thesi, thesi, *(pin + thesi));
	} else {
		printf("NOT FOUND");
	}

	bubbleDesc(n, pin);
	showPin(n, pin);

	printf("\nGive an integer num : ");
	scanf("%d", &num);
	thesi = binarySearchPThesiNum(0, n-1, n, pin, num);
	if (thesi != -1) {
		printf("Found num = %d in position %d, p[%d] = %d", num, thesi, thesi, *(pin + thesi));
	} else {
		printf("NOT FOUND");
	}

	thesi = binarysearchPThesiNumRec(0, n-1, pin, num);
	if (thesi != -1) {
		printf("\nFound num = %d in position %d, p[%d] = %d", num, thesi, thesi, *(pin + thesi));
	} else {
		printf("\nNOT FOUND");
	}

	thesi = binarysearchPThesiNumREcPointers(pin, n, 0, num);
	if (thesi != -1) {
		printf("\nFound num = %d in position %d, p[%d] = %d", num, thesi, thesi, *(pin + thesi));
	} else {
		printf("\nNOT FOUND");
	}

	int index = rand() % (n-1);
	swapPin(index, index+1, pin);
	printf("\nswap p[%d], p[%d]", index, index + 1);
	showPin(n, pin);

	free(pin);
	printf("\n");
	system("pause");
	return 0;
}
