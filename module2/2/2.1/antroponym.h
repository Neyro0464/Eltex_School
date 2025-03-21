#ifndef ANTROPONYM_H
#define ANTROPONYM_H

typedef struct Antroponym {
    char firstName[20];
    char lastName[20];
    char patronymic[20];
} Antroponym;

void ClearAnthroponym(Antroponym* s);

#endif /*ANTROPONYM_H*/