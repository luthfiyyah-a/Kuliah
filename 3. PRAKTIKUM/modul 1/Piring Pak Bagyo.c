#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>


typedef struct node{
    int data;
    struct node *next;
}Node;

typedef struct stack{
    unsigned size;
    Node *top;
}
int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */    
    
    Stack stack;
    init(&stack);
    
    scanf("%d", &N);
    scanf("%s", &perintah);
    
    
    if(strcmp(perintah, "add")){
        scanf("%d %d", &X, &Y);
        printf("%d", size);
        
    }
    else if(strcmp(perintah, "del")){
        printf("%d", top);
        for(i=0; i<Y; i++){
            pop(&stack);
        }
    }
    else if(strcmp(perintah, "adx"))
    else if(strcmp(perintah, "dex")){}
    else if(strcmp(perintah, "mux")){}
    
    
    return 0;
}
