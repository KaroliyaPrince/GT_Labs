#include<stdio.h>
void main(){
    int number_of_vertex = 0;

    printf("Enter number of vertex = ");
    scanf("%d", &number_of_vertex);

    int number_of_edges;

    printf("Enter number of edges = ");
    scanf("%d", &number_of_edges);

    int edges[number_of_edges][2];
    int adja[number_of_vertex][number_of_vertex];


    for(int i=0;i<number_of_edges;i++){
        for(int j=0;j<2;j++){
            printf("Enter vertex = ");
            scanf("%d",&edges[i][j]);
        }
    }
    
    for(int i=0;i<number_of_edges;i++){
        for(int j=0;j<number_of_vertex;j++){
            adja[i][j] = 0;
        }
    }

    int count = 0;
    int isComplete = 1;
    
     for(int i=0;i<number_of_vertex;i++){
        count = 0;
        for(int j=0;j<number_of_edges;j++){
            if(i == edges[j][0] || i == edges[j][1]){
                count++;
            }
        }

        if(count != number_of_vertex-1){
            isComplete = 0;
            break;
        }
    }

    if(isComplete){
        printf("Complete graph\n\n");
    }
    else{
        printf("Not complete graph\n\n");
    }

    for(int i=0 ; i<number_of_vertex;i++){
        for(int j=0 ; j<number_of_vertex;j++){
            for(int k=0;k<number_of_edges;k++){
                if((i==edges[k][0] && j==edges[k][1]) || (i==edges[k][1] && j==edges[k][0])){
                    adja[i][j] += 1;
                }
            }
        }
    }


    for(int i=0;i<number_of_edges;i++){
        for(int j=0;j<number_of_vertex;j++){
            if(adja[i][j] > 1 || (i==j && adja[i][j] != 0)){
                printf("Not simple graph");
                return;
            }
        }
    }

    printf("Simple graph");
}