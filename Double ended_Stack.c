#include <stdio.h>
#define MAX 10

int a[MAX];
int top1 = -1;
int top2 = MAX;

void pushLeft(int x)
{
    if (top1 + 1 == top2)
        printf("Stack Overflow\n");
    else
    {
        top1++;
        a[top1] = x;
    }
}

void pushRight(int x)
{
    if (top1 + 1 == top2)
        printf("Stack Overflow\n");
    else
    {
        top2--;
        a[top2] = x;
    }
}

void popLeft()
{
    if (top1 == -1)
        printf("Left Stack Underflow\n");
    else
    {
        printf("Deleted: %d\n", a[top1]);
        top1--;
    }
}

void popRight()
{
    if (top2 == MAX)
        printf("Right Stack Underflow\n");
    else
    {
        printf("Deleted: %d\n", a[top2]);
        top2++;
    }
}

void display()
{
    int i;

    printf("Left Stack: ");
    for (i = 0; i <= top1; i++)
        printf("%d ", a[i]);

    printf("\nRight Stack: ");
    for (i = MAX - 1; i >= top2; i--)
        printf("%d ", a[i]);

    printf("\n");
}

int main()
{
    pushLeft(10);
    pushLeft(20);
    pushRight(30);
    pushRight(40);

    display();

    popLeft();
    popRight();

    display();

    return 0;
}
