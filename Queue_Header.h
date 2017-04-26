#include <stdio.h>
#include <stdlib.h>

struct node;
typedef struct node node;

struct queue;
typedef struct queue queue;

queue* queue_create();

void queue_enqueueRec(node* n, int d);

void queue_enqueue(queue* q, int d);

int queue_dequeue(queue* q);

int queue_size(queue* q);