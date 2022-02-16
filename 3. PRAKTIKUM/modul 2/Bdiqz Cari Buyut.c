#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

/**
 * Node structure and
 * uniqueBST structure
 */

typedef struct bstnode_t {
    int key;
    struct bstnode_t \
        *left, *right;
} BSTNode;

typedef struct bst_t {
    BSTNode *_root;
    unsigned int _size;
} BST;

/**
 * !!! WARNING UTILITY FUNCTION !!!
 * Recognized by prefix "__bst__"
 * ---------------------------------------------
 * Note that you better never access these functions, 
 * unless you need to modify or you know how these functions work.
 */

BSTNode* __bst__createNode(int value) {
    BSTNode *newNode = (BSTNode*) malloc(sizeof(BSTNode));
    newNode->key = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

BSTNode* __bst__insert(BSTNode *root, int value) {
    if (root == NULL) 
        return __bst__createNode(value);

    if (value < root->key)
        root->left = __bst__insert(root->left, value);
    else if (value > root->key)
        root->right = __bst__insert(root->right, value);
    
    return root;
}

BSTNode* __bst__search(BSTNode *root, int value) {
    while (root != NULL) {
        if (value < root->key)
            root = root->left;
        else if (value > root->key)
            root = root->right;
        else
            return root;
    }
    return root;
}

BSTNode* __bst__findMinNode(BSTNode *node) {
    BSTNode *currNode = node;
    while (currNode && currNode->left != NULL)
        currNode = currNode->left;
    
    return currNode;
}

/**
 * PRIMARY FUNCTION
 * ---------------------------
 * Accessible and safe to use.
 */

void bst_init(BST *bst) {
    bst->_root = NULL;
    bst->_size = 0u;
}

bool bst_isEmpty(BST *bst) {
    return bst->_root == NULL;
}

bool bst_find(BST *bst, int value) {
    BSTNode *temp = __bst__search(bst->_root, value);
    if (temp == NULL)
        return false;
    
    if (temp->key == value)
        return true;
    else
        return false;
}

void bst_insert(BST *bst, int value) {
    if (!bst_find(bst, value)) {
        bst->_root = __bst__insert(bst->_root, value);
        bst->_size++;
    }
}

int cari_buyut(BST* bst, int B1, int B2){
    
    BSTNode* root = bst->_root;
    while(1){
        
        if( (B1<root->key && B2>root->key) ||(B2<root->key && B1>root->key)){
            return root->key;
        }
        else if( B1<root->key && B2<root->key){
            root = root->left;
        }
        else if( B1>root->key && B2>root->key){
            root = root->right;
        }
        else if( B1==root->key || B2==root->key){
            return root->key;
        }
        
    }
    
}
int main()
{
    BST bst;
    int N;
    int A; //"1" atau "2". 1->input. 2->cek buyut
    int B; //bilangan yang insya Allah akan dimasukkan ke pohon keluarga
    int B1, B2; //2 bilangan yang akan dicek buyutnya, insya Allah
    int i, j=0;
    int output[5001];
    bst_init(&bst);

    scanf("%d", &N);
    
    for(i=0; i<N; i++){
        scanf("%d", &A);
        
        if(A == 1){
            scanf("%d", &B);
            bst_insert(&bst, B);
        }
        else if(A == 2){ //cari buyut
            scanf("%d %d", &B1, &B2);
            if(bst_find(&bst, B1) && bst_find(&bst, B2)){ //jika datanya ada di bst
                output[j] = cari_buyut(&bst, B1, B2);
            }
            else output[j] = 0; //jika datanya gaada di bst
            j++;
        }
        else{
        	output[j] = 0;
        	j++;
		}
    }
    
    for(i=0; i<j; i++){
        if(output[i] != 0){
            printf("%d\n", output[i]);
        }
        else{
            printf("Data tidak valid.\n");
        }
            
    }
    return 0;
}
