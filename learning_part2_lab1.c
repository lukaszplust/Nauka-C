#include <stdio.h>
#include <stdlib.h>

struct Node
{
	struct Node *previous;
	int x;//liczba przechowywana na danej pozycji listy
	struct Node *next;
} *begin;//begin = wskaznik na poczatek listy

//Wskaźniki previous pierwszego oraz next
//ostatniego elementu listy mają wartość NULL

struct Node * insert(int obj, struct Node *ptr)//1,begin
{
	struct Node *p;
	p = ptr->next;//wez adres analizowanego elementu

	//sprawdz czy koniec listy
	if (p != NULL)
	{
		if (obj > (p->x))
		{
			p->next = insert(obj, p);
		}
		//utwórz nowy element
		else
		{
			p->previous = (struct Node *)malloc(sizeof(struct Node));
			//zapamietaj adres nowego elementu
			p = p->previous;

			//zainicjuj skladowe nowego elementu
			p->x = obj;
			p->next = ptr->next;
			p->previous = ptr;
		}
	}
	//koniec listy
	else
	{
		//utwórz nowy element
		p = (struct Node *)malloc(sizeof(struct Node));
		//inicializacja skaldowych nowego elementu
		p->x = obj;
		p->next = NULL;
		p->previous = ptr;
	}
	//zwracam adres nowego elementu
	return p;//begin->next
}

int main() {
	begin = (struct Node*)malloc(sizeof(struct Node));
	begin->next = NULL;
	begin->previous = NULL;
	begin->next = insert(1, begin);
	begin->next = insert(2, begin);
	begin->next = insert(3, begin);
}
