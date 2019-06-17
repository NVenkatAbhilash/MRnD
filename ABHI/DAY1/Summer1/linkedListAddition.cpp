#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

#include "Header.h"

SLL *linkedListFromArray(int *arr, int arrSize){
	if (arrSize == 0)
		return NULL;
	SLL *head = createNode(arr[0]);
	SLL *iterNode = head;
	for (int i = 1; i < arrSize; i++){
		iterNode->next = createNode(arr[i]);
		iterNode = iterNode->next;
	}
	return head;
}

int lengthOfLinkedList(SLL *head){
	int length = 0;
	while (head != NULL){
		head = head->next;
		length++;
	}
	return length;
}

SLL *recursiveSum(SLL *numberHead1, SLL *numberHead2, int *carry){
	if (numberHead1 == NULL)
		return NULL;
	SLL *nextNode = recursiveSum(numberHead1->next, numberHead2->next, carry);
	SLL *newNode;
	int sum = numberHead1->data + numberHead2->data + *carry;
	*carry = sum / 10;
	newNode = createNode(sum % 10);
	newNode->next = nextNode;
	return newNode;
}

SLL *numberAdditionToList(SLL *head, int *number, SLL *endNode){
	if (head == endNode)
		return NULL;
	SLL *nextNode = numberAdditionToList(head->next, number, endNode);
	SLL *newNode;
	int sum = head->data + *number;
	*number = sum / 10;
	newNode = createNode(sum % 10);
	newNode->next = nextNode;
	return newNode;
}

SLL *LinkedListSum(SLL *numberLinkedList1, SLL *numberLinkedList2){
	int carry = 0;
	int lengthOfLinkedList1 = lengthOfLinkedList(numberLinkedList1);
	int lengthOfLinkedList2 = lengthOfLinkedList(numberLinkedList2);
	int diff = lengthOfLinkedList1 - lengthOfLinkedList2;
	SLL *addHead1 = numberLinkedList1;
	SLL *addHead2 = numberLinkedList2;
	if (diff > 0)
		addHead1 = getKthNode(diff + 1, addHead1);
	else
		addHead2 = getKthNode(diff*-1 + 1, addHead2);
	SLL *recursionHead = recursiveSum(addHead1, addHead2, &carry);
	SLL *numberHead;
	if (diff > 0){
		numberHead = numberAdditionToList(numberLinkedList1, &carry, addHead1);
	}
	else if (diff < 0)
		numberHead = numberAdditionToList(numberLinkedList2, &carry, addHead2);
	else
		numberHead = recursionHead;
	if (carry != 0){
		SLL *carryNode = createNode(carry);
		carryNode->next = numberHead;
		numberHead = carryNode;
	}
	if (diff != 0){
		SLL *numberHeadLastNode = getLastNode(numberHead);
		numberHeadLastNode->next = recursionHead;
		return numberHead;
	}
}

void executeLinkedListAddition(){
	SLL *numberLinkedList1, *numberLinkedList2;
	printf("enter first number, plese provide space between each digit\n");
	numberLinkedList1 = linkedListCreation();
	printf("enter second number, plese provide space between each digit\n");
	numberLinkedList2 = linkedListCreation();
	/*int numberInArray1[4] = { 3, 4, 5, 6 };
	int numberInArray2[3] = { 6, 7, 8 };
	numberLinkedList1 = linkedListFromArray(numberInArray1, 4);
	numberLinkedList2 = linkedListFromArray(numberInArray2, 3);*/
	SLL *sumOfLinkedLists = LinkedListSum(numberLinkedList1, numberLinkedList2);
	displayLinkedList(sumOfLinkedLists);
}