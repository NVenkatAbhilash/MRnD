#include<stdio.h>

bool solve(int maze[][4], int start_row, int start_column, int end_row, int end_column, int solution_matrix[][5], int number_of_rows, int number_of_columns){
	if (start_row >= number_of_rows || start_row < 0 || start_column >= number_of_columns || start_column < 0)
		return false;
	if (solution_matrix[start_row][start_column] == 1 || maze[start_row][start_column] == -1)
		return false;
	if (start_row == end_row && start_column == end_column){
		solution_matrix[start_row][start_column] = 1;
		return true;
	}
	solution_matrix[start_row][start_column] = 1;
	bool isPossible = solve(maze, start_row + 1, start_column, end_row, end_column, solution_matrix, number_of_rows, number_of_columns) || solve(maze, start_row, start_column + 1, end_row, end_column, solution_matrix, number_of_rows, number_of_columns) || solve(maze, start_row, start_column - 1, end_row, end_column, solution_matrix, number_of_rows, number_of_columns) || solve(maze, start_row - 1, start_column, end_row, end_column, solution_matrix, number_of_rows, number_of_columns);
	if (!isPossible)
		solution_matrix[start_row][start_column] = 0;
	return isPossible;
}

void executePossilePathMaze(){
	int number_of_rows = 5;
	int number_of_columns = 4;
	int maze[5][4] = {
		{ 0, 0, 0, 0 },
		{ -1, 0, 0, 0 },
		{ 0, 0, 0, 0 },
		{ 0, 0, 0, 0 },
		{ 0, 0, 0, 0 } };
	int start_row = 0, start_column = 0;
	int end_row = 4, end_column = 3;
	int solution_matrix[5][5];
	for (int i = 0; i < number_of_rows; i++){
		for (int j = 0; j < number_of_columns; j++){
			solution_matrix[i][j] = 0;
		}
	}
	int path = solve(maze, start_row, start_column, end_row, end_column, solution_matrix, number_of_rows, number_of_columns);
	if (path == false)
		printf("path not possible\n");
	else{
		for (int i = 0; i < number_of_rows; i++){
			for (int j = 0; j < number_of_columns; j++){
				printf("%d  ", solution_matrix[i][j]);
			}
			printf("\n");
		}
	}
}