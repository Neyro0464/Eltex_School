#include "subtask1.h"

int calcBitNum(char* data){
    int numRightsU = (data[0] - '0') << 6;
    int numRightsG = (data[1] - '0') << 3;
    int numRightsO = data[2] - '0';

    int res = numRightsU | numRightsG | numRightsO;
    PrintBits(res);
    printf("\n");
    return res;
}

int calcBitStr(char* data){
    int res = 0;
    for (int i = 8; i >= 0; i--)
    {
        if (data[8-i] == 'r' && i % 3 == 2)
        {
            res = res | (1 << i);
        } 
        else if(data[8-i] == 'w' && i % 3 == 1)
        {
            res = res | (1 << i);
        }
        else if(data[8-i] == 'x' && i % 3 == 0)
        {
            res = res | (1 << i);
        }
        else if (data[8-i] == '-')
        {
            continue;
        }
        else
        {
            fprintf(stderr, "Incorrect character\n");
            return -1;
        }
    }

    PrintBits(res);
    printf("\n");
    return res;
}

int showBits(char* data){
    int res = 0;
    if(CheckNumInput(data)){
        if(strlen(data) != 3)
            {
                fprintf(stderr, "Inctorrect size of input");
                return -1;
            }
        return calcBitNum(data);
    }
    else
    {
        if(strlen(data) != 9)
        {
            fprintf(stderr, "Inctorrect size of input");
            return -1;
        }
        return calcBitStr(data);
    }
    return res; 
}