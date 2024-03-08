#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define LIM1 100000
#define LIM2 100000
#define LIM3 100000

void initArray( int array[], int len );
void seqSearch( int array[], int len, int num );

int main() {

	int n = LIM1, q = LIM2;
	int num;
	int array[n];

	srand(time(NULL));

	initArray(array, n);

	for(int i = 0; i<q; i++) {

		num = rand() % LIM3;
		seqSearch(array, n, num);
	}
}

void initArray( int array[], int len ) {
	
	for(int i = 0; i<len; i++) {

		array[i] = rand() % LIM3;
	}
}

void seqSearch( int array[], int len, int num ) {
	
	for(int i = 0; i<len; i++) {

		if(array[i] == num) {

			//printf("%d is at %d\n", num, i);
			return;
		}
	}
	//puts("Not found.");
}
