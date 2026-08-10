#include <stdio.h>

int queue[10], front = -1, rear = -1;
int visited[10];

void enqueue(int x)
{
    if(rear == 9)
        return;

    if(front == -1)
        front = 0;

    queue[++rear] = x;
}

int dequeue()
{
    return queue[front++];
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

    enqueue(0);
    visited[0] = 1;

    printf("BFS Traversal: ");

    while(front <= rear)
    {
        node = dequeue();
        printf("%d ", node);

        for(i = 0; i < 5; i++)
        {
            if(graph[node][i] == 1 && visited[i] == 0)
            {
                enqueue(i);
                visited[i] = 1;
            }
        }
    }

    return 0;
} 
