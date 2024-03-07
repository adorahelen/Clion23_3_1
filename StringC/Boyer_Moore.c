#include <stdio.h>
#include <string.h>
#include <limits.h>

int bm_match(const char txt[], const char pat[]);

int main(void) {
    int idx;
    char s1[256]; // 텍스트
    char s2[256]; // 패턴

    puts("Boyer-Moore");
    printf(" Text : ");
    scanf("%s", s1);
    printf("pattern : ");
    scanf("%s", s2);

    idx = bm_match(s1, s2);
    // 문자열 s1에서, s2를 Boyer-Moore법을 사용해 검색
    if (idx == -1)
        puts("Text doesn't have pattern;");
    else
        printf("From %d, it start matched...\n", idx+1);

    return 0;
}

int bm_match(const char txt[], const char pat[]){

    int pt;
    int pp;
    int txt_len = strlen(txt); // txt문자 개수
    int pat_len = strlen(pat); // pat문자 개수
    int skip[UCHAR_MAX + 1]; // 건너띄기 표

    // 건너띄기 표 만들기
    for(pt = 0; pt <= UCHAR_MAX; pt++)
        skip[pt] = pat_len;

    for(pt = 0; pt <= pat_len-1; pt++) // 디버깅 1
        skip[pat[pt]] = pat_len - pt - 1;

    while (pt < txt_len) { // 검사
        pp = pat_len - 1;
        while (txt[pt] == pat[pp]) {
            if(pp == 0)
                return pt;
            pp--;
            pt--;
        }
        pt += (skip[txt[pt]] > pat_len - pp) ? skip[txt[pt]] : pat_len - pp;
    }
    return -1;
}

