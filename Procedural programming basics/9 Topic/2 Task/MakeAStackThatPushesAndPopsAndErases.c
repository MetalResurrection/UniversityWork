#include <stdio.h>
#include <stdlib.h>

typedef struct Stack {

    int sizeOfDynamicStack;
    int *theStack;
    int top;

} Stack;

void initStack(Stack *stack);
void printStack(Stack *stack);
int getStackSize(Stack *stack);
void push(Stack *stack, int value);
int top(Stack *stack);
int pop(Stack *stack);
void destroyStack(Stack *stack);

int main() {

    Stack stack;
    initStack(&stack);

    push(&stack, 5);
    push(&stack, 10);
    push(&stack, 15);
    push(&stack, 20);

    printStack(&stack);

    printf("Top element: %d\n", top(&stack));

    printf("Stack size: %d\n", getStackSize(&stack));

    printf("Removed element: %d\n\n", pop(&stack));

    printStack(&stack);

    printf("Top element: %d\n", top(&stack));

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
    printf("%d ", stack->theStack[i]);
    }

    printf("\n");
}





int getStackSize(Stack *stack) {
    return stack->top;
}






void push(Stack *stack, int value) {

    if(stack->top == stack->sizeOfDynamicStack) {
            int newSize = (stack->sizeOfDynamicStack == 0) ? 1 : stack->sizeOfDynamicStack * 2;

    int *temp = realloc(stack->theStack, newSize * sizeof(int));

    if (temp == NULL) {
        printf("Memory allocation failed\n");
        return;
         }

         stack->theStack = temp;

         stack->sizeOfDynamicStack = newSize;

   }


  stack->theStack[stack->top] = value;

    stack->top++;
}

int top(Stack *stack) {

    if(stack->top != 0) {
    return stack->theStack[stack->top-1];
    }
    else {
        printf("The array is empty, the element on top is 0\n");
        return -1;
    }
}

int pop(Stack *stack) {

    if (stack->top == 0) {
        printf("Stack is empty!\n");
        return -1;
    }

    int value = top(stack);

    stack->top--;

    int newSize = stack->sizeOfDynamicStack / 2;

    if (newSize >= stack->top && newSize > 0) {

        int *temp = realloc(stack->theStack,
                            newSize * sizeof(int));

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


