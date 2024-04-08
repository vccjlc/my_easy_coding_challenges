// Find k-th smallest value
// BST only, infiksowo

int znajdz_k(drzewo d, int k, int *counter) {
    if (!d)
        return INT_MAX;

    int lewy = znajdz_k(d->lsyn, k, counter);
    if (lewy != INT_MAX)
        return lewy;
    if (*counter == k - 1)
        return d->val;

    (*counter)++;

    return znajdz_k(d->psyn, k, counter);
}


