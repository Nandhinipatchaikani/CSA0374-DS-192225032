#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

struct Stack {
    int data[MAX_SIZE];
    int top;
};

void initialize(struct Stack* stack) {
    stack->top = -1;
}

int isEmpty(struct Stack* stack) {
    return stack->top == -1;
}

int isFull(struct Stack* stack) {
    return stack->top == MAX_SIZE - 1;
}

void push(struct Stack* stack, int value) {
    if (isFull(stack)) {
        printf("Stack overflow. Cannot push %d.\n", value);
        return;
    }
    stack->data[++stack->top] = value;
}

int pop(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack underflow. Cannot pop.\n");
        return -1;
    }
    return stack->data[stack->top--];
}

int peek(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty.\n");
        return -1;
    }
    return stack->data[stack->top];
}

int areParenthesesBalanced(const char* expression) {
    struct Stack stack;
    initialize(&stack);

    for (int i = 0; expression[i] != '\0'; i++) {
        if (expression[i] == '(' || expression[i] == '[' || expression[i] == '{') {
            push(&stack, expression[i]);
        } else if (expression[i] == ')' || expression[i] == ']' || expression[i] == '}') {
            if (isEmpty(&stack)) {
                return 0;
            }

            char popped = pop(&stack);
            if ((expression[i] == ')' && popped != '(') ||
                (expression[i] == ']' && popped != '[') ||
                (expression[i] == '}' && popped != '{')) {
                return 0;
            }
        }
    }

    return isEmpty(&stack);
}
int main() {
    const char* expression1 = "{[()]()}";
    if (areParenthesesBalanced(expression1)) {
        printf("%s is balanced.\n", expression1);
    } else {
        printf("%s is not balanced.\n", expression1);
    }

    const char* expression2 = "{[(])}";
    if (areParenthesesBalanced(expression2)) {
        printf("%s is balanced.\n", expression2);
    } else {
        printf("%s is not balanced.\n", expression2);
    }

    // Application 2: Postfix Expression Evaluation
    const char* postfixExpression = "23*5+";
    int result = evaluatePostfixExpression(postfixExpression);
    printf("Result of %s = %d\n", postfixExpression, result);

    return 0;
}

