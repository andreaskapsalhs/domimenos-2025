#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/*
	MATHIMA : DOMHMENOS PROGRAMMATISMOS
	ERGASTHRIAKH ASKHSH : 7.1
*/

void swapPin(int i, int j, int p[]) {
	int temp = p[i];
	p[i] = p[j];
	p[j] = temp;
}

void bubbleDesc(int n, int pin[]) {
	int i, j;

	for (i = n-1; i >= 1; i--) {
		for(j=0; j <= i-1; j++) {
			if(pin[j] < pin[j+1]) {
				swapPin(j, j+1, pin);
			}
		}
	}
}

void searchPThesiNum(int n, int pin[], int num) {
	bool found = false;
	int thesi = -1;

	for (int i = 0; i <= n-1; i++) {
		if(pin[i] == num) {
			found = true;
			thesi = i;
		}
	}

	if(found == true) {
		printf("Found num = %d in position %d, p[%d] = %d", num, thesi, thesi, num);
	} else {
		printf("NOT FOUND");
	}
}

int countAvg(int n, int pin[]) {
	int sum = 0;
	int plithos = 0;
	double avg;

	for (int i = 1; i<= n-1; i++) {
		sum += pin[i];
	}

	avg = sum/n;

	for (int i = 1; i<= n-1; i++) {
		if(pin[i] > avg) {
			plithos++;
		}
	}

	return plithos;
}

int findThesiMin(int n, int pin[]) {
	int thesMin = 0;
	int min = pin[0];

	for (int i = 1; i<= n-1; i++) {
		if (pin[i] < min) {
			min = pin[i];
			thesMin = i;
		}
	}

	return thesMin;
}

int findThesiMax(int n, int pin[]) {
	int thesMax = 0;
	int max = pin[0];

	for (int i = 1; i<= n-1; i++) {
		if (pin[i] > max) {
			max = pin[i];
			thesMax = i;
		}
	}

	return thesMax;
}

void showPin(int n, int pin[]) {
	printf("p = ");

	for (int i = 0; i<=n-1; i++) {
		printf("%d ", pin[i]);
	}
}

void fillPin(int n, int pin[]) {
	for (int i = 0; i<=n-1; i++) {
		pin[i] = (rand() % 10) + 1;
	}
}

void binarySearchPThesiNum(int arxi, int telos, int n, int pin[], int num) {
	int mesi;
	int thesi = -1;
	bool found = false;
	
	while (arxi<=telos && thesi == -1) {
		mesi = (arxi+telos)/2;
		if (num == pin[mesi]) {
			found = true;
			thesi = mesi;
		}
		else if (num > pin[mesi]) {
			telos = mesi-1;
		}
		else {
			arxi = mesi+1;
		}
	}
	
	if(found == true) {
		printf("Found num = %d in position %d, p[%d] = %d", num, thesi, thesi, num);
	} else {
		printf("NOT FOUND");
	}
}

int main(void) {
	int n;

	do {
		printf("Give an integer n > 5 : ");
		scanf("%d", &n);
	} while (n <= 5);

	int pin[n];

	fillPin(n, pin);
	showPin(n, pin);

	int sum = 0;
	for (int i = 0; i < n; i++) {
		sum += pin[i];
	}
	
	int thesiMax = findThesiMax(n, pin);
	int thesiMin = findThesiMin(n, pin);
	int plithos = countAvg(n, pin);
	double avg = (double) sum/ n;

	printf("\nmax = %d thesiMax = %d", pin[thesiMax], thesiMax);
	printf("\nmin = %d thesiMin = %d", pin[thesiMin], thesiMin);
	printf("\navg = %lf", avg);
	printf("\ncount avg = %d", plithos);

	int num;
	int apantisi;

	do {
		printf("\nGive an integer num : ");
		scanf("%d", &num);
		searchPThesiNum(n, pin, num);

		printf("\nThes na anazitiseis kiallon arithmo? (1 gia nai, 0 gia oxi): ");
		scanf("%d", &apantisi);
	} while (apantisi == 1);

	bubbleDesc(n, pin);
	showPin(n, pin);
	
	do {
		printf("\nGive an integer num : ");
		scanf("%d", &num);
		binarySearchPThesiNum(0, n-1, n, pin, num);

		printf("\nThes na anazitiseis kiallon arithmo? (1 gia nai, 0 gia oxi): ");
		scanf("%d", &apantisi);
	} while (apantisi == 1);
	
	int index = (rand() % n-2);
	swapPin(index, index+1, pin);
	printf("\nswap p[%d], p[%d]", index, index + 1);
	showPin(n, pin);

	printf("\n");
	system("pause");
}
