#include <stdio.h>
#include <stdlib.h>

/*Zadanie nr 3
Napisz program, który utworzy listę dwukierunkową zawierającą cztery elementy typu int, następnie usunie z niej 3 elementy i wyprintuje pozostały wynik. Pamiętaj o zwolnieniu pamięci.*/

//na stercie
struct Node {
	int x;
	struct Node* next;
	struct Node* previous;
};

struct list {
	struct Node* head;//wskaznik na 1 element listy
	struct Node* tail;//wskaznik na ostatni element listy
};

void insert(struct list* lista, int wartosc){//struct list* lista = lista = wskaznik na strukture list
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

void delete(struct list* lista) {
	lista->tail = lista->tail->previous;
	lista->tail->next = NULL;
	free(lista->tail->next);

}

void print(struct Node* p) {
	printf("%i \n", p->x);
	if (p->next != NULL)
	{
		print(p->next);
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
	delete(lista);
	delete(lista);

	print(lista->head);

	//free(lista);
	return 0;
}
