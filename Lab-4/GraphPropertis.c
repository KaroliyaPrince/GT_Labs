#include <stdio.h>

int visited[] = {-1, -1, -1, -1, -1,-1};
int Q[100];
int F = -1;
int R = -1;
int idx = -1;
int list[6][6] = {
    {1},
    {0,2,3},
    {1},
    {1,4,5},
    {3},
    {3}
};

int size[6] = {1,3,1,3,1,1};



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

void BFS(int cur,int dis[]){

    EnQueue(cur);
    int vertex = cur;
    visited[++idx] = cur;

    while (1)
    {
        vertex = DeQueue();

        for (int i = 0; i < size[vertex]; i++)
        {
            if (!isVisited(list[vertex][i]))
            {
                EnQueue(list[vertex][i]);
                visited[++idx] = list[vertex][i];
                dis[list[vertex][i]] = dis[vertex]+1;
            }
        }

        if (isEmpty())
        {
            break;
        }
    }

    for(int i=0;i<6;i++){
        visited[i] = -1;
    }
    idx=-1;
}

void main()
{

    int edges[5][2] = {{0, 1}, {1, 2}, {1, 3}, {3, 4}, {3, 5}};

    int degree[6] = {0};

    // for (int i = 0; i < 5; i++)
    // {
    //     degree[edges[i][0]] += 1;
    //     degree[edges[i][1]] += 1;
    // }

    // printf("1.List of pendent vertices\n");
    // for (int i = 0; i < 6; i++)
    // {
    //     if (degree[i] == 1)
    //     {
    //         printf("%d,",i);
    //     }
    // }

    // printf("\n2.Degree of each vertex\n");
    // for (int i = 0; i < 6; i++)
    // {
    //     printf("vertex %d = %d\n",i,degree[i]);
    // }

    int dis[6][6] = {0};

    for(int i=0;i<6;i++){
        BFS(i,dis[i]);
    }

    for(int i=0;i<6;i++){
        for(int j=0;j<6;j++){
            printf("%d ",dis[i][j]);
        }
        printf("\n");
    }
    
}