#include <stdio.h>
#include "asm_codes.h"
#include "stack.h"

int main(int argc, char *argv[])
{
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

    SPU processor = {};

    processor.elements_amount = fread(processor.buff, sizeof(int), SPU_BUFF_SIZE, src); 
    stack_t stk1 = {};

    StackInit(&stk1, 1);

    while (processor.marker < processor.elements_amount)
    {
        StackDump(&stk1);

        switch (processor.buff[processor.marker])
        {
            case PUSH:
                StackPush(&stk1, processor.buff[++processor.marker]);
                break;
            case POP:
                StackPopReg(&stk1, &processor, processor.buff[++processor.marker]);
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

        processor.marker++;
    }

    StackDestroy(&stk1);

    return 0;
}
// TODO
// Структура SPU {stk, total commands, command index, buff}
// StackVerify
// Добавить защиту (см конспект)
// Регистры
// Канареечная защита
// Jump
// Оперативка
