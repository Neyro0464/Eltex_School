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
    /* Task 1
    param in: 1 [777/rwxrwxrwx]
    out: access rights bits
    e.g. in: 1 750 ; out: 111101000
    */
    if(argc == 3 && strcmp(argv[1], "1") == 0) 
    {
        showBits(argv[2]);
    }
    /* Task 2
    param in: 2 ./tools.h
    out: [rwx/777/111] access format
    e.g. in: 2 ./tools.h ; out: ./tools.h       rw-r--r-- 644 110100100
    */
    if(argc == 3 && strcmp(argv[1], "2") == 0)
    {
        ls(argv[2]);
    }
    /* Task 3
    in: [1/2] [needed mask] [filedir/access rights]
    out: 
    e.g. 
    */
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