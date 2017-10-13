/* 
 * File:   functionsLib.c
 * Author: Ngoan Tran
 *
 */
#include "basicLib_LinkedList.c"

void READ_LIST(List* L) {
    int n, i;
    ElementType tmp;
    printf("How many elements on list: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &tmp);
        INSERT(tmp, NEXT(LAST(*L), *L), &(*L));
    }
}

void PRINT_LIST(List L) {
    Position tmp = FIRST(L);
    while (tmp != ENDLIST(L)) {
        printf("%d, ", RETRIEVE(tmp, L));
        tmp = NEXT(tmp, L);
    }
    printf("\n");
}

void SORT(List *L) {
    Position p, q;
    ElementType tmp;
    for (p = FIRST(*L); p != ENDLIST(*L); p = NEXT(p, *L)) {
        for (q = NEXT(p, *L); q != ENDLIST(*L); q = NEXT(q, *L)) {
            if (RETRIEVE(p, *L) > RETRIEVE(q, *L)) {
                SWAP(p, q, L);
            }
        }
    }
}

void AUTO_INSERT(ElementType x, List* L) {
    Position p = FIRST(*L);
    while ((p != ENDLIST(*L))&&(x > RETRIEVE(p, *L))) {
        p = NEXT(p, *L);
    }
    INSERT(x, p, &(*L));
}

void ELIMINATE_SIMILAR_ELEMENTS(List* L) {
    Position p = FIRST(*L);
    Position q;
    while (p != ENDLIST(*L)) {
        q = NEXT(p, *L);
        while (q != ENDLIST(*L)) {
            if (RETRIEVE(p, *L) == RETRIEVE(q, *L)) {
                DELETE(q, &(*L));
                q = NEXT(p, *L);
            } else {
                q = NEXT(q, *L);
            }
        }
        p = NEXT(p, *L);
    }
}

void SMART_READING(List *L) {
    int n, i;
    ElementType tmp;
    printf("How many elements on list: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &tmp);
        if (!LOCATE(tmp, *L))
            AUTO_INSERT(tmp, &(*L));
    }
}

void MERGE_LISTS(List L1, List* L2) {
    Position p;
    p = FIRST(L1);
    while (p != ENDLIST(L1)) {
        AUTO_INSERT(p->Value, &(*L2));
        p = NEXT(p, L1);
    }
}

void DELETE_ODD(List *L) {
    Position p, q;

    while ((FIRST(*L) != ENDLIST(*L))&&(FIRST(*L)->Value % 2 != 0)) {
        DELETE(FIRST(*L), &(*L));
    };
    p = FIRST(*L);
    while (p != ENDLIST(*L)) {
        q = NEXT(p, *L);
        while ((q != ENDLIST(*L))&&(q->Value % 2 != 0)) {
            DELETE(q, &(*L));
            q = NEXT(p, *L);
        }
        p = NEXT(p, *L);
    }
}

void SPLIT_OE(List L, List *OL, List *EL) {
    Position p;
    p = FIRST(L);
    while (p != ENDLIST(L)) {
        if (p->Value % 2 == 0) {
            AUTO_INSERT(p->Value, &(*EL));
        } else {
            AUTO_INSERT(p->Value, &(*OL));
        }
        p = NEXT(p, L);
    }
}