#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <signal.h>
#include <pqueue.h>

char *filename = "queue.dat";

int itemId = 0; //czy tutaj nie 1?	

typedef struct item item;
struct item {
	int id;
};


item *
produce() {
	int time = rand() % 5 + 1;
	item *it = (item *)malloc(sizeof(item));
	
	sleep(time);
	it->id = itemId;
	itemId += 1;
	return it;
}

void
consume(item *it) {
	int time = rand() % 5 + 1;
	sleep(time);
	free(it);
}


void
producer(pid_t childPid) {

	while(1)
	{
		item *it = produce();
		pqueue *q;
		qunserialize(&q, sizeof(item), filename);
		qinsert(&q, it, k);
		qserialize(q, sizeof(item), filename);

		printf("producer: %d\n", it->id);
		qlist(q,napis);

		//zwolnienie pamieci
		free(it);


	}

}

void
consumer() {
	while(1)
	{
		pqueue *q;
		pqueue *pop;
		qunserialize(&q, sizeof(item), filename);
		pop = qpop(&q);
		qserialize(q, sizeof(item), filename);

		//deklaracja id
		int id = ((item*)pop->data)->id;
		printf("consumer: %d\n", id);
		qlist(q, napis);

		consume(pop->data);
		
		//zwolnienie pamieci
		free(pop);

	}
}

//tworze klase napis do printowania
void
napis(void* data)
{
	printf("%d",((item*)data)->id);
}

int
main(int argc, char **argv) {
	pid_t pid;
	pqueue *qu = NULL;
	/* watch -n 1 ps -l --forest */
	
	/* create empty queue */
	qserialize(qu, sizeof(item), filename);

	//to dodaje co jest nizej
	//dzieki fork moge stwierdzic ktory proces jest pierwotny = else,a ktory potomny = 0
	pid = fork();
	if (pid ==0)
	{
		//printf("potomny %d\n", getpid()); -> w consumer
		consumer();
	}
	else
	{
		producer(pid);
		// printf("macierzysty %d\n", getpid()); -> w producer
	}

	

	return 0;
}

