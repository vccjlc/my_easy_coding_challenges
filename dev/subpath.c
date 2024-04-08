struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct ListNode {
    int val;
    struct ListNode *next;
};

bool dfs(struct TreeNode* root, struct ListNode* list) {
    // Jeśli lista jest całkowicie przebyta, sprawdź, czy bieżący węzeł drzewa jest liściem
    if (list == NULL) {
        // Najpierw sprawdź, czy root jest NULL, a następnie, czy to węzeł liścia
        return root != NULL && root->left == NULL && root->right == NULL;
    }
    // Jeśli węzeł drzewa jest NULL lub wartości się nie zgadzają, zwróć fałsz
    if (root == NULL || root->val != list->val) return false;
    // Kontynuuj wyszukiwanie z następnym węzłem listy i lewym lub prawym dzieckiem drzewa
    return dfs(root->left, list->next) || dfs(root->right, list->next);
}

bool czy_sciezka(struct ListNode* list, struct TreeNode* root) {
    if (list == NULL) return false;
    if (root == NULL) return false; // Jeśli drzewo jest null, lista nie może być podścieżką
    // Sprawdź, czy lista odpowiada ścieżce w dół od bieżącego węzła drzewa
    if (dfs(root, list)) return true;
    // Rekurencyjnie sprawdź lewe i prawe poddrzewa
    return czy_sciezka(list, root->left) || czy_sciezka(list, root->right);
}

