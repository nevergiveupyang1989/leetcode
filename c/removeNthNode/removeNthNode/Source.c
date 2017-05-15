#include <stdio.h>
#include <stdlib.h>


 struct ListNode {
     int val;
     struct ListNode *next;
};


struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
	struct ListNode* fastNode;
	struct ListNode* removeNode;
	struct ListNode* preRemoveNode;

	if (NULL == head)
		return NULL;

	fastNode = head;
	removeNode = NULL;

	if (1 == n && head->next==NULL)
		return NULL;

	while (n-2>0)
	{
		fastNode = fastNode->next;
		n--;
	}

	preRemoveNode = NULL;
	while (fastNode->next!=NULL)
	{
		preRemoveNode = removeNode;
		fastNode = fastNode->next;

		if (NULL == removeNode)
			removeNode = head;
		else
			removeNode = removeNode->next;
	}

	if (NULL==preRemoveNode && n==2)
	{
		return head->next;
	}
	
	if (NULL==preRemoveNode && n==1)
	{
		head->next = NULL;
	}

	if (1==n)
	{
		removeNode->next = NULL;
	}

	if (removeNode!=NULL && preRemoveNode!=NULL && n!=1)
		preRemoveNode->next = removeNode->next;
	//free(removeNode);

	return head;
}

void main(){
	struct ListNode head1;
	struct ListNode head2;
	struct ListNode head3;
	struct ListNode head4;
	struct ListNode* result;

	head1.val = 1;
	head2.val = 2;
	head3.val = 3;
	head4.val = 4;

	head1.next = &head2;
	head2.next = &head3;
	head3.next = NULL;
	head4.next = NULL;

	result = removeNthFromEnd(&head1,1);

	while (NULL!=result)
	{
		printf("%d", result->val);
		result = result->next;
	}
}