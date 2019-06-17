#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

long long powerOfNumber(long long number, long long power){
	if (power == 0)
		return 1;
	if (power % 2 == 0)
		return ((powerOfNumber(number, power / 2) % 1000000) * (powerOfNumber(number, power / 2) % 1000000)) % 1000000000000000;
	else
		return ((powerOfNumber(number, power / 2) % 1000000)*(powerOfNumber(number, power / 2) % 1000000)* number) % 1000000000000000;
}

void executePowerOfNumber(){
	long long number = 9999999;
	long long power = 99999;
	printf("%d", powerOfNumber(number, power));
}