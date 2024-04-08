#include <stdio.h>
#include <limits.h>

int czy_poza(int x);
int dlugosc_ciagu_collatza(int x);

int main() {
        int a, b, max_dl = 0, max_x = 0, dl, x_poza = 0;
        scanf("%d %d", &a, &b);

        if (a == 1 && b == 1) {
                printf("1 0\n");
                return 0;
        }

        for (int x = a; x <= b; x++) {
                if (czy_poza(x)) {
                        x_poza = x;
                        break;
                }

                dl = dlugosc_ciagu_collatza(x);
                if (dl > max_dl) {
                        max_dl = dl;
                        max_x = x;
                }
        }

        if (x_poza) {
                printf("%d?\n", x_poza);
        } else {
                printf("%d %d\n", max_x, max_dl);
        }

        return 0;
}

int czy_poza(int x) {
        while (x != 1) {
                if (x % 2 == 0) {
                        x /= 2;
                } else {
                        if (x > (INT_MAX - 1) / 3) {
                                return 1;
                        }
                        x = 3 * x + 1;
                }
        }
        return 0;
}

int dlugosc_ciagu_collatza(int x) {
        int dl = 0;
        while (x != 1) {
                if (x % 2 == 0) {
                        x /= 2;
                } else {
                        x = 3 * x + 1;
                }
                dl++;
        }
        return dl;
}
