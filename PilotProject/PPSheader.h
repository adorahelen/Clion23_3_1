// #ifndef CLION23_3_1_PPSHEADER_H
// #define CLION23_3_1_PPSHEADER_H
typedef struct
{
    int numerator; // 분자
    int denominator; // 분모
} FRACTION; // 분수

FRACTION getFr (void); // 자료형(구조체)_함수 이름()_원소 값(미정)
FRACTION  multFr (FRACTION fr1, FRACTION fr2);
void printFr (FRACTION fr1, FRACTION fr2, FRACTION result);

// #endif //CLION23_3_1_PPSHEADER_H

/* 주석 처리된 부분은 헤더 파일의 중복 포함을 방지하기 위한 것
 프로젝트가 커지고 여러 소스 파일에서 해당 헤더 파일을 포함할 경우,
중복이 발생할 수 있기에 매크로를 정의하여, 헤더파일이 포함되지 않은 경우만
 헤더파일의 내용이 포함되도록 한다.
 */
