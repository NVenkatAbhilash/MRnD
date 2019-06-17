#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

void printArray(char *arr, int arraySize){
	for (int i = 0; i < arraySize; i++){
		printf("%c ", arr[i]);
	}
}

void mirrorDigits(char *arr, int arraySize, char *mirrorCharacters){
	if (arraySize == 0)
		return;
	arr[0] = mirrorCharacters[arr[0]-'0'];
	mirrorDigits(arr + 1, arraySize - 1, mirrorCharacters);
}

void executeMirrorDigits(){
	int arraySize=6;
	char arr[6] = { '1', '2', '5', '8', '9', '7' };
	char mirrorCharacters[10] = { '0', '1', '2', 'E', 'h', '5', '9', 'L', '8', '6' };
	mirrorDigits(arr, arraySize, mirrorCharacters);
	printf("\nOutput\n");
	printArray(arr, arraySize);
}