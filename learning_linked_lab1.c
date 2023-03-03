#include <stdio.h>
#include <stdlib.h>

struct Node{
	int x;
	struct Node* next;
} *top = NULL;

void push(int element)
{
	struct Node *p;
	p = top;
	top = (struct Node*)malloc(sizeof(struct Node));
	top->x = element;
	top->next = p;
}
int pop(void) 
{
	int element = 0;
	struct Node* p;
	if (top != NULL)
	{
		p = top;
		element = top->x;
		top = top->next;
		free(p);
	}
	return element;
}
int main(int argc, char* argv[])
{
	push(1);
	push(2);
	push(3);
	printf("% d\n", top->x);
	//pop();
	top = top->next;
	pop();
	printf("% d\n", top->x);
}
