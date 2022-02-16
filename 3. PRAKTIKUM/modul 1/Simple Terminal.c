#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX_CHAR 60

/* Struktur Node */

typedef struct snode_t {
    char data[MAX_CHAR];
    struct snode_t *next;
} SListNode;

/* Struktur ADT SinglyList */

typedef struct slist_t {
    unsigned _size;
    SListNode *_head;
} SinglyList;

/* DAFTAR FUNGSI YANG TERSEDIA */

void slist_init(SinglyList *list);
bool slist_isEmpty(SinglyList *list);
void slist_pushFront(SinglyList *list, char value[MAX_CHAR]);
void slist_popFront(SinglyList *list);
void slist_pushBack(SinglyList *list, char value[MAX_CHAR]);
void slist_popBack(SinglyList *list);
void slist_insertAt(SinglyList *list, int index, char value[MAX_CHAR]);
void slist_removeAt(SinglyList *list, int index);
void slist_remove(SinglyList *list, char value[MAX_CHAR]);
const char*  slist_front(SinglyList *list);
const char*  slist_back(SinglyList *list);
const char*  slist_getAt(SinglyList *list, int index);
unsigned slist_size(SinglyList *list);

/* Function definition below */

void slist_init(SinglyList *list) {
    list->_head = NULL;
    list->_size = 0;
}

bool slist_isEmpty(SinglyList *list) {
    return (list->_head == NULL);
}

void slist_pushFront(SinglyList *list, char value[MAX_CHAR]) {
    SListNode *newNode = (SListNode*) malloc(sizeof(SListNode));
    if (newNode) {
        list->_size++;
        strcpy(newNode->data, value);

        if (slist_isEmpty(list)) newNode->next = NULL;
        else newNode->next = list->_head;
        list->_head = newNode;
    }
}

void slist_popFront(SinglyList *list){
    if (!slist_isEmpty(list)) {
        SListNode *temp = list->_head;
        list->_head = list->_head->next;
        free(temp);
        list->_size--;
    }
}

void slist_pushBack(SinglyList *list, char value[MAX_CHAR]){
    SListNode *newNode = (SListNode*) malloc(sizeof(SListNode));
    if (newNode) {
        list->_size++;
        strcpy(newNode->data, value);
        newNode->next = NULL;
        
        if (slist_isEmpty(list)) 
            list->_head = newNode;
        else {
            SListNode *temp = list->_head;
            while (temp->next != NULL) 
                temp = temp->next;
            temp->next = newNode;
        }
    }
}

void slist_popBack(SinglyList *list){
    if (!slist_isEmpty(list)) {
        SListNode *nextNode = list->_head->next;
        SListNode *currNode = list->_head;

        if (currNode->next == NULL) {
            free(currNode);
            list->_head = NULL;
            return;
        }

        while (nextNode->next != NULL) {
            currNode = nextNode;
            nextNode = nextNode->next;
        }
        currNode->next = NULL;
        free(nextNode);
        list->_size--;
    }
}

void slist_insertAt(SinglyList *list, int index, char value[MAX_CHAR]){
    /* Kasus apabila posisinya melebihi batas */
    if (slist_isEmpty(list) || index >= list->_size) {
        slist_pushBack(list, value);
        return;    
    }
    else if (index == 0 || index < 0) {
        slist_pushFront(list, value);
        return;
    }
    
    SListNode *newNode = (SListNode*) malloc(sizeof(SListNode));
    if (newNode) {
        SListNode *temp = list->_head;
        int _i = 0;
        while (temp->next != NULL && _i < index-1) {
            temp = temp->next;
            _i++;
        }
        strcpy(newNode->data, value);
        newNode->next = temp->next;
        temp->next = newNode;
        list->_size++;
    }
}

void slist_removeAt(SinglyList *list, int index){
    if (!slist_isEmpty(list)) {
        
        /* Kasus apabila posisinya melebihi batas */
        if (index >= list->_size) {
            slist_popBack(list);
            return;    
        }
        else if (index == 0 || index < 0) {
            slist_popFront(list);
            return;
        }
        
        SListNode *temp = list->_head;
        int _i = 0;
        while (temp->next != NULL && _i < index-1) {
            temp = temp->next;
            _i++;
        }
        SListNode *nextTo = temp->next->next;
        free(temp->next);
        temp->next = nextTo;
        list->_size--;
    }
}

void slist_remove(SinglyList *list, char value[MAX_CHAR]){
    if (!slist_isEmpty(list)) {
        SListNode *temp, *prev;
        temp = list->_head;

        if (temp->data == value) {
            slist_popFront(list);
            return;
        }
        while (temp != NULL && temp->data != value) {
            prev = temp;
            temp = temp->next;
        }

        if (temp == NULL) return;
        prev->next = temp->next;
        free(temp);
        list->_size--;
    }
}

const char* slist_front(SinglyList *list){
    if (!slist_isEmpty(list)) {
        return list->_head->data;
    }
    return 0;
}

const char* slist_back(SinglyList *list){
    if (!slist_isEmpty(list)) {
        SListNode *temp = list->_head;
        while (temp->next != NULL) 
            temp = temp->next;
        return temp->data;
    }
    return 0;
}

const char* slist_getAt(SinglyList *list, int index){
    if (!slist_isEmpty(list)) {
        SListNode *temp = list->_head;
        int _i = 0;
        while (temp->next != NULL && _i < index) {
            temp = temp->next;
            _i++;
        }
        return temp->data;
    }
    return 0;
}

unsigned slist_size(SinglyList *list){
    return list->_size;
}

int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   

    char command[20];
    char data[MAX_CHAR];
    int index_awal, index_tujuan;
    int inisalah = 0;
    SinglyList terminal;
    
    slist_init(&terminal);
    
    do{
        scanf("%s", command);

        if(strcmp(command, "append")==0){
            scanf("%s", data);
            slist_pushBack(&terminal, data);
            
        }
        else if(strcmp(command, "prepend")==0){
            scanf("%s", data);
            slist_pushFront(&terminal, data);    
        }
        else if(strcmp(command, "cp")==0){
            scanf("%d %d", &index_awal, &index_tujuan);
            strcpy(data, slist_getAt(&terminal, index_awal));
            slist_insertAt(&terminal, index_tujuan, data);
        }
        else if(strcmp(command, "mv")==0){
            scanf("%d %d", &index_awal, &index_tujuan);
            strcpy(data, slist_getAt(&terminal, index_awal));
            slist_removeAt(&terminal, index_awal);
            slist_insertAt(&terminal, index_tujuan, data);
        }
        else if(strcmp(command, "rm")==0){
            scanf("%d", &index_awal);
            slist_removeAt(&terminal, index_awal);
        }
        else if(strcmp(command, "stop")==0){
            break;
        }
        else{
            inisalah = 1;
        }
    } while(strcmp(command, "stop")!=0);
    
    if(inisalah == 0){
        int size = slist_size(&terminal);
        printf("%d\n", size);
        int i;
        for(i=0; i<size; i++){
            printf("%s\n", slist_getAt(&terminal, i));
        }
    }
    return 0;
}

