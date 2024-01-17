#include<stdio.h>
#include<stdlib.h>
#define MAX_SIZE 5

struct queue {
    int *items;
    int rear;
    int front;
};

void enqueue(struct queue *q, int x) {
    if (q->rear == MAX_SIZE - 1) {
        printf("The queue is full.\n");
        return;
    } else {
        q->rear++;
        q->items[q->rear] = x;
        printf("Data inserted successfully.\n");
    }
}

void dequeue(struct queue *q) {
    if (q->front > q->rear) {
        printf("Queue is empty.\n");
        return;
    } else {
        int a = q->items[q->front++];
        printf("The dequeued element is: %d\n", a);
    }
}

void display(struct queue *q) {
    if (q->front > q->rear) {
        printf("Queue is empty.\n");
        return;
    }

    printf("Queue elements: ");
    for (int i = q->front; i <= q->rear; ++i) {
        printf("%d ", q->items[i]);
    }
    printf("\n");
}

int main() {
    struct queue q;
    q.rear = -1;
    q.front = 0;
    q.items = (int *)malloc(sizeof(int) * MAX_SIZE);

    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    enqueue(&q, 40);
    enqueue(&q, 50);

    display(&q);

    dequeue(&q);
    dequeue(&q);

    display(&q);

    free(q.items);

    return 0;
}
