#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TRUCKS 10

typedef struct {
    char name[20];
} Truck;

typedef struct {
    Truck trucks[MAX_TRUCKS];
    int front, rear, size;
} CircularQueue;

void initQueue(CircularQueue* q) {
    q->front = q->rear = -1;
    q->size = 0;
}

int isFull(CircularQueue* q) {
    return q->size == MAX_TRUCKS;
}

int isEmpty(CircularQueue* q) {
    return q->size == 0;
}

void enqueue(CircularQueue* q, Truck truck) {
    if (isFull(q)) {
        printf("Garage is full.\n");
        return;
    }
    if (isEmpty(q)) {
        q->front = q->rear = 0;
    } else {
        q->rear = (q->rear + 1) % MAX_TRUCKS;
    }
    q->trucks[q->rear] = truck;
    q->size++;
}

Truck dequeue(CircularQueue* q) {
    if (isEmpty(q)) {
        Truck nullTruck = {"NULL"};
        printf("Garage is empty.\n");
        return nullTruck;
    }
    Truck truck = q->trucks[q->front];
    if (q->front == q->rear) {
        q->front = q->rear = -1;
    } else {
        q->front = (q->front + 1) % MAX_TRUCKS;
    }
    q->size--;
    return truck;
}

void showTrucks(CircularQueue* q) {
    if (isEmpty(q)) {
        printf("Garage is empty.\n");
        return;
    }
    printf("Trucks in the garage:\n");
    int i;
    for (i = q->front; i != q->rear; i = (i + 1) % MAX_TRUCKS) {
        printf("%s\n", q->trucks[i].name);
    }
    printf("%s\n", q->trucks[q->rear].name);
}

int main() {
    CircularQueue garage;
    initQueue(&garage);
    while (1) {
        printf("Enter command (1: Enter garage, 2: Exit garage, 3: Show trucks, 0: Exit program):\n");
        int command;
        scanf("%d", &command);
        if (command == 0) {
            break;
        }
        if (command == 1) {
            printf("Enter truck name:\n");
            char name[20];
            scanf("%s", name);
            Truck truck;
            strcpy(truck.name, name);
            enqueue(&garage, truck);
            printf("%s entered the garage.\n", name);
        }
        if (command == 2) {
            printf("Enter truck name:\n");
            char name[20];
            scanf("%s", name);
            Truck truck;
            strcpy(truck.name, name);
            Truck dequeuedTruck = dequeue(&garage);
            if (strcmp(dequeuedTruck.name, truck.name) == 0) {
                printf("%s exited the garage.\n", name);
            } else {
                printf("%s is not the next truck to exit.\n", name);
            }
        }
        if (command == 3) {
            showTrucks(&garage);
        }
    }
    return 0;
}
