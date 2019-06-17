#include<stdio.h>
#include<stdlib.h>

#include"Header.h"

void permutationsWithRepeatation(int *avaible, int currentState, int *prevChoioce, int terminalState){
	if (currentState == terminalState){
		for (int i = 0; i < terminalState; i++)
			printf("%d", prevChoioce[i]);
		printf("\n");
		return;
	}
	for (int i = 0; i < terminalState; i++){
//		if (avaible[i] == -1)
	//		continue;
		prevChoioce[currentState] = avaible[i];
	//	avaible[i] = -1;
		permutationsWithRepeatation(avaible, currentState + 1, prevChoioce, terminalState);
	//	avaible[i] = prevChoioce[currentState];
	}
}

void executepermutationsWithRepeatation(){
	int avaible[5] = { 2, 2, 4, 4, 5 };
	int answer[5];
	int availableSize = 5;
	availableSize = availableInDistinct(avaible, 5);
	permutationsWithRepeatation(avaible, 0, answer, availableSize);
}