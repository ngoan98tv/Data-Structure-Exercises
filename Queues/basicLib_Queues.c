#include "basicLib_LinkedList.c"

typedef List Queues;

// Make stack S be an empty stack. 
void MAKENULL_QUEUE(Queues* Q){
	MAKENULL_LIST(&(*Q));
}
//Return true if S is an empty stack; return false otherwise.
int EMPTY(Queues Q){
    return IS_EMPTY(Q);
}
//Return true if S is full; return false otherwise.
int FULL(Queues Q){
    return 0;
}
// Return the element at the top of stack S. TOP(S) can be written in terms of list
ElementType FRONT(Queues Q){
    if (!EMPTY(Q))
        RETRIEVE(FIRST(Q),Q);
}
//Delete the top element of the stack, that is, DELETE_LIST(FIRST(S), S).
void DEQUEUE(Queues* Q){
    if (!EMPTY(*Q))
        DELETE(FIRST(*Q),&(*Q));
}
//Insert the element x at the top of stack S. This operation is INSERT_LIST(x, FIRST(S), S).
void ENQUEUE(ElementType x, Queues* Q){
    INSERT(x,NEXT(LAST(*Q),*Q),&(*Q));
}
