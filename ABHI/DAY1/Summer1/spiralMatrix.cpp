#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

void spiralToArray(int matrix[][30], int rows, int columns, int arr[50]){
	int sizeOfArray = rows*columns;
	int index = 0;
	int rowInc;
	int colInc=-1;
	rows = rows - 1;
	int row = 0, col = -1;
	for (int i = 0; i < sizeOfArray; i++){
		rowInc = 0;
		colInc = 1;
		for (int j = 0; j < columns; j++){
			col = col + colInc;
			arr[index] = matrix[row][col];
			index++;
		}
		columns--;
		rowInc = 1;
		colInc = 0;
		for (int k = 0; k < rows; k++){
			row = row + rowInc;
			arr[index] = matrix[row][col];
			index++;
		}
		rows--;
		rowInc = 0;
		colInc = -1;
		for (int j = 0; j < columns; j++){
			col = col + colInc;
			arr[index] = matrix[row][col];
			index++;
		}
		columns--;
		rowInc = -1;
		colInc = 0;
		colInc = 0;
		for (int k = 0; k < rows; k++){
			row = row + rowInc;
			arr[index] = matrix[row][col];
			index++;
		}
		rows--;
	}
}

void displayArray(int arr[], int size){
	for (int i = 0; i < size; i++)
		printf("%d ", arr[i]);
}

void executeSpiralMatrix(){
	int rows ;
	int columns ;
	int matrix[30][30];
	printf("rows and columns\n");
	scanf("%d %d", &rows, &columns);
	int value;
	printf(" enter values\n");
	for (int row = 0; row < rows; row++){
		for (int column = 0; column < columns; column++){
			scanf("%d", &value);
			matrix[row][column] = value;
		}
	}
	int arr[50];
	spiralToArray(matrix, rows, columns, arr);
	displayArray(arr, rows*columns);
}