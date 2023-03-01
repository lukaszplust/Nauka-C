#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	int x;
	struct Node* next;
} Node;

int main(int argc, char* argv[])
{
	Node root;
	root.x = 15;
	root.next = malloc(sizeof(Node));//root.next = &element2,          &element2 = malloc(sizeof(Node))
	root.next->x = -2; // root.next->x = element2.x
	root.next->next = malloc(sizeof(Node));
	root.next->next->x = 8;
	root.next->next->next = NULL; //root.next->next = element2.next

	Node* curr = &root;// int i=0
	while (curr != NULL)// curr != NULL = i < n
	{
		printf("%d\n", curr->x);
		curr = curr->next;//i++
	}

	for (Node* curr = &root; curr != NULL; curr = curr->next)
	{
		printf("%d\n", curr->x);
	}

	//printf("First: %d\n", root.x);
	//printf("Second: %d\n", root.next->x); // root.next->x = (*root.next).x

	free(root.next->next);//kolejenosc taka !!!!!
	free(root.next);
	return 0;
}
