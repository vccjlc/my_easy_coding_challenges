#include <stdio.h>

int wieksza(int a, int b) {
  if (a > b) {
    return a;
  } else {
    return b;
  }
}

int main(void) {
  int x, y;
  scanf("%d", &x);
  scanf("%d", &y);
  printf("%d\n", wieksza(x, y));
  return 0;
}
