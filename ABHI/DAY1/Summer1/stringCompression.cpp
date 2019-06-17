#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>

int intInString(char* string, int position, int count)
{
	int lengthOfCount = 0;
	int reverseOfCount = 0;
	while (count != 0)
	{
		reverseOfCount = reverseOfCount * 10 + count % 10;
		count = count / 10;
		lengthOfCount++;
	}
	while (reverseOfCount != 0)
	{
		string[position] = '0' + reverseOfCount % 10;
		reverseOfCount = reverseOfCount / 10;
		position++;
		lengthOfCount--;
	}
	while (lengthOfCount != 0)
	{
		string[position] = '0';
		lengthOfCount--;
		position++;
	}
	return position;
}

void compressString(char *string)
{
	char ch = string[0];
	int currentPosition = 0;
	int count = 0;
	int toModifiyPosition = 0;
	while (string[currentPosition] != '\0')
	{
		if (ch == string[currentPosition])
			count++;
		else
		{
			string[toModifiyPosition] = ch;
			toModifiyPosition++;
			if (count != 1)
			{
				toModifiyPosition = intInString(string, toModifiyPosition, count);
			}
			count = 1;
			ch = string[currentPosition];
		}
		currentPosition++;
	}
	string[toModifiyPosition] = ch;
	toModifiyPosition++;
	if (count != 1)
	{
		toModifiyPosition = intInString(string, toModifiyPosition, count);
	}
	count = 1;
	string[toModifiyPosition] = '\0';
}

void executeStringCompression()
{
	char string[500];
	printf("Enter string to compress\n");
	scanf("%s", string);
	compressString(string);
	printf("Compressed String\n");
	printf("%s\n", string);
}