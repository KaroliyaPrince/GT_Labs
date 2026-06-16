#include<stdio.h>
void main(){
    int number_of_vertex = 0;

    printf("Enter number of vertex = ");
    scanf("%d", &number_of_vertex);

    int number_of_edges;

    printf("Enter number of edges = ");
    scanf("%d", &number_of_edges);

    int edges[number_of_edges][2];
    int ans[number_of_vertex][number_of_vertex];

    for(int i=0;i<number_of_edges;i++){
        for(int j=0;j<2;j++){
            printf("Enter vertex = ");
            scanf("%d",&edges[i][j]);
        }
    }

    
    for(int i=0;i<number_of_edges;i++){
        for(int j=0;j<number_of_vertex;j++){
            ans[i][j] = 0;
        }
    }


    for(int i=0 ; i<number_of_vertex;i++){
        for(int j=0 ; j<number_of_vertex;j++){
            for(int k=0;k<number_of_edges;k++){
                if((i==edges[k][0] && j==edges[k][1]) || (i==edges[k][1] && j==edges[k][0])){
                    ans[i][j] = 1;
                }
            }
        }
    }

    
    for(int i=0;i<number_of_edges;i++){
        for(int j=0;j<number_of_vertex;j++){
            printf("%d",ans[i][j]);
        }
        printf("\n");
    }

}