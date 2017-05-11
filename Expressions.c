#include "Expressions.h"

enum types { VAR, NUM, EXPR };

struct expression
{
	void* content;
	expression* left;
	expression* right;
	enum types type;
};

bool isLeaf(expression* expr)
{
	if (expr->left == NULL && expr->right == NULL)
		return true;
	return false;
}

expression* var()
{
	expression* myExpression = (expression*)malloc(sizeof(expression));
	myExpression->left = NULL;
	myExpression->right = NULL;
	myExpression->content = 'x';
	myExpression->type = VAR;

	return myExpression;
}

expression* num(int i)
{
	expression* myExpression = (expression*)malloc(sizeof(expression));
	myExpression->left = NULL;
	myExpression->right = NULL;
	myExpression->content = i;
	myExpression->type = NUM;

	return myExpression;
}

expression* addExpr(expression* expr1, expression* expr2)
{
	expression* myExpression = (expression*)malloc(sizeof(expression));
	myExpression->left = expr1;
	myExpression->right = expr2;
	myExpression->content = '+';
	myExpression->type = EXPR;

	return myExpression;
}

expression* subExpr(expression* expr1, expression* expr2)
{
	expression* myExpression = (expression*)malloc(sizeof(expression));
	myExpression->left = expr1;
	myExpression->right = expr2;
	myExpression->content = '-';
	myExpression->type = EXPR;

	return myExpression;
}
expression* mulExpr(expression* expr1, expression* expr2)
{
	expression* myExpression = (expression*)malloc(sizeof(expression));
	myExpression->left = expr1;
	myExpression->right = expr2;
	myExpression->content = '*';
	myExpression->type = EXPR;

	return myExpression;
}

expression* divExpr(expression* expr1, expression* expr2)
{
	expression* myExpression = (expression*)malloc(sizeof(expression));
	myExpression->left = expr1;
	myExpression->right = expr2;
	myExpression->content = '/';
	myExpression->type = EXPR;

	return myExpression;
}

expression* print(expression* expr)
{
	if (!isLeaf(expr))
	{
		printf("(");
		print(expr->left);
	}
	
	if (expr->type == VAR)
		printf("%c", expr->content);
	else if (expr->type == NUM)
		printf("%d", expr->content);
	else
		printf("%c", expr->content);

	if (!isLeaf(expr))
	{
		print(expr->right);
		printf(")");
	}
}

void replaceVar(expression* expr, int x)
{
	if (expr != NULL)
	{
		if (expr->type == VAR)
		{
			expr->content = x;
			expr->type = NUM;
		}

		replaceVar(expr->left, x);
		replaceVar(expr->right, x);
	}
}

int solveExpr(expression* expr)
{
	if (expr->type == EXPR)
	{
		if(expr->content == '+')
			return solveExpr(expr->left) + solveExpr(expr->right);
		if (expr->content == '-')
			return solveExpr(expr->left) - solveExpr(expr->right);
		if (expr->content == '*')
			return solveExpr(expr->left) * solveExpr(expr->right);
		if (expr->content == '/')
			return solveExpr(expr->left) / solveExpr(expr->right);
	}

	return expr->content;
}

int eval(expression* expr, int x)
{
	replaceVar(expr, x);

	printf("Your expression with x = %d\n", x);
	print(expr);
	printf("\n");
	return solveExpr(expr);
}

int main()
{
	expression* myExpression = subExpr(addExpr(mulExpr(mulExpr(num(2), var()), var()), mulExpr(num(4), var())), num(1));

	print(myExpression);
	printf("\n");
	printf("Result: %d\n", eval(myExpression, 10));

	getchar();

	return EXIT_SUCCESS;
}

