#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#define MAX_DATA 1025

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

/* struct dan variabel global (khusus) */

typedef struct{
	int tingkat; //tingkatan suatu data pada bst
	int nilai;
}Paket; //paket data, maksudnya data yang udah sepaket gitu hehe, ada tingkatnya dan nilainya

int z;

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


/* bukan fungsi dari modul */

void __cari__tingkat(BSTNode* root, int tingkat, Paket* data){

	(data+z)->nilai = root->key;
	(data+z)->tingkat = ++tingkat;
	z++;
	if(root->left){
		__cari__tingkat(root->left, tingkat, data);
	}
	if(root->right){
		__cari__tingkat(root->right, tingkat, data);
	}
}

void cari_tingkat(BST* bst, Paket* data){
	__cari__tingkat(bst->_root, 0, data);
}

int tingkat_tertinggi(Paket* data){
	
	int i;
	int tertinggi = data->tingkat; //menunjuk ke indeks pertama
	for(i=1; i<z; i++){
		if((data+i)->tingkat > tertinggi){
			tertinggi = (data+i)->tingkat;
		}
	}
	return tertinggi;
}

int nilai_terbesar(Paket* data, int x){
	//x adalah tingkat
	int i;
	int terbesar = 0;
	
	for(i=0; i<z; i++){
		if((data+i)->tingkat == x){ //mengklasifikasi per tingkat
			
			if((data+i)->nilai > terbesar){
				terbesar = (data+i)->nilai;
			}
		}
	}
	return terbesar;
}

int nilai_terkecil(Paket* data, int x){
	//x adalah tingkat
	int i;
	int terkecil = 100001; //semoga ini angka terbesar. ngambilnya dari maks contrains index trus ditambah 1
	
	for(i=0; i<z; i++){
		if((data+i)->tingkat == x){ //mengklasifikasi per tingkat
			if((data+i)->nilai < terkecil){
				terkecil = (data+i)->nilai;
			}
		}
	}
	return terkecil;
}


int main(){
	
	BST bst;
	Paket data[MAX_DATA];
	int output[MAX_DATA];
	int i, j;
	int n; //jumlah data
	int temp;
	int tertinggi; //tingkat tertinggi
	
	bst_init(&bst);
	
	scanf("%d", &n);
	for(i=0; i<n; i++){
		scanf("%d", &temp); 
		bst_insert(&bst, temp);
	}
	
	z=0;
	cari_tingkat(&bst, data);

	tertinggi = tingkat_tertinggi(data);
	
	//selang seling
	for(i=tertinggi, j=0; i>0; i=i-2, j=j+2){
		output[j] = nilai_terkecil(data, i);
	}
	for(i=tertinggi-1, j=1; i>0; i=i-2, j=j+2){
		output[j] = nilai_terbesar(data, i);
	}
	
	for(i=0; i<tertinggi; i++){
		printf("%d ", output[i]);
	}
	
	return 0;
}
 
