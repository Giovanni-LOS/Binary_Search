#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define LIM1 10000000
#define LIM2 100000000

void initArray( int array[], int len );
void seqSearch( int array[], int len, int num );

int main() {

	int n = LIM1, q = LIM2;
	int num;
	int *array = (int*) malloc(sizeof(int)*n);
	clock_t start, end;
	double cpu_time_used;

	srand(time(NULL));

	initArray(array, n);
	
	start = clock();

	for(int i = 0; i<q; i++) {

		num = rand() % LIM1;
		seqSearch(array, n, num);
	}

	end = clock();

	cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

	printf("%f\n", cpu_time_used);
}

void initArray( int array[], int len ) {
	
	for(int i = 0; i<len; i++) {

		array[i] = rand() % LIM1;
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
