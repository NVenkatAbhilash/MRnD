#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

#include "Header.h"

SLL* getLastNode( SLL *head){
	if (head == NULL)
		return NULL;
	while (head->next!=NULL)
	{
		head = head->next;
	}
	return head;
}

SLL *detectMeetingPointNode(SLL *head){
	SLL *slowPointer = head;
	SLL *fastPointer = head->next;
	int kthNode = 0;
	while (true){
		if (slowPointer != fastPointer)
			kthNode ++;
		for (int move = 0; move < 2 * kthNode; move++){
			if (slowPointer == fastPointer)
				return slowPointer;
			fastPointer = fastPointer->next;
		}
		slowPointer = slowPointer->next;
	}
	return slowPointer;
}

int lengthOfLinkedListWithSpecialEndNode(SLL *head, SLL* endNode = NULL){
	int length = 0;
	while (head != endNode){
		head = head->next;
		length++;
	}
	return length;
}

SLL *getYJunctionNode(SLL* head1, SLL* head2, SLL* endNode = NULL){
	int lenght1 = lengthOfLinkedListWithSpecialEndNode(head1, endNode);
	int length2 = lengthOfLinkedListWithSpecialEndNode(head2, endNode);
	int diff=lenght1-length2;
	if (diff > 0){
		head1 = getKthNode(diff+1, head1);
	}
	else
		head2 = getKthNode(diff*-1+1, head2);
	while (head1 != head2){
		head1 = head1->next;
		head2 = head2->next;
	}
	return head1;
}

void executeLinkDetection(){
	SLL* head = linkedListCreation();
	if (head == NULL)
		return;
	printf("connect to Kth node,k value:\n");
	int k;
	scanf("%d", &k);
	SLL *lastNode = getLastNode(head);
	SLL *KthNode = getKthNode(k, head);
	lastNode->next = KthNode;
	SLL* meetingNode = detectMeetingPointNode(head);
	printf("Meeting Node is : %d\n", meetingNode->data);
	SLL* junctionNode = getYJunctionNode(head, meetingNode->next, meetingNode);
	if (KthNode == junctionNode)
		printf("Junction node found\nIt is : %d", junctionNode->data);
}
