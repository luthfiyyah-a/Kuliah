/*

- soal 2 modul 1 struktur data
program ini menggunakan priority queue

dibuat dan ditulis oleh luthfiyyah hanifah amari, masya Allah. alhamdulillah.
--- tanggal 26 maret 2021. 

curhat dikit:
	alhamdulillah buatnya lumayan lancar, masya Allah.

catatan lain :
	banyak source code yang copas dari source code modul github

*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#define MAX_OUTPUT 30


// struct pqueque node
typedef struct pqueueNode_t {
    int data_urgensi;
    int data_id;
    struct pqueueNode_t *next;
} PQueueNode;

// struct priority queue
typedef struct pqueue_t {
    PQueueNode *_top;
    unsigned _size;
} PriorityQueue;

/* prototype fungsi */
void pqueue_init(PriorityQueue *pqueue);
bool pqueue_isEmpty(PriorityQueue *pqueue);
void pqueue_push(PriorityQueue *pqueue, int id, int urgensi);
void pqueue_pop(PriorityQueue *pqueue);
int  pqueue_top(PriorityQueue *pqueue);


/* fungsi */

void pqueue_init(PriorityQueue *pqueue)
{
    pqueue->_top = NULL;
    pqueue->_size = 0;
}

bool pqueue_isEmpty(PriorityQueue *pqueue) {
    return (pqueue->_top == NULL);
}


void pqueue_push(PriorityQueue *pqueue, int id, int urgensi)
{
    PQueueNode *temp = pqueue->_top;
    PQueueNode *newNode = \
        (PQueueNode*) malloc (sizeof(PQueueNode));
    newNode->data_id = id;
    newNode->data_urgensi = urgensi;
    newNode->next = NULL;

    if (pqueue_isEmpty(pqueue)) {
        pqueue->_top = newNode;
        return;
    }

    if (urgensi > pqueue->_top->data_urgensi) {
        newNode->next = pqueue->_top;
        pqueue->_top = newNode;
    }
    else {
        while ( temp->next != NULL &&
                temp->next->data_urgensi > urgensi)
            temp = temp->next;
        newNode->next = temp->next;
        temp->next = newNode;
    }
}


void pqueue_pop(PriorityQueue *pqueue)
{
    if (!pqueue_isEmpty(pqueue)) {
        PQueueNode *temp = pqueue->_top;
        pqueue->_top = pqueue->_top->next;
        free(temp);
    }
}

int pqueue_top(PriorityQueue *pqueue) {
    if (!pqueue_isEmpty(pqueue))
        return pqueue->_top->data_id;
    else return 0;
}

int main()
{
    char input[10];
    char masuk[10] = "MASUK";
    char layani[10] = "LAYANI";
    int temp_id, temp_urgensi;
    int output;
    PQueueNode daftar;
    int bismillah = 1;

    pqueue_init(&daftar);

    while (bismillah){
        scanf("%s", &input);
        if(strcmp(input, masuk) == 0){
            scanf("%d %d", &temp_id, &temp_urgensi);

            pqueue_push(&daftar, temp_id, temp_urgensi);
        }
        if(strcmp(input, "LAYANI") == 0){
            output = pqueue_top(&daftar);
            if(output != 0)
                printf("%d\n", output);
            else{
                printf("HORE\n");
                break;
            }
            pqueue_pop(&daftar);
        }
    }

    printf("alhamdulillah... masya Allah tabarokallah\n");
    return 0;
}
