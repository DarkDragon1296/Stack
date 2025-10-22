#include <stdio.h>
#include <math.h>
#include "stack.h"


StackErrors StackAdd(stack_t *stk)
{
    int a = 0, b = 0;

    StackPop(stk, &a);
    StackPop(stk, &b);
    
    return StackPush(stk, a + b);
}

StackErrors StackSub(stack_t *stk)
{
    int a = 0, b = 0;

    StackPop(stk, &b);
    StackPop(stk, &a);
    
    
    return StackPush(stk, a - b);
}

StackErrors StackMul(stack_t *stk)
{
    int a = 0, b = 0;

    StackPop(stk, &a);
    StackPop(stk, &b);
    
    return StackPush(stk, a * b);
}

StackErrors StackDiv(stack_t *stk)
{
    int a = 0, b = 0;

    StackPop(stk, &a);
    StackPop(stk, &b);
    
    return StackPush(stk, a / b);
}

StackErrors StackOut(stack_t *stk)
{
    int a = 0;

    StackPop(stk, &a);
    printf("%d\n", a);

    return NO_ERRORS;
}

StackErrors StackSqrt(stack_t *stk)
{
    int a = 0;

    StackPop(stk, &a);
    StackPush(stk, (int)sqrt(a));

    return NO_ERRORS;
}

void StackDump(stack_t *stk)
{
    putchar('\n');
    printf("Stack info:\n");
    printf("Capacity : %d\n", stk->capacity);
    printf("Elements amount : %d\n", stk->elemets_amount);
    printf("Data :");

    for (int i = 0; i < stk->capacity; i++)
        printf(" %d", stk->data[i]);

    printf("\n\n");
    
    return;
}