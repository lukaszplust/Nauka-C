#include <stdio.h>
#include <stdlib.h>

/*Zadanie nr 2
Napisz program, który stworzy self-referencing structure o nazwie Pies i doda trzy różne psy, każdy z osobnym numerem ID i unikalnym imieniem. Program musi wyprintować ID każdego psa i jego imię.*/

//na stercie
struct Node {
	int x;//x=ID
	char* imie;
	struct Node* next;
	struct Node* previous;
};

struct list {
	struct Node* head;//wskaznik na 1 element listy
	struct Node* tail;//wskaznik na ostatni element listy
};

void insert(struct list* lista, int id, char* name){//struct list* lista = lista = wskaznik na strukture list
	struct Node* new = malloc(sizeof(struct Node));//adres na stercie 
	if (lista->head == NULL) {
		new->x = id;
		new->imie = name;
		new->previous = NULL;
		new->next = NULL;
		lista->head = new;
		lista->tail = NULL;
	}
	else {
		if (lista->tail == NULL) {
			new->x = id;
			new->imie = name;
			new->previous = lista->head;
			new->next = NULL;
			lista->tail = new;
			lista->head->next = new;
		}
		else {
			new->x = id;
			new->imie = name;
			new->previous = lista->tail;
			new->next = NULL;
			lista->tail->next = new;
			lista->tail = lista->tail->next;
		}
	}
}

void print(struct Node* p) {
	printf("ID:%i  Name:%s \n", p->x, p->imie);
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
	insert(lista, 1.0f,"Ola");
	insert(lista, 3.0f,"Ala");
	insert(lista, 4.0f,"Kasia");
	

	printf("ID dog and name:\n");
	print(lista->head);

	//free(lista);
	return 0;
}
