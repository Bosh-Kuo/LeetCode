#include <stdio.h>
#include <stdlib.h>

// define Node
typedef struct Node
{
    int val;
    struct Node *next;
} MyLinkedList;

MyLinkedList *myLinkedListCreate()
{
    MyLinkedList *dumyHead = (MyLinkedList *)malloc(sizeof(MyLinkedList));
    dumyHead->next = NULL;
    return dumyHead;
}

int myLinkedListGet(MyLinkedList *obj, int index)
{
    MyLinkedList *node = obj;
    int culmulativeLen = 0;
    while (node->next != NULL && culmulativeLen - 1 < index)
    {
        culmulativeLen++;
        node = node->next;
    }
    if (index > culmulativeLen - 1 || index < 0)
    {
        return -1;
    }
    else 
        return node->val;
}

void myLinkedListAddAtHead(MyLinkedList *obj, int val)
{
    MyLinkedList *newHead = myLinkedListCreate();
    newHead->val = val;
    newHead->next = obj->next;
    obj->next = newHead;
}

void myLinkedListAddAtTail(MyLinkedList *obj, int val)
{
    MyLinkedList *newTail = myLinkedListCreate();
    newTail->val = val;
    newTail->next = NULL;
    MyLinkedList *node = obj;
    while (node->next != NULL)
    {
        node = node->next;
    }
    node->next = newTail;
}

void myLinkedListAddAtIndex(MyLinkedList *obj, int index, int val)
{
    MyLinkedList *front = obj; // dumy head
    MyLinkedList *back = NULL;
    int culmulativeLen = 0;
    while (front->next != NULL && culmulativeLen - 1 < index)
    {
        culmulativeLen++;
        back = front;
        front = front->next;
    }
    if (index == culmulativeLen && front->next == NULL)
    {
        myLinkedListAddAtTail(obj, val);
    }
    else if (culmulativeLen - 1 == index)
    {
        MyLinkedList *newNode = myLinkedListCreate();
        newNode->val = val;
        newNode->next = front;
        back->next = newNode;
    }
}

void myLinkedListDeleteAtIndex(MyLinkedList *obj, int index)
{
    MyLinkedList *front = obj;
    MyLinkedList *back = NULL;
    int culmulativeLen = 0;
    while (front->next != NULL && culmulativeLen - 1 < index)
    {
        culmulativeLen++;
        back = front;
        front = front->next;
    }
    if (index == culmulativeLen - 1)
    {
        back->next = front->next;
        free(front);
    }
}

void myLinkedListFree(MyLinkedList *obj)
{
    MyLinkedList *front = obj->next, *back = obj;
    while (front != NULL)
    {
        free(back);
        back = front;
        front = front->next;
    }
    free(front); //釋放最後一個結點
}

/**
 * Your MyLinkedList struct will be instantiated and called as such:
 * struct MyLinkedList* obj = myLinkedListCreate();
 * int param_1 = myLinkedListGet(obj, index);
 * myLinkedListAddAtHead(obj, val);
 * myLinkedListAddAtTail(obj, val);
 * myLinkedListAddAtIndex(obj, index, val);
 * myLinkedListDeleteAtIndex(obj, index);
 * myLinkedListFree(obj);
 *
 **/

// int main()
// {
//     MyLinkedList *dumyHead = myLinkedListCreate();
//     myLinkedListAddAtHead(dumyHead, 1);
//     myLinkedListAddAtTail(dumyHead, 3);
//     myLinkedListAddAtIndex(dumyHead, 1, 2);
//     int first = myLinkedListGet(dumyHead, 1);
//     myLinkedListDeleteAtIndex(dumyHead, 1);
//     int second = myLinkedListGet(dumyHead, 1);

//     MyLinkedList *node = dumyHead->next;
//     for (; node != NULL; node = node->next)
//     {
//         printf("位址: %p\n", node);
//         printf("val: %d\n", node->val);
//     }
//     printf("%d", first);
//     printf("%d", second);
// }