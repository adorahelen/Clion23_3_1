// 브루트-포스법으로 문자열을 검색하는 프로그램
#include <stdio.h>

int bf_match (const char txt[], const char pat[]);

int main (void) {
    int idx;
    char s1[256];
    char s2[256];
    puts("BF method");
    printf("text : "); // 밑에 있는 패턴을 지금의 텍스트와 비교
    scanf("%s", s1);
    printf(" Pattern : "); // 입력된 패턴을 위에 입력한 텍스트와 비교
    scanf("%s", s2);

    idx = bf_match(s1, s2);
    if(idx == -1)
        puts("It doesnt in the text (your pattern)");
    else
        printf("from %d char, started Match. \n", idx + 1 );


    return 0;

}

// 브루트 포스법으로 문자열을 검색하는 함수
int bf_match(const char txt[], const char pat[])
{
    int pt = 0; // txt 커서
    int pp = 0; // pat 커서
    while (txt[pt] != '\0' && pat[pp] != '\0') { // 텍스트 커서와 패턴 커서가 널문자를 만나게 되면 종결하도록
        if (txt[pt] == pat[pp]) {
            pt++;
            pp++;
        } else {
            pt = pt - pp + 1;
            pp = 0;
        }
    }
    if (pat[pp] == '\0')
        return pt - pp;
    return -1;
}