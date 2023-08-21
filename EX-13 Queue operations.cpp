#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

struct Queue {
    int data[MAX_SIZE];
    int front, rear;
};

void initialize(struct Queue* queue) {
    queue->front = -1;
    queue->rear = -1;
}

int isEmpty(struct Queue* queue) {
    return queue->front == -1;
}

int isFull(struct Queue* queue) {
    return (queue->rear + 1) % MAX_SIZE == queue->front;
}

void enqueue(struct Queue* queue, int value) {
    if (isFull(queue)) {
        printf("Queue overflow. Cannot enqueue %d.\n", value);
        return;
    }
    
    if (isEmpty(queue)) {
        queue->front = 0;
    }

    queue->rear = (queue->rear + 1) % MAX_SIZE;
    queue->data[queue->rear] = value;
}

int dequeue(struct Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue underflow. Cannot dequeue.\n");
        return -1;
    }

    int value = queue->data[queue->front];
    if (queue->front == queue->rear) {
        initialize(queue);
    } else {
        queue->front = (queue->front + 1) % MAX_SIZE;
    }
    
    return value;
}

void display(struct Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty.\n");
        return;
    }

    int i = queue->front;
    printf("Queue elements:\n");
    while (i != queue->rear) {
        printf("%d\n", queue->data[i]);
        i = (i + 1) % MAX_SIZE;
    }
    printf("%d\n", queue->data[i]);
}

int main() {
    struct Queue queue;
    initialize(&queue);

    enqueue(&queue, 10);
    enqueue(&queue, 20);
    enqueue(&queue, 30);

    printf("Queue after enqueue operations:\n");
    display(&queue);

    int dequeued1 = dequeue(&queue);
    printf("Dequeued element: %d\n", dequeued1);

    printf("Queue after dequeue operation:\n");
    display(&queue);

    int dequeued2 = dequeue(&queue);
    printf("Dequeued element: %d\n", dequeued2);

    printf("Queue after dequeue operation:\n");
    display(&queue);

    return 0;
}

