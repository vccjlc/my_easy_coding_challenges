#include <stdbool.h>
#include <limits.h>

typedef struct drzewo {
    int val;
    struct drzewo *lsyn;
    struct drzewo *psyn;
} drzewo;

int max(int a, int b) {
    return a > b ? a : b;
}

bool sprawdz_max(drzewo *d, int *max_leaf) {

    if (!d) return false;

    if (!d->lsyn && !d->psyn) {
        *max_leaf = d->val;
        return false;
    }

    int max_lewy = INT_MIN, max_prawy = INT_MIN;
    bool lewe = d->lsyn ? sprawdz_max(d->lsyn, &max_lewy) : false;
    bool prawe = d->psyn ? sprawdz_max(d->psyn, &max_prawy) : false;

    *max_leaf = max(max_lewy, max_prawy);

    return d->val > *max_leaf || lewe || prawe;
}

bool jestPoddrzewoM(drzewo *d) {
    int max_leaf = INT_MIN;
    return sprawdz_max(d, &max_leaf);
}
