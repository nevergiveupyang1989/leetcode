#include <stdio.h>
#include <stdlib.h>

#define bool int
#define true 1
#define false 0
#define MAXSIZE 1000000

typedef struct stackList{
	int top;
	char symbols[MAXSIZE];
	int stackSize;
}Stack;

void initailStack(Stack *pStack)
{
	pStack->top = -1;
	pStack->stackSize = 1000000;
}

int push(Stack *pStack, char element)
{
	if (pStack->top == pStack->stackSize)
		return -1;
	pStack->top++;
	pStack->symbols[pStack->top] = element;

	return 1;
}

int pop(Stack *pStack)
{
	if (-1 == pStack->top)
		return -1;
	pStack->top--;

	return 1;
}

char getTopEle(Stack *pStack)
{
	char ele;

	if (pStack->top == -1)
		return -1;
	
	ele = pStack->symbols[pStack->top];

	return ele;
}

bool isValid(char* s) {
	int i;
	int size;
	int tmp;
	char ele;
	Stack *pStack = NULL;

	pStack = (Stack*)malloc(sizeof(Stack));
	
	initailStack(pStack);

	i = 0;
	while (s[i]!='\0')
	{
		ele = getTopEle(pStack);

		if (s[i]==')')
		{
			if (-1==ele || ele == '(')
			{
				tmp = pop(pStack);
				i++;
				continue;
			}
		}

		else if (s[i] == ']')
		{
			if (-1 == ele || ele == '[')
			{
				tmp = pop(pStack);
				i++;
				continue;
			}
		}

		else if (s[i] == '}')
		{
			if (-1 == ele || ele == '{')
			{
				tmp = pop(pStack);
				i++;
				continue;
			}
		}
		
		tmp = push(pStack, s[i]);	
		i++;

		if (tmp == -1)
			return false;
	}

	if (pStack->top==-1)
	{
		return true;
	}

	return false;
}


void main()
{
	bool result;
	char *s = "]";

	result = isValid(s);

	printf("%d", result);
}