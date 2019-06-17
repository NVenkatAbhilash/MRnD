#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

#include "Header.h"


LLR *createLinkedListRandom(int data){
	LLR *newNode = (LLR*)malloc(sizeof(LLR));
	newNode->data = data;
	newNode->next = NULL;
	newNode->next = NULL;
	return newNode;
}

LLR* cloneData(LLR *head){
	if (head == NULL)
		return NULL;
	LLR *newNode = createLinkedListRandom(head->data);
	newNode->next = cloneData(head->next);
	return newNode;
}

void generateLinks(LLR *originalHead, LLR *cloneHead){
	if (originalHead == NULL)
		return ;
	LLR *tempOriginalHeadNext = originalHead->next;
	originalHead->next = cloneHead;
	LLR *tempCloneHeadNext = cloneHead->next;
	cloneHead->next = tempOriginalHeadNext;
	generateLinks(tempOriginalHeadNext, tempCloneHeadNext);
}

void pointingRandom(LLR *originalHead){
	if (originalHead == NULL)
		return;
	LLR *cloneNode = originalHead->next;
	cloneNode->random = originalHead->random->next;
	pointingRandom(originalHead->next->next);
}

void separateingLinks(LLR *originalHead, LLR* cloneHead){
	originalHead->next = cloneHead->next;
	if (originalHead->next == NULL)
		return;
	cloneHead->next = originalHead->next->next;
	separateingLinks(originalHead->next, cloneHead->next);
}

LLR *cloneLinknedList(LLR *originalHead){
	LLR* cloneHead;
	if (originalHead == NULL)
		return NULL;
	LLR* tempOriginalNode = originalHead;
	cloneHead = createLinkedListRandom(originalHead->data);
	cloneHead->next = cloneData(originalHead->next);
	generateLinks(originalHead, cloneHead);
	pointingRandom(originalHead);
	separateingLinks(originalHead, cloneHead);
	return cloneHead;
}

void executeCloneList(){
	LLR *head = NULL;
	LLR *node1 = createLinkedListRandom(1);
	LLR *node2 = createLinkedListRandom(2);
	LLR *node3 = createLinkedListRandom(3);
	LLR *node4 = createLinkedListRandom(4);
	LLR *node5 = createLinkedListRandom(5);
	LLR *node6 = createLinkedListRandom(6);
	head = node1;
	node1->next = node2;
	node2->next = node3;
	node3->next = node4;
	node4->next = node5;
	node5->next = node6;
	node1->random = node3;
	node2->random = node4;
	node3->random = node5;
	node4->random = node6;
	node5->random = node1;
	node6->random = node2;
	LLR *cloneHead = cloneLinknedList(head);
	while (head!=NULL)
	{
		if (head->random != NULL)
			printf("%d->", head->random->data);
		else
			printf("NULL->");
		head = head->next;
	}
}