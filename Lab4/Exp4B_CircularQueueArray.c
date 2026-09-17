#include <stdio.h>

/* Data Structures Lab implementation */
#define SIZE 5

int q[SIZE], front = -1, rear = -1;

int isFull() { return (front == (rear + 1) % SIZE); }
int isEmpty() { return front == -1; }

void enqueue(int x) {
    if (isFull()) { printf("Queue is full\n"); return; }
    if (front == -1) front = 0;
    rear = (rear + 1) % SIZE;
    q[rear] = x;
    printf("%d enqueued\n", x);
}

void dequeue() {
    if (isEmpty()) { printf("Queue is empty\n"); return; }
    printf("%d dequeued\n", q[front]);
    if (front == rear) front = rear = -1;
    else front = (front + 1) % SIZE;
}

void display() {
    if (isEmpty()) { printf("Queue is empty\n"); return; }
    printf("Queue: ");
    int i = front;
    while (1) {
        printf("%d ", q[i]);
        if (i == rear) break;
        i = (i + 1) % SIZE;
    }
    printf("\n");
}

int main() {
    int ch, x;
    while (1) {
        printf("\n1.Enqueue 2.Dequeue 3.Display 4.Exit\nChoice: ");
        scanf("%d", &ch);
        switch (ch) {
             case 1: printf("Value: "); scanf("%d", &x); enqueue(x); break;
             case 2: dequeue(); break;
             case 3: display(); break;
             case 4: return 0;
             default: printf("Invalid\n");
        }
    }
}
