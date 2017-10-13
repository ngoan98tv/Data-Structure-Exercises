#include "basicLib_GeneralTree.c"


void PROD(Tree T); //preorder node-left-right
void INOD(Tree T); //inorder left-node-right
void POD(Tree T); //postorder left-right-node
void BFS(Tree T); //Breadth-first order

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
    printf("BFS: "); BFS(T); printf("\n");
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

void BFS(Tree T){
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

/*

int is_sibling(Node n, Node m){
    return PARENT(n) == PARENT(m);
}

int is_ancestor(Node n, Node m){
    while (m != NULL){
        if (m == n)
            return 1;
        else
            m = m->parent;
    }
    return 0;
}

int oneChildNodes(Tree T){
    if ((T->left == NULL)&&(T->right != NULL)){
        return (1 + oneChildNodes(T->right));
    }
    if ((T->left != NULL)&&(T->right == NULL)){
        return (1 + oneChildNodes(T->left));
    }
    if ((T->left == NULL)&&(T->right == NULL)){
        return 0;
    }
    if ((T->left != NULL)&&(T->right != NULL)){
        return oneChildNodes(T->left) + oneChildNodes(T->right);
    }
}

int numLeafs(Tree T){
    if ((T->left == NULL)&&(T->right == NULL)){
        return 1;
    }
    if ((T->left == NULL)&&(T->right != NULL)){
        return numLeafs(T->right);
    }
    if ((T->left != NULL)&&(T->right == NULL)){
        return numLeafs(T->left);
    }
    if ((T->left != NULL)&&(T->right != NULL)){
        return numLeafs(T->left) + numLeafs(T->right);
    }
}

Tree CREATE(DataType label, Tree LeftChild, Tree RightChild ){
    Tree n = (Tree)(malloc(sizeof(Tree)));
    n->parent = NULL;
    n->left = LeftChild;
    n->right = RightChild;
    n->label = label;
    return n;
}

*/