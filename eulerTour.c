#include "BinaryTreeUnsorted.h"
#include <time.h>

struct unsorted_btree
{
	int size;
	int max;
	int min;
	unsorted_btree_node* root;
};

struct unsorted_btree_node
{
	void* value;
	unsorted_btree_node* left;
	unsorted_btree_node* right;
};

unsorted_btree* btree_create()
{
	unsorted_btree* myBtree = (unsorted_btree*)malloc(sizeof(unsorted_btree));
	myBtree->root = NULL;
	myBtree->size = 0;

	return myBtree;
}

int randomInt()
{
	return rand() % 2;
}

unsorted_btree_node* node_create(void* d)
{
	unsorted_btree_node* myNode = (unsorted_btree_node*)malloc(sizeof(unsorted_btree_node));
	myNode->left = NULL;
	myNode->right = NULL;
	myNode->value = d;

	return myNode;
}

bool btree_insertRec(unsorted_btree_node n, void d)
{
	if (n == NULL)
		return false;

	int r = randomInt();

	if (r)
	{
		if (n->left == NULL)
		{
			n->left = node_create(d);
		}
		else
		{
			btree_insertRec(n->left, d);
		}
	}
	else
	{
		if (n->right == NULL)
		{
			n->right = node_create(d);
		}
		else
		{
			btree_insertRec(n->right, d);
		}
	}
}

bool btree_insert(unsorted_btree t, void d)
{
	if (t == NULL)
		return false;
	if (d == NULL)
		return false;

	if (t->root == NULL)
	{
		t->root = node_create(d);
	}
	else 
	{
		btree_insertRec(t->root, d);
	}
}

int btree_size(unsorted_btree* t)
{
	return t->size;
}

// EULER TRAVERSAL

void pre_visit()
{
	printf("(");
}

void in_visit(unsorted_btree_node* n)
{
	printf("%d", n->value);
}

void post_visit()
{
	printf(")");
}

void eulerTour(unsorted_btree_node n, void(*preVisit)(), void(*inVisit)(unsorted_btree_node n), void(*postVisit)())
{
	preVisit();

	if (n->left != NULL)
		eulerTour(n->left, preVisit, inVisit, postVisit);

	inVisit(n);

	if (n->right != NULL)
		eulerTour(n->right, preVisit, inVisit, postVisit);

	postVisit();
}

int main()
{
	srand(time(0));

	unsorted_btree* myBtree = btree_create();
	btree_insert(myBtree, 5);
	btree_insert(myBtree, 3);
	btree_insert(myBtree, 4);
	btree_insert(myBtree, 2);
	btree_insert(myBtree, 1);
	btree_insert(myBtree, 7);
	btree_insert(myBtree, 6);
	btree_insert(myBtree, 8);
	btree_insert(myBtree, 9);

	eulerTour(myBtree->root, pre_visit, in_visit, post_visit);

	getchar();
}
