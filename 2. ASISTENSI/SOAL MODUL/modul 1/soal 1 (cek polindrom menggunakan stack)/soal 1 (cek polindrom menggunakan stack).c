/*

mengecek apakah suatu kata merupakan polindrom menggunakan stack
- soal 1 modul 1 struktur data

dibuat dan ditulis oleh luthfiyyah hanifah amari, masya Allah. alhamdulillah.
--- tanggal 24-25 maret 2021. 

curhat dikit:
	buat malem sampe begadang, selesainya pagi wkwk. alhamdulillah kelarr...


*/


#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//deklarasi struct node
typedef struct stackNode_t{
	char data;
	struct stackNode_t *next; //apakah ini bisa diganti "stackNode *next" ?
}stacknode;

typedef struct stack_t{
	stacknode *top;
	unsigned size;
} stack;

/* prototype fungsi */
void stack_init(stack *inistack);
bool stack_isEmpty(stack *inistack);
void stack_push(stack *inistack, char value);
char cari_top(stack *inistack);
char cari_bottom(stack *inistack);
int isPolindrom(stack *inistack);

/* fungsi */

void stack_init(stack *inistack){
	inistack->size = 0;
	inistack->top = NULL;
}

bool stack_isEmpty(stack *inistack){
	return(inistack->top == NULL);
}

void stack_push(stack *inistack, char value){
	stacknode *newnode = (stacknode*) malloc(sizeof(stacknode));
	if(newnode){
		inistack->size++;
		newnode->data = value;
		
		if(stack_isEmpty(inistack)) newnode->next = NULL;
		else newnode->next = inistack->top;
		
		inistack->top = newnode;
	}
}
	
char cari_top(stack *inistack){
	
	printf("top data : %c\n", inistack->top->data);
		if(inistack->top->next != NULL){
			stacknode* temp = inistack->top;
			char a = inistack->top->data;
			inistack->top = inistack->top->next;
			free(temp);
			return a;

		}
		else return NULL;	
	}
	
char cari_bottom(stack *inistack){
		if(inistack->top->next == NULL){
			return inistack->top->data;
		}
		else{
			stacknode *temp1 = inistack->top;
			stacknode *temp2;
			
			while(temp1->next != NULL){
				
				temp2 = temp1;
				temp1 = temp1->next;
			}
			
			char a = temp1->data;
			free(temp1);
			inistack->size--;
			printf("botton: %c\n", temp2->data);
			temp2->next = NULL;
			return a;
		}
	}
	
int isPolindrom(stack *inistack){
	if(!stack_isEmpty(inistack)){
			
		char top, bottom;
		int polindrom = 1;
		int i=1;
		while(polindrom == 1){
			top = cari_top(inistack);
			if(top == NULL) break;
			bottom = cari_bottom(inistack);
			
			if(top == bottom){
				polindrom = 1;
			}
			else{
				polindrom = 0;
			}
		}
		return polindrom;
	}
}


int main(){
	
	int cek;
	char temp;
	// buat objek stack
	stack inistack;
	
	//inisialisasi stack
	stack_init(&inistack);
	
	//input dari user
	temp = 'a';
	while(temp != '\n'){
		scanf("%c", &temp);
		if(temp != '\n'){
			stack_push(&inistack, temp);
		}
	}
	
	cek = isPolindrom(&inistack);
	
	if(cek == 1) printf("polindrom");
	else if(cek == 0) printf("mahal, eh bukan polindrom");
	
	return 0;	
}
