#include <stdio.h>
#include <stdlib.h>

struct ListNode {
	int val;
	struct ListNode *next;
};


struct ListNode* swapPairs(struct ListNode* head) {
	struct ListNode* pre;
	struct ListNode* dummy;
	struct ListNode* cur;

	pre = (struct ListNode*)malloc(sizeof(struct ListNode));
	if (NULL == pre)
		return NULL;

	dummy = pre;
	cur = head;

	while (cur && cur->next)
	{
		pre->next = cur->next;
		cur->next = pre->next->next;
		pre->next->next = cur;
		pre = cur;
		cur = cur->next;
	}

	return dummy->next;
}

void main()
{
	struct ListNode* l1node1;
	struct ListNode* l1node2;
	struct ListNode* l2node1;
	struct ListNode* l2node2;
	struct ListNode* l2node3;
	struct ListNode* result;

	l1node1 = (struct ListNode*)malloc(sizeof(struct ListNode));
	l1node2 = (struct ListNode*)malloc(sizeof(struct ListNode));
	l2node1 = (struct ListNode*)malloc(sizeof(struct ListNode));
	l2node2 = (struct ListNode*)malloc(sizeof(struct ListNode));
	l2node3 = (struct ListNode*)malloc(sizeof(struct ListNode));

	l1node1->val = 1;
	l1node2->val = 2;

	l2node1->val = 3;
	l2node2->val = 4;
	l2node3->val = 5;

	l2node2->next = NULL;

	l1node1->next = l1node2;
	l1node2->next = l2node1;
	l2node1->next = l2node2;
	l2node2->next = l2node3;
	l2node3->next = NULL;
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