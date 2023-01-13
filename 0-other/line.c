#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
typedef int E;
typedef struct List{
    E * array;
    int capacity;
    int size;
}* ArrayList;
bool iniiList(ArrayList list);
void printList(ArrayList list);
bool insertList(ArrayList list, E element, int index);
bool deteleList(ArrayList list, int index);
int sizeList(ArrayList list);
E *getList(ArrayList list, int index);
int findList(ArrayList list, E element);
int main()
{
    struct List list;
    if(iniiList(&list)){
        for(int i = 0; i < 20; i++){
            insertList(&list, i * 10, i + 1);
        }
        printList(&list);
        deteleList(&list, 4);
        printList(&list);
    }
    else{
        printf("顺序表初始化失败，无法启动程序");
    }
    system("pause");
    return 0;
}


bool iniiList(ArrayList list)
{
    list->array = (E *)malloc(sizeof(E) * 10);
    if(list->array == NULL)
        return false;
    list->size = 0;
    list->capacity = 10;
    return true;
}

bool insertList(ArrayList list, E element, int index)
{
    if(index < 1 || index > list->size + 1) return false;
    if(list->size == list->capacity){
        int newcapacity = list->capacity + list->capacity >> 1;
        E *newArray = (E *)realloc(list->array, newcapacity * sizeof(E));
        if(newArray == NULL) return false;
        list->array = newArray;
        list->capacity = newcapacity;
    }
    for(int i = list->size; i > index - 1; i--){
        list->array[i] = list->array[i - 1];
    }
    list->array[index - 1] = element;
    list->size++;
    return true;
}

bool deteleList(ArrayList list, int index)
{
    if(index < 1 || index >= list->size) return false;
    for(int i = index - 1; i < list->size - 1; i++){
        list->array[i] = list->array[i + 1];
    }
    list->size--;
    return true;
}

int sizeList(ArrayList list)
{
    return list->size;
}

E *getList(ArrayList list, int index)
{
    if(index < 1 || index > list->size) return NULL;
    return & list->array[index - 1];
}

int findList(ArrayList list, E element)
{
    for(int i = 0; i < list->size; i++){
        if(list->array[i] == element) return i + 1;
    }
    return -1;
}

void printList(ArrayList list)
{
    for(int i = 0; i < list->size; i++){
        printf("%d ", list->array[i]);
    }
    putchar('\n');
}