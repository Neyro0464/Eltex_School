#ifndef WORKINFO_H
#define WORKINFO_H
#include <string.h>

#define ARRAYSIZE 20

/*
### Structure contains person's information about job
- char placeOfWork[]
- char post[]
*/
typedef struct workInfo
{
    char placeOfWork[ARRAYSIZE];
    char post[ARRAYSIZE];
} workInfo;

/*
### Function clearing struct workInfo
- Clearing char[] by filling it with character '\0'
*/
void ClearWork(workInfo* s);

#endif /* WORKINFO_H */