#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "asm_codes.h"

int main(int argc, char *argv[])
{   
    const size_t buff_size = 64 * sizeof(char);

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

    while (true)
    {
        char buff[buff_size] = "";

        fscanf(src, "%63s", buff);

        if (!strcmp(buff, "HLT"))
            break;

        if (!strcmp(buff, "PUSH"))
        {
            AsmCodes code = PUSH;
            int value = 0;

            fwrite(&code, sizeof(code), 1, target);
            fscanf(src, "%d", &value);
            
            fwrite(&value, sizeof(value), 1, target);
        }
        else if (!strcmp(buff, "ADD"))
        {
            AsmCodes code = ADD;
            fwrite(&code, sizeof(code), 1, target);
        }
        else if (!strcmp(buff, "SUB"))
        {
            AsmCodes code = SUB;
            fwrite(&code, sizeof(code), 1, target);
        }
        else if (!strcmp(buff, "MUL"))
        {
            AsmCodes code = MUL;
            fwrite(&code, sizeof(code), 1, target);
        }
        else if (!strcmp(buff, "DIV"))
        {
            AsmCodes code = DIV;
            fwrite(&code, sizeof(code), 1, target);
        }
        else if (!strcmp(buff, "OUT"))
        {
            AsmCodes code = OUT;
            int value = 0;

            fwrite(&code, sizeof(code), 1, target);
        }
        else if (!strcmp(buff, "SQRT"))
        {
            AsmCodes code = SQRT;
            int value = 0;

            fwrite(&code, sizeof(code), 1, target);
        }
        else
        {
            printf("Incorrect file commands");
            return -1;
        }
    }

    return 0;
}