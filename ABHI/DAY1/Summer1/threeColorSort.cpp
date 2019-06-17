#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

void swapArrayValues(int *arr, int index1, int index2){
	int temp = arr[index1];
	arr[index1] = arr[index2];
	arr[index2] = temp;
}

void threeColorSort(int* arr, int arraySize){
	int index0 = 0;
	int index2 = arraySize - 1;
	int currentIndex = 0;
	if (arraySize < 2)
		return;
	while (currentIndex <= index2 && currentIndex >= index0)
	{
		if (arr[currentIndex] == 0)
		{
			swapArrayValues(arr, index0, currentIndex);
			index0++;
		}
		else if (arr[currentIndex] == 2)
		{
			swapArrayValues(arr, index2, currentIndex);
			index2--;
		}
		else
			currentIndex++;
	}
}

void executeThreeColorSort(){
	int arraySize;
	printf("\ninput array size:\n");
	scanf("%d", &arraySize);
	int *arr = (int *)malloc(arraySize*sizeof(int));
	printf("\nInut Values\n");
	for (int i = 0; i < arraySize; i++){
		scanf("%d", &arr[i]);
	}
	threeColorSort(arr, arraySize);
	printf("\nOutput\n");
	for (int i = 0; i < arraySize; i++){
		printf("%d ", arr[i]);
	}
}