#include <stdio.h>

int stack[10], top = -1;
int visited[10];

void push(int x)
{
    stack[++top] = x;
}

int pop()
{
    return stack[top--];
}

int main()
{
    int graph[5][5] = {
        {0,1,1,0,0},
        {1,0,0,1,0},
        {1,0,0,0,1},
        {0,1,0,0,0},
        {0,0,1,0,0}
    };

    int i, node;

    push(0);

    printf("DFS Traversal: ");

    while(top != -1)
    {
        node = pop();

        if(visited[node] == 0)
        {
            printf("%d ", node);
            visited[node] = 1;

            for(i = 4; i >= 0; i--)
            {
                if(graph[node][i] == 1 && visited[i] == 0)
                {
                    push(i);
                }
            }
        }
    }

    return 0;
}
