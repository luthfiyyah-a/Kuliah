#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>


// harusnya pake priority queque, tapi baru telat ngeh kalo data inputnya belum terurut. udah telanjur pakai stack

typedef struct node_t{
    int barang;
    int harga;
    struct node_t *next;
} Node;

typedef struct stack_t{
    unsigned size;
    Node *top;
} Stack;



/* fungsi */

void init(Stack *stack){
    stack->size = 0;
    stack->top = NULL;
}

bool isEmpty(Stack *stack){
    return (stack->top == NULL);
}

void push(Stack *stack, int barang, int harga){
    Node *newnode = (Node*) malloc(sizeof(Node));
    if(newnode){
        stack->size++;
        Node *temp = stack->top;
        newnode->barang = barang;
        newnode->harga = harga;
        
        if(isEmpty(stack)){
            newnode->next = NULL;
            stack->top = newnode;
            return;
        }
        else{
            if(harga < stack->top->harga){
                newnode->next = stack->top;
                stack->top = newnode;
            }
            else{
                while(temp->next != NULL && harga > temp->next->harga)
                temp = temp->next;
                newnode->next = temp->next;
                temp->next = newnode;
            }
        }
    }
}

void pop(Stack *stack)
{
    if (!isEmpty(stack)) {
        Node *temp = stack->top;
        stack->top = stack->top->next;
        free(temp);
    }
}

int top(Stack *stack) {
    if (!isEmpty(stack))
        return stack->top->barang;
    else return 0;
}

int cari(Stack *stack, int X){
    
    int i=0;
    
    Node *pointer = stack->top;
    while(pointer != NULL)
    if(pointer->barang == X){
        return i;
    }
    else{
        pointer = pointer->next;
        i++;
    }
    
    return 0;
    }



int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    
    Stack belanjaan;
    init(&belanjaan);
    
    int N; //jumlah barang yang ada di dalam tas
    int B_temp; //barang
    int M_temp; //harga barang
    int X; //barang yang diminta pacarnya
    int berapa; //berapa kali harus mengeluarkan barang
    
    scanf("%d", &N);
    
    int i;
    for(i=0; i<N; i++){
        scanf("%d %d", &B_temp, &M_temp);
        push(&belanjaan, B_temp, M_temp);
    }
    
    
    
    scanf("%d", &X);
    
    berapa = cari(&belanjaan, X);
    
    if(berapa == 0) printf("Barangnya gak ada beb");
    else{
        printf("%d", berapa);
    }
    
    // while (!isEmpty(&belanjaan)) {
    //     printf("%d ", top(&belanjaan));
    //     pop(&belanjaan);
    // }
    
    return 0;
}
