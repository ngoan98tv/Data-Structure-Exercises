#include <stdio.h>
#include <stdlib.h>
#define MaxLength 100

typedef int ElementType;
typedef int Position;
typedef struct {
    ElementType Element[MaxLength];
    int Last;
} List;

// read elements and put to list L.
void READ_LIST_fromFIRST(List* L){ 
    Position p=0;
    printf("How many elements on list: ");
    scanf("%d", &(L->Last));
    while (p < L->Last){
        printf("Enter element %d: ", p+1);
        scanf("%d", &(L->Element[p]));
        p++;
    }
}
// read elements and put to list L.
void READ_LIST_fromLAST(List* L){ 
    Position p;
    printf("How many elements on list: ");
    scanf("%d", &(L->Last));
    p = L->Last -1;
    while (p >= 0){
        printf("Enter element %d: ", p+1);
        scanf("%d", &(L->Element[p]));
        p--;
    }
}
// print all elements on list L.
void PRINT_LIST(List L){ 
    Position p = 0;
    printf("Having %d elements on list: ", L.Last);
    while (p < L.Last) {
        printf("%d, ", L.Element[p]);
        p++;
    }
    printf("\n");
}
// Insert x at position p in list L.
void INSERT(ElementType x, Position p, List* L){ 
    if ((p > 0)&&(p <= L->Last)) {
        Position tmp = L->Last;
        L->Last++;
        while (tmp >= p){
            L->Element[tmp] = L->Element[tmp-1];
            tmp--;
        }
        L->Element[p-1] = x;
    }
}
// Delete the element at p of list L
void DELETE(Position p, List* L){ 
    if (p != 0) {
    while (p <= L->Last){
        L->Element[p-1] = L->Element[p];
        p++;
    }
    L->Last--;
    }
}
// Create empty list
void MAKENULL_LIST(List* L){
    L->Last = 0;
}
// Check if list L is empty
int IS_EMPTY(List L){
    return (L.Last == 0);
}
// Return the element after p of list L
Position NEXT(Position p, List L){
    return p++;
}
// Return the element before p of list L
Position PREVIOUS(Position p, List L){
    return p--;
}
// returns the position of x on list L. If x does not appear at all, then 0 is returned.
Position LOCATE(ElementType x, List L){
    Position p=0;
    while ((p < L.Last)&&(L.Element[p] != x)){
        p++;
    }
    if (p == L.Last)
        return 0;
    else
        return p+1;
}
// returns the element at position p on list L 
ElementType RETRIEVE(Position p, List L){
    return L.Element[p-1];
}
// sorting increase
void SORT(List* L){
    ElementType tmp;
    Position i, j;
    for (i=0; i<L->Last; i++)
        for (j=i+1; j<L->Last; j++) {
            if (L->Element[i] > L->Element[j]){
                tmp = L->Element[i];
                L->Element[i] = L->Element[j];
                L->Element[j] = tmp;
            }
        }
}
// invert
void INVERT(List* L) {
    ElementType tmp;
    Position i;
    for (i=0; i < (L->Last)/2; i++){
        tmp = L->Element[L->Last -i -1];
        L->Element[L->Last -i -1] = L->Element[i];
        L->Element[i] = tmp;
    }
}

void AUTO_INSERT(ElementType x, List* L) {
    Position p;
    p = 0;
    while ((x > L->Element[p])&&(p < L->Last)){
        p++;
    }
    if (p < L->Last) {
        p++;
        Position tmp = L->Last;
        L->Last++;
        while (tmp >= p){
            L->Element[tmp] = L->Element[tmp-1];
            tmp--;
        }
        L->Element[p-1] = x;
    }
    else{
        L->Element[L->Last] = x;
        L->Last = L->Last +1;
    }
    
}

void ELIMINATE_SIMILAR_ELEMENTS(List* L) {
    Position p;
    for (p=0; p < L->Last -1; p++){
         while (L->Element[p] == L->Element[p+1])
             DELETE(p+1,&(*L));
    }
}