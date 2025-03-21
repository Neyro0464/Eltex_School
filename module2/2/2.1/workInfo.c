#include "workInfo.h"

void ClearWork(workInfo* s){
    memset(s->post, '\0', sizeof(s->post));
    memset(s->placeOfWork, '\0', sizeof(s->placeOfWork));
}