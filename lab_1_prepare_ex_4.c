#include <stdio.h>
#include <stdlib.h>

/*Zadanie nr 4
Napisz program, który utworzy kolejkę z ustalonym limitem na podstawie liczb podanych przez użytkownika. Użytkownik powinien mieć możliwość dodawania elementów do kolejki i sprawdzania jej elementów.*/

//na stercie
struct Node {
	int x;
	struct Node* next;
};

struct list {
	struct Node* head;//wskaznik na 1 element listy
	struct Node* tail;//wskaznik na ostatni element listy
};

void insert(struct list* lista, int wartosc){//struct list* lista = lista = wskaznik na strukture list
	struct Node* new = malloc(sizeof(struct Node));//adres na stercie 
	if (lista->head == NULL) {
		new->x = wartosc;
		new->next = NULL;
		lista->head = new;
		lista->tail = NULL;
	}
	else {
		if (lista->tail == NULL) {
			new->x = wartosc;
			new->next = NULL;
			lista->tail = new;
			lista->head->next = new;
		}
		else {
			new->x = wartosc;
			new->next = NULL;
			lista->tail->next = new;
			lista->tail = lista->tail->next;
		}
	}
}

void quit(struct list* lista) {
	lista->head->x = NULL;
	lista->head = lista->head->next;

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

	int flag = 0;
	int input;
	char inputed;
	printf("p-print elements; a-add; f-first element quit; q-quit queue\n");

	while (flag == 0) {
		scanf_s("%c", &inputed);
		if (inputed == 'p') {
			printf("Printed elements:\n");

			print(lista->head);
			printf("\n");
			printf("p-print elements; a-add; f-first element quit; q-quit queue\n");
		}
		else if (inputed == 'a') {
			printf("Input value:");
			scanf_s("%d",&input);
			insert(lista, input);
			printf("p-print elements; a-add; f-first element quit; q-quit queue\n");
		}
		else if (inputed == 'f') {
			quit(lista);
			printf("p-print elements; a-add; f-first element quit; q-quit queue\n");
		}
		else if (inputed == 'q') {
			flag = 1;
		}
	}
	//free(lista);
	return 0;
}
