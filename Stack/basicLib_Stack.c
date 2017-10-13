#include "basicLib_LinkedList.c"

typedef List Stack;

// Make stack S be an empty stack. 
void MAKENULL_STACK(Stack* S){
	MAKENULL_LIST(&(*S));
}
//Return true if S is an empty stack; return false otherwise.
int EMPTY(Stack S){
    return IS_EMPTY(S);
}
//Return true if S is full; return false otherwise.
int FULL(Stack S){
    return 0;
}
// Return the element at the top of stack S. TOP(S) can be written in terms of list
ElementType TOP(Stack S){
    if (!EMPTY(S))
        RETRIEVE(FIRST(S),S);
}
//Delete the top element of the stack, that is, DELETE_LIST(FIRST(S), S).
int POP(Stack* S){
    if (EMPTY(*S))
        return 0;
    DELETE(FIRST(*S),&(*S));
}
//Insert the element x at the top of stack S. This operation is INSERT_LIST(x, FIRST(S), S).
void PUSH(ElementType x, Stack* S){
    INSERT(x,FIRST(*S),&(*S));
}
