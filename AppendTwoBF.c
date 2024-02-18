#include <stdio.h>
#include <stdlib.h>

int main (void)
{
    // Local

     FILE* sp1;
     FILE* sp2;
     int data;
     long datacount;
     char fileID[13];

     // statement
    printf("THis program appends two files. \n");
    printf("Please enter file ID of the primary file: ");
    scanf("%12s", fileID);
    if (! (sp1 = fopen(fileID, "ab")))
        printf("\a Can't open %s \n", fileID), exit(100);

    // 867
}