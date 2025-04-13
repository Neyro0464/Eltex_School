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
    int pos = 0;
    int (*operations[]) (int, int) = {add, sub, eq};
    while(inputString[pos] == 'u' || inputString[pos] == 'g' || inputString[pos] == 'o'){
        switch (inputString[pos])
        {
        case 'u':
            flagU = 1;
            pos++;
            break;
        case 'g':
            flagG = 1;
            pos++;
            break;
        case 'o':
            flagO = 1;
            pos++;
            break;
        default:
            break;
        }
        
    }
    if(flagU != 1 && flagG != 1 && flagO != 1){
        printf("Incorrect \"ugo\"-format\n");
        return -1;
    }
    switch (inputString[pos])
    {
    case '+':
        operator = 0;
        pos++;
        break;
    case '-':
        operator = 1;
        pos++;
        break;
    case '=':
        operator = 2;
        pos++;
        break;
    default:
        break;
    }
    if(operator == -1){
        printf("Incorrect operator\n");
        return -1;
    }
    while(inputString[pos] == 'r' || inputString[pos] == 'w' || inputString[pos] == 'x'){
        switch (inputString[pos])
        {
        case 'r':
            flagR = 1;
            pos++;
            break;
        case 'w':
            flagW = 1;
            pos++;
            break;
        case 'x':
            flagX = 1;
            pos++;
            break;
        default:
            break;
        }
        
    }
    if(flagR != 1 && flagW != 1 && flagX != 1){
        printf("Incorrect \"rwx\"-format\n");
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
    printf("\t");
    PrintLetter(res);
    printf(" ");
    PrintNum(res);
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
    printf("\t");
    PrintLetter(rwxMask);
    printf(" ");
    PrintNum(rwxMask);

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