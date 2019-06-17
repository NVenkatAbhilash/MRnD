#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

long fibnocii(int n){
	if (n == 0 || n==1)
		return n;
	return fibnocii(n - 1) + fibnocii(n - 2);
}

long fibnociiHash(int *arr,int n){
	if (n == 0 || n == 1)
		arr[n] = n;
	if (arr[n] != -1)
		return arr[n];
	arr[n] = fibnociiHash(arr,n - 1) + fibnociiHash(arr,n - 2);
	return arr[n];
}

void init(int *arr, int arraySize){
	for (int i = 0; i < arraySize+1; i++)
		arr[i] = -1;
}

void executeFibnocii(){
	int n = 40;
	printf("\ninput nth fibinocii:\n");
	scanf("%d", &n);
	if (n < 0){
		printf("Invalid input");
		return;
	}
	int *arr = (int*)malloc(sizeof(int)*(n+1));
	init(arr, n);
	long answer;
	answer = fibnociiHash(arr, n);
	//answer = fibnocii(n);
	printf("Output\n%d \n", answer);
}