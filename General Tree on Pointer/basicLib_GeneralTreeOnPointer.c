#include <stdio.h>
#include <stdlib.h>

typedef char DataType;
typedef struct Cell{
	DataType Data;
	struct Cell* Leftmost_Child;
	struct Cell* Right_Sibling;
	struct Cell* Parent;
} Cell;
typedef Cell* Node;
typedef Node Tree;

typedef struct Queue{
    Node arr[10];
    int First, Last;
} Queues;

Node PARENT(Node n){
    return n->Parent;
}

Node LEFTMOST_CHILD(Node n){
    return n->Leftmost_Child;
}

Node RIGHT_SIBLING(Node n){
    return n->Right_Sibling;
}

Node ROOT(Tree T){
    while (T->Parent != NULL)
        T = T->Parent;
    return T;
}

DataType LABEL(Node n){
    return n->Data;
}

void MAKENULL_TREE(Tree *T){
    *T = NULL;
}

int EMPTY(Tree T){
    return T == NULL;
}

Tree CREATE2(DataType label, Tree LeftmostChild, Tree RightSibling ){
    Node n = (Node)(malloc(sizeof(Node)));
    n->Parent = NULL;
    n->Leftmost_Child = LeftmostChild;
    n->Right_Sibling = NULL;
    n->Data = label;
    if (LeftmostChild != NULL){
        LeftmostChild->Parent = n;
        LeftmostChild->Right_Sibling = RightSibling;
    }
    if (RightSibling != NULL){
        RightSibling->Parent = n;
    }
    return n;
}

void ADD_RIGHT_SIBLING(Node L, Node R){
    L->Right_Sibling = R;
    R->Parent = L->Parent;
}

void MAKENULL_QUEUE(Queues *Q){
    Q->First = 0;
    Q->Last = 0;
}

void ENQUEUE(Node n, Queues *Q){
    Q->arr[Q->Last] = n;
    Q->Last = (Q->Last + 1)%10;
}

Node FRONT(Queues Q){
    return Q.arr[Q.First];
}

void DEQUEUE(Queues *Q){
    Q->First = (Q->First + 1)%10;
}

int EMPTY_QUEUE(Queues Q){
    return Q.First == Q.Last;
}