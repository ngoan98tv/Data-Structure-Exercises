#include "basicLib_ArrayList.c"

int main() {
    List L;
    ElementType x;
    MAKENULL_LIST(&L);
    // 1a
    READ_LIST_fromFIRST(&L);
    PRINT_LIST(L);
    /* 1b
    READ_LIST_fromLAST(&L);
    PRINT_LIST(L);
    // 3a */
    SORT(&L);
    printf("After sorted\n");
    PRINT_LIST(L);
    // 4
    printf("Enter the elements to insert: ");
    scanf("%d", &x);
    AUTO_INSERT(x,&L);
    printf("After inserted\n");
    PRINT_LIST(L);
    // 5
    printf("Enter the elements to delete: ");
    scanf("%d", &x);
    DELETE(LOCATE(x,L),&L);
    printf("After deleted\n");
    PRINT_LIST(L);
    // 7
    ELIMINATE_SIMILAR_ELEMENTS(&L);
    printf("After eliminated similar elements\n");
    PRINT_LIST(L);
    
    return (EXIT_SUCCESS);
}

