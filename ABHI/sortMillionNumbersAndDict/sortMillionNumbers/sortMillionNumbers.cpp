#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

void putNumbers(char* fileName){
	FILE *fileToRead = fopen(fileName, "r");
	FILE *fileToWrite = fopen("sorted.txt", "w");
	char ch = fgetc(fileToRead);
	int number = 0;
	while (ch != -1)
	{
		if (ch == '1')
			fprintf(fileToWrite, "%d\n", number);
		ch = fgetc(fileToRead);
		number++;
	}
	fclose(fileToRead);
	fclose(fileToWrite);
}

void sortFile(char *oldFileName, FILE *inputFile){
	char buffer[10];
	char *ch = fgets(buffer, 10, inputFile);
	FILE *oldFile = fopen(oldFileName, "r+");
	int number;
	sscanf(buffer, "%d", &number);
	int count = 0;
	while (ch != NULL){
		fseek(oldFile, sizeof(char)*number, SEEK_SET);
		fputc('1', oldFile);
		ch = fgets(buffer, 10, inputFile);
		sscanf(buffer, "%d", &number);
	}
	fclose(oldFile);
	putNumbers(oldFileName);
	return;
}

void initFile(char *fileName){
	FILE *f = fopen(fileName, "w");
	for (int i = 0; i < 1000000; i++){
		fputs("0000000000", f);
	}
	fclose(f);
}

int executeSortMillion(){
	char fileName[20] = "input.txt";
	FILE *f = fopen(fileName, "r");
	initFile("samp1.txt");
	sortFile("samp1.txt", f);
	fclose(f);
	return 0;
}
