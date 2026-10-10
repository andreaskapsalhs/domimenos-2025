#include <stdio.h>

/*
	MATHIMA : DOMHMENOS PROGRAMMATISMOS
	ERGASTHRIAKH ASKHSH : 5.4
*/

int main(void) {
	int a;
	printf("Dwse arithmo:");
	scanf("%d", &a);
	
	int i = 0;
	int pos = 0;
	int neg = 0;
	
	do {
		if (!(a<=25 && a>=15)) {
			if (a >= 0) {
				pos++;
				printf("to tetragwno: %d\n", a*a);
			} else if (a<=200 && a>=100) {
				i++;
			} else if (a<0) {
				neg++;
			}
		
			printf("Dwse arithmo:");
			scanf("%d", &a);
		}
	} while (!(a<=25 && a>=15));
	
	printf("Synolo thetikwn: %d \n", pos);
	printf("Synolo arnitikwn: %d \n", neg);
	printf("Synolo arithmwn sto [100, 200]: %d", i);

	return 0;
}