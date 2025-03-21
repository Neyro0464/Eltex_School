#include "messenger.h"

void ClearMessenger(Messenger* s){
    memset(s->TGlink, '\0', sizeof(s->TGlink));
    memset(s->VKlink, '\0', sizeof(s->VKlink));
}