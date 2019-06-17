#include<stdio.h>
#include<stdlib.h>

#include"Header.h"

void matrixCopy(int fromMatrix[][2], int toMatrix[][2], int dimention){
	for (int i = 0; i < dimention; i++){
		for (int j = 0; j < dimention; j++)
			toMatrix[i][j] = fromMatrix[i][j];
	}
}

void matrixMultiplication(int matrix1[][2], int matrix[][2], int rows1, int columns1, int rows2, int columns2, int result[][2]){
	if (columns1 != rows2)
		return;
	for (int i = 0; i < rows1; i++){
		for (int j = 0; j < columns1; j++){
			for (int k = 0; k < columns2; k++){

			}
		}
	}
}

void matrixExponentiation(int matrix[][2], int dimention,int result[][2],int n){
	if (n == 1)
		return;
	int multipy[2][2];
	matrixExponentiation(matrix, dimention, result, n - 1);
	for (int i = 0; i < dimention; i++){
		for (int j = 0; j < dimention; j++){
			int value = 0;
			for (int k = 0; k < dimention; k++){
				value = value + matrix[i][k] * result[k][j];
			}
			multipy[i][j] = value;
		}
	}
	matrixCopy(multipy, result,dimention);
}

void executeMatrixExponentiation(){
	int matrix[][2] = { { 1, 2 }, { 3, 4 } };
	int result[2][2];
	matrixCopy(matrix, result,2);
	matrixExponentiation(matrix, 2, result, 3);
	
}