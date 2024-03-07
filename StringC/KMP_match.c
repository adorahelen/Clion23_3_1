#include <stdio.h>

int kmp_match (const char txt[], const char pat[])
{
    int pt = 1; // txt 커서
    int pp = 0; // pat 커서

    int skip[1024];
    skip[pt] = 0;

    // 표 만들기
    while(pat[pt] != '\0'){
        if (pat[pt] == pat[pp])
            skip[++pt] = ++pp;
        else if (pp == 0)
            skip[++pt] = pp;
        else
            pp = skip[pp];
    }


    //  검색
    pt = pp = 0;
    while (txt[pt] != '\0' && pat[pp] != '\0') {
        if (txt[pt] == pat[pp]) {
            pt++; pp++;
        } else if(pp==0)
            pt++;
        else
            pp = skip[pp];
    }
    if (pat[pp] == '\0')
        return pt - pp;

    return -1;

}


int main (void) {
    int idx;
    char s1[256];
    char s2[256];
    puts("KMP_method");
    printf("text : "); // 밑에 있는 패턴을 지금의 텍스트와 비교
    scanf("%s", s1);
    printf(" Pattern : "); // 입력된 패턴을 위에 입력한 텍스트와 비교
    scanf("%s", s2);

    idx = kmp_match(s1, s2);
    if(idx == -1)
        puts("It doesnt in the text (your pattern)");
    else
        printf("from %d char, started Match. \n", idx + 1 );


    return 0;

}
// 지금 사용된 KMP법은 부르트-포스트법 보다는 복잡하고,
// Boyer-More법과는 성능이 같거나 좋지 않아 사용될 일은 없다.