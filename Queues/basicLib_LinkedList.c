/* 
 * File:   basicLib_Pointer.c
 * Author: Ngoan Tran
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char* ElementType;
typedef struct Node {
    ElementType Value;
    struct Node* Next;
} Node;
typedef Node* List;
typedef Node* Position;

void MAKENULL_LIST(List* L) {
    (*L) = (Node*)malloc(sizeof(Node));
    (*L)->Next = NULL;
}

int IS_EMPTY(List L) {
    return (L->Next == NULL);
}

Position ENDLIST(List L){
    return NULL;
}

Position NEXT(Position p, List L){
    return (p->Next);
}

Position FIRST(List L){
    return (L->Next);
}

Position LAST(List L){
    Position tmp = L;
    while (tmp->Next != NULL){
        tmp = tmp->Next;
    }
    return tmp;
}

Position PREVIOUS(Position p, List L){
    Position tmp = L;
    while ((tmp->Next != NULL) && (tmp->Next != p))
        tmp = tmp->Next;
    return tmp;
}

Position LOCATE(ElementType x, List L){
    Position tmp = L;
    while ((tmp->Next != NULL)&&(tmp->Next->Value < x))
        tmp = tmp->Next;
    if ((tmp->Next != NULL)&&(tmp->Next->Value == x))
        return tmp->Next;
    else
        return NULL;
}

ElementType RETRIEVE(Position p, List L){
    return p->Value;
}

void INSERT(ElementType x, Position p, List* L) {
    Position tmp = (Node*)malloc(sizeof(Node));
    tmp->Next = p;
    tmp->Value = x;
    PREVIOUS(p,*L)->Next = tmp;
}

void DELETE(Position p, List* L) {
    PREVIOUS(p,*L)->Next = NEXT(p,*L);
    free(p);
}

void SWAP(Position x, Position y, List* L){
    ElementType tmp;
    tmp = (x)->Value;
    (x)->Value = (y)->Value;
    (y)->Value = tmp;
}