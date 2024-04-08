#include <stdio.h>
#include <stdlib.h>

int main(){
  int N; scanf("%d", &N);
  int A[N]; for(int i = 0; i < N; i++) scanf("%d", &A[i]);
  int wynik;
  // Mamy ustalone N, zawartość tablicy A oraz zadeklarowaną zmienną wynik 
  // ---------------------------------------------------------------------
  // Poniżej wpisz swój fragment programu:


  // gramatyka opisuje język, który słowami można określić tak:
  // słowa złożone z 0,1,2,3, w których po każdym 0 następuje 1
  // (bez zer pomiędzy)
  wynik = 1;
  
	for (int i = 0; i < N && wynik; i++) {
		if (A[i] == 0) {
			if (i + 1 < N && A[i+1] != 1) {


  for(int i = 0; i < N && wynik; i++){
    // wynik == 1 <==> istnieje wyprowadzenie S -->* A[0]..A[i-1]stan
    if (stan == sprawdzaj_zero){
      if (A[i] == 0) {
        stan = B;
      } else if (A[i] < 0 || A[i] > 3) {
        wynik = 0;
      } // else stan bez zmian
    } else { // stan == B
      if (A[i] == 1) {
        stan = S;
      } else if (A[i] < 1 || A[i] > 3) {
        wynik = 0;
      } // else stan bez zmian
    }
  }
  if (wynik){
    wynik = (stan == S); // bo tylko w stanie S można przeczytać puste słowo
  }

  // Dla ciekawskich: powyższy program symuluje działanie deterministycznego
  // "automatu skończonego" - będzie na IIr na przedmiocie JAO
  // na razie do ew. sprawdzenia w wikipedii :) 

  // Uwaga! Niestety nie jest prawdą, że dla każdej gramatyki
  // istnieje automat skończony, który rozpoznaje język generowany
  // przez tę gramatykę. (np. "palindromy" to przykład
  // gramatyki, której języka nie da się rozpoznać automatem skończonym,
  // bo "nie potrafi on patrzeć w dwa miejsca słowa na raz" :).

  // ---------------------------------------------------------------------
  printf("%d\n", wynik);
  return 0;

}
