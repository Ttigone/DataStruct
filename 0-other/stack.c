#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
typedef int E;

typedef struct Stack
{
    E * array;
    int capacity;
    int top;
} * Arraystack;

_Bool initStack(Arraystack stack);
_Bool PushStack(Arraystack stack, E element);
_Bool isEmpty(Arraystack stack);
E PopStack(Arraystack stack);

_Bool PushStack(Arraystack stack, E element);
int main()
{
    struct Stack stack;
    initStack(&stack);
    for(int i = 0; i <= 3; i++)
        PushStack(&stack, i);
    for(int i = 0; i <= 3; i++)
        printf("%d\n", stack.array[i]);
    while(isEmpty(&stack)){
        printf("%d\n", PopStack(&stack));
    }
    system("pause");
    return 0;
}

_Bool initStack(Arraystack stack)
{
    stack->array = (E * )malloc(sizeof(E) * 10);
    if(stack->array == NULL)
        return false;
    stack->capacity = 10;
    stack->top = -1;
    return true;
}

_Bool PushStack(Arraystack stack, E element)
{
    if(stack->top + 1 == stack->capacity){
        int newCapacity = stack->capacity + (stack->capacity >> 1);
        stack->capacity = newCapacity;
        E * newArraystack = (E * )realloc(stack->array, sizeof(E) * newCapacity);
        if(newArraystack == NULL)
            return false;
        stack->array = newArraystack;
    }
    stack->array[++stack->top] = element;   
    return true;
}

_Bool isEmpty(Arraystack stack)
{
    if(stack->top == -1)
        return false;
    return true;
}

E PopStack(Arraystack stack)
{
    return stack->array[stack->top--];
}