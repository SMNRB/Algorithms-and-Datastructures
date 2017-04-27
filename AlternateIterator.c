#include "AlternateIteratorHeader.h"

struct node {
	int position;
	int value;
	node* next;
	node* previous;
};

struct list {
	int size;
	node* new_node;
};

list* create_list()
{
	list* new_list = (list*)malloc(sizeof(list));
	new_list->size = 0;
	new_list->new_node = NULL;

	return new_list;
}

void append_list_rec(node* list_node, int value)
{
	if (list_node->next == NULL)
	{
		node* new_node = (node*)malloc(sizeof(node));
		new_node->value = value;
		new_node->next = NULL;
		new_node->previous = list_node;
		new_node->position = list_node->position + 1;

		list_node->next = new_node;
	}
	else
	{
		append_list_rec(list_node->next, value);
	}
}

bool append_list(list* list, int value)
{
	if (list == NULL)
	{
		return false;
	}
	else if (list->size == 0)
	{
		node* temp = (node*)malloc(sizeof(node));
		temp->value = value;
		temp->next = NULL;
		temp->previous = NULL;
		temp->position = 0;

		list->new_node = temp;
	}
	else
	{
		append_list_rec(list->new_node, value);
	}

	list->size += 1;
	return list;
}

bool alternateIterator(node* node)
{
	if (node->position % 2 == 0)
		return true;

	return false;
}

void print(node* node)
{
	if (node == NULL)
		return;

	if (alternateIterator(node))
		printf("%d\n", node->value);

	print(node->next);
}

int main(void) {

	list* new_list = create_list();

	for (int i = 0; i < 100; i++)
	{
		append_list(new_list, i);
	}

	print(new_list->new_node);
	getchar();

	return EXIT_SUCCESS;
}
