// Queue.cpp : Definiert den Einstiegspunkt f¸r die Konsolenanwendung.
//

#include "Queue_Header.h"

struct queue
{
	node* end;
	node* start;
	int size;
};

struct node
{
	node* next;
	int value;
};

// Complexity O(1)
queue* queue_create()
{
	queue* newQueue = (queue*)malloc(sizeof(queue));
	newQueue->size = 0;
	newQueue->start = NULL;
	newQueue->end = NULL;

	return newQueue;
}

void queue_enqueueRec(node* n, int d)
{
	if (n->next == NULL)
	{
		node* temp = (node*)malloc(sizeof(node));
		temp->next = NULL;
		temp->value = d;

		n->next = temp;
	}
	else
	{
		queue_enqueueRec(n->next, d);
	}
}

// Complexity O(n)
void queue_enqueue(queue* q, int d)
{
	if (q == NULL)
		return NULL;

	if (q->size == 0)
	{
		node* temp = (node*)malloc(sizeof(node));
		temp->next = NULL;
		temp->value = d;

		q->start = temp;
	}
	else
	{
		queue_enqueueRec(q->start, d);
	}

	q->size += 1;
}

// Complexity O(1)
void queue_enqueue1(queue* q, int d)
{
	if (q == NULL)
		return NULL;

	if (queue_size(q) == 0)
	{
		node* temp = (node*)malloc(sizeof(node));
		temp->next = NULL;
		temp->value = d;

		q->start = temp;
		q->end = temp;
	}
	else
	{
		node* temp = (node*)malloc(sizeof(node));
		temp->next = NULL;
		temp->value = d;

		q->end->next = temp;
		q->end = q->end->next;
	}

	q->size += 1;
}

// Complexity O(1)
int queue_dequeue(queue* q)
{
	if (q == NULL)
		return NULL;
	if (q->size == 0)
		return NULL;

	int result = q->start->value;
	q->start = q->start->next;
	q->size -= 1;

	return result;
}

// Complexity O(1)
int queue_size(queue* q)
{
	if (q == NULL)
		return NULL;

	return q->size;
}

int main()
{
	queue* myQueue = queue_create();

	for (int i = 0; i < 10; i++)
		queue_enqueue1(myQueue, i);

	printf("Queue-size: %d\n", queue_size(myQueue));

	for (int i = 0; i < 10; i++)
		printf("%d\n", queue_dequeue(myQueue));

	printf("Queue-size: %d\n", queue_size(myQueue));
	getchar();


	return 0;
}

