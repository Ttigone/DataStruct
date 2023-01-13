#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int E;

typedef struct ListNode
{
    E element;
    struct ListNode * next;
    struct ListNode * prev;
}* Node;

void initList(Node head);
_Bool insertList(Node head, E element, int index);
_Bool deteleList(Node head, int index);

int main()
{
    struct ListNode head;
    initList(&head);
    for(int i = 1; i <= 5; i++){
        insertList(&head, i * 10, i);
    }
    Node node = &head;
    deteleList(&head, 3);
    do{
        node = node->next;
        printf("%d -> ", node->element);
    }while(node->next != NULL);
    printf("\n");
    do{
        printf("%d -> ", node->element);
        node = node->prev;
    }while(node != &head);
    system("pause");
    return 0;    
}

void initList(Node head)
{
    head->next = head->prev = NULL;
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
    Node Newnode = (Node)malloc(sizeof(struct ListNode));
    if(Newnode == NULL)
        return false;
    Newnode->element = element;
    if(head->next){
        head->next->prev = Newnode;
        Newnode->next = head->next;
    }
    else
        Newnode->next = NULL;
    head->next = Newnode;
    Newnode->prev = head;
    return true;
}

_Bool deteleList(Node head, int index)
{
    if(index < 1)
        return 0;
    while(--index){
        head = head->next;
        if(head == NULL)
            return false;
    }
    if(head->next == NULL)
        return false;
    Node delnode = head->next;
    if(head->next->next == NULL){
        head->next = NULL;
    }
    else{
        head->next->next->prev = head;
        head->next = head->next->next;
    }
    free(delnode);
    return true;
}
