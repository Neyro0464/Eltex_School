#ifndef SUBTASK2_H_
#define SUBTASK2_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>
#include"tools.h"


void UgoRights(int ugoMode);
int OutputAccessRights(unsigned int mode);
int ls();

#endif