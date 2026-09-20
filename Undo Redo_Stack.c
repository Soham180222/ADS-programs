#include <stdio.h>

#define MAX 10

int undoStack[MAX];
int redoStack[MAX];

int undoTop = -1;
int redoTop = -1;

void perform(int x)
{
    if (undoTop == MAX - 1)
    {
        printf("Undo Stack Overflow\n");
    }
    else
    {
        undoTop++;
        undoStack[undoTop] = x;

        redoTop = -1;

        printf("Performed: %d\n", x);
    }
}

void undo()
{
    if (undoTop == -1)
    {
        printf("Nothing to Undo\n");
    }
    else
    {
        int x = undoStack[undoTop];
        undoTop--;

        redoTop++;
        redoStack[redoTop] = x;

        printf("Undo: %d\n", x);
    }
}

void redo()
{
    if (redoTop == -1)
    {
        printf("Nothing to Redo\n");
    }
    else
    {
        int x = redoStack[redoTop];
        redoTop--;

        undoTop++;
        undoStack[undoTop] = x;

        printf("Redo: %d\n", x);
    }
}

void display()
{
    int i;

    printf("Undo Stack: ");
    for (i = 0; i <= undoTop; i++)
        printf("%d ", undoStack[i]);

    printf("\nRedo Stack: ");
    for (i = 0; i <= redoTop; i++)
        printf("%d ", redoStack[i]);

    printf("\n");
}

int main()
{
    perform(10);
    perform(20);
    perform(30);

    display();

    undo();
    display();

    redo();
    display();

    undo();
    undo();
    display();

    return 0;
}
