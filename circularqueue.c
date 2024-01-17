#include<stdio.h>
#include<stdlib.h>
#define MAX_SIZE 5
struct circularqueue{
    int rear;
    int front;
    int *items;
};
void enqueue(struct circularqueue *cq, int x){
    if((cq->rear+1)%MAX_SIZE==cq->front){
        printf("The queue is full.\n");
        return;
    }else{
        if(cq->front==-1){
            cq->front=0;
        }
        cq->rear=(cq->rear+1)%MAX_SIZE;
        cq->items[cq->rear]=x;
    }
    printf("Data inserted successfully\n");
}
void dequeue(struct circularqueue *cq){
    if(cq->front==-1){
        printf("The queue is empty.\n");
        return;
    }
    int a=cq->items[cq->front];
    if(cq->front==cq->rear){
        cq->front=cq->rear=-1;
    }else{
        cq->front=(cq->front+1)%MAX_SIZE;
    }
    printf("The dequeued element is:%d",a);
}
void display(struct circularqueue *cq){
    if(cq->front==-1){
        printf("The queue is empty.\n");
        return;
    }
    int i=cq->front;
    printf("The displayed elements are:");
   do{
    printf("%d ",cq->items[i]);
    i=(i+1)%MAX_SIZE;
   }while (i!=(cq->rear+1)%MAX_SIZE);   
}
int main(){
    struct circularqueue cq;
    cq.rear=cq.front=-1;
    cq.items=(int*)malloc(sizeof(int)*MAX_SIZE);
    int choice, value;
    do{
        printf("\n1. Enqueue");
        printf("\n2. Dequeue");
        printf("\n3. display");
        printf("\n0. Exit");
        printf("\nEnter your choice:");
        scanf("%d",&choice);

        switch(choice){
            case 1:
            printf("Enter the data:");
            scanf("%d",&value);
            enqueue(&cq,value);
            break;
            case 2:
            dequeue(&cq);
            break;
            case 3:
            display(&cq);
            break;
            case 0:
            printf("Exiting program.");
            break;
            default:
            printf("Invalid choice");
        }
    }while(choice!=0);
    free(cq.items);
}