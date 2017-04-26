#include<stdlib.h>
#include<stdio.h>

struct bin_tree {
	int data;
	struct bin_tree * right, *left;
};
typedef struct bin_tree node;

void insert(node ** tree, int val)
{
	node *temp = NULL;
	if (!(*tree))
	{
		temp = (node *)malloc(sizeof(node));
		temp->left = temp->right = NULL;
		temp->data = val;
		*tree = temp;
		return;
	}

	if (val < (*tree)->data)
	{
		insert(&(*tree)->left, val);
	}
	else if (val >(*tree)->data)
	{
		insert(&(*tree)->right, val);
	}

}

// Part of the homework start //
// O(n)
void print_preorder(node* node)
{
	if (node == NULL)
		return;

	printf("%d\n", node->data);
	print_preorder(node->left);
	print_preorder(node->right);
}

// O(n)
void print_inorder(node* node)
{
	if (node == NULL)
		return;
	
	print_inorder(node->left);
	printf("%d\n", node->data);
	print_inorder(node->right);
}

// O(n)
void print_postorder(node* node)
{
	if (node == NULL)
		return;

	print_postorder(node->left);
	print_postorder(node->right);
	printf("%d\n", node->data);
}
// Part of the homework end //

void deltree(node * tree)
{
	if (tree)
	{
		deltree(tree->left);
		deltree(tree->right);
		free(tree);
	}
}

void main()
{
	node *root;
	node *tmp;
	//int i;

	root = NULL;
	/* Inserting nodes into tree */
	insert(&root, 9);
	insert(&root, 4);
	insert(&root, 15);
	insert(&root, 6);
	insert(&root, 12);
	insert(&root, 17);
	insert(&root, 2);

	/* Printing nodes of tree */
	printf("Pre Order Display\n");
	print_preorder(root);

	printf("In Order Display\n");
	print_inorder(root);

	printf("Post Order Display\n");
	print_postorder(root);

	/* Deleting all nodes of tree */
	deltree(root);

	getchar();
}
