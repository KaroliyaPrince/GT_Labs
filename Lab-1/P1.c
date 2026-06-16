#include <stdio.h>
void main()
{

    int number_of_vertex = 0;

    printf("Enter number of vertex = ");
    scanf("%d", &number_of_vertex);

    int number_of_edges;

    printf("Enter number of edges = ");
    scanf("%d", &number_of_edges);

    int edges[number_of_edges][2];

    for(int i=0;i<number_of_edges;i++){
        for(int j=0;j<2;j++){
            printf("Enter vertex = ");
            scanf("%d",&edges[i][j]);
        }
    }

    for(int i=0;i<number_of_vertex;i++){
        for(int j=0;j<number_of_edges;j++){
            if(i == edges[j][0]){
                printf("%d -> %d\n",i,edges[j][1]);
            }
        }
    }
}