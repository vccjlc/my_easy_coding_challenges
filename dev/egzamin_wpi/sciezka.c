bool sciezka(Twezel *d, Tlista *l) {
    Tlista *lstart = l;
    return czy_sciezka(d, l, lstart);
}

bool czy_sciezka(Twezel *d, Tlista *l, Tlista *lstart) {
    if (!l || !d)
        return false;

    if (d->val == l->val) {
        if (d->lsyn == NULL && d->psyn == NULL && l->next == NULL) {
            return true;
        } else {
            return czy_sciezka(d->lsyn, l->next, lstart) || czy_sciezka(d->psyn, l->next, lstart);
        }
    }

    if (d->val > l->val)
        return false;

    if (d->val < l->val) {
        if (l == lstart) {
            return czy_sciezka(d->lsyn, l, lstart) || czy_sciezka(d->psyn, l, lstart);
        } else {
            return false;
        }
    }
}
