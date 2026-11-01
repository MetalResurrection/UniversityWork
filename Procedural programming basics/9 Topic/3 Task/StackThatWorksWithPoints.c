#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct Point {
    double x;
    double y;
} Point;

typedef struct Stack {
    int sizeOfDynamicStack;
    Point *theStack;
    int top;
} Stack;

void initStack(Stack *stack);
void printStack(Stack *stack);
int getStackSize(Stack *stack);
void push(Stack *stack, Point value);
Point top(Stack *stack);
Point pop(Stack *stack);
void destroyStack(Stack *stack);

int main() {

    Stack stack;
    initStack(&stack);

    Point p1 = {2, 3};
    Point p2 = {5, 7};
    Point p3 = {10, 15};
    Point p4 = {4, 8};
    Point p5 = {6, 9};

    push(&stack, p1);
    push(&stack, p2);
    push(&stack, p3);
    push(&stack, p4);
    push(&stack, p5);

    printf("Stack elements:\n");
    printStack(&stack);

    Point p = top(&stack);
    printf("Top element: (%.2f, %.2f)\n", p.x, p.y);

    printf("Stack size: %d\n", getStackSize(&stack));

    Point removed = pop(&stack);
    printf("Removed element: (%.2f, %.2f)\n",
           removed.x, removed.y);

    printf("\nStack after pop:\n");
    printStack(&stack);

    p = top(&stack);
    printf("Top element: (%.2f, %.2f)\n", p.x, p.y);

    printf("Stack size: %d\n", getStackSize(&stack));

    destroyStack(&stack);

    return 0;
}

void initStack(Stack *stack) {
    stack->theStack = NULL;
    stack->sizeOfDynamicStack = 0;
    stack->top = 0;
}


void printStack(Stack *stack) {

    for (int i = 0; i < stack->top; i++) {

        double x = stack->theStack[i].x;
        double y = stack->theStack[i].y;

        double distance = sqrt(x * x + y * y);

        printf("Point: (%.2f, %.2f), Distance from origin: %.2f\n",
               x, y, distance);
    }

}


int getStackSize(Stack *stack) {
    return stack->top;
}


void push(Stack *stack, Point value) {

    if (stack->top == stack->sizeOfDynamicStack) {

        int newSize = (stack->sizeOfDynamicStack == 0)
                      ? 1 : stack->sizeOfDynamicStack * 2;

        Point *temp = realloc(stack->theStack,
                              newSize * sizeof(Point));

        if (temp == NULL) {
            printf("Memory allocation failed!\n");
            return;
        }

        stack->theStack = temp;
        stack->sizeOfDynamicStack = newSize;
    }

    stack->theStack[stack->top] = value;
    stack->top++;
}


Point top(Stack *stack) {

    if (stack->top != 0) {
        return stack->theStack[stack->top - 1];
    }
    else {
        printf("Stack is empty!\n");
        return (Point){-1, -1};
    }
}


Point pop(Stack *stack) {

    if (stack->top == 0) {
        printf("Stack is empty!\n");
        return (Point){-1, -1};
    }

    Point value = top(stack);

    stack->top--;


    int newSize = stack->sizeOfDynamicStack / 2;

    if (newSize >= stack->top && newSize > 0) {

        Point *temp = realloc(stack->theStack,
                              newSize * sizeof(Point));

        if (temp != NULL) {
            stack->theStack = temp;
            stack->sizeOfDynamicStack = newSize;
        }
    }

    return value;
}


void destroyStack(Stack *stack) {

    free(stack->theStack);

    stack->theStack = NULL;
    stack->sizeOfDynamicStack = 0;
    stack->top = 0;
}


