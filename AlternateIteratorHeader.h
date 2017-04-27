#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

struct node;
typedef struct node node;

struct iterator;
typedef struct iterator iterator;

struct list;
typedef struct list list;

list* create_list();

void append_list_rec(node* list_node, int value);

bool append_list(list* list, int value);

void print(node* node);
