//
// Created by adora on 2024-03-03.
//

typedef  enum {
    TERMINATE, ADD, REMOVE, SEARCH, PRINT
} Menu;

Menu SelectMenu (void)
{
    int ch;
    do {
        printf("(1) Insert (2) Delete (3) FIND (4) Show (0) END: ");
        scanf("%d", &ch);
    } while(ch < TERMINATE || ch > PRINT);
    return (Menu)ch;
}

int main (void)
{
    Menu menu;
    BinNode *root = NULL;
    do {
        Member x;
        struct __bnode temp;
        switch (menu= SelectMenu()) {

            case ADD :
                x = ScanMember

        }
    }
}
