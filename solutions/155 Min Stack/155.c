#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int* valArray;
    int* minArray;
    int arrayLen;
} MinStack;


MinStack* minStackCreate() {
    MinStack * stack = malloc(sizeof(*stack));
    stack->valArray = NULL;
    stack->minArray = NULL;
    stack->arrayLen = 0;
    return stack;
}

void minStackPush(MinStack* obj, int val) {
    obj->arrayLen++;
    obj->valArray = realloc(obj->valArray, obj->arrayLen*sizeof(*obj->valArray));
    obj->minArray = realloc(obj->minArray, obj->arrayLen*sizeof(*obj->minArray));
    obj->valArray[obj->arrayLen-1] = val;
    if (obj->arrayLen <= 1) 
        obj->minArray[obj->arrayLen-1] = val;
    else 
        obj->minArray[obj->arrayLen-1] = obj->minArray[obj->arrayLen-2] < val ? obj->minArray[obj->arrayLen-2] : val;
}

void minStackPop(MinStack* obj) {
    obj->arrayLen--;
}

int minStackTop(MinStack* obj) {
    return obj->valArray[obj->arrayLen-1];
}

int minStackGetMin(MinStack* obj) {
    return obj->minArray[obj->arrayLen-1];
}

void minStackFree(MinStack* obj) {
    free(obj->valArray);
    free(obj);
}