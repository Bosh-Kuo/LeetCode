#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    int queue[100];
    int head;
    int tail;
} MyQueue;


MyQueue* myQueueCreate() {
    MyQueue *newQueue = (MyQueue*)malloc(sizeof(MyQueue));
    newQueue->head = 0;
    newQueue->tail = 0;
    return newQueue;
}

void myQueuePush(MyQueue* obj, int x) {
    obj->queue[obj->tail] = x;
    obj->tail += 1;
}

int myQueuePop(MyQueue* obj) {
    int pop = obj->queue[obj->head];
    obj->head += 1;
    return pop;
}

int myQueuePeek(MyQueue* obj) {
    int peek = obj->queue[obj->head];
    return peek;
}

bool myQueueEmpty(MyQueue* obj) {
    return obj->head == obj->tail;
}

void myQueueFree(MyQueue* obj) {
    free(obj->queue);
}

/**
 * Your MyQueue struct will be instantiated and called as such:
 * MyQueue* obj = myQueueCreate();
 * myQueuePush(obj, x);
 
 * int param_2 = myQueuePop(obj);
 
 * int param_3 = myQueuePeek(obj);
 
 * bool param_4 = myQueueEmpty(obj);
 
 * myQueueFree(obj);
*/