#include <stdio.h>
#include "prioqueue.h"

int main() {
    PrioQueue Q;
    CreatePrioQueue(&Q);

    if(IsPrioQueueEmpty(Q)) {
        printf("The priority queue is empty.\n");
    } else {
        printf("The priority queue is not empty.\n");
    }
    printf("\n");

    EnqueuePrio(&Q, newPrioElmt(1, 3));
    EnqueuePrio(&Q, newPrioElmt(2, 2));
    EnqueuePrio(&Q, newPrioElmt(3, 5));
    EnqueuePrio(&Q, newPrioElmt(4, 1));

    printf("Enqueue:\n");
    DisplayPrioQueue(Q);
    printf("\n");

    if (IsPrioQueueEmpty(Q)) {
        printf("The priority queue is empty.\n");
    } else {
        printf("The priority queue is not empty.\n");
    }
    printf("\n");

    if (IsPrioQueueFull(Q)) {
        printf("The priority queue is full.\n");
    } else {
        printf("The priority queue is not full.\n");
    }
    printf("\n");

    int length = lengthPrioQueue(Q);
    printf("Length of the priority queue: %d\n", length);
    printf("\n");

    printf("Enqueue:\n");
    EnqueuePrio(&Q, newPrioElmt(5, 6));
    EnqueuePrio(&Q, newPrioElmt(6, 7));
    EnqueuePrio(&Q, newPrioElmt(7, 10));
    EnqueuePrio(&Q, newPrioElmt(8, 23));
    EnqueuePrio(&Q, newPrioElmt(9, 5));
    EnqueuePrio(&Q, newPrioElmt(10, 1));
    EnqueuePrio(&Q, newPrioElmt(11, 2));
    EnqueuePrio(&Q, newPrioElmt(12, 15));
    EnqueuePrio(&Q, newPrioElmt(13, 20));
    EnqueuePrio(&Q, newPrioElmt(14, 26));
    EnqueuePrio(&Q, newPrioElmt(15, 16));
    EnqueuePrio(&Q, newPrioElmt(16, 19));
    EnqueuePrio(&Q, newPrioElmt(17, 100));
    EnqueuePrio(&Q, newPrioElmt(18, 30));
    EnqueuePrio(&Q, newPrioElmt(19, 9));
    EnqueuePrio(&Q, newPrioElmt(20, 10));
    DisplayPrioQueue(Q);
    printf("\n");

    length = lengthPrioQueue(Q);
    printf("Length of the priority queue: %d\n", length);
    printf("\n");

    if (IsPrioQueueFull(Q)) {
        printf("The priority queue is full.\n");
    } else {
        printf("The priority queue is not full.\n");
    }
    printf("\n");

    infotype dequeued;
    DequeuePrio(&Q, &dequeued);

    printf("Dequeue:\n");
    DisplayPrioQueue(Q);
    printf("\n");

    return 0;
}
