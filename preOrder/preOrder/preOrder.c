#include <stdio.h>
#include <string.h>
#include <malloc.h>
typedef char dataType;

struct treeNode
{
	dataType num;
	struct treeNode* left;
	struct treeNode* right;
}treeNode;

typedef struct treeNode* ptreeNode;

void preOrder(ptreeNode root)
{	
	ptreeNode curNode;

	if(NULL==root)
		return;

	curNode = root;
	printf("%d", curNode->num);
	preOrder(curNode->left);
	preOrder(curNode->right);
}

void main()
{
	ptreeNode node1;
	ptreeNode node2;
	ptreeNode node3;
	
	node1 = (ptreeNode)malloc(sizeof(treeNode));
	node2 = (ptreeNode)malloc(sizeof(treeNode));
	node3 = (ptreeNode)malloc(sizeof(treeNode));
	
	node1->num = 1;
	node2->num = 2;
	node3->num = 3;

	node1->left = node2;
	node1->right = node3;
	
	node2->left = NULL;
	node2->right = NULL;

	node3->left = NULL;
	node3->right = NULL;

	preOrder(node1);
}
