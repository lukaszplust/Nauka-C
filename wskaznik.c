#include <stdio.h>
#include <stdlib.h>

void zamiana(int *a)//deklaracja jako wskaznik
{
	//odwo³anie sie do wartosci ze wskaznika
	*a = 10;
	printf("%d\n",*a);
}



int main()
{
	int liczba = 1;
	//int *wliczba;
	//wliczba = &liczba;
	// &liczba -> jest to adres w pamiêci gdzie jest zapisana nasza int liczba = 1
	// %d wyswietlanie liczb ca³kowitych

	//printf("%d\n",&liczba);//adres
	//printf("%d\n",wliczba);//adres
	//printf("%d\n", liczba);//1
	//printf("%d\n", *wliczba);//1





	printf("%d\n", liczba);//1
	zamiana(&liczba);//10
	printf("%d\n", liczba);//10



	//wskaznik

	//* &


	return 0;
}