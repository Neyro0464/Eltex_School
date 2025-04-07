#include "subtask2.h"


void UgoRights(int ugoMode)
{
    char rwx[] = "---";
    if(ugoMode & S_IROTH)
        rwx[0] = 'r';

    if(ugoMode & S_IWOTH)
        rwx[1] = 'w';

    if(ugoMode & S_IXOTH)
        rwx[2] = 'x';

    printf("%s", rwx);
}

int OutputAccessRights(unsigned int mode)
{
    int userRights = (mode & S_IRWXU) >> 6;
    UgoRights(userRights);

    int groupRights = (mode & S_IRWXG) >> 3; 
    UgoRights(groupRights);

    int otherRights = mode & S_IRWXO;
    UgoRights(otherRights);

    printf(" %d%d%d ", userRights, groupRights, otherRights);

    int res = mode & (S_IRWXU | S_IRWXG | S_IRWXO);
    PrintBits(res);
    return res;
}
int ls(char* filename){
    struct stat statbuf;

    if (stat(filename, &statbuf)) {
        fprintf(stderr, "The file does not exist\n");
        return -1;
    }

    printf("%s\t", filename);
    
    int res = OutputAccessRights(statbuf.st_mode);
    
    printf("\n");

    return res;
}
