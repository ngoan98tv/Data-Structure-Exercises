#include "basicLib_GeneralTreeOnPointer.c"


void PROD(Tree T); //preorder node-left-right
void INOD(Tree T); //inorder left-node-right
void POD(Tree T); //postorder left-right-node
void BFO(Tree T); //Breadth-first order

int main() {
    //Bai Tap 1 & 2 Chuong III
    Tree T1 = CREATE2('D',NULL,NULL);
    Tree T2 = CREATE2('M',NULL,NULL);
    Tree T3 = CREATE2('N',NULL,NULL);
    Tree T4 = CREATE2('F',NULL,NULL);
    Tree T5 = CREATE2('J',NULL,NULL);
    Tree T6 = CREATE2('K',NULL,NULL);
    Tree T7 = CREATE2('L',NULL,NULL);
    Tree T8 = CREATE2('I',T2,T3);
    Tree T9 = CREATE2('E',T8,NULL);
    Tree T10 = CREATE2('B',T1,T9);
    Tree T11 = CREATE2('G',T5,T6);
    Tree T12 = CREATE2('C',T4,T11);
    Tree T13 = CREATE2('H',T7,NULL);
    ADD_RIGHT_SIBLING(T11,T13);
    Tree T = CREATE2('A',T10,T12);
    printf("preorder: "); PROD(T); printf("\n");
    printf("inorder: "); INOD(T); printf("\n");
    printf("postorder: "); POD(T); printf("\n");
    printf("breadth-first order: "); BFO(T); printf("\n");
    return 0;
}

void PROD(Tree T){
    printf("%c ", LABEL(T));
    if (LEFTMOST_CHILD(T) != NULL)
    {
        PROD(LEFTMOST_CHILD(T));
    }
    if (RIGHT_SIBLING(T) != NULL)
    {
        PROD(RIGHT_SIBLING(T));
    }
}

void INOD(Tree T){
   if (LEFTMOST_CHILD(T) != NULL)
    {
        INOD(LEFTMOST_CHILD(T));
    }
    printf("%c ", LABEL(T));
    if (LEFTMOST_CHILD(T) != NULL)
    {
        Node i = LEFTMOST_CHILD(T);
        while (RIGHT_SIBLING(i) != NULL)
        {
            INOD(RIGHT_SIBLING(i));
            i = RIGHT_SIBLING(i);
        }
        
    }
}

void POD(Tree T){
    if (LEFTMOST_CHILD(T) != NULL)
    {
        POD(LEFTMOST_CHILD(T));
    }
    printf("%c ", LABEL(T));
    if (RIGHT_SIBLING(T) != NULL)
    {
        POD(RIGHT_SIBLING(T));
    }
}

void BFO(Tree T){
    Queues Q;
    MAKENULL_QUEUE(&Q);
    ENQUEUE(T, &Q);
    while (!EMPTY_QUEUE(Q)){
        Node n = FRONT(Q);
        DEQUEUE(&Q);
        printf("%c ", LABEL(n));
        if (LEFTMOST_CHILD(n) != NULL)
        {
            Node i = LEFTMOST_CHILD(n);
            while (i != NULL){
                ENQUEUE(i,&Q);
                i = RIGHT_SIBLING(i);
            }
        }
    }
}