#include <stdio.h>

#define MAXLENGTH 100 /* array length */
#define NULL -1

typedef char DataType; // type of labels
typedef int Node; //type of indices of nodes 
typedef struct {
	DataType Data[MAXLENGTH]; /* for storing labels of nodes*/
	Node Parent[MAXLENGTH]; /* for storing parent index*/
	int MaxNode; /* number of actual nodes */
} Tree; 

void MAKENULL_TREE (Tree T){
	T.MaxNode=0;
}

int EMPTY_TREE(Tree T){
	return T.MaxNode == 0;
}

Node PARENT(Node n,Tree T){
	if (EMPTY_TREE(T) || (n>T.MaxNode-1))
		return NULL;
	else return T.Parent[n];
}

DataType LABEL_NODE(Node n,Tree T){
	if (!EMPTY_TREE(T) && (n<=T.MaxNode-1))
		return T.Data[n];
}

Node ROOT(Tree T){
	if (!EMPTY_TREE(T)) return 0;
	else return NULL;
}

Node LEFTMOST_CHILD(Node n,Tree T){
	Node i;
	if (n<0) return NULL;
	i=n+1;/* the first index for searching the left most child*/
	while (i<=T.MaxNode-1) 
		if (T.Parent[i]==n) return i;
	else i=i+1;
	return NULL;
}

Node RIGHT_SIBLING(Node n,Tree T){
	Node i,parent;
	if (n<0) return NULL;
	parent=T.Parent[n];
	i=n+1;
	while (i<=T.MaxNode-1) 
	//search for node after n with same parent
		if (T.Parent[i]==parent) return i;  
		else i=i+1;
	return NULL;
}

void PreOrder(Node n,Tree T){
	if (n!=NULL){
		printf("%c ",LABEL_NODE(n,T));
		Node i=LEFTMOST_CHILD(n,T);
		while (i!=NULL){
			PreOrder(i,T);
			i=RIGHT_SIBLING(i,T);
		}
	}
}

void InOrder(Node n,Tree T){
	Node i=LEFTMOST_CHILD(n,T);
	if (i!=NULL) InOrder(i,T);
	printf("%c ",LABEL_NODE(n,T));
	i=RIGHT_SIBLING(i,T);
	while (i!=NULL){
		InOrder(i,T);
		i=RIGHT_SIBLING(i,T);
	}
}

void PosOrder(Node n,Tree T){
	Node i=LEFTMOST_CHILD(n,T);
	while (i!=NULL){
		PosOrder(i,T);
		i=RIGHT_SIBLING(i,T);
	}
	printf("%c ",LABEL_NODE(n,T));
}	 