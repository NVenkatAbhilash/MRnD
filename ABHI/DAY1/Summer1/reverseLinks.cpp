#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

#include "Header.h"

SLL* createNode(int data){
	SLL *newNode = (SLL*)malloc(sizeof(SLL));
	newNode->data = data;
	newNode->next = NULL;
	return newNode;
}

SLL* linkedListCreation(){
	SLL *head;
	int numberOfNodes;
	printf("number of Nodes\n");
	scanf("%d", &numberOfNodes);
	if (numberOfNodes == 0){
		printf("NULL");
		return NULL;
	}
	int value;
	printf("enter nodes\n");
	scanf("%d", &value);
	head = createNode(value);
	SLL *tempNode = head;
	for (int i = 1; i < numberOfNodes; i++){
		scanf("%d", &value);
		tempNode->next = createNode(value);
		tempNode = tempNode->next;
	}
	return head;
}

SLL* getKthNode(int k, SLL *head){
	for (int i = 1; i < k; i++)
	{
		if (head == NULL)
			return NULL;
		head = head->next;
	}
	return head;
}


SLL* connector(int k, SLL *head){
	SLL *tempHead = head;
	SLL *tempLink;
	SLL *KthNext = NULL;
	if (head == NULL)
		return NULL;
	tempLink = getKthNode(k, tempHead);
	if (tempLink != NULL){
		head = tempLink;
		KthNext = head->next;
		for (int i = k - 1; i > 1; i--){
			tempLink->next = getKthNode(i, tempHead);
			tempLink = tempLink->next;
		}
	}
	else
		return head;
	tempLink->next = tempHead;
	tempHead->next = KthNext;
	tempHead->next=connector(k, tempHead->next);
	return head;
}

void displayLinkedList(SLL *head){
	while (head != 0){
		printf("%d->", head->data);
		head = head->next;
	}
	printf("NULL\n");
}

void executeReverseLinks(){
	int k;
	SLL *head = NULL;
	printf("k value \n");
	scanf("%d",&k);
	head = linkedListCreation();
	head=connector(k,head);
	displayLinkedList(head);
}