#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    int *queue;
    int head;
    int tail;
    int length;
    int count;
} MyCircularQueue;


MyCircularQueue* myCircularQueueCreate(int k) {
    MyCircularQueue *myQueue = (MyCircularQueue*)malloc(sizeof(MyCircularQueue));
    myQueue->queue = (int*)malloc(sizeof(int)*k);
    myQueue->length = k;
    myQueue->head = 0;
    myQueue->tail = -1;  // 第一筆資料 enqueue 後 tail index 變成 0
    myQueue->count = 0;
    return myQueue;
}

bool myCircularQueueEnQueue(MyCircularQueue* obj, int value) {
    if(obj->count == obj->length)
        return false;
    else
    {
        if(obj->tail != obj->length-1)
        {  
            obj->tail +=1;
            obj->count += 1;
            obj->queue[obj->tail] = value;
        }    
        else
        {
            obj->tail = 0;
            obj->count += 1;
            obj->queue[obj->tail] = value;
        }    
        return true;
    }
    
}

bool myCircularQueueDeQueue(MyCircularQueue* obj) {
    if(obj->count == 0)
        return false;
    else
    {
        if(obj->head != obj->length-1)
        {   
            obj->queue[obj->head] = 0;
            obj->head += 1;
            obj->count -= 1;
            
        }    
        else
        {
            obj->queue[obj->head] = 0;
            obj->head = 0;
            obj->count -= 1;
            
        }    
        return true;
    }
}

int myCircularQueueFront(MyCircularQueue* obj) {
    if(obj->count == 0)
        return -1;
    else
        return obj->queue[obj->head]; 
}

int myCircularQueueRear(MyCircularQueue* obj) {
    if(obj->count == 0)
        return -1;
    else
        return obj->queue[obj->tail]; 
}

bool myCircularQueueIsEmpty(MyCircularQueue* obj) {
    if(obj->count == 0)
        return true;
    else
        return false;
}

bool myCircularQueueIsFull(MyCircularQueue* obj) {
    if(obj->count == obj->length)
        return true;
    else
        return false;
}

void myCircularQueueFree(MyCircularQueue* obj) {
    
}

/**
 * Your MyCircularQueue struct will be instantiated and called as such:
 * MyCircularQueue* obj = myCircularQueueCreate(k);
 * bool param_1 = myCircularQueueEnQueue(obj, value);
 
 * bool param_2 = myCircularQueueDeQueue(obj);
 
 * int param_3 = myCircularQueueFront(obj);
 
 * int param_4 = myCircularQueueRear(obj);
 
 * bool param_5 = myCircularQueueIsEmpty(obj);
 
 * bool param_6 = myCircularQueueIsFull(obj);
 
 * myCircularQueueFree(obj);
*/