#include <stdio.h>
#include <stdlib.h>
#include "lnad.h"

void printList(FILE* f, Tlista *l){
  while(l != NULL){
    fprintf(f, "%d -> ", l->val);
    l = l->next;
  }
  fprintf(f, "*\n");
}

int len(Tlista *l){
  int d=0;
  while (l != NULL) {
    l = l->next;
    d++;
  }
  return d;
}

void printListElems(FILE* f, Tlista *l){
  while(l != NULL){
    fprintf(f, "%d\n", l->val);
    l = l->next;
  }
}

int main(){
  //int n = 6;
  //int A[] = {6,6,8,8,11,12};
  //int B[] = {6,7,7,8,9,11};

  int n;
  scanf("%d", &n);

  int A[n];
  for(int i=0; i<n; i++){
    scanf("%d", &A[i]);
  }
    
  int B[n];
  for(int i=0; i<n; i++){
    scanf("%d", &B[i]);
  }

  Tlista *lista;

  nadlista(n, A, B, &lista);

  //printList(stdout, lista);

  printf("%d\n",len(lista));
  printListElems(stdout, lista);
  
  return 0;
}
