#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

Node *front = NULL;
Node *rear = NULL;

void enqueue(int x)
{
    Node *p = malloc(sizeof(Node));
    if (!p) return;

    p->data = x;
    p->next = NULL;

    if (!rear)
        front = rear = p;
    else
    {
        rear->next = p;
        rear = p;
    }
}

int dequeue()
{
    if (!front) return -1;

    Node *p = front;
    int x = p->data;
    front = p->next;

    if (!front)
        rear = NULL;

    free(p);
    return x;
}

int readInt()
{
    int x = 0;
    char c = getchar();

    while (c < '0' || c > '9')
        c = getchar();

    while (c >= '0' && c <= '9')
    {
        x = x * 10 + (c - '0');
        c = getchar();
    }

    return x;
}

int main()
{
    int c, v;

    while (1)
    {
        c = readInt();

        if (c == 1)
        {
            v = readInt();
            enqueue(v);
        }
        else if (c == 2)
        {
            printf("%d\n", dequeue());
        }
        else if (c == 3)
        {
            printf("%d\n", front == NULL);
        }
        else if (c == 4)
            break;
    }

    return 0;
}
