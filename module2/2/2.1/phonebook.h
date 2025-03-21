#include <stdio.h>
#include "antroponym.h"
#include "messenger.h"
#include "workInfo.h"

#ifndef PHONEBOOK_H
#define PHONEBOOK_H

typedef struct PersonInfo{
    // Required info 
    Antroponym antroponym;
    char phoneNumber[14]; // primary key
    
    // additional info
    workInfo work;
    Messenger messenger;
    char email[20];

} PersonInfo;

void InitializingTable(PersonInfo *);
void ClearContact(PersonInfo*);
void uploadBook(PersonInfo*);
void ReadingData(PersonInfo* p);
void addToBook(PersonInfo*);
void OutputTable(PersonInfo[], int);


#endif /*PHONEBOOK_H*/