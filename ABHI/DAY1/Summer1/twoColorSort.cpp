#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>


void twoColorSort(int *arr, int size){
	int frontPointer = 0;
	int backPointer = size - 1;
	while (true){
		while (arr[frontPointer]==0)
		{
			frontPointer++;
		}
		while (arr[backPointer]==1)
		{
			backPointer--;
		}
		if (frontPointer < backPointer)
		{
			arr[frontPointer] = 0;
			arr[backPointer] = 1;
		}
		else
		{
			break;
		}
	}
}


void executeTwoColorSort(){
	int arraySize;
	printf("\ninput array size:\n");
	scanf("%d", &arraySize);
	int *arr=(int *)malloc(arraySize*sizeof(int));
	printf("\nInut Values\n");
	for (int i = 0; i < arraySize; i++){
		scanf("%d", &arr[i]);
	}
	twoColorSort(arr, arraySize);
	printf("\nOutput\n");
	for (int i = 0; i < arraySize; i++){
		printf("%d ", arr[i]);
	}
}