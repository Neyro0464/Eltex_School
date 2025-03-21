#include "antroponym.h"

void ClearAnthroponym(Antroponym* s)
{
	memset(s->firstName, '\0', sizeof(s->firstName));
	memset(s->lastName, '\0', sizeof(s->lastName));
    memset(s->patronymic, '\0', sizeof(s->patronymic));
}