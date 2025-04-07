#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include "subtask1.h"
#include "subtask2.h"
#include "subtask3.h"


int main(int argc, char** argv){

    int mask = 0;
    if(argc < 3){
        return -1;
    }
    if(argc == 3 && strcmp(argv[1], "1") == 0)
    {
        showBits(argv[2]);
    }
    if(argc == 3 && strcmp(argv[1], "2") == 0)
    {
        ls(argv[2]);
    }
    if(argc == 4 && strcmp(argv[1], "1") == 0){
        mask = showBits(argv[3]);
        Subtask3(mask, argv[2]);
    }
    if(argc == 4 && strcmp(argv[1], "2") == 0){
        
            mask = ls(argv[3]);
            Subtask3(mask, argv[2]);
        }
        
    

    return 0;
}