/* 
 * File:   main.c
 * Author: Ngoan Tran
 *
 */
#include "functionsLib_LinkedList.c"

int main() {
    List L;
    ElementType X;
    Position P;

    printf("\n---------PROBLEMS 3b--------\n");
    printf("SORT LIST\n");
    MAKENULL_LIST(&L);
    READ_LIST(&L);
    SORT(&L);
    printf("All element of list: ");
    PRINT_LIST(L);

    printf("\n---------PROBLEMS 4--------\n");
    printf("INSERT A ELEMENT\n");
    printf("Enter a element to insert: ");
    scanf("%d", &X);
    AUTO_INSERT(X, &L);
    printf("List after inserting  %d : ", X);
    PRINT_LIST(L);

    printf("\n---------PROBLEMS 5--------\n");
    printf("DELETE A ELEMENT\n");
    printf("Enter the element to delete: ");
    scanf("%d", &X);
    if (P = LOCATE(X, L)) {
        DELETE(P, &L);
        printf("List after deleting %d : ", X);
        PRINT_LIST(L);
    } else {
        printf("ERROR: The element is not on this list!\n");
    }

    printf("\n---------PROBLEMS 6--------\n");
    printf("READ LIST, KEEP ORDER\n");
    MAKENULL_LIST(&L);
    SMART_READING(&L);
    printf("List after reading : ");
    PRINT_LIST(L);

    printf("\n---------PROBLEMS 7--------\n");
    printf("ELIMINATE SIMILAR ELEMENTS\n");
    ELIMINATE_SIMILAR_ELEMENTS(&L);
    printf("List after eliminate similar elements: ");
    PRINT_LIST(L);

    printf("\n---------PROBLEMS 8--------\n");
    printf("READ LIST, KEEP ORDER AND UNIQUE\n");
    MAKENULL_LIST(&L);
    SMART_READING(&L);
    printf("List after reading : ");
    PRINT_LIST(L);

    printf("\n---------PROBLEMS 9--------\n");
    printf("MERGE TWO LISTS\n");
    List L1;
    MAKENULL_LIST(&L);
    SMART_READING(&L);
    MAKENULL_LIST(&L1);
    SMART_READING(&L1);
    MERGE_LISTS(L, &L1);
    printf("List after merging : ");
    PRINT_LIST(L1);

    printf("\n---------PROBLEMS 10--------\n");
    printf("DELETE ODD ELEMENTS\n");
    DELETE_ODD(&L1);
    printf("List after deleting odd elements : ");
    PRINT_LIST(L1);

    printf("\n---------PROBLEMS 11--------\n");
    printf("SPLIT ODD AND EVEN ELEMENTS\n");
    List OL, EL;
    MAKENULL_LIST(&OL);
    MAKENULL_LIST(&EL);
    SPLIT_OE(L, &OL, &EL);
    printf("List after splitting elements:\n");
    printf("List odd: ");
    PRINT_LIST(OL);
    printf("List even: ");
    PRINT_LIST(EL);

    return 0;
}

