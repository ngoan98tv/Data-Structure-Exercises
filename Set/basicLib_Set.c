#include <stdio.h>
#include <stdlib.h>

const maxlength = 100; // universal set 1…N
typedef int SET [maxlength];

void MAKENULL_SET(SET* a){
 int i;
 for(i=0;i<maxlength;i++)
      a[i]=0;
}

void UNION (SET a,SET b,SET* c){
 int i;
 for (i=0;i<maxlength;i++)
  if ((a[i]==1)||(b[i]==1)) c[i]=1;
  else c[i]=0;
}

void INTERSECTION (SET a,SET b, SET* c) {
 int i;
 for (i=0;i<maxlength;i++)
  if ((a[i]==1)&&(b[i]==1)) c[i]=1;
  else c[i]=0;
}

void DIFFERENCE (SET a,SET b, SET* c) {
 int i;
 for (i=0;i<maxlength;i++)
  if ((a[i]==1)&&(b[i]==0)) c[i]=1;
  else c[i]=0;
}

