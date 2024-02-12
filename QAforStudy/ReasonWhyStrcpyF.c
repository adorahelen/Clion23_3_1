/*
#include <stdio.h>
#include <string.h>

#define MAX 200

int main(void) {
    char s1[MAX]; // 문자열을 저장할 배열 선언

    printf("Enter a string: ");
    scanf("%s", s1); // 사용자로부터 문자열을 입력받아 lion 배열에 저장

    char s2[MAX]; // 복사할 문자열을 저장할 배열 선언

    // s1 배열의 내용을 s2 배열로 복사합니다.
    strcpy(s2, s1);

    // 입력한 문자열 및 복사된 문자열 출력
    printf("The entered string is: %s\n", s1);
    printf("The copied string is: %s\n", s2);

    return 0;
}
*/

#include <stdio.h>

void my_strcpy(const char *src, char *dest) {
    // src가 NULL이 아닐 때까지 반복하며, NULL 문자를 만날 때까지 dest에 복사합니다.
    while (*src != '\0') {
        *dest = *src;
        src++;
        dest++;
    }
    // 복사가 끝나면 dest의 마지막에 NULL 문자를 추가하여 문자열을 종료합니다.
    *dest = '\0';
}

int main() {
    char s1[] = "Hello, world!";
    char s2[20]; // 충분한 크기로 배열을 할당합니다.

    // s1의 내용을 s2로 복사합니다.
    my_strcpy(s1, s2);

    // 복사된 문자열을 출력합니다.
    printf("Copied string: %s\n", s2);

    return 0;
}
/* 결론 strcpy 함수가(s1, s2)
 * 뒤에서 앞으로 복사하는 이유는
 * string.h에 선언 및 정의된 함수의 매개인자가
 * 기존 문자열을 뒤로 받고
 * 복사할 배열을 앞으로 받아서 그렇다. */