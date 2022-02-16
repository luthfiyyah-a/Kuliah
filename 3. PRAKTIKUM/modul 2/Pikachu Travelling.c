#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>
#define MAX_N 100

/* struct */

typedef struct bstnode_t {
    int key;
    struct bstnode_t \
        *left, *right;
} BSTNode;

typedef struct bst_t {
    BSTNode *_root;
    unsigned int _size;
} BST;

/* utility function */

BSTNode* __bst__createNode(int value) {
    BSTNode *newNode = (BSTNode*) malloc(sizeof(BSTNode));
    newNode->key = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

BSTNode* __search(BSTNode *root, int value) {
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

BSTNode* __bst__insert(BSTNode *root, int value) {
    if (root == NULL) 
        return __bst__createNode(value);

    if (value < root->key)
        root->left = __bst__insert(root->left, value);
    else if (value > root->key)
        root->right = __bst__insert(root->right, value);
    
    return root;
}

/* primary function */

void bst_init(BST *bst) {
    bst->_root = NULL;
    bst->_size = 0u;
}

bool bst_find(BST *bst, int value) {
    BSTNode *temp = __search(bst->_root, value);
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

/* fungsi khusus */

//untuk menghitung jarak dari suatu root ke suatu nilai yang berada di bawah root itu.
int hitung(BSTNode* root, int target)
{
    int i = 0;
    while(root->key != target){
        if(target < root->key){
            root = root->left;
        }
        else if(target > root->key){
            root = root->right;
        }
        i++;
    }
    
    return i;
}

int jarak(BST* bst, int a, int b)
{
    BSTNode* root = bst->_root;
    while(1){
        if((root->key > a && root->key < b) || (root->key > b && root->key < a)){
            return (hitung(root, a) + hitung(root, b));
        }
        else if(root->key > a && root->key > b){
            root = root->left;
        }
        else if(root->key < a && root->key < b){
            root = root->right;
        }
        else if(root->key == a){
            return hitung(root, b);
        }
        else if(root->key == b){
            return hitung(root, a);
        }
    }
}

int main() {
    
    BST bst;
    int N; //banyaknya kota
    int Ni; //kota
    int n; //banyaknya pasangan kota yang mau dicek jaraknya
    int a, b; //2 kota yang mau dicek jaraknya
    int output[MAX_N]; //array yang menyimpan output (jarak antar kota)
    int i;
    
    scanf("%d", &N);
    
    for(i=0; i<N; i++){
        scanf("%d", &Ni);
        bst_insert(&bst, Ni);
    }
    
    scanf("%d", &n);
    
    for(i=0; i<n; i++){
        scanf("%d %d", &a, &b);
        output[i] = jarak(&bst, a, b);
    }
    
    for(i=0; i<n; i++){
        printf("%d\n", output[i]);
    }
    
    return 0;
}
