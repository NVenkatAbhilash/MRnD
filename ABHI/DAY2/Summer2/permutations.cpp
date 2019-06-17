#include<stdio.h>
#include<stdlib.h>

void swapArrayValues(int *arr, int position1, int position2){
	int temp = arr[position1];
	arr[position1] = arr[position2];
	arr[position2] = temp;
}

int availableInDistinct(int *arr, int arraySize){
	for (int i = 0; i < arraySize-1; i++){
		for (int j = i; j < arraySize; j++){
			if (i != j && arr[i] == arr[j] && arr[i] != -1){
				swapArrayValues(arr, i, arraySize-1);
				arraySize--;
			}
		}
	}
	return arraySize;
}

void permutations(int *avaible, int currentState,int *prevChoioce, int terminalState){
	if (currentState == terminalState){
		for (int i = 0; i < terminalState; i++)
			printf("%d", prevChoioce[i]);
		printf("\n");
		return;
	}
	for (int i = 0; i < terminalState; i++){
		if (avaible[i] == -1)
			continue;
		prevChoioce[currentState] = avaible[i];
		avaible[i] = -1;
		permutations(avaible, currentState + 1, prevChoioce, terminalState);
		avaible[i] = prevChoioce[currentState];
	}
}

void executePermutations(){
	int avaible[5] = { 2, 2, 4, 4, 5};
	int answer[5];
	int availableSize = 5;
	availableSize = availableInDistinct(avaible, 5);
	permutations(avaible, 0, answer, availableSize);
}