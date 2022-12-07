#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct Point
{
    double x, y;
} Point;

typedef struct Stack
{
    Point *pointer;
    int size;
} Stack;

void initStack(Stack *stack);
Point createPoint(double x, double y);
double getDistance(Point a, Point b);
void push(Stack *stack, Point value);
Point top(Stack *stack);
Point pop(Stack *stack);
void printStack(Stack *stack);
void destroyStack(Stack *stack);

int main()
{
    Stack stack;
    initStack(&stack);
    push(&stack, createPoint(1.2, 2.0));
    push(&stack, createPoint(3.1, 4.3));
    push(&stack, createPoint(5.0, 6.0));
    push(&stack, createPoint(7.1, 8.0));
    push(&stack, createPoint(9.3, 10.1));
    printStack(&stack);
    Point point;
    point = pop(&stack);
    printf("paskutinis elementas: (%f,%f)\n", point.x, point.y);
    destroyStack(&stack);
    return 0;
}

void initStack(Stack *stack)
{
    stack->size = 0;
    stack->pointer = calloc(stack->size, sizeof(Point));
}

Point createPoint(double x, double y)
{
    Point p;
    p.x = x;
    p.y = y;
    return p;
}

double getDistance(Point a, Point b)
{
    float distance;
    distance = sqrt(pow(a.x-b.x,2)+pow(a.y-b.y,2));
    return distance;
}

void push(Stack *stack, Point value)
{
    stack->size = stack->size + 1;
    stack->pointer = realloc(stack->pointer, (stack->size+1) * sizeof(Point));
    stack->pointer[stack->size] = value;
}

Point top(Stack *stack)
{
    if(stack->size == 0)
    {
        Point point;
        point.x = 0;
        point.y = 0;
        return point;
    }
    else
    {
        return (stack->pointer [stack->size]);
    }
}

Point pop(Stack *stack)
{
    Point deleted_object = top(stack);
    stack->size = stack->size - 1;
    stack->pointer = realloc(stack->pointer, (stack->size-1) * sizeof(Point));
    return deleted_object;
}

void printStack(Stack *stack)
{
    for (int i = 1; i <= 5; ++i)
    {
        printf("koordinates: (%f,%f) atstumas iki pradzios: %f\n", stack->pointer[i].x , stack->pointer[i].y, getDistance(createPoint(0,0), stack->pointer[i]));
    }
}

void destroyStack(Stack *stack)
{
    free(stack->pointer);
    stack->size = 0;
}