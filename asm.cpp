#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "asm_codes.h"

int main(int argc, char *argv[])
{   
    const size_t BUFF_SIZE = 128; // Максимальное число обрабатываемых комманд
    const size_t COMMAND_SIZE = 64 * sizeof(char); // Максимальный размер комманд

    if (argc < 3)
    {
        printf("Error opening file\n");
        return -1;
    }

    FILE *src = fopen(argv[1], "r");
    FILE *target = fopen(argv[2], "wb");

    if (src == NULL || target == NULL)
    {
        printf("NULL file ptr\n");
        return -1;
    }

    int buff[BUFF_SIZE] = {};
    int command_counter = 0;
    
    while (true)
    {
        char command[COMMAND_SIZE] = "";

        fscanf(src, "%63s", command);

        if (!strcmp(command, "HLT"))
            break;

        if (!strcmp(command, "PUSH"))
        {
            int value = 0;
            fscanf(src, "%d", &value);
            
            buff[command_counter++] = PUSH;
            buff[command_counter++] = value;
        }
        else if (!strcmp(command, "POP"))
        {
            char temp[10] = "";

            fgets(temp, 9, src);

            buff[command_counter++] = POP;
            buff[command_counter++] = temp[1] - 'A' + 1;
        }
        else if (!strcmp(command, "ADD"))
        {
            buff[command_counter++] = ADD;
        }
        else if (!strcmp(command, "SUB"))
        {
            buff[command_counter++] = SUB;
        }
        else if (!strcmp(command, "MUL"))
        {
            buff[command_counter++] = MUL;
        }
        else if (!strcmp(command, "DIV"))
        {
            buff[command_counter++] = DIV;
        }
        else if (!strcmp(command, "OUT"))
        {
            buff[command_counter++] = OUT;
        }
        else if (!strcmp(command, "SQRT"))
        {
            buff[command_counter++] = OUT;
        }
        else
        {
            printf("Incorrect file commands");
            return -1;
        }
    }

    fwrite(buff, sizeof(int), command_counter, target);

    return 0;
}