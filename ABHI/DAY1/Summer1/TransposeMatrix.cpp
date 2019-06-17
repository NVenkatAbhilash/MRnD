#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

void displayMatrix(int matrix[][50], int rows, int columns){
	for (int row = 0; row < rows; row++){
		for (int column = 0; column < columns; column++){
			printf("%d ", matrix[row][column]);
		}
		printf("\n");
	}
}

void transposeOfMatrix(int originalMatrix[][50], int transposeMatrix[][50], int rows,int columns){
	for (int row = 0; row < rows; row++){
		for (int column = 0; column < columns; column++){
			transposeMatrix[column][row] = originalMatrix[row][column];
		}
	}
}

void executeTransposeMatrix(){
	int rows ;
	int columns ;
	int originalMatrix[50][50];
	int transposeMatrix[50][50];
	printf("rows and columns\n");
	scanf("%d %d", &rows, &columns);
	int value;
	printf(" enter values\n");
	for (int row = 0; row < rows; row++){
		for (int column = 0; column < columns; column++){
			scanf("%d", &value);
			originalMatrix[row][column]=value;
		}
	}
	transposeOfMatrix(originalMatrix, transposeMatrix, rows, columns);
	printf("Original Matrix\n");
	displayMatrix(originalMatrix, rows, columns);
	printf("\nTranspose Matrix\n");
	displayMatrix(transposeMatrix, columns, rows);
}