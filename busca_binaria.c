#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LIM1 10000000
#define LIM2 1000000

void initArray( int array[], int len );
void merge( int *array, int *array1, int *array2, int num );
void mergeSort( int *array, int num );
int binary_search( int array[], int sPtr, int ePtr, int num );
void busca_binaria(int* v,int n,int chave);

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

	mergeSort(array, n);
	
	for(int i = 0; i<q; i++) {

		num = rand() % LIM1;
		//busca_binaria(array, n, num);
		array2[i] = binary_search(array, 0, n - 1, num);
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

int binary_search( int array[],int sPtr, int ePtr, int num ) {
	
	if( sPtr > ePtr ) {
		// puts("Not Found.");
		return -1;
	}

	int mPtr = sPtr + ((ePtr - sPtr) / 2);
	if( array[mPtr] == num ) {
		// printf("%d is at %d.\n", num, mPtr);
		return 1;
	} else if( array[mPtr] < num ) {
		return binary_search( array, mPtr + 1, ePtr, num );
	} else {
		return binary_search( array, sPtr, mPtr - 1 , num );
	}
	
}

void busca_binaria(int* v,int n,int chave){
    int l,r,m;
    l = 0;
    r = n-1;
    while(l<=r){
        m = (l+r)/2;
        if(chave<v[m]){
            r = m-1;
        }
        else if(chave>v[m]){
            l = m+1;
        }
        else{
            return;
        }
    }
    return;
}

void merge( int *array, int *array1, int *array2, int num ) {
	
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
