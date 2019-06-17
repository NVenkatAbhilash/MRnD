#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

#include"Header.h"

long recuresiveSumOfArray(int *arr, int arraySize){
	if (arraySize == 0)
		return 0;
	return arr[0] + recuresiveSumOfArray(arr + 1, arraySize - 1);
}

void  executeRecursiveSumOfArray(){
	int arraySize;
	printf("\ninput array size:\n");
	scanf("%d", &arraySize);
	int *arr = (int *)malloc(arraySize*sizeof(int));
	printf("\nInut Values\n");
	for (int i = 0; i < arraySize; i++){
		scanf("%d", &arr[i]);
	}
	long sum = recuresiveSumOfArray(arr, arraySize);
	printf("\nSum is %d\n", sum);
}