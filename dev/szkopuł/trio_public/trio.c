#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include "drzewo.h"


drzewo czytaj_drzewo(){
  char b[5];
  scanf("%s", b);
  if (b[0]=='N') {
    return NULL;
  } else { //b='W'
    drzewo pom = malloc(sizeof(Twezel));
    scanf("%d", &pom->val);
    pom->lsyn = czytaj_drzewo();
    pom->psyn = czytaj_drzewo();
    return pom;
  }
}

void free_drzewo(drzewo d){
  if (d==NULL) {
    return;
  } else {
    free_drzewo(d->lsyn);
    free_drzewo(d->psyn);
    free(d);
  }
}   


/* ROZWIĄZANIE **************************************************************/

void trojki(drzewo d, int *wynik) {
    if (d == NULL) {
        return;
    }

    // Check if left child and its left child exist and meet the condition
    if (d->lsyn && d->lsyn->lsyn) {
        if (d->lsyn->val > d->val && d->lsyn->lsyn->val > d->lsyn->val) {
            (*wynik)++;
        }
    }

    // Check if right child and its right child exist and meet the condition
    if (d->psyn && d->psyn->psyn) {
        if (d->psyn->val > d->val && d->psyn->psyn->val > d->psyn->val) {
            (*wynik)++;
        }
    }

    // Recursively check the left and right subtrees
    if(d->lsyn) {
    trojki(d->lsyn, wynik);
}
if (d->psyn) {
    trojki(d->psyn, wynik);
   }
}



int main(){
  drzewo d = czytaj_drzewo();
  int wynik = 0;
  trojki(d, &wynik); 
  printf("%d\n", wynik);
  free_drzewo(d);
  return 0;
}
