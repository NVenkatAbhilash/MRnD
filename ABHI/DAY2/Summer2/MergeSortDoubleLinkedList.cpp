#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

#include"Header.h"

DLL *createDoubleLinkedListNode(int data){
	DLL *newNode = (DLL*)malloc(sizeof(DLL));
	newNode->data = data;
	newNode->next = NULL;
	newNode->prev = NULL;
	return newNode;
}

DLL *createDoubleLinkedListThroughArray(int* arr,int arraySize){
	DLL *listHead = createDoubleLinkedListNode(arr[0]);
	DLL *iterNode = listHead;
	for (int i = 1; i < arraySize; i++){
		iterNode->next = createDoubleLinkedListNode(arr[i]);
		iterNode->next->prev = iterNode;
		iterNode = iterNode->next;
	}
	return listHead;
}

void displayDoubleLinkedList(DLL *head){
	while (head != NULL){
		printf("%d <-> ", head->data);
		head = head->next;
	}
	printf("NULL\n");
}

DLL *getKthDLL(DLL *head, int k){
	for (int i = 1; i < k; i++)
		head = head->next;
	return head;
}

int lengthOfDLL(DLL *head, DLL *endNode){
	int length = 0;
	while (head != endNode){
		head = head->next;
		length++;
	}
	return length;
}

void swapDLL(DLL *node1, DLL *node2){
	DLL *node1Prev = node1->prev;
	DLL *node2Next = node2->next;
	if (node1Prev != NULL){
		node1Prev->next = node2;
		node2->next = node1;
		node2->prev = node1;
		node1->next = node2Next;
		node1->prev = node2;
		node2Next->prev = node1;
	}
}

DLL *mergeDLL(DLL *head1, DLL *head2, int length1, int length2){
	DLL *newHead;
	if (head1->data < head2->data){
		newHead = head1;
		length1--;
		head1 = head1->next;
	}
	else
	{
		newHead = head2;
		length2--;
		head2 = head2->next;
	}
	DLL *iterNode = newHead;
	while (length1 != 0 && length2 != 0){
		if (head1->data < head2->data){
			length1--;
			iterNode->next = head1;
			head1->prev = iterNode;
		}
		else
		{
			length2--;
			iterNode->next = head2;
			head2->prev = iterNode;
		}
		iterNode = iterNode->next;
	}
	while (length1 != 0){
		length1--;
		iterNode->next = head1;
		head1->prev = iterNode;
	}
	while (length2 != 0){
		length2--;
		iterNode->next = head2;
		head2->prev = iterNode;
	}
	return newHead;
}

DLL *divideDLL(DLL *head, int length){
	if (length == 1)
		return head;
	divideDLL(head, length / 2);
	int KthNumber = length / 2 + 1;
	DLL* KhNode = getKthDLL(head, KthNumber);
	divideDLL( KhNode, length-KthNumber+1);
	return mergeDLL(head, KhNode, length / 2, length - KthNumber + 1);
}

void executeMergeSortOfDoubleLinkedList(){
	int arr[6] = { 6, 4, 2, 1, 3, 5 };
	DLL *head = createDoubleLinkedListThroughArray(arr,6);
	displayDoubleLinkedList(head);
	head = divideDLL(head, 6);
	displayDoubleLinkedList(head);
}