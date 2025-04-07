#include "subtask3.h"
#include "tools.h"

int add(int fileMask, int ugoRwxMask)
{
    return (fileMask | ugoRwxMask);
}

int sub(int fileMask, int ugoRwxMask)
{
    return (fileMask & ~(ugoRwxMask));
}

int eq(int fileMask, int ugoRwxMask)
{
    return ugoRwxMask;
}

int UgoParse(char *inputString, int filemask)
{
    int rwxMask = 0;
    int ugoRwxMask = 0;
    int flagU = 0, flagG = 0, flagO = 0;
    int flagR = 0, flagW = 0, flagX = 0;
    int operator = -1;
    int (*operations[]) (int, int) = {add, sub, eq};
    for (int i = 0; i < strlen(inputString) - 1; i++)
    {
        switch (inputString[i])
        {
        case 'u':
            flagU = 1;
            break;
        case 'g':
            flagG = 1;
            break;
        case 'o':
            flagO = 1;
            break;
        case 'r':
            flagR = 1;
            break; 
        case 'w':
            flagW = 1;
            break; 
        case 'x':
            flagX = 1;
            break; 
        case '+':
            operator = 0;
            break; 
        case '-':
            operator = 1;
            break; 
        case '=':
            operator = 2;
            break; 
        default:
            fprintf(stderr, "Incorrect \"ugo\"-format\n");
            return -1;
            break;
        }
    }
    if(operator == -1)
    {
        fprintf(stderr, "The operator is lost\n");
        return -1;
    }
    if(flagU == 0 && flagG == 0 && flagO == 0)
    {
        fprintf(stderr, "Not entered ugo\n");
        return -1;
    }
    if(flagR == 1) rwxMask |= (1 << 2);
    if(flagW == 1) rwxMask |= (1 << 1);
    if(flagX == 1) rwxMask |= 1;

    if(flagU == 1) ugoRwxMask |= rwxMask << 6;
    if(flagG == 1) ugoRwxMask |= rwxMask << 3;
    if(flagO == 1) ugoRwxMask |= rwxMask;

    double res = operations[operator](filemask, ugoRwxMask);
    PrintBits(res);
    printf("\n");
    return res;
}

int NumParse(char *inputString, int filemask)
{
    if (strlen(inputString) != 3)
    {
        fprintf(stderr, "Wrong size\n");
        return -1;
    }

    int rwxMask = 0;
    int ugoRwxMask = 0;

    for (int i = 0; i < 3; i++)
    {
        int right = inputString[i] - '0';
        if(right <= '0' && right >= '7')
        {
            fprintf(stderr, "Wrong character\n");
            return -1;
        }
        rwxMask |= right << (6 - (2 * i) - i);
    }
    PrintBits(rwxMask);
    printf("\n");

    return rwxMask;
}

int Subtask3(int filemask, char* cmd)
{
    if(CheckNumInput(cmd))
    {
        return NumParse(cmd, filemask);
    }
    else
    {
        return UgoParse(cmd, filemask);
    }
}