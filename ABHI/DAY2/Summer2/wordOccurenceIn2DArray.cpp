#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

void checkOccurence(char arr[][30], int row, int column, int rowInc, int colInc, int numberOfrows, int numberOfcolumns, char* word, int position){
	if (word[position] == '\0'){
		position--;
		printf("starts at %d %d   ends at %d %d\n", row + 1, column + 1, row + rowInc*position + 1, column + colInc*position + 1);
		return;
	}
	int checkRow = row + rowInc*position;
	int checkColumn = column + colInc*position;
	if (checkColumn == numberOfcolumns || checkRow == numberOfrows || checkRow < 0 || checkColumn < 0 || arr[checkRow][checkColumn]!=word[position]){
		return;
	}
	checkOccurence(arr, row, column, rowInc, colInc, numberOfrows, numberOfcolumns, word, position+1);
}

void checkPossiblePaths(char arr[][30], int row, int column, int numberOfrows, int numberOfcolumns, char* word){
	checkOccurence(arr, row, column, 1 , 1 , numberOfrows, numberOfcolumns, word, 1);
	checkOccurence(arr, row, column, 1, -1, numberOfrows, numberOfcolumns, word, 1);
	checkOccurence(arr, row, column, -1, -1, numberOfrows, numberOfcolumns, word, 1);
	checkOccurence(arr, row, column, -1, 1, numberOfrows, numberOfcolumns, word, 1);
	checkOccurence(arr, row, column, 0, 1, numberOfrows, numberOfcolumns, word, 1);
	checkOccurence(arr, row, column, 0, -1, numberOfrows, numberOfcolumns, word, 1);
	checkOccurence(arr, row, column, -1, 0, numberOfrows, numberOfcolumns, word, 1);
	checkOccurence(arr, row, column, 1, 0, numberOfrows, numberOfcolumns, word, 1);
}

void searchOccurence(char arr[][30], int row, int column, int numberOfrows, int numberOfcolumns, char *word){
	if (arr[row][column] == word[0])
		checkPossiblePaths(arr, row, column, numberOfrows, numberOfcolumns, word);
	if (column + 1 == numberOfcolumns){
		column = 0;
		row = row + 1;
		if (row == numberOfrows)
			return;
	}
	else
		column++;
	searchOccurence(arr, row, column, numberOfrows, numberOfcolumns, word);
}

void executeWordOccurence2D(){
	char word[] = { 'c', 'a', 't', '\0'};
	char arr[3][30] = { { 't', 'a', 'c', 'a', 't' }, { 'x', 'x', 'a', 'x', 'x' }, { 'c', 'a', 't', 'a', 'c' } };
	searchOccurence(arr, 0, 0, 3, 5, word);
}