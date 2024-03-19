#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define LIM1 100000
#define LIM2 1000

void initArray( int array[], int len );
int seqSearch( int array[], int len, int num );

int main() {

	int n = LIM1, q = LIM2;
	int num;
	int *array = (int*) malloc(sizeof(int)*n);
	int *array2 = (int*) malloc(sizeof(int)*q);
	clock_t start, end;
	double cpu_time_used;

	srand(time(NULL));

	initArray(array, n);
	
	start = clock();

	for(int i = 0; i<q; i++) {

		num = rand() % LIM1;
		array2[i] = seqSearch(array, n, num);
	} 

	end = clock();

	cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

	printf("%f\n", cpu_time_used);

	free(array);
	free(array2);
}

void initArray( int array[], int len ) {
	
	for(int i = 0; i<len; i++) {

		array[i] = rand() % LIM1;
	}
}

int seqSearch( int array[], int len, int num ) {
	
	for(int i = 0; i<len; i++) {

		if(array[i] == num) {

			//printf("%d is at %d\n", num, i);
			return 1;
		}
	}
	//puts("Not found.");
	return -1;
}
