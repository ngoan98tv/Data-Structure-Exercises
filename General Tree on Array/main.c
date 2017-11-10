#include "basicLib_GeneralTreeOnArray.c"

void READTREE(Tree *T){
	int i;	
	MAKENULL_TREE((*T));
	//input the number of nodes
	do {
		printf("how many nodes of tree? ");
		scanf("%d",&(*T).MaxNode);
	} while (((*T).MaxNode<1) || ((*T).MaxNode>MAXLENGTH));
	printf("label of root: ");
	scanf("%c", &(*T).Data[0]);
	scanf("%c", &(*T).Data[0]);
	(*T).Parent[0]=NULL; /* root has no parent */
	for (i=1;i<=(*T).MaxNode-1;i++){
		printf("input the index of parent of node %d: ",i);
		scanf("%d",&(*T).Parent[i]);
		printf("input the label of node %d: ",i);
		scanf("%c",&(*T).Data[i]);
		scanf("%c",&(*T).Data[i]);
	}
}

int main(){
	Tree T;
	printf("input data to create a tree\n");
	READTREE(&T);
	printf("preorder: ");
	PreOrder(ROOT(T),T); 
	printf("\ninorder: ");
	InOrder(ROOT(T),T);
	printf("\npostorder: ");
	PosOrder(ROOT(T),T);
	return 0;
}