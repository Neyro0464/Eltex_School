#include "phonebook.h"

void InitializingTable(PersonInfo *dataBase)
{
    if(dataBase != NULL)
	{
        for (int i = 0; i < BOOKSIZE; i++)
	    {
		   ClearContact(&dataBase[i]);
	    }
    }
}

void ClearContact(PersonInfo* person){
	person->id = 0;
    ClearAntroponym(&person->antroponym);
    ClearWork(&person->work);
    ClearMessenger(&person->messenger);
    memset(person->phoneNumber, ' ', 12);
    memset(person->email, ' ', 20); 
}


void AddInBook(PersonInfo* dataBase, PersonInfo* personalInf)
{
	int statusExit = -1;
	for (int i = 0; i < BOOKSIZE && statusExit == -1; i++)
	{
		if(dataBase[i].id == 0)
		{
			dataBase[i].id = i + 1;
			strncpy(dataBase[i].antroponym.firstName, personalInf->antroponym.firstName, 20);
			strncpy(dataBase[i].antroponym.lastName, personalInf->antroponym.lastName, 20); 
			strncpy(dataBase[i].antroponym.patronymic, personalInf->antroponym.patronymic, 20); 
			strncpy(dataBase[i].phoneNumber, personalInf->phoneNumber, 12); 
			strncpy(dataBase[i].email, personalInf->email, 20); 
			strncpy(dataBase[i].work.post, personalInf->work.post, 20); 
			strncpy(dataBase[i].work.placeOfWork, personalInf->work.placeOfWork, 20);
			strncpy(dataBase[i].messenger.VKlink, personalInf->messenger.VKlink, 20);
			strncpy(dataBase[i].messenger.TGlink, personalInf->messenger.TGlink, 20);
			statusExit = 1;
			printf("The contact has been added to the table.\n");
		}
	}
	if(statusExit == -1)
		printf("There is no place for a new contact in the table.\n");
}

void ReadingData(PersonInfo* p){
    char buf[64];
	//Adding name
	Antroponym tmp;
	ReadAntroponym(&tmp);
	strncpy(p->antroponym.firstName, tmp.firstName, 20);
	strncpy(p->antroponym.lastName, tmp.lastName, 20);
	strncpy(p->antroponym.patronymic, tmp.patronymic, 20);
	
	
	printf("Enter your phone number.\n");
	scanf("%s", buf);
	strncpy(p->phoneNumber, buf, 12);

    memset(buf, '\0', sizeof(buf));
    while(buf[0] != 'n' && buf[0] != 'N'){
	    printf("Do you want to enter additional data? (y/n)\n");
	    scanf("%s", buf);
	    if( buf[0] == 'y' || buf[0] == 'Y' )
	    {
	    	printf("Enter the email.\n");
	    	scanf("%s", buf);
	    	strncpy(p->email, buf, 20);

	    	printf("Enter your place of work.\n");
	    	scanf("%s", buf);
	    	strncpy(p->work.placeOfWork, buf, 20);

	    	printf("Enter a position at work.\n");
	    	scanf("%s", buf);
	    	strncpy(p->work.post, buf, 20);

	    	printf("Enter the link to the VK profile at work.\n");
	    	scanf("%s", buf);
	    	strncpy(p->messenger.VKlink, buf, 20);

	    	printf("Enter the link to the telegram profile at work.\n");
	    	scanf("%s", buf);
	    	strncpy(p->messenger.TGlink, buf, 20);

			buf[0] = 'n';
	    }
    }
}

void OutputTable(PersonInfo* data, int flag){
    if(data != NULL)
    {
        for (int i = 0; i < BOOKSIZE; i++)
	    {
		    if(data[i].id != 0)
		    {
			    printf("\n| %d | %s %s %s |", data[i].id, data[i].antroponym.firstName, data[i].antroponym.lastName, data[i].antroponym.patronymic);
		    	printf(" %s |", data[i].phoneNumber);
		    }
            if(flag == 1 && data[i].email[0] != ' ')
            {
                printf(" %s |", data[i].email);
                printf(" %s %s |", data[i].work.placeOfWork, data[i].work.post);
                printf(" %s %s |", data[i].messenger.TGlink, data[i].messenger.VKlink);
            }
	    }    
    }
}

void DeleteInTable(PersonInfo *dataBase)
{
	Antroponym anthroponym;
	ReadAntroponym(&anthroponym);

	int posInTable = FindRowInBook(dataBase, anthroponym);
	if(posInTable != -1)
	{
		ClearContact(&dataBase[posInTable]);
		printf("Contact deleted!\n");
	}
	else
		printf("Unknown contact!\n");
}
int FindRowInBook(PersonInfo* dataBase, Antroponym tmpAntroponym){
	char buf[64];
	int resIndex[BOOKSIZE];
	int j = 0;
	for(int i = 0; i < BOOKSIZE; i++)
	{
		if(strncmp(dataBase[i].antroponym.firstName, tmpAntroponym.firstName, 20) == 0){
			if(strncmp(dataBase[i].antroponym.lastName, tmpAntroponym.lastName, 20) == 0){
				if(strncmp(dataBase[i].antroponym.patronymic, tmpAntroponym.patronymic, 20) == 0){
					resIndex[j] = i;
					j++;	
				}
			}
		}
		dataBase = dataBase + 1;
	}
	if (j > 1){
		printf("Enter your phone number.\n");
		scanf("%s", buf);
		for(int i = 0; i < j; i++){
			if(strncmp(dataBase[resIndex[i]].phoneNumber, buf, 20) == 0){
				return resIndex[i];
			}
		}
	}
	else if(j == 1){
		return resIndex[0];
	}
	return -1;
}

void EditPersonData(PersonInfo* dataBase){
	Antroponym tmpAntroponym; 
	ReadAntroponym(&tmpAntroponym);
	char buf[64];
	int pos = FindRowInBook(dataBase, tmpAntroponym);
	if(pos != -1)
	{
		int flag = 0;
		printf("What do you want to change?\n");
		printf("1) Phone Number\n"); 
		scanf("%d", &flag);
		switch (flag)
		{
		case 1:
			printf("Enter a new phone number.\n");
			scanf("%s", buf);
			strncpy(dataBase[pos].phoneNumber, buf, 12);
			break;

		default:
			printf("Wrong action!\n");
			break;
		}
	}
	else{
		printf("There is no such contact!\n");
	}
}