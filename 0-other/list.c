#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
typedef int E;

typedef struct ListNode
{
    E element;
    struct ListNode * next;
}* Node;


void iniList(Node head);
_Bool insertList(Node head, E element, int index);
_Bool deteleList(Node head, int index);
E *getList(Node head, int index);
int findList(Node head, E element);
int sizeList(Node head);

void printList(Node head);
int main()
{
    // struct ListNode head;
    // iniList(&head);

    // printList(&head);
    // printf("%d", sizeList(&head));
    system("pause");
    return 0;
}

void iniList(Node head)
{
    head->next = NULL;
}

_Bool insertList(Node head, E element, int index)
{
    if(index < 1)
        return false;
    while(--index){
        head = head->next;
        if(head == NULL)
            return false;
    }
    Node node = (Node)malloc(sizeof(struct ListNode));
    if(node == NULL)
        return false;
    node->element = element;
    node->next = head->next;
    head->next = node;
    return true;
}

_Bool deteleList(Node head, int index)
{
    if(index < 1)
        return false;
    while(--index){
        head = head->next;
        if(head == NULL)
            return false;
    }
    if(head->next == NULL)
        return false;
    Node deteNode = head->next;
    head->next = head->next->next;
    free(deteNode);
    return true;
}

E *getList(Node head, int index)
{
    // if(index < 1)
    //     return 0;
    // while(--index){
    //     head = head->next;
    //     if(head == NULL)
    //         return 0;
    // }
    // if(head->next == NULL)
    //     return 0;
    // return &head->next->element;
    if(index < 1)
        return 0;
    do{
        head = head->next;
        if(head == NULL)
            return NULL;
    }while(--index);
    return &head->element;
}

int findList(Node head, E element)
{
    // int i = 1;
    // do{
    //     head = head->next;
    //     if(head->element == element)   // 如果为空表，会造成 NULL->element
    //         return i;
    // }while(i++, head);
    // return 0;
    int i = 1;
    head = head->next;
    while(head){
        if(head->element == element)
            return i;
        i++;
        head = head->next;
    }
    return 0;
}

int sizeList(Node head)
{
    int i = 0;
    while(head->next){
        head = head->next;
        i++;
    }
    return i;
}

void printList(Node head)
{
    while(head->next){
        head = head->next;
        printf("%d\n", head->element);
    }
}