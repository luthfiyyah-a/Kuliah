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

//variabel global
int index;
int berhenti;

typedef struct{
   int data;
   int perintah; //"1" atau "2"
   int index; //diperlukan saat perintah "2"
   int ada; //mengecek apakah data tersebut ada di BST atau tidak. jika ada, ada=1. jika tidak, ada=0
}Output;


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

BSTNode* __bst__remove(BSTNode *root, int value) {
    if (root == NULL) return NULL;

    if (value > root->key) 
        root->right = __bst__remove(root->right, value);
    else if (value < root->key) 
        root->left = __bst__remove(root->left, value);
    else {
        
        if (root->left == NULL) {
            BSTNode *rightChild = root->right;
            free(root);
            return rightChild;
        }
        else if (root->right == NULL) {
            BSTNode *leftChild = root->left;
            free(root);
            return leftChild;
        }

        BSTNode *temp = __bst__findMinNode(root->right);
        root->key     = temp->key;
        root->right   = __bst__remove(root->right, temp->key);
    }
    return root;
}

void hitung_index(void){
    index++;
}

void __bst__postorder(BSTNode *root, int value) {
    if (root) {
        __bst__postorder(root->left, value);
        __bst__postorder(root->right, value);
        //printf("%d ", root->key);
        if(berhenti != 1){
            hitung_index();
            if(root->key == value) berhenti = 1;
        }
    }
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

void bst_remove(BST *bst, int value) {
    if (bst_find(bst, value)) {
        bst->_root = __bst__remove(bst->_root, value);
        bst->_size--;
    }
}

/**
 * Binary search tree traversal
 * - Postorder
 */


void bst_postorder(BST *bst, int value) {
    __bst__postorder(bst->_root, value);
}


int main(){

    int N; //banyaknya bilangan yang akan dimasukkan ke BST 
    int Q; //banyaknya perintah
    int data;
    int i;
    int perintah; //"1" atau "2"
    int x; //bilangan
    BST bst;
    Output output[1000];
    
    bst_init(&bst);
    
    scanf("%d %d", &N, &Q);
    
    for(i=0; i<N; i++){
        scanf("%d ", &data);
        bst_insert(&bst, data);
    }
    
    for(i=0; i<Q; i++){
        scanf("%d %d", &perintah, &x);
        if(perintah == 1){ //menghapus bilangan x
        	output[i].perintah = 1;
	        output[i].data = x;
			if(bst_find(&bst, x)){
	            bst_remove(&bst, x);
	            output[i].ada = 1;
	        }
	        else{
	        	output[i].ada = 0;
			}
        }
        else if(perintah == 2){ //menampilkan index bilangan x secara postorder
            output[i].perintah = 2;
            output[i].data = x;
            if (bst_find(&bst, x)){
                index = 0;
                berhenti = 0;
                bst_postorder(&bst, x);
                //printf("\n\n");
                //printf("index = %d\n", index);
                output[i].index = index;
                output[i].ada = 1;
            }
            else output[i].index = 0;
        }
    }
    
    for(i=0; i<Q; i++){
    	
    	if(output[i].ada != 0){
	        if(output[i].perintah == 1){
	            printf("%d sudah terhapus\n", output[i].data);
	        }
	        else if(output[i].perintah == 2){
	            printf("%d ada di index ke-%d\n", output[i].data, output[i].index);
			}
	    }
	    else{
	        printf("%d tidak ada\n", output[i].data);
		}
	}



    return 0;
}
