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

    StackInit(&stk1, 16);

    for (int i = 0; i < elements_amount; i++)
    {
        
    }

    StackDestroy(&stk1);

    return 0;
}
// TODO
// StackDump
// StackVerify
// Чтение из файла (бинарного)
// Добавить защиту (см конспект)
// Регистры
// Канареечная защита