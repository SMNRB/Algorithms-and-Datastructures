#include <stdio.h>
#include <stdlib.h>

//_ _ _ _ _ _ _ _ _ _ _ _ _ DEFINITION _ _ _ _ _ _ _ _ _ _ _ _ _

struct stack_node;
typedef struct stack_node stack_node;

struct stack;
typedef struct stack stack;

stack* stack_create();

size_t stack_size(stack* s);

void stack_push(stack* s, int d);

int stack_top(stack* s);

int stack_pop(stack* s);

//_ _ _ _ _ _ _ _ _ _ _ _ _ _IMPLEMENTATION_ _ _ _ _ _ _ _ _ _ _ _ _ _

struct stack
{
	size_t size;
	stack_node* top;
};

struct stack_node
{
	int value;
	stack_node* next;
};

stack* stack_create()
{
	stack* newStack = (stack*)malloc(sizeof(stack));
	newStack->size = 0;
	newStack->top = NULL;

	return newStack;
}

void stack_push(stack* s, int d)
{
	if (s == NULL)
		return;

	stack_node* newNode = (stack_node*)malloc(sizeof(stack_node));
	newNode->next = s->top;
	newNode->value = d;

	s->top = newNode;

	s->size += 1;
}

int stack_top(stack* s)
{
	if (s == NULL)
		return NULL;
	if (s->size == 0)
		return 0;

	return s->top->value;
}

int stack_pop(stack* s)
{
	if (s == NULL)
		return NULL;

	if (s->size == 0)
		return NULL;


	int result = s->top->value;

	s->top = s->top->next;
	s->size -= 1;

	return result;
}

size_t stack_size(stack* s)
{
	if (s == NULL)
		return NULL;

	return s->size;
}
