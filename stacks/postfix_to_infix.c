#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 100

typedef struct {
    char items[MAX_SIZE];
    int top;
} Stack;

void initializeStack(Stack* stack) {
    stack->top = -1;
}

int isEmpty(Stack* stack) {
    return stack->top == -1;
}

int isFull(Stack* stack) {
    return stack->top == MAX_SIZE - 1;
}

void push(Stack* stack, char item) {
    if (isFull(stack)) {
        printf("Stack overflow!\n");
        exit(EXIT_FAILURE);
    }
    stack->items[++stack->top] = item;
}

char pop(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack underflow!\n");
        exit(EXIT_FAILURE);
    }
    return stack->items[stack->top--];
}

void postfixToInfix(char* postfix, char* infix) {
    Stack stack;
    initializeStack(&stack);
    int i = 0, j = 0;
    char operand1[MAX_SIZE], operand2[MAX_SIZE], op[MAX_SIZE];

    while (postfix[i] != '\0') {
        char current = postfix[i];

        if (isalnum(current)) {
            push(&stack, current);
        } else {
            operand2[0] = pop(&stack);
            operand1[0] = pop(&stack);
            operand2[1] = operand1[1] = '\0';
            sprintf(op, "%c", current);
            strcat(infix, "(");
            strcat(infix, operand1);
            strcat(infix, op);
            strcat(infix, operand2);
            strcat(infix, ")");
            push(&stack, infix);
            infix[0] = '\0';
        }

        i++;
    }

    if (!isEmpty(&stack)) {
        printf("Invalid postfix expression!\n");
        exit(EXIT_FAILURE);
    }
}

int main() {
    char postfix[MAX_SIZE];
    char infix[MAX_SIZE];

    printf("Enter a postfix expression: ");
    scanf("%s", postfix);

    postfixToInfix(postfix, infix);

    printf("Infix expression: %s\n", infix);

    return 0;
}
