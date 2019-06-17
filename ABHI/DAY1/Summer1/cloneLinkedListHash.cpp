#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

#include "Header.h"





void executeCloneListHash(){
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
	//LLR *cloneHead = cloneLinknedListHash(head);
	while (head != NULL)
	{
		if (head->random != NULL)
			printf("%d->", head->random->data);
		else
			printf("NULL->");
		head = head->next;
	}
}