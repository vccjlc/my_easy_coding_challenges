#include <stdbool.h>

extern int znajdz_max_lisc(Twezel *d);

bool jestPoddrzewoM(Twezel *d) {
    if (!d) return false;
    
    int max_lisc = znajdz_max_lisc(d); 
    
    bool lewe = jestPoddrzewoM(d->lsyn);
    bool prawe = jestPoddrzewoM(d->psyn);
   

    return d->val > max_lisc || lewe || prawe;
}
