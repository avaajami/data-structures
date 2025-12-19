#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

Node *top = NULL;

void push(int x)
{
    Node *p = malloc(sizeof(Node));
    if (p == NULL)
        return;

    p->data = x;
    p->next = top;
    top = p;
}

int pop()
{
    if (top == NULL)
        return -1;

    Node *p = top;
    int x = p->data;
    top = p->next;
    free(p);
    return x;
}

int peek()
{
    if (top == NULL)
        return -1;

    return top->data;
}

int isEmpty()
{
    return top == NULL;
}

int main()
{
    push(5);
    push(10);
    push(15);

    printf("%d\n", pop());
    printf("%d\n", peek());
    printf("%d\n", isEmpty());

    return 0;
}
