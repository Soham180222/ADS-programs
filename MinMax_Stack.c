#include <stdio.h>

#define MAX 10

struct Stack
{
    int a[MAX];
    int smax[MAX];
    int smin[MAX];
    int top;
};

void push(struct Stack *s, int x)
{
    if (s->top == MAX - 1)
    {
        printf("Stack Overflow\n");
    }
    else
    {
        s->top++;
        s->a[s->top] = x;

        if (s->top == 0)
        {
            s->smax[s->top] = x;
            s->smin[s->top] = x;
        }
        else
        {
            if (x > s->smax[s->top - 1])
                s->smax[s->top] = x;
            else
                s->smax[s->top] = s->smax[s->top - 1];

            if (x < s->smin[s->top - 1])
                s->smin[s->top] = x;
            else
                s->smin[s->top] = s->smin[s->top - 1];
        }
    }
}

void pop(struct Stack *s)
{
    if (s->top == -1)
    {
        printf("Stack Underflow\n");
    }
    else
    {
        printf("Popped element is %d\n", s->a[s->top]);
        s->top--;
    }
}

int maximum(struct Stack *s)
{
    return s->smax[s->top];
}

int minimum(struct Stack *s)
{
    return s->smin[s->top];
}

int main()
{
    struct Stack s;
    s.top = -1;

    push(&s, 15);
    push(&s, 9);
    push(&s, 13);
    push(&s, 22);
    push(&s, 7);
    push(&s, 10);
    push(&s, 18);

    printf("Maximum = %d\n", maximum(&s));
    printf("Minimum = %d\n", minimum(&s));

    pop(&s);

    printf("Maximum = %d\n", maximum(&s));
    printf("Minimum = %d\n", minimum(&s));

    return 0;
}
