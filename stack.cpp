#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "stack.h"

StackErrors StackInit(stack_t *stk, const size_t capacity)
{
    assert(stk);

    if (capacity < 1)
        return STACK_CALLOC_ERROR;

    stk->data = (int *)calloc(capacity, sizeof(int));

    if (stk->data == NULL)
        return STACK_CALLOC_ERROR;

    stk->capacity = capacity;

    return NO_ERRORS;
}

StackErrors StackPush(stack_t *stk, const int value)
{
    assert(stk);

    if (stk->capacity == stk->elemets_amount)
    {
        int *temp = (int *)realloc(stk->data, stk->capacity * 2);
        
        if (temp == NULL)
            return STACK_REALLOC_ERROR;
        
        stk->data = temp;
        stk->capacity *= 2;
    }

    stk->data[stk->elemets_amount] = value;
    stk->elemets_amount++;

    return NO_ERRORS;
}

StackErrors StackPop(stack_t *stk, int *result)
{
    assert(stk);

    if (stk->elemets_amount == 0)
        return STACK_ELEMENTS_MISSING;

    stk->elemets_amount--;
    *result = stk->data[stk->elemets_amount];
    stk->data[stk->elemets_amount] = STACK_POISON;

    return NO_ERRORS;
}

StackErrors StackPopReg(stack_t *stk, SPU *processor, int reg_index)
{
    assert(stk);

    if (stk->elemets_amount == 0)
        return STACK_ELEMENTS_MISSING;

    int temp = 0;

    StackPop(stk, &temp);

    processor->registers[reg_index] = temp;

    return NO_ERRORS;
}

StackErrors StackDestroy(stack_t *stk)
{
    assert(stk);

    if (stk->data == NULL)
        return STACK_PTR_NULL;

    for (int i = stk->elemets_amount; i >= 0; i--)
        stk->data[i] = STACK_POISON;

    free(stk->data);

    return NO_ERRORS;
}