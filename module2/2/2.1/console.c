#include <stdio.h>
#include "phonebook.h"

extern BOOKSIZE;

int main()
{
    PersonInfo dataBase[BOOKSIZE];
    InitializingTable(&dataBase);
    int flag = 1;

    while(flag != 0)
    {
        printf("Select a menu option:\n");
		printf("\t1) Add a contact to the database.\n");
		printf("\t2) Redact a contact from the databsase.\n");
		printf("\t3) Delete a contact from the databsase.\n");
		printf("\t4) Output database (general info).\n");
        printf("\t5) Output database (all info).\n");
        printf("\t9) Download testing database.\n");
        printf("\t0) Exit programm.");

        scanf("%d", flag);
        switch(flag)
        {
            case 1:
                PersonInfo* tmpData;
                ReadingData(tmpData);
                AddIntable(dataBase, tmpData);
                free(tmpData);
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                OutputTable(dataBase, 0);
                break;
            case 5:
                OutputTable(dataBase, 1);
                break;
            case 9:
                break;
            case 0:
                flag = 0;
                break;
            default:
                printf("Wrong parameter.\n");
                break;
        }
    }
    printf("Programm successfully finished");
    
}