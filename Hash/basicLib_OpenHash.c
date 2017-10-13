#include <stdio.h>
#include <stdlib.h>

#define B 7 // number of buckets
typedef int ElementType;
typedef struct Node{
	ElementType Data;
	struct Node* Next;
} Node;
typedef Node* Position;
typedef Position Dictionary[B];

void MAKENULL_SET(Dictionary *D){
	for(int i=0;i<B;i++){
		(*D)[i]=NULL;
	}
}

int H(ElementType X){
	return X % B;
}

int MEMBER(ElementType X, Dictionary D){
	Position P = D[H(X)];
	//search in the list at the bucket H(X)
	while (P!=NULL)
		if (P->Data==X) return 1;
		else P=P->Next;
	return 0;
}

void INSERT_SET(ElementType X, Dictionary *D){
	int Bucket;
	Position P;
	if (!MEMBER(X,*D))
	{
		Bucket=H(X);
		P=(*D)[Bucket]; //giu lai D[Bucket] hien tai
		//Cap phat o nho moi cho D[Bucket]
		(*D)[Bucket] = (Node*)malloc(sizeof(Node)); 		
		(*D)[Bucket]->Data=X;
		(*D)[Bucket]->Next=P;
	}
}

void DELETE_SET(ElementType X, Dictionary *D){
	int Bucket, Done;
	Position P,temp;
	Bucket=H(X);
	// if the list is not null
	if ((*D)[Bucket]!=NULL)	{ 
		if ((*D)[Bucket]->Data==X){ // X is at the head of list
			temp=(*D)[Bucket];
			(*D)[Bucket]=(*D)[Bucket]->Next;
			free(temp);
		}
	else { // search for X
			P=(*D)[Bucket];
			while (P->Next!=NULL) 
				if (P->Next->Data==X) break; 
				else P=P->Next;
			// if x is found
			if (P->Next!=NULL) 	{
				temp=P->Next;
				P->Next=temp->Next;
				free(temp);
			}
		}
	}
}

void READ_SET(Dictionary *L){
	int n;
	int x;
	MAKENULL_SET(L);
	printf("input the number of buckets: ");
	scanf("%d",&n);
	for (int i=1; i<=n; i++){
		printf("input the key %d: ",i);
		scanf("%d",&x);
		INSERT_SET(x,L);		
		}
}

void PRINT_SET(Dictionary L){
	printf("all keys in hash table:\n");
	for (int i=0;i<B;i++){
		printf("[%d] " , i);
		for(Position p = L[i]; p!=NULL; p=p->Next)
			printf("%d ",p->Data);
		printf("\n");
	}
}
