#include "antroponym.h"

void ClearAntroponym(Antroponym* s)
{
	memset(s->firstName, '\0', sizeof(s->firstName));
	memset(s->lastName, '\0', sizeof(s->lastName));
    memset(s->patronymic, '\0', sizeof(s->patronymic));
}

void ReadAntroponym(Antroponym* antroponym){
	char buf[ARRAYSIZE];
	printf("Enter the first name.\n");
    scanf("%s", buf);
	strncpy(antroponym->firstName, buf, 20);

	printf("Enter the last name.\n");
    scanf("%s", buf);
	strncpy(antroponym->lastName, buf, 20);

	printf("Enter the patronymic name.\n");
    scanf("%s", buf);
	strncpy(antroponym->patronymic, buf, 20);

}