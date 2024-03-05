#include <stdio.h>


int str_len (const char *s)
{
         int len = 0;

         while(s[len])
             len++;

    return len;
}
int main (void) {
    char str[256];
    printf("Sentence : ");
    scanf("%s", str);
    printf("this Sentence's length is %d..", str_len(str));

    return 0;
}