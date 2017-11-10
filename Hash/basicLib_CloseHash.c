#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define B 7
#define Deleted -999
#define  Empty	-999
typedef int  ElementType;		
typedef  ElementType Dictionary [B];

int h(ElementType x){
	return x % B;
}

void MAKENULL_SET(Dictionary* D){
	for (int i=0;i<B; i++)
		(*D)[i]=Empty;
}

/*Locate function search in hash table from
 the bucket H(x) until getting x or
  getting an empty bucket.
  It returns the index of bucket at the stop
  position of searching
*/
int LOCATE(ElementType x, Dictionary A){
	int inital,i;
	inital=h(x);
	i=0;
	while (( A[(inital+i) %  B]!=x) && (A[(inital+i) % B]!= Empty) && (i <=B)) 
		i++;
	return (inital+i) % B;
}

/*
 Locate1 function search in hash table from
 the bucket H(x) until getting x or
 getting an empty bucket or
 an deleted bucket.
 It returns the index of bucket at the stop
 position of searching.
*/
int LOCATE1(ElementType x, Dictionary A){
	int inital,i;
	inital=h(x);
	i=0;
	while 	((i<B) && ( A[(inital+i) % B]!=x) && (A[(inital+i) % B]!= Empty) 
		&& (A[(inital+i) % B]!= Deleted)) 
		i++;
	return (inital+i) %  B ;
} 

int MEMBER(ElementType x, Dictionary A){
	return A[LOCATE(x,A)] == x;
}

void INSERT_SET(ElementType x,Dictionary* A){
	int bucket;
	if (*A[LOCATE(x,(*A))]!=x){ // x is not in hash table yet 
		bucket= LOCATE1 (x,(*A));
		if (((*A)[bucket]==Empty) || ((*A)[bucket]==Deleted))
			(*A)[bucket]=x;
		else printf ("error: table is full");
	}
}


void DELETE_SET(ElementType x,Dictionary* A){
	int bucket;
	bucket=LOCATE(x,(*A));
	if ((*A)[bucket]==x) 
		(*A)[bucket]=Deleted; //mark as deleted 
}


void PRINT_SET(Dictionary L){
	printf("all keys in hash table :\n");
	for (int i=0;i<B;i++){
		printf("[%d] %d\n" , i, L[i]);
	}
}


void READ_SET(Dictionary * L){
	int n;
	int x;
	MAKENULL_SET(&(*L));
	printf("input the number of bucket of hash table: ");
	scanf("%d",&n);
	for (int i=1; i<=n; i++){
		printf("input the key %d: ",i);
		scanf("%d",&x);
		INSERT_SET(x,&(*L));		
	}
}