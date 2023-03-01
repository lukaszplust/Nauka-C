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
	root.next->next = NULL; //root.next->next = element2.next

	printf("First: %d\n", root.x);
	printf("Second: %d\n", root.next->x); // root.next->x = (*root.next).x

	free(root.next);
	return 0;
}
