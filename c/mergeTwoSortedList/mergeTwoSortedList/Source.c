#include <stdio.h>
#include <stdlib.h>


struct ListNode {
	int val;
	struct ListNode *next;
};

struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
	struct ListNode* header;
	struct ListNode* rail;
	struct ListNode* l1List;
	struct ListNode* l2List;
	int fristFlag = 1;

	if (NULL == l1)
		return l2;

	if (NULL == l2)
		return l1;
	
	l1List = l1;
	l2List = l2;

	if (l1List->val < l2List->val)
	{
		header = l1List;
		rail = l1List;
		l1List = l1List->next;
	}
	else
	{
		header = l2List;
		rail = l2List;
		l2List = l2List->next;
	}

	while (l1List != NULL && l2List !=NULL)
	{
		if (l1List->val < l2List->val)
		{
			rail->next = l1List;
			rail = l1List;
			l1List = l1List->next;
		}
		else
		{
			rail->next = l2List;
			rail = l2List;
			l2List = l2List->next;
		}

		if (fristFlag==1)
		{
			header->next = rail;
		}

		fristFlag = 0;
	}

	while (l1List)
	{
		rail->next = l1List;
		rail = l1List;
		l1List = l1List->next;
	}

	while (l2List)
	{
		rail->next = l2List;
		rail = l2List;
		l2List = l2List->next;
	}

	return header;
}

void main()
{
	struct ListNode* l1node1;
	struct ListNode* l1node2;
	struct ListNode* l2node1;
	struct ListNode* l2node2;
	struct ListNode* result;

	l1node1 = (struct ListNode*)malloc(sizeof(struct ListNode));
	l1node2 = (struct ListNode*)malloc(sizeof(struct ListNode));
	l2node1 = (struct ListNode*)malloc(sizeof(struct ListNode));
	l2node2 = (struct ListNode*)malloc(sizeof(struct ListNode));
	
	l1node1->val = 2;
	l1node2->val = 4;
	l1node1->next = l1node2;
	l1node2->next = NULL;
	
	l2node1->val = 1;
	l2node2->val = 5;
	l2node1->next = l2node2;
	l2node2->next = NULL;

	result = mergeTwoLists(l1node1,l2node1);

	while (result)
	{
		printf("%d", result->val);
		result = result->next;
	}

	free(l1node1);
	free(l2node2);
	free(l1node2);
	free(l2node1);
}