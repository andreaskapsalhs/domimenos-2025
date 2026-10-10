#include <stdio.h>

/*
	MATHIMA : DOMHMENOS PROGRAMMATISMOS
	ERGASTHRIAKH ASKHSH : 5.3
*/

int main(void) {
	int theseis = 0;
	int sum_epitirites = 0;
	int aithouses = 0;
	
	do {
		aithouses++;
				
		int xoritikotita;
		int epitirites;
		
		printf("dwse akeraio arithmo: ");
		scanf("%d", &xoritikotita);
		
		theseis = theseis + xoritikotita;
		
		if (xoritikotita <= 15) {
			epitirites = 1;
			sum_epitirites++;
		} else if (xoritikotita <= 23) {
			epitirites = 2;
			sum_epitirites = sum_epitirites + epitirites;
		} else {
			epitirites = 3;
			sum_epitirites = sum_epitirites + epitirites;
		}
		
		printf("Apaitountai %d epitirites\n", epitirites);
		
	} while (theseis<100);

	printf("\nSynolo aithouswn: %d", aithouses);
	printf("\nSynolo epitiritwn: %d", sum_epitirites);
	printf("\nSynolo thesewn: %d", theseis);

	return 0;
}