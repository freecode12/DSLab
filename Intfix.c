#include<stdio.h>
#include<string.h>

int F(char symbol)
{
    switch(symbol){
        case '+': return 2;
        case '-': return 2;
        case '*': return 4;
        case '/': return 4;
        case '^': return 5;
        case '$': return 5;
        case '(': return 0;
        case '#': return -1;
        default: return 8;
    }

}
int G(char symbol)
{
    switch(symbol){
        case '+': return 1;
        case '-': return 1;
        case '*': return 3;
        case '/': return 3;
        case '^': return 6;
        case '$': return 6;
        case '(': return 9;
        case ')': return 0;
        default: return 7;
    }

}

void intfix_postfix(char intfix[], char postfix[])
{
    int top = -1;
    int i, j = 0;
    char s[30];
    char symbol;
    s[++top] = '#';

    for (i=0; i<strlen(intfix);i++)
    {
        symbol = intfix[i];
        while((F(s[top]))>(G(symbol)))
        {
            postfix[j] = s[top--];
            j++;
        }
        if (F(s[top]) != G(symbol))
            s[++top] = symbol;
        else
            top--;
    }
    while (s[top] != '#')
    {
        postfix[j++] = s[top--];
    }
    postfix[j] = '\0';
}

void main()
{
char intfix[20];
char postfix[20];

printf("Enter an intfix expression\n");
scanf("%s",intfix);

intfix_postfix(intfix,postfix);

printf("The postfix expression is:\n");
printf("%s",postfix);

}
