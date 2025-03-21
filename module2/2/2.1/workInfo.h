#ifndef WORKINFO_H
#define WORKINFO_H

/*
Structure contains person's information about job
*/
typedef struct workInfo
{
    char placeOfWork[20];
    char post[20];
} workInfo;

void ClearWork(workInfo* s);

#endif /* WORKINFO_H */