// 예전에 배운 리스트가 순서대로 데이터를 나열하는 자료구조 (포인터 사용)
// 트리는 데이터 시이의 계층 관계를 나타내는 자료구조

// 트리를 구성하는 요소는 Node 그리고 edge

// 이진 검색 트리 만들기(메인 먼저-> 함수-> 헤더)

#include <stdio.h>
#include <stdlib.h>
#include "Member.h" // 뒤에 나오는 거를 미리 작성해서 불러온다. (노드에 담긴 데이터)
// 여서 사용되는 Member 자료형은 앞서 나온 "List", 뒤에 나올 "Hash법"에서도 그대로 적용된다.
#include "MyTree.h" // 노드와 간선의 관계 (좌우 노드 설정)


// 1. 함수: 노드를 동적으로 할당
static BinNode *AllocBinNode (void)
{
    return calloc(1, sizeof(BinNode));
}

// 2. 함수: 노드 맴버의 값을 설정
static void SetBinNode(BinNode *n, const Member *x, const BinNode *left, const BinNode *right)
{
    n->data = *x;
    n->left = left;
    n->right = right;
}

 // 3. 검색
 BinNode *Search (BinNode *p, const Member *x) {

     int cond;

     if (p == NULL)
         return NULL; // 검색실패
     else if ((cond = MemberNoCmp(x, &p->data)) == 0)
         return p; // 성공
     else if (cond < 0)
         Search(p->left, x); // 왼쪽 서브 트리에서 검색
     else
         Search(p->right, x); // 오른쪽 서브 트리에서 검색
 }

 // 4. 노드 삽입 함수
 BinNode *Add (BinNode *p, const Member *x)
 {
    int cond;
    if (p == NULL) {
        //p가 널인 경우 => 루트 노드를 만들고 값을 설정한다.
        // 함수를 처음 호출하는 상태가 아니라면(재귀 호출) *삽입할 노드 만들고 값을 설정하면 삽입과정은 끝
        p = AllocBinNode();
        SetBinNode(p, x, NULL, NULL);

    } else if ((cond = MemberNoCmp(x, &p->data)) == 0) // 선택한 노드의 키 값과 삽입할 키 값이 같은 경우
        printf("-ERROR-  %d is Registered Already. \n", x->no);
    else if (cond < 0) // 삽입할 키 값이 선택한 노드의 키 값보다 작은 경우 
        p->left = Add(p->left, x);
    else
        p->right = Add(p->right, x);
     return p;
 }

 // 5. 노드 삭제 함수
 int Remove(BinNode **root, const Member *x)
 {
    BinNode *next, *temp;
    BinNode **left;
    BinNode **p = root;

    while(1) {
        int cond;
        if (*p == NULL) {
            printf(" -ERROR - %d is Not Registered YET. \n", x->no);
            return -1;  // 검색에 실패한 경우

        } else if ((cond = MemberNoCmp(x, &(*p)->data)) ==0)
            break; // 검색에 바로 성공한 경우

        else if (cond < 0) // 왼쪽 서브 트리에서 검색
            p = &((*p) ->left);
        else
            p = &((*p)->right); // 오른쪽 서브트리에서 검색
    }
// **********3번정도 다시 읽어 보기**********
    if ((*p)->left == NULL)
        next = (*p)->right;
    else {
        left = &((*p)->left);
        while ((*left)->right !=NULL)
            left = &(*left)->right;
        next = *left;
        *left = (*left)->left;
        next->left = (*p)->left;
        next->right = (*p)->right;
    }
    temp = *p;
    *p = next;
    free(temp);

     return 0;
 }

 // 6. 출력 함수 (모든 노드의 데이터를 출력)
 void PrintTree(const BinNode *p)
 {
    if (p != NULL) {
        PrintTree(p->left);
        PrintLnMember(&p->data);
        PrintTree(p->right);
    }
  }

  // 7. 삭제 함수 (모든 노드의 데이터를 삭제)
  void FreeTree(BinNode *p)
  {
    if (p != NULL) {

        FreeTree(p->left);
        FreeTree(p->right);
        free(p);
    }
  }
