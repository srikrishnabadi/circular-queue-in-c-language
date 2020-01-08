//Circular queue using structure & dynamic memory allocation for container.
#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 5

struct Queue
{
int *items;
int front, rear;
};

void initQueue(struct Queue *cq)
{
	cq->front = cq->rear = -1;
}

void deinitQueue(struct Queue *cq)
{
	free(cq->items);
}

int isFull(struct Queue *cq)
{
    if( (cq->front == cq->rear + 1) || (cq->front == 0 && cq->rear == MAXSIZE-1)) return 1;
    return 0;
}

int isEmpty(struct Queue *cq)
{
    if(cq->front == -1) return 1;
    return 0;
}

void insert(struct Queue *cq, int element)
{
    if(isFull(cq)) printf("\n Queue is full!! \n");
    else
    {
        //printf("Enter the element to be inserted\n");
        if(cq->front == -1) cq->front = 0;
        cq->rear = (cq->rear + 1) % MAXSIZE;
        cq->items[cq->rear] = element;
        printf("\n Inserted -> %d\n", element);
    }
}


int delete(struct Queue *cq)
{
    int element;
    if(isEmpty(cq)) {
        printf("\n Queue is empty !! \n");
        return(-1);
    } else {
        element = cq->items[cq->front];
        if (cq->front == cq->rear){
            cq->front = -1;
            cq->rear = -1;
        } /* Q has only one element, so we reset the queue after dequeing it. ? */
        else {
            cq->front = (cq->front + 1) % MAXSIZE;
        }
        printf("\n Deleted element -> %d \n", element);
        return(element);
    }
}




void display(struct Queue *cq)
{
    int i;
    if(isEmpty(cq)) printf(" \n Empty Queue\n");
    else
    {
        printf("\n Front -> %d ",cq->front);
        printf("\n Items -> ");
        for( i = cq->front; i!=cq->rear; (i=(i+1)%MAXSIZE))
        {
        printf("%d ",cq->items[i]);
        }
        printf("%d ",cq->items[i]);
        printf("\n Rear -> %d \n",cq->rear);
    }
}

int main()
{
	struct Queue q;
	int ch,val;
	q.items = (int*)malloc(MAXSIZE*sizeof(int)); // This can be moved to initQueue()
	initQueue(&q);
    // Fails because front = -1
    do
    {
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Display\n");
        printf("\nEnter your choice ");
        scanf("%d",&ch);
        switch(ch)
        {
        case 1:
            printf("Enter the element to be inserted\n");
            scanf("%d",&val);
            insert(&q,val);
            break;
        case 2:
            delete(&q);
            break;
        case 3:
            display(&q);
            break;
        }
    }while(ch!=4);
