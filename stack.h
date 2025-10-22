#ifndef STACK_H
#define STACK_H

#ifndef STACK_POISON
#define STACK_POISON 1296
#endif

const int SPU_BUFF_SIZE = 128 * sizeof(int);

enum StackErrors
{
    NO_ERRORS,
    STACK_CALLOC_ERROR,
    STACK_REALLOC_ERROR,
    STACK_PTR_NULL,
    STACK_ELEMENTS_MISSING
};

struct stack_t
{
    int * data;
    size_t capacity;
    size_t elemets_amount;
};

struct SPU
{
    stack_t stk = {};
    int buff[SPU_BUFF_SIZE] = {};
    int elements_amount = 0;
    int marker = 0;
    int registers[5] = {};
};

StackErrors StackInit(stack_t *stk, const size_t capacity);

StackErrors StackPush(stack_t *stk, const int value);

StackErrors StackPop(stack_t *stk, int *result);

StackErrors StackDestroy(stack_t *stk);

StackErrors StackAdd(stack_t *stk);

StackErrors StackSub(stack_t *stk);

StackErrors StackMul(stack_t *stk);

StackErrors StackDiv(stack_t *stk);

StackErrors StackOut(stack_t *stk);

StackErrors StackSqrt(stack_t *stk);

StackErrors StackPopReg(stack_t *stk, SPU *processor, int reg_index);

void StackDump(stack_t *stk);

#endif