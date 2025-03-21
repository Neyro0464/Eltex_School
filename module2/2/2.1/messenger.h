#ifndef MESSENGER_H
#define MESSENGER_H

typedef struct Messenger
{
    char VKlink[20];
	char TGlink[20];    
} Messenger;

void ClearMessenger(Messenger* s);





#endif /*MESSENGER_H*/