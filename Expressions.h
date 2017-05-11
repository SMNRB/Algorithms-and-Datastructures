#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct expression;
typedef struct expression expression;

expression* var();
expression* num(int i);
expression* addExpr(expression* expr1, expression* expr2);
expression* subExpr(expression* expr1, expression* expr2);
expression* mulExpr(expression* expr1, expression* expr2);
expression* divExpr(expression* expr1, expression* expr2);
expression* print(expression* expr);
int eval(expression* expr, int x);