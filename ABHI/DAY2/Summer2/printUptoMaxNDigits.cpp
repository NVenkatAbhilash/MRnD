#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

void printNumber(int *arr, int arraySize){
	int i = 0;
	while (arr[i]==0){
		i++;
	}
	for (; i < arraySize; i++)
	{
		printf("%d", arr[i]);
	}
	printf("\n");
}

void maxNDigits(int *prevChoice, int currentState, int terminalState){
	if (currentState == terminalState)
	{
		printNumber(prevChoice, terminalState);
		return;
	}
	for (int i = 0; i < 10; i++){
		prevChoice[currentState] = i;
		maxNDigits(prevChoice, currentState + 1, terminalState);
	}
}

void executeMaxNDigits(){
	int n;
	printf("\nenter max digits, n value:\n");
	scanf("%d", &n);
	int *arr = (int *)malloc(n*sizeof(int));
	maxNDigits(arr, 0, n);
}