// 배열을 역순으로 정렬하기

#include <stdio.h>
#include <stdlib.h>
/*

 C 전처리기와  C 라이브러리

" # "
 - 전처리기는 프로그램이 컴파일 되기 전에 그 프로그램을 처리한다. (so 전처리기) 또한 전처리기는 요청하는 다른 파일들을 프로그램에 포함시킬 수 있다.
 ex: #define, #include

메크로로 정의해 놓은 것들은 함수 또는 코드를 읽어드릴때 자동으로 치환해서 읽는다.

이때
 매크로냐 함수냐 두고 고민하는 것은,
=> 시간절약이냐, 메모리 절약이냐의 문제다.

메크로는 인라인 코드를 만든다. 즉 프로그램안에 문장을 넣는다. = 속도 up, 메모리 down
ex: 매크로 20번 사용 == 코드 20라인 넣는거

함수는 20번 사용하더라도 한번만 나옴
=> 메모리 공간을 적게 차지한다.

<> <- 시스템 디렉토리에서 찾는다
" "  <- 현재 작업 디렉토리에서 찾는다


*/


#define swap(type, x, y) do{type t = x; x = y; y = t;}while(0);
// define 함수와 inline 함수의 차이점은? , 함수에 do while문을 쓸 수 있는가?
// swap 을 사용한 모든 구문에, define이 들어감
// while 안에 0 또는 1을 사용하며, 0의 경우 세미콜론이 누락되도 돌아간다.

void reverse (int a[], int n)
{
    for ( int i = 0; i < n /2; i++)
        swap(int, a[i], a[n - i -1]);
}

int main (void) {
    int nx;

    printf(" enter the Number ");
    scanf("%d", &nx);
    int *x = calloc(nx, sizeof(int));
    for (int i = 0; i < nx; i++) {
        printf("x[%d] :", i);
        scanf("%d", &x[i]);
    }
    reverse(x, nx);
    printf("reversed \n");
    for (int i =0; i < nx; i++) {
        printf(" x[%d] = %d\n", i, x[i]);
    }
    free(x);
    return 0;
}
