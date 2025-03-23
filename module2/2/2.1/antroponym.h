#ifndef ANTROPONYM_H
#define ANTROPONYM_H

#include <string.h>
#include <stdio.h>

#define ARRAYSIZE 20
/*
## Structure contains full name
- char firstName[];
- char lastName[];
- char patronymic[];
*/
typedef struct Antroponym {
    char firstName[ARRAYSIZE];
    char lastName[ARRAYSIZE];
    char patronymic[ARRAYSIZE];
} Antroponym;

/*
### Function clearing all about full name
- Replaces the entire array with a character '\0'
*/
void ClearAntroponym(Antroponym*);
/*
### Function fills in the structure from the console
*/
void ReadAntroponym(Antroponym* );

#endif /*ANTROPONYM_H*/