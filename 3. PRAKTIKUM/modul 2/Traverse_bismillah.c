#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX_STR 21

/**

- Node structure and
- uniqueBST structure
*/

typedef struct bstnode_t {
	char key[MAX_STR];
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
	char nilai[MAX_STR];
}Paket; //paket data, maksudnya data yang udah sepaket gitu hehe, ada tingkatnya dan nilainya

int z;


/**

- !!! WARNING UTILITY FUNCTION !!!
- Recognized by prefix "**bst**"
- 
- Note that you better never access these functions,
- unless you need to modify or you know how these functions work.
*/

BSTNode* __bst__createNode(char value[MAX_STR]) {
	BSTNode *newNode = (BSTNode*) malloc(sizeof(BSTNode));
	strcpy(newNode->key, value);
	newNode->left = newNode->right = NULL;
	return newNode;
}

BSTNode* __bst__insert(BSTNode *root, char value[MAX_STR]) {
	if (root == NULL)
		return __bst__createNode(value);
	
	if (strcmp(value, root->key) < 0)
	    root->left = __bst__insert(root->left, value);
	else if (strcmp(value, root->key) >= 0)
	    root->right = __bst__insert(root->right, value);
	
	return root;

}

BSTNode* __bst__search(BSTNode *root, char value[MAX_STR]) {
	while (root != NULL) {
		if (strcmp(value, root->key) < 0)
			root = root->left;
		else if (strcmp(value, root->key) > 0)
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
		int j=0;
		if(root->key[j] == '0'){
			while(root->key[j] == '0'){
				j++;
			}
			int k=0;
			int temp[MAX_STR];
			temp[k] = root->key[j];
			printf("%s ", temp);
		}
		else
			printf("%s ", root->key);
		__bst__inorder(root->right);
	}
}

void __bst__postorder(BSTNode *root) {
	if (root) {
		__bst__postorder(root->left);
		__bst__postorder(root->right);
		int j=0;
		if(root->key[j] == '0'){
			while(root->key[j] == '0'){
				j++;
			}
			int k=0;
			int temp[MAX_STR];
			temp[k] = root->key[j];
			printf("%s ", temp);
		}
		else
			printf("%s ", root->key);
	}
}

void __bst__preorder(BSTNode *root) {
	if (root) {
		int j=0;
		if(root->key[j] == '0'){
			while(root->key[j] == '0'){
				j++;
			}
			int k=0;
			int temp[MAX_STR];
			temp[k] = root->key[j];
			printf("%s ", temp);
		}
		else
			printf("%s ", root->key);
		__bst__preorder(root->left);
		__bst__preorder(root->right);
	}
}

/**

- PRIMARY FUNCTION
- 
- Accessible and safe to use.
*/

void bst_init(BST *bst) {
	bst->_root = NULL;
	bst->_size = 0u;
}

bool bst_isEmpty(BST *bst) {
	return bst->_root == NULL;
}

bool bst_find(BST *bst, char value[MAX_STR]) {
	BSTNode *temp = __bst__search(bst->_root, value);
	if (temp == NULL)
	return false;
	
	if (strcmp(temp->key, value) == 0)
	    return true;
	else
	    return false;

}

void bst_insert(BST *bst, char value[MAX_STR]) {
//	if (!bst_find(bst, value)) {
		bst->_root = __bst__insert(bst->_root, value);
		bst->_size++;
//	}
}

/**

- Binary search tree traversal
- Inorder
- Postorder
- Preorder
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

	strcpy((data+z)->nilai, root->key);
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
				char temp[MAX_STR];
				int j=0;
				
				if((data+i)->nilai[j] == '0'){
					while((data+i)->nilai[j] == '0'){
						j++;
					}
				
					int k=0;
					temp[k] = (data+i)->nilai[j];
					printf("%s ", temp);
				}
				else
					printf("%s ", (data+i)->nilai);
			}
		}
	}
}

int main(){

	int T; //banyaknya testcase
	char input[MAX_STR][MAX_STR];
	char temp[MAX_STR];
	int l, k, j, i = 0;
	BST bst;
	Paket data[MAX_STR];
	
	scanf("%d", &T);
	
	for(k=0; k<T; k++){
		i=0;
		bst_init(&bst);
		while(1){
			scanf("%s", input[i]);
		
			if(strcmp(input[i], "STOP") == 0) break;
		
			i++;
		}
		
		//cari panjang string terbesar
		int len_terbesar = 0;
		for(j=0; j<i; j++){
			if(strlen(input[j]) > len_terbesar)
				len_terbesar = strlen(input[j]);
		}
//		printf("len_Terbesar = %d\n", len_terbesar);
		for(j=0; j<i; j++){
			if(strlen(input[j]) < len_terbesar){
				strcpy(temp, input[j]);
				int temp_len = strlen(input[j]);
				for(l=0; l<(len_terbesar-temp_len); l++){
					input[j][l]='0';
				}
				strcat(input[j], temp);
			}
		}
		
		//insert data ke bst
		for(j=0; j<i; j++){
			bst_insert(&bst, input[j]);
//			printf("data input bismillah semoga ac aamiin : %s\n", input[j]);
		}
		
//	}
	
//	for(k=0; k<T; k++){
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
