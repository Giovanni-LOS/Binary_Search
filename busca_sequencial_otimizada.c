#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define LIM1 100000
#define LIM2 100000
#define LIM3 100000

void initArray( int array[], int len );
void seqSearch( int array[], int len, int num );
void merge(int *array, int *array1, int *array2, int num);
void mergeSort( int *array, int num );

int main() {

	int n = LIM1, q = LIM2;
	int num;
	int array[n];

	srand(time(NULL));

	initArray(array, n);
	mergeSort(array, n);
	
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
		
		if( array[i] > num ) break;

		if( array[i] == num ) {

			//printf("%d is at %d\n", num, i);
			return;
		}
	}
	//puts("Not found.");
}

void merge(int *array, int *array1, int *array2, int num) {
	
	int size_array1 = num / 2;
	int size_array2 = num - size_array1;
	int i = 0, j = 0, k = 0;

	for(;j < size_array1 && k < size_array2; i++) {
		if( array1[j] <= array2[k] ) {
			array[i] = array1[j++];
		} else {
			array[i] = array2[k++];
		}
	}

	while( j < size_array1 ) {
		array[i++] = array1[j++];
	}

	while( k < size_array2 ) {
		array[i++] = array2[k++];
	}
}

void mergeSort( int *array, int num ) {
	
	int mid;
	if( num > 1 ) {
		mid = num / 2;
		
		int *array1 = malloc(sizeof(int) * mid);
		if(array1 == NULL) {
			exit(-1);
		}
		int *array2 = malloc(sizeof(int) * num - mid);
		if(array2 == NULL) {
			exit(-1);
		}
		int i;

		for (i = 0; i<mid; i++) {
			array1[i] = array[i];
		}

		for(i = mid; i<num; i++) {
			array2[i - mid] = array[i]; 
		}

		mergeSort(array1, mid);
		mergeSort(array2, num - mid);
		merge(array,array1,array2,num);
		
		free(array1);
		free(array2);
	}
}
