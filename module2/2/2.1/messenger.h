#ifndef MESSENGER_H
#define MESSENGER_H

#include <string.h>

#define ARRAYSIZE 20

/*
### Structure contain social network links
- char VKlink[]
- char TGlink[]
*/
typedef struct Messenger
{
    char VKlink[ARRAYSIZE];
	char TGlink[ARRAYSIZE];    
} Messenger;

/*
### Function clearing Messenger struction
- Filling char[] with character '\0' 
*/
void ClearMessenger(Messenger* s);





#endif /*MESSENGER_H*/