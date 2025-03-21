#include "phonebook.h"
#include <string.h>
#include <stdio.h>
#define BOOKSIZE 20



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
    ClearAnthroponym(&person->antroponym);
    ClearWork(&person->work);
    ClearMessenger(&person->messenger);
    memset(person->phoneNumber, ' ', 12);
    memset(person->email, ' ', 20); 
}


void ReadingData(PersonInfo* p){
    char buf[256];

	printf("Enter the first name.\n");
    scanf("%s", &buf);
	strncpy(p->antroponym.firstName, buf, 20);

	printf("Enter the last name.\n");
    scanf("%s", &buf);
	strncpy(p->antroponym.lastName, buf, 20);

	printf("Enter the patronymic name.\n");
    scanf("%s", &buf);
	strncpy(p->antroponym.patronymic, buf, 20);

	printf("Enter your phone number.\n");
	scanf("%s", &buf);
	strncpy(p->phoneNumber, buf, 14);

    memset(buf, '\0', sizeof(buf));
    while(buf[0] != 'n' && buf[0] != 'N'){
	    printf("Do you want to enter additional data? (y/n)\n");
	    scanf("%s", &buf);
	    if( buf[0] == 'y' || buf[0] == 'Y' )
	    {
	    	printf("Enter the email.\n");
	    	scanf("%s", &buf);
	    	strncpy(p->email, buf, 20);

	    	printf("Enter your place of work.\n");
	    	scanf("%s", &buf);
	    	strncpy(p->work.placeOfWork, buf, 20);

	    	printf("Enter a position at work.\n");
	    	scanf("%s", &buf);
	    	strncpy(p->work.post, buf, 20);

	    	printf("Enter the link to the VK profile at work.\n");
	    	scanf("%s", &buf);
	    	strncpy(p->messenger.VKlink, buf, 20);

	    	printf("Enter the link to the telegram profile at work.\n");
	    	scanf("%s", &buf);
	    	strncpy(p->messenger.TGlink, buf, 20);
	    }
    }
}

void OutputTable(PersonInfo data[], int flag){
    if(data != NULL)
    {
        for (int i = 0; i < BOOKSIZE; i++)
	    {
		    if(data[i].antroponym.firstName[0] != ' ')
		    {
			    printf("| %d %s %s %s |", i + 1, data[i].antroponym.firstName, data[i].antroponym.patronymic);
		    	printf(" %s |", data[i].phoneNumber);
		    }
            if(flag == 1 && data[i].email[0] != ' ')
            {
                printf(" %s |", data[i].email);
                printf(" %s %s |", data[i].work.placeOfWork, data[i].work.post);
                printf(" %s %s |\n", data[i].messenger.TGlink, data[i].messenger.VKlink);
            }
            else
            {
                printf("\n");
            }
	    }    
    }
}
