#include "header.h"
 
 
int main()
{
    BST set;
    bst_init(&set);

    bst_insert(&set, 6);
    bst_insert(&set, 1);
    bst_insert(&set, 8);
    bst_insert(&set, 12);
    bst_insert(&set, 1);
    bst_insert(&set, 3);
    bst_insert(&set, 7);

    bst_inorder(&set);
    puts("");

    bst_remove(&set, 8);
    bst_remove(&set, 6);
    bst_inorder(&set);
    puts("");
    
    return 0;
}
