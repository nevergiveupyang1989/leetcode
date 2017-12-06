#include <stdio.h>
#include <string.h>
#include <malloc.h>
#define SIZE 100
typedef char dataType;

struct treeNode
{
	dataType num;
	struct treeNode* left;
	struct treeNode* right;
}treeNode;

typedef struct treeNode* ptreeNode;

struct seqStack
{
	ptreeNode stack[SIZE];
	int top;
}stack;

typedef struct seqStack* pseqStack;

void push(pseqStack pstack, ptreeNode pnode)
{
	if(NULL==pstack)
		return;
	
	pstack->stack[++(pstack->top)] = pnode;
}

ptreeNode pop(pseqStack pstack)
{
	ptreeNode topNode;

	if(NULL==pstack)
		return NULL;
	
	topNode = pstack->stack[pstack->top];
	pstack->stack[pstack->top--] = NULL;

	return topNode;
}

void preOrder(ptreeNode root)
{	
	int i;
	ptreeNode curNode;

	if(NULL==root)
		return;

	curNode = root;
	printf("%d", curNode->num);
	preOrder(curNode->left);
	preOrder(curNode->right);
}

void preOrder2(ptreeNode root)
{
	int i;
	ptreeNode curNode;
	pseqStack pnewStack;
	
	if(NULL==root)
		return;

	pnewStack = (pseqStack)malloc(sizeof(stack));
	if(NULL==pnewStack)
		return;
	
	for(i=0; i<SIZE; i++)
	{
		pnewStack->stack[i] = NULL;
	}
	
	pnewStack->top = -1;
	
	curNode  = root;
	while(curNode || pnewStack->top!=-1)
	{
		while(curNode)
		{
			printf("%d", curNode->num);
			push(pnewStack, curNode);
			curNode = curNode->left;
		}
		curNode = pop(pnewStack);
		curNode = curNode->right;
	}
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

	preOrder2(node1);
}
