#include <stdio.h>
#include <stdlib.h>

struct ListNode {
	int val;
	struct ListNode* next;
};

struct ListNode* rotateRight(struct ListNode* head, int k)
{
	struct ListNode* newHead = NULL;
	struct ListNode* rail = NULL;
	struct ListNode* newRail = NULL;
	
	rail  = head;
	newRail = head;
	while(rail->next)
	{
		rail = rail->next;
		if(k<=-1)
		{
			newRail = newRail->next;
		}
		k--;
	}
	
	rail->next = head;
	newHead = newRail->next;
	newRail->next = NULL;

	return newHead;
}

void main()
{
	struct ListNode* node1;
	struct ListNode* node2;
	struct ListNode* node3;
	struct ListNode* node4;
	struct ListNode* node5;
	struct ListNode* head;
	int k;	
	
	k=2;
	head = NULL;
	node1 = (struct ListNode*)malloc(sizeof(struct ListNode)*1);
	node2 = (struct ListNode*)malloc(sizeof(struct ListNode)*1);
	node3 = (struct ListNode*)malloc(sizeof(struct ListNode)*1);
	node4 = (struct ListNode*)malloc(sizeof(struct ListNode)*1);
	node5 = (struct ListNode*)malloc(sizeof(struct ListNode)*1);
	
	node1->val = 1;
	node2->val = 2;
	node3->val = 3;
	node4->val = 4;
	node5->val = 5;
	
	node1->next = node2;
	node2->next = node3;
	node3->next = node4;
	node4->next = node5;
	node5->next = NULL;
	
	head = rotateRight(node1, k);
	
	while(head)
	{
		printf("%d", head->val);
		head = head->next;
	}
}
