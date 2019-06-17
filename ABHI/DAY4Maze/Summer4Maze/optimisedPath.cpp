#include<stdio.h>

int minimun(int *arr, int arrSize){
	int min=arr[0];
	for (int i = 1; i < arrSize; i++){
		if (min>arr[i])
			min = arr[i];
	}
	return min;
}

bool traceOptimised(int maze[][4], int start_row, int start_column, int end_row, int end_column, int solution_matrix[][5], int number_of_rows, int number_of_columns,int distance_traversed,int minPath){
	if (start_row >= number_of_rows || start_row < 0 || start_column >= number_of_columns || start_column < 0)
		return false;
	if (solution_matrix[start_row][start_column] == 1 || maze[start_row][start_column] == -1)
		return false;
	if (start_row == end_row && start_column == end_column && minPath-1==distance_traversed){
		solution_matrix[start_row][start_column] = 1;
		return true;
	}
	solution_matrix[start_row][start_column] = 1;
	bool isMinPath;
	isMinPath = traceOptimised(maze, start_row + 1, start_column, end_row, end_column, solution_matrix, number_of_rows, number_of_columns,distance_traversed+1,minPath) ||  traceOptimised(maze, start_row, start_column + 1, end_row, end_column, solution_matrix, number_of_rows, number_of_columns, distance_traversed + 1, minPath)|| traceOptimised(maze, start_row, start_column - 1, end_row, end_column, solution_matrix, number_of_rows, number_of_columns, distance_traversed + 1, minPath)|| traceOptimised(maze, start_row - 1, start_column, end_row, end_column, solution_matrix, number_of_rows, number_of_columns, distance_traversed + 1, minPath);
	if (!isMinPath)
		solution_matrix[start_row][start_column] = 0;
	return isMinPath;
}

int solveOptimised(int maze[][4], int start_row, int start_column, int end_row, int end_column, int solution_matrix[][5], int number_of_rows, int number_of_columns){
	if (start_row >= number_of_rows || start_row < 0 || start_column >= number_of_columns || start_column < 0)
		return 999;
	if (solution_matrix[start_row][start_column] == 1 || maze[start_row][start_column] == -1)
		return 999;
	if (start_row == end_row && start_column == end_column){
		//solution_matrix[start_row][start_column] = 1;
		return 1;
	}
	solution_matrix[start_row][start_column] = 1;
	int path[4];
	path[0] = solveOptimised(maze, start_row + 1, start_column, end_row, end_column, solution_matrix, number_of_rows, number_of_columns);
	path[1] = solveOptimised(maze, start_row, start_column + 1, end_row, end_column, solution_matrix, number_of_rows, number_of_columns);
	path[2] = solveOptimised(maze, start_row, start_column - 1, end_row, end_column, solution_matrix, number_of_rows, number_of_columns);
	path[3] = solveOptimised(maze, start_row - 1, start_column, end_row, end_column, solution_matrix, number_of_rows, number_of_columns);
	solution_matrix[start_row][start_column] = 0;
	int min = minimun(path, 4) + 1;
	return  min;
}

void executeOptimisedPath(){
	int number_of_rows = 5;
	int number_of_columns = 4;
	int maze[5][4] = {
		{ 0, 0, -1, 0 },
		{ 0, 0, 0, 0 },
		{ 0, 0, -1, 0 },
		{ 0, 0, -1, 0 },
		{ 0, 0, -1, 0 } };
	int start_row = 0, start_column = 0;
	int end_row = 4, end_column = 3;
	int solution_matrix[5][5];
	for (int i = 0; i < number_of_rows; i++){
		for (int j = 0; j < number_of_columns; j++){
			solution_matrix[i][j] = 0;
		}
	}
	int path = solveOptimised(maze, start_row, start_column, end_row, end_column, solution_matrix, number_of_rows, number_of_columns);
	if (path == -1)
		printf("path not possible\n");
	else{
		traceOptimised(maze, start_row, start_column, end_row, end_column, solution_matrix, number_of_rows, number_of_columns,0,path);
		for (int i = 0; i < number_of_rows; i++){
			for (int j = 0; j < number_of_columns; j++){
				printf("%d  ", solution_matrix[i][j]);
			}
			printf("\n");
		}
	}
}