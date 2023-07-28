// #include<stdio.h>
// #define MAXLEN 100
// typedef struct{ 
//     int char[MAXLEN];
//     int top;
// } stack;
// stack push ( stack S , int x )
// { 
//     if (isFull(S))
// printf("OVERFLOW\n");
// else
// { 
//     ++S.top;
//     S.element[S.top] = x;
// }
// return S; 
// }

// stack pop ( stack S )
// {
//      if (isEmpty(S))
//         printf("UNDERFLOW\n");
//     else
//         { --S.top;}
//         return S;
//     }

// void print ( stack S )
// { int i;
// for (i= S.top; i>= 0; --i)
//     printf("%d",S.element[i]);
//      }
// int precedence(char a, char b){

// }
#include <stdio.h>
#include <stdlib.h>
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

int precedence(char operator) {
    switch (operator) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
            return 3;
        default:
            return 0;
    }
}

void infixToPostfix(char* infix, char* postfix) {
    Stack stack;
    initializeStack(&stack);
    int i = 0, j = 0;

    while (infix[i] != '\0') {
        char current = infix[i];

        if (isalnum(current)) {
            postfix[j++] = current;
        } else if (current == '(') {
            push(&stack, current);
        } else if (current == ')') {
            while (!isEmpty(&stack) && stack.items[stack.top] != '(') {
                postfix[j++] = pop(&stack);
            }
            if (!isEmpty(&stack) && stack.items[stack.top] == '(') {
                pop(&stack); // Discard the opening parenthesis
            } else {
                printf("Invalid infix expression!\n");
                exit(EXIT_FAILURE);
            }
        } else {
            while (!isEmpty(&stack) && precedence(current) <= precedence(stack.items[stack.top])) {
                postfix[j++] = pop(&stack);
            }
            push(&stack, current);
        }

        i++;
    }

    while (!isEmpty(&stack)) {
        if (stack.items[stack.top] == '(') {
            printf("Invalid infix expression!\n");
            exit(EXIT_FAILURE);
        }
        postfix[j++] = pop(&stack);
    }

    postfix[j] = '\0';
}

int main() {
    char infix[MAX_SIZE];
    char postfix[MAX_SIZE];

    printf("Enter an infix expression: ");
    scanf("%s", infix);

    infixToPostfix(infix, postfix);

    printf("Postfix expression: %s\n", postfix);

    return 0;
}
