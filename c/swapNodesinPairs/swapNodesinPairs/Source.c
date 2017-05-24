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
	int i;

	if (NULL == l1)
		return l2;

	if (NULL == l2)
		return l1;

	l1List = l1;
	l2List = l2;

	i = 0;
	header = l1;
	rail = l1;
	l1 = l1->next;

	while (l1&&l2)
	{
		if (i % 2 == 0 && rail!=NULL)
		{
			rail->next = l2;
			rail = l2;
			l2 = l2->next;
		}
		else if (l1!=NULL && rail!=NULL)
		{
			rail->next = l1;
			rail = l1;
			l1 = l1->next;
		}
		i++;
	}

	while (l1)
	{
		rail->next = l1;
		rail = l1;
		l1 = l1->next;
	}

	while (l2)
	{
		rail->next = l2;
		rail = l2;
		l2 = l2->next;
	}

	return header;
}


struct ListNode* swapPairs(struct ListNode* head) {
	struct ListNode* l1;
	struct ListNode* l2;
	struct ListNode* l1Header;
	struct ListNode* l2Header;
	struct ListNode* tmp;
	struct ListNode* header;
	struct ListNode* delNode;
	int i;
	int firstFlag;

	if (NULL == head || NULL==head->next)
		return head;

	i = 0;
	firstFlag = 1;
	l1 = NULL;
	l2 = NULL;
	tmp = head;
	l1Header = NULL;
	l2Header = NULL;
	delNode = NULL;
	while (tmp)
	{
		if (firstFlag==1)
		{
			l1Header = head;
			l2Header = head->next;
			l1 = l1Header;
			l2 = l2Header;

			if (head->next!=NULL)
				tmp = (head->next)->next;
			firstFlag = 0;
			i=2;
			continue;
		}

		if (i % 2 == 0)
		{
			l1->next = tmp;
			l1 = tmp;

			if (tmp->next != NULL)
			{
				if (!tmp->next->next)
				{
					delNode = tmp;
				}
			}
			tmp = tmp->next;
		}
		else
		{
			if (l2)
				l2->next = tmp;
			l2 = tmp;
			tmp = tmp->next;
		}
		i++;
	}

	if (delNode != NULL)
	{
		delNode->next = NULL;
	}

	header = mergeTwoLists(l2Header, l1Header);

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

	l1node1->val = 1;
	l1node2->val = 2;

	l2node1->val = 3;
	l2node2->val = 4;
	l2node2->next = NULL;

	l1node1->next = l1node2;
	l1node2->next = l2node1;
	l2node1->next = NULL;

	result = swapPairs(l1node1);

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