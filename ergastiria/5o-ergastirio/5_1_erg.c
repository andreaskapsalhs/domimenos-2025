#include <stdio.h>
#include <math.h>

/*
    MATHIMA : DOMHMENOS PROGRAMMATISMOS
	TMHMA : Τ11
	ERGASTHRIAKH ASKHSH : 5.1
*/

int main(void) {
	int num;
	printf("Dwse metavliti anamesa se 2 kai 10: ");
	scanf("%d", &num);
	
	while (num<2 || num>10) {
		printf("Dwse metavliti anamesa se 2 kai 10: ");
		scanf("%d", &num);
	}
	
	int dynami = 1;
	double apotelesma = num;
	printf("dynami = %d^%d = %f \n", num, dynami, apotelesma);

	while(apotelesma <= 100) {
		dynami++;
		
		apotelesma = pow(num, dynami);
		printf("dynami = %d^%d = %f \n", num, dynami, apotelesma);
	}
		
	return 0;
}
