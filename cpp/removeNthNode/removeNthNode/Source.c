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
	removeNode = head;

	while (n-1>0)
	{
		fastNode = fastNode->next;
		n--;
	}

	preRemoveNode = NULL;
	while (fastNode->next!=NULL)
	{
		preRemoveNode = removeNode;
		fastNode = fastNode->next;
		removeNode = removeNode->next;
	}

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
	head3.next = &head4;
	head4.next = NULL;

	result = removeNthFromEnd(&head1,2);

	while (NULL!=result)
	{
		printf("%d", result->val);
		result = result->next;
	}
}