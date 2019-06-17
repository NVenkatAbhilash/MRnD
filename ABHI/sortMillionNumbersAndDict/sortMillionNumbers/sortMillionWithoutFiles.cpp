#define _CRT_SECURE_NO_WARNINGS
#include<stdlib.h>
#include<stdio.h>

void printNumbers(bool *storeNumbers[]){
	FILE *fileToWrite = fopen("sortedWithoutFiles.txt", "w");
	int number = 0;
	for (int i = 0; i < 10;i++){
		bool *checkNumber = storeNumbers[i];
		for (int j = 0; j < 1000000; j++){
			if (checkNumber[j]==true)
				fprintf(fileToWrite, "%d\n", number);
			number++;
		}
		
	}
	fclose(fileToWrite);
}

void sort(bool *storeNumber[], FILE *inputFile){
	char buffer[10];
	char *ch = fgets(buffer, 10, inputFile);
	int number;
	sscanf(buffer, "%d", &number);
	int count = 0;
	int storeIndex;
	bool *checkNumber;
	while (ch != NULL){
		storeIndex = number / 1000000;
		int deduce = storeIndex * 1000000;
		number = number -  deduce;
		checkNumber = storeNumber[storeIndex];
		checkNumber[number] = true;
		ch = fgets(buffer, 10, inputFile);
		sscanf(buffer, "%d", &number);
	}
	return;
}

void initNumberArray(bool *markNumber){
	for (int i = 0; i < 1000000; i++)
		markNumber[i] = false;
}

int executeSortMillionWithoutFiles(){
	char fileName[20] = "input.txt";
	FILE *f = fopen(fileName, "r");
	
	bool *storeNumbers[10];
	for (int i = 0; i < 10; i++){
		bool *markNumber = (bool *)malloc(1000000 * (sizeof(bool)));
		initNumberArray(markNumber);
		storeNumbers[i] = markNumber;
	}
	sort(storeNumbers, f);
	printNumbers(storeNumbers);
	fclose(f);
	return 0;
}
