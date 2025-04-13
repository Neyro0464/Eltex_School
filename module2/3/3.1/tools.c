#include"tools.h"

void PrintBits(int val) 
{
  for (int i = 8; i >= 0; i--) {
    printf("%c", (val & (1 << i)) ? '1' : '0');
  }
}

void PrintNum(int val){
  printf("%d", (val & S_IRWXU) >> 6 );
  printf("%d", (val & S_IRWXG) >> 3 );
  printf("%d", (val & S_IRWXO));
}

void PrintLetter(int val){
  for(int i = 8; i >= 0; i--){
    if((i+1) % 3 == 0){
      printf("%c", (val & (1 << i)) ? 'r' : '-');
    }
    else if((i+1) % 3 == 2){
      printf("%c", (val & (1 << i)) ? 'w' : '-');
    }
    else if((i+1) % 3 == 1){
      printf("%c", (val & (1 << i)) ? 'x' : '-');
    }
  }
}

int CheckNumInput(char *stringRights)
{
    if(stringRights[0] >= '0' &&  stringRights[0] <= '7')
    {
        if(stringRights[1] >= '0' &&  stringRights[1] <= '7')
        {
            if(stringRights[2] >= '0' &&  stringRights[2] <= '7')
                return 1;
        }
    }
    return 0;
}