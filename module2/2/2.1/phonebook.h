#ifndef PHONEBOOK_H
#define PHONEBOOK_H
#include <stdio.h>
#include <string.h>
#include "antroponym.h"
#include "messenger.h"
#include "workInfo.h"
#define BOOKSIZE 20 // Max size of phonebook (number of rows allowed)

/*
### Struct contains information about person
- int id - determain id of the data row in phonebook
- Antroponym - struct that contains full name:
> char fisrtName[]
> char lastName[]
> char patronymic[]
- char phoneNumber[] - primary key
- workInfo - struct that contains:
> char placeOfWork[]
> char post[]
- Messenger - struct that contains social network links:
> char VKlink[]
> char TGlink[]
- char email[]
*/
typedef struct PersonInfo{
    // Required info 
    int id;
    Antroponym antroponym;
    char phoneNumber[12];
    // additional info
    workInfo work;
    Messenger messenger;
    char email[20];

} PersonInfo;


void AddStartData(PersonInfo*);

/*
### Function initializing array of struct PersonInfo by fiiling all fields with 'zero' values
*/
void InitializingTable(PersonInfo *);
/*
### Function that filling all fields with 'zero values
*/
void ClearContact(PersonInfo*);

/*
### Function that fiiling one row in the phonebook from console
*/
void ReadingData(PersonInfo*);
/*
### Function that delete one row in phone book by searching by name and phone number(if we find multiple identical names)
*/
void DeleteInTable(PersonInfo*);
/*
### Function that adding filled row in the phonebook by searching free pos in the array
*/
void AddInBook(PersonInfo*, PersonInfo*);
/*
### Function that show all filled rows in the phon book
- PersonInfo* - phonebook
- int - flag to change display mode
> 0 - show only the required information
> 1 - show all information
*/
void OutputTable(PersonInfo*, int);
/*
### Function that seraching needed row in the phone book
- requires you to enter the necessary search parameters in the console:
> Antroponym - searching person
> If we find multiple identical names requires phone number
*/
int FindRowInBook(PersonInfo*, Antroponym);
/*
# IN PROGRESS
### Edit persons data
- Search needed row by requiring Antroponym and phone number (if needed)
- Asks which fields need to be replaced
*/
void EditPersonData(PersonInfo*);


#endif /*PHONEBOOK_H*/