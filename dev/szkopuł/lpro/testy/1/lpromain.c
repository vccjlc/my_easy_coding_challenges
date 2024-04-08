#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lpro.h"


// wypisywaniem listy w jednej linii z zaznaczeniem
// pozycji kursora (do testowania)
void printList(FILE* f, Tlista *l, Tlista *kursor){
  while(l != NULL){
    fprintf(f, (l==kursor ? "[%d] -> " : "%d -> "), l->val);
    l = l->next;
  }
  fprintf(f, (l==kursor ? "[*]\n" : "*\n"));
}
#ifndef _lpro_h
#define _lpro_h

struct lista {
  int val;
  struct lista *next;
};

typedef struct lista Tlista;

void przetworz(char* program, Tlista** lista_ptr);

#endif
// tworzenie listy z tablicy (do testowania)
Tlista *mkList(int n, int tab[n]){
  Tlista *l = NULL;
  for (int i = n-1; i >= 0; i--){
    Tlista *pom = malloc(sizeof(Tlista));
    pom->val = tab[i];
    pom->next = l;
    l = pom;
  }
  return l;
}

// obliczanie długości listy
int len(Tlista *l){
  int d=0;
  while (l != NULL) {
    l = l->next;
    d++;
  }
  return d;
}

// wypisywanie elementów listy w osobnych wierszach
void printListElems(FILE* f, Tlista *l){
  while(l != NULL){
    fprintf(f, "%d\n", l->val);
    l = l->next;
  }
}

void freeList(Tlista *l){
  while(l != NULL){
    Tlista *pom = l;
    l = l->next;
    free(pom);
  }
}

int main(){
  //int n = 8;
  //int tab[8] = {10,11,12,13,14,15,16,17};

  //Tlista *lista = mkList(n, tab);

  //char* program = "D2F1R5I1I9H1M5D1H0I0";

  
  // Wczytanie danych
  //char program[100];
  //scanf("%s", program);
  char* program=NULL;
  size_t buflen=0;
  getline(&program, &buflen, stdin);

  program[strlen(program)-1]=0; // zastąpienie \n przez \0
  
  int n;
  scanf("%d", &n);

  Tlista *atrapa = malloc(sizeof(Tlista));
  Tlista *lista = atrapa;
  
  for(int i=0; i<n; i++){
    int v;
    scanf("%d", &v);
    lista->next = malloc(sizeof(Tlista));
    lista = lista->next;
    lista->val = v;
  }
  lista->next = NULL;
  
  lista = atrapa->next;
  free(atrapa);

  
  // Wywołanie testowanej funkcji 
  przetworz(program, &lista);

  // Wypisanie wyniku
  printf("%d\n",len(lista));
  printListElems(stdout,lista);

  freeList(lista);
  free(program);
  
  return 0;
}
  

