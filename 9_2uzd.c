#include <stdio.h>
#include <stdlib.h>

typedef struct Stack
{
    int *pointer;
    int size;
} Stack;

void initStack(Stack *stack);
void printStack(Stack *stack);
int getStackSize(Stack *stack);
void push(Stack *stack, int value);
int top(Stack *stack);
int pop(Stack *stack);
void destroyStack(Stack *stack);

int main()
{
    Stack *stack;
    initStack(stack);
    printStack(stack);
    printf("size: %d\n", getStackSize(stack));
    push(stack, 2);
    printf("last value: %d\n", top(stack));
    printf("deleted object: %d\n", pop(stack));
    destroyStack(stack);
    return 0;
}

void initStack(Stack *stack)
{
    stack->size = 0;
    stack->pointer = calloc(stack->size, sizeof(Stack));
}

void printStack(Stack *stack)
{
    printf("pointer: %d, size: %d\n", stack->pointer, stack->size);
}

int getStackSize(Stack *stack)
{
    return stack->size;
}

void push(Stack *stack, int value)
{
    stack->size = stack->size + 1;
    stack->pointer = realloc(stack->pointer, (stack->size) * sizeof(Stack));
    *(stack->pointer + stack->size) = value;
}

int top(Stack *stack)
{
    if(stack->size == 0)
    {
        return 0;
    }
    else
    {
        return *(stack->pointer + stack->size);
    }
}

int pop(Stack *stack)
{
    int deleted_object = top(stack);
    stack->size = stack->size - 1;
    stack->pointer = realloc(stack->pointer, (stack->size) * sizeof(Stack));
    return deleted_object;
}

void destroyStack(Stack *stack)
{
    free(stack->pointer);
}