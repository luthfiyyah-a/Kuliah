#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#define MAX_ARR 25
#define MAX_TEST 101

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

typedef struct{
    int nilai_ganda;
    int jumlah;
} Ganda; //data yang diinput lebih dari 1.

Ganda ganda[MAX_ARR];
int z; //dipakai saat nyari tingkatannya
int w = 0; //dipakai untuk mengetahui jumlah data yang berlebih (doubel) keseluruhan. cth: 1 2 2 3 4 4 4. -> w=3(yaitu 2, 4, 4)

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


void __bst__inorder(BSTNode *root) {
    if (root) {
        __bst__inorder(root->left);
        printf("%d ", root->key);
        //diginiin karena ada input data yang double2
        int i, j;
        for(i=0; i<w; i++){
            if(root->key == ganda[i].nilai_ganda){
                for(j=0; j<ganda[i].jumlah; j++){ 
                    printf("%d ", root->key);
                }
            }
        }
        __bst__inorder(root->right);
    }
}

void __bst__postorder(BSTNode *root) {
    if (root) {
        __bst__postorder(root->left);
        __bst__postorder(root->right);
        printf("%d ", root->key);
        //diginiin karena ada input data yang double2
        int i, j;
        for(i=0; i<w; i++){
            if(root->key == ganda[i].nilai_ganda){
                for(j=0; j<ganda[i].jumlah; j++){ 
                    printf("%d ", root->key);
                }
            }
        }
    }
}

void __bst__preorder(BSTNode *root) {
    if (root) {
        printf("%d ", root->key);
        //diginiin karena ada input data yang double2
        int i, j;
        for(i=0; i<w; i++){
            if(root->key == ganda[i].nilai_ganda){
                for(j=0; j<ganda[i].jumlah; j++){ 
                    printf("%d ", root->key);
                }
            }
        }
        __bst__preorder(root->left);
        __bst__preorder(root->right);
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
    if(!bst_find(bst, value)){
        bst->_root = __bst__insert(bst->_root, value);
        bst->_size++;
    }
    else{
        int baru=1;
        int i;
        for(i=0; i<w; i++){
            if(value == ganda[i].nilai_ganda){ //jika nilainya sudah pernah berlebih. (berarti ini input yg sama minimal ke 3)
                ganda[i].jumlah++;
                baru=0;
                break;
            }
        }
        if(baru == 1){
            //jika angkanya dimasukkin 2 kali, artinya baru pertama kali sama. maka ditambah baru.
            ganda[w].nilai_ganda = value;
            ganda[w].jumlah = 1;
            w++;
        }
    }
}

/**
 * Binary search tree traversal
 * - Inorder
 * - Postorder
 * - Preorder
 */

void bst_inorder(BST *bst) {
    __bst__inorder(bst->_root);
}

void bst_postorder(BST *bst) {
    __bst__postorder(bst->_root);
}

void bst_preorder(BST *bst) {
    __bst__preorder(bst->_root);
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


void bst_levelorder(BST* bst, Paket* data){
    int i;
    int tertinggi;
    int t; //tingkat
    
    z=0;
    cari_tingkat(bst, data);

    tertinggi = tingkat_tertinggi(data);
    
    for(t=1; t<=tertinggi; t++){
        
        for(i=0; i<z; i++){
            if((data+i)->tingkat == t){
                printf("%d ", (data+i)->nilai);
                //diginiin karena ada input data yang double2
                int k, j;
                for(k=0; k<w; k++){
                    if((data+i)->nilai == ganda[k].nilai_ganda){
                        for(j=0; j<ganda[k].jumlah; j++){ 
                            printf("%d ", (data+i)->nilai);
                        }
                    }
                }
            }
        }
    }
}
 



int main(){
    
    int T; //jumlah testcase
    char input[MAX_ARR];
    int value;
    int k;
    Paket data[MAX_ARR];
    BST bst[MAX_TEST];
    
    scanf("%d", &T);
    
    for(k=0; k<T; k++){
        
        bst_init(&bst);
        
        while(1){
            scanf("%s", input);
            if( strcmp(input, "STOP")==0) break;
            sscanf(input, "%d", &value);
            bst_insert(&bst, value);
        }
        
        printf("Pre-order: ");
        bst_preorder(&bst);
        printf("\n");
        printf("In-order: ");
        bst_inorder(&bst);
        printf("\n");
        printf("Post-order: ");
        bst_postorder(&bst);
        printf("\n");
        printf("Level-order: ");
        bst_levelorder(&bst, data);
        printf("\n");
    }
    
    return 0;
}
