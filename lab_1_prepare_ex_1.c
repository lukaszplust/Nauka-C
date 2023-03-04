#include <stdio.h>
#include <stdlib.h>

/*Zadanie nr 1
Napisz program, który utworzy listę dwukierunkową i umieści w niej elementy typu float.
Program powinien wyprintować wszystkie elementy w kolejności od pierwszego do ostatniego i odwrotnie.*/

//na stercie
struct Node {
	float x;
	struct Node* next;
	struct Node* previous;
};

struct list {
	struct Node* head;//wskaznik na 1 element listy
	struct Node* tail;//wskaznik na ostatni element listy
};

void insert(struct list* lista, float wartosc){//struct list* lista = lista = wskaznik na strukture list
	struct Node* new = malloc(sizeof(struct Node));//adres na stercie 
	if (lista->head == NULL) {
		new->x = wartosc;
		new->previous = NULL;
		new->next = NULL;
		lista->head = new;
		lista->tail = NULL;
	}
	else {
		if (lista->tail == NULL) {
			new->x = wartosc;
			new->previous = lista->head;
			new->next = NULL;
			lista->tail = new;
			lista->head->next = new;
		}
		else {
			new->x = wartosc;
			new->previous = lista->tail;
			new->next = NULL;
			lista->tail->next = new;
			lista->tail = lista->tail->next;
		}
	}
}

void print_from_back(struct Node* p) {
	printf("%f \n", p->x);
	if (p->previous != NULL)
	{
		print_from_back(p->previous);
	}
}

void print_from_front(struct Node* p) {
	printf("%f \n", p->x);
	if (p->next != NULL)
	{
		print_from_front(p->next);
	}
}
int main() {
	struct list* lista;

	lista = malloc(sizeof(lista));
	lista->head = NULL;
	lista->tail = NULL;
	insert(lista, 1.0f);
	insert(lista, 3.0f);
	insert(lista, 4.0f);
	insert(lista, 2.0f);
	insert(lista, 9.0f);
	insert(lista, 12.0f);
	
	printf("From behind:\n");
	print_from_back(lista->tail);
	printf("\n");
	printf("From front:\n");
	print_from_front(lista->head);

	free(lista);
	return 0;
}
