#include <stdio.h>
#include <math.h>
#include "stack.h"


StackErrors ADD(stack_t *stk)
{
    int a = 0, b = 0;

    StackPop(stk, &a);
    StackPop(stk, &b);
    
    return StackPush(stk, a + b);
}

StackErrors SUB(stack_t *stk)
{
    int a = 0, b = 0;

    StackPop(stk, &b);
    StackPop(stk, &a);
    
    
    return StackPush(stk, a - b);
}

StackErrors MUL(stack_t *stk)
{
    int a = 0, b = 0;

    StackPop(stk, &a);
    StackPop(stk, &b);
    
    return StackPush(stk, a * b);
}

StackErrors DIV(stack_t *stk)
{
    int a = 0, b = 0;

    StackPop(stk, &a);
    StackPop(stk, &b);
    
    return StackPush(stk, a / b);
}

StackErrors OUT(stack_t *stk)
{
    int a = 0;

    StackPop(stk, &a);
    printf("%d\n", a);

    return NO_ERRORS;
}

StackErrors SQRT(stack_t *stk)
{
    int a = 0;

    StackPop(stk, &a);
    StackPush(stk, (int)sqrt(a));

    return NO_ERRORS;
}

StackErrors HLT(stack_t *stk)
{
    StackDestroy(stk);

    return NO_ERRORS;
}