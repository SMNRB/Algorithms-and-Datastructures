
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//---->  Declarations
struct btree;
typedef struct btree btree;

struct btree_node;
typedef struct btree_node btree_node;

btree* btree_create();

btree_node* node_create(int d);

void btree_insert(btree* t, int d);

int btree_size(btree* t);

int btree_max(btree* t);

int btree_min(btree* t);

bool btree_contains(btree* t, int d);

void btree_print(btree* t);
//---->  Declarations end

struct btree
{
	int size;
	int max;
	int min;
	btree_node* root;
};

struct btree_node
{
	int value;
	btree_node* left;
	btree_node* right;
};

btree* btree_create()
{
	btree* myBtree = (btree*)malloc(sizeof(btree));
	myBtree->root = NULL;
	myBtree->size = 0;

	return myBtree;
}

btree_node* node_create(int d)
{
	btree_node* myNode = (btree_node*)malloc(sizeof(btree_node));
	myNode->left = NULL;
	myNode->right = NULL;
	myNode->value = d;

	return myNode;
}

void btree_insertRec(btree_node* n, int d)
{
	if (n->value > d)
	{
		if (n->left == NULL)
			n->left = node_create(d);
		else
			btree_insertRec(n->left, d);
	}
	else
	{
		if (n->right == NULL)
			n->right = node_create(d);
		else
			btree_insertRec(n->right, d);
	}
}

void btree_insert(btree* t, int d)
{
	if (t == NULL)
		return;
	if (btree_contains(t, d))
		return;

	if (btree_size(t) == 0)
	{
		t->max = d;
		t->min = d;
		t->root = node_create(d);
	}
	else
	{
		btree_insertRec(t->root, d);
	}

	t->size += 1;
}

bool btree_containsRec(btree_node* n, int d)
{
	if (n == NULL)
		return false;

	if (n->value == d)
		return true;
	else
	{
		if (n->value > d)
			return btree_containsRec(n->left, d);
		else
			return btree_containsRec(n->right, d);
	}
}

bool btree_contains(btree* t, int d)
{
	if (t == NULL)
		return false;

	if (btree_containsRec(t->root, d))
		return true;

	return false;
}

int btree_size(btree* t)
{
	return t->size;
}

int btree_max(btree* t)
{
	return t->max;
}

int btree_min(btree* t)
{
	return t->min;
}

void btree_printRec(btree_node* n)
{
	if (n == NULL)
		return;

	printf("(");
	btree_printRec(n->left);
	printf("%d", n->value);
	btree_printRec(n->right);
	printf(")");
}

void btree_print(btree* t)
{
	if (t == NULL)
		return ;
	if (btree_size(t) == 0)
		printf("Your binary tree is empty!\n");
	else
	{
		btree_printRec(t->root);
	}
}

int main(void) {

	btree* myBtree = btree_create();
	btree_insert(myBtree, 5);
	btree_insert(myBtree, 3);
	btree_insert(myBtree, 2);
	btree_insert(myBtree, 1);
	btree_insert(myBtree, 4);
	btree_insert(myBtree, 7);
	btree_insert(myBtree, 6);
	btree_insert(myBtree, 8);
	btree_insert(myBtree, 9);

	btree_print(myBtree);


	return EXIT_SUCCESS;
}
