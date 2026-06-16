#include <stdio.h>

int visited[] = {-1, -1, -1, -1, -1};
int Q[100];
int F = -1;
int R = -1;
int idx = -1;

void EnQueue(int element)
{

    if (F == -1)
    {
        F++;
    }
    Q[++R] = element;
}

int DeQueue()
{

    return Q[F++];
}

int isEmpty()
{
    if (F > R)
    {
        return 1;
    }

    return 0;
}

int isVisited(int element)
{
    for (int i = 0; i < 5; i++)
    {
        if (element == visited[i])
        {
            return 1;
        }
    }

    return 0;
}

void main()
{

    int numberOfVertex;
    int numberOfAdjacentVertex;

    printf("Enter number of vertex = ");
    scanf("%d",&numberOfVertex);

    int list[numberOfVertex][numberOfVertex];
    int size[numberOfVertex];

    for(int i=0;i<numberOfVertex;i++){
        printf("Enter number of adjacent vertex of a vertex %d = ",i);
        scanf("%d",&numberOfAdjacentVertex);
        size[i] = numberOfAdjacentVertex;

        for(int j=0;j<numberOfAdjacentVertex;j++){
            printf("Enter adjacent vertex = ");
            scanf("%d",&list[i][j]);
        }
    }

    printf("BFS traversal for a given graph is ");

    EnQueue(0);
    int vertex = 0;
    visited[++idx] = 0;

    while (1)
    {
        vertex = DeQueue();

        for (int i = 0; i < size[vertex]; i++)
        {
            if (!isVisited(list[vertex][i]))
            {
                EnQueue(list[vertex][i]);
                visited[++idx] = list[vertex][i];
            }
        }

        printf("%d,", vertex);

        if (isEmpty())
        {
            break;
        }
    }
}