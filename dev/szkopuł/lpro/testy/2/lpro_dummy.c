#include "lpro.h"
#include<stdlib.h>
#include<stdio.h>

void przetworz(char* program, Tlista** lista_ptr){

  // Działa (prawie ;) TYLKO dla listy:
  // 10 -> 11 -> 12 -> 13 -> 14 -> 15 -> 16 -> 17 -> *
  // i wywołania  przetworz("D2F1R5I1I9H1M5D1H0I0", &list);
  // rezultat końcowy:
  // 0 -> 12 -> 16 -> 15 -> 14 -> 13 -> 1 -> 17 -> *

  // tablica (wskaźników do) węzłów:
  // początkowo z oryginalnej listy
  Tlista *wezly[8];
	
  Tlista *pom = *lista_ptr;
  int i=0;
  while(pom!=NULL){
    wezly[i] = pom;
    pom = pom->next;
    i++;
  }

  if (i==8){
    // Usuwanie węzłów skasowanych
    free(wezly[0]);
    free(wezly[1]);
    
    // Nowe węzły dodane
    wezly[0] = malloc(sizeof(Tlista));
    wezly[0]->val = 0;
    
    wezly[1] = malloc(sizeof(Tlista));
    wezly[1]->val = 1;
    
    *lista_ptr = wezly[0];      // 0
    wezly[0]->next = wezly[2];  //  0->12
    wezly[2]->next = wezly[6];  // 12->16
    wezly[6]->next = wezly[5];  // 16->15
    wezly[5]->next = wezly[4];  // 15->14
    wezly[4]->next = wezly[3];  // 14->13
    wezly[3]->next = wezly[1];  // 13->1
    wezly[1]->next = wezly[7];  //  1->17
    wezly[7]->next = NULL;      // 17->*

  } else {

    // zakładamy, że i==3 :)
    // Nowe węzły dodane
    wezly[3] = malloc(sizeof(Tlista));
    wezly[3]->val = 1;
    
    wezly[4] = malloc(sizeof(Tlista));
    wezly[4]->val = 2;

    wezly[0]->next = wezly[3];  // 10->1
    wezly[3]->next = wezly[4];  // 1->2
    wezly[4]->next = wezly[1];  // 2->13
    // 13-14, 14->* już jest
  } 

}
