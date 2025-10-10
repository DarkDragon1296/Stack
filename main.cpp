#include <stdio.h>
#include "asm_codes.h"
#include "stack.h"

int main(int argc, char *argv[])
{
    const int buff_size = 128 * sizeof(int);

    if (argc < 2)
    {
        printf("Error opening file\n");
        return -1;
    }

    FILE *src = fopen(argv[1], "rb");

    if (src == NULL)
    {
        printf("NULL file ptr\n");
        return -1;
    }   

    int buff[buff_size] = {};
    int elements_amount = fread(buff, sizeof(int), buff_size, src); 
    stack_t stk1 = {};

    StackInit(&stk1, 1);

    int i = 0;

    while (i < elements_amount)
    {
        StackDump(&stk1);

        switch (buff[i])
        {
            case PUSH:
                i++;
                StackPush(&stk1, buff[i]);
                break;
            case ADD:
                StackAdd(&stk1);
                break;
            case SUB:
                StackSub(&stk1);
                break;
            case MUL:
                StackMul(&stk1);
                break;
            case DIV:
                StackDiv(&stk1);
                break;
            case SQRT:
                StackSqrt(&stk1);
                break;
            case OUT:
                StackOut(&stk1);
                break;
        }

        i++;
    }

    StackDestroy(&stk1);

    return 0;
}
// TODO
// StackVerify
// Добавить защиту (см конспект)
// Регистры
// Канареечная защита