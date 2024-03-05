// 문자열에서 문자 검색하기

#include <stdio.h>

int str_chr (const char *s, int c);

int main (void)
{
    char str[64]; // 이 문자열에서 검색
    char tmp[64];

    int ch;
    int idx;

    printf("sentence : ");
    scanf("%s", str);

    printf("Searching char : ");
    scanf("%s", tmp); // 검색할 문자를 먼저 문자열로 읽어들인다.
    ch = tmp[0];

    if((idx = str_chr(str, ch)) == -1) // 처음 나오는 문자를 검색한다.
        printf("char '%c' is not here . \n", ch);
    else
        printf("char '%c' is In %d ...\n", ch, idx+1);

    return 0;
}

int str_chr (const char *s, int c){
    int i = 0;
    c  = (char)c;
    while(s[i] != c) {
        if(s[i] == '\0') // 검색실패
            return -1;
        i++;
    }
    return i;
}