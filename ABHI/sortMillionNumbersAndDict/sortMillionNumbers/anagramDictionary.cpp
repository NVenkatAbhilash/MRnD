#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include"Header.h"

void swap(char* arr, int one, int two)
{
	char temp;
	temp = arr[one];
	arr[one] = arr[two];
	arr[two] = temp;
}

void checkInDictionary(char *str, char *currentDict, FILE *f){
	if (_stricmp(str, currentDict) == 0){
		printf("%s\n", currentDict);
		return;
	}
	else if (_stricmp(str, currentDict) < 0)
		return;
	char buffer[100];
	char *ch = fgets(buffer, 100, f);
	int bufferLen;
	while (ch != NULL){
		bufferLen = strlen(buffer);
		buffer[bufferLen - 1] = '\0';
		if (_stricmp(str, buffer) == 0){
			printf("%s\n", buffer);
			break;
		}
		else if (_stricmp(str, buffer) < 0)
			break;
		ch = fgets(buffer, 100, f);
	}
	if (ch != NULL)
		strcpy(currentDict, buffer);
}

void permutationsWithRepeatation(char *avaible, int currentState, char *prevChoioce, int terminalState, char *currentDict, FILE *f){
	if (currentState == terminalState){
		checkInDictionary(prevChoioce,currentDict,f);
		return;
	}
	for (int i = 0; i < terminalState; i++){
		if (avaible[i] == -1)
			continue;
		prevChoioce[currentState] = avaible[i];
		avaible[i] = -1;
		permutationsWithRepeatation(avaible, currentState + 1, prevChoioce, terminalState,currentDict,f);
		avaible[i] = prevChoioce[currentState];
	}
}

void sortArrray(char *arr, int size)
{
	int currentIndex = 0;
	for (int i = 0; i < size-1; i++){
		for (int j = i + 1; j < size; j++){
			if (arr[i]>arr[j])
				swap(arr, i, j);
		}
	}
}

void executeAnagramDictionary(){
	printf("enter word to find anagrams\n");
	char avaible[1000];
	scanf("%s", &avaible);
	printf("Anagrams are\n");
	int inputLength = strlen(avaible);
	_strlwr(avaible);
	char *answer = (char*)malloc((inputLength+1)*sizeof(char));
	answer[inputLength] = '\0';
	sortArrray(avaible, inputLength);
	FILE *f = fopen("words.txt","r");
	char buffer[100];
	fgets(buffer, 1000, f);
	int bufferLen = strlen(buffer);
	buffer[bufferLen - 1] = '\0';
	permutationsWithRepeatation(avaible, 0, answer, inputLength,buffer,f);
}