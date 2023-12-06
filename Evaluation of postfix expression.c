#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_SIZE 100

int stack[MAX_SIZE];
int top = -1;

void push(int value) 
{
    if (top == MAX_SIZE - 1) 
	{
        printf("Stack Overflow\n");
        return;
    }
    stack[++top] = value;
}

int pop() 
{
    if (top == -1) 
	{
        printf("Stack Underflow\n");
        exit(EXIT_FAILURE);
    }
    return stack[top--];
}

int evaluatePostfix(char postfix[]) 
{
	int i;
    for (i = 0; postfix[i] != '\0'; i++) 
	{
        if (isdigit(postfix[i])) 
		{
            push(postfix[i] - '0');
        } 
		else 
		{
            int operand2 = pop();
            int operand1 = pop();
            
            switch (postfix[i]) 
			{
                case '+':
                    push(operand1 + operand2);
                    break;
                case '-':
                    push(operand1 - operand2);
                    break;
                case '*':
                    push(operand1 * operand2);
                    break;
                case '/':
                    push(operand1 / operand2);
                    break;
            }
        }
    }
    return pop();
}

int main() 
{
    char postfix[MAX_SIZE];
    printf("Enter the Postfix expression: ");
    scanf("%s", postfix);

    int result = evaluatePostfix(postfix);
    printf("Result: %d\n", result);

    return 0;
}

