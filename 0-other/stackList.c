#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
typedef int E;

typedef struct StackList
{
    E element;
    struct StackList * next;
} * StackNode;

void initstackList(StackNode stackhead);
_Bool PushstackList(StackNode stackhead, E element);
E PopstackList(StackNode stackhead);
_Bool isempty(StackNode stackhead);
void prstacklist(StackNode stackhead);

int main()
{
    struct StackList stackhead;
    initstackList(&stackhead);
    for(int i = 1; i <= 3; i++){
        // printf("|");
        PushstackList(&stackhead, i);
    }
    prstacklist(&stackhead);
    StackNode head = &stackhead;
    while(isempty(head)){
        printf("%d ", PopstackList(head));
    }
    printf("\n");
    system("pause");
    return 0;
}

void initstackList(StackNode stackhead)
{
    stackhead->next = NULL;
}

_Bool PushstackList(StackNode stackhead, E element)
{
    StackNode newnode = (StackNode)malloc(sizeof(struct StackList));
    if(newnode == NULL)
        return false;
    newnode->element = element;
    newnode->next = stackhead->next;
    stackhead->next = newnode;
    return true;
}

_Bool isempty(StackNode stackhead)
{
    if(stackhead->next == NULL)
        return false;
    return true;
}

E PopstackList(StackNode stackhead)
{
    StackNode tem = stackhead->next;
    E tmp_e = tem->element;
    stackhead->next = tem->next;
    free(tem);
    tem = NULL;
    return tmp_e;
}

void prstacklist(StackNode stackhead)
{
    stackhead = stackhead->next;
    while(stackhead){
        printf("%d", stackhead->element);
        stackhead = stackhead->next;
    }
    printf("|\n");
}