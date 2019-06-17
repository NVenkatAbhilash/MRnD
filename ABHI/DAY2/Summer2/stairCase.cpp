#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

long staircase(int n, int k){
	if (n < 0)
		return 0;
	if (n == 0)
		return 1;
	long sum = 0;
	for (int i = 1; i <= k; i++){
		sum += staircase(n - i, k);
	}
	return sum;
}

void executeStaircase(){
	int n ,k;
	printf("\ninput n steps and k:\n");
	scanf("%d %d", &n,&k);
	long possibleWays=0;
	if (n != 0)
		possibleWays = staircase(n,k);
	printf("\nOutput\n%d", possibleWays);
}