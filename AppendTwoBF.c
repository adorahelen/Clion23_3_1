#include <stdio.h>
#include <stdlib.h>

int main (void)
{
    // Local

     FILE* sp1;
     FILE* sp2;
     int data;
     long dataCount;
     char fileID[13];

     // statement
    printf("THis program appends two files. \n");
    printf("Please enter file ID of the primary file: ");
    scanf("%12s", fileID);
    if (! (sp1 = fopen(fileID, "ab")))
        printf("\a Can't open %s \n", fileID), exit(100);

    if (!(dataCount = (ftell(sp1))))
        printf("\a %s has no data \n", fileID), exit(101);
    dataCount /= sizeof (int);

    printf("Please enter file ID of the second file:  ");
    scanf("%12s", fileID);
    if (!(sp2 = fopen(fileID, "rb")))
        printf("\a Can't open %s \n", fileID), exit(110);

    while (fread(&data, sizeof (int), 1, sp2)==1)
    {
        fwrite(&data, sizeof (int), 1, sp1);
        dataCount++;

    }// while

    if (!feof(sp2))
        printf("\a Read Error. No output. \n"), exit(120);

    fclose(sp1);
    fclose(sp2);

    printf("Append complete: %ld records in file \n", dataCount);

    return 0;
} // main