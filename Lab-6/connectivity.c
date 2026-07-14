#include<stdio.h>

void DFS(int vertex,int adjs[5][5],int visited[],int removeVertex){

    visited[vertex] = 1;
    for(int i=0;i<5;i++){
        
        if(i!=removeVertex && adjs[vertex][i] != 0 && !visited[i]){
            DFS(i,adjs,visited,removeVertex);
        }
    }
}


void main(){
    int edges[5][2] = {{0,1},{1,2},{1,3},{2,4},{3,4}};
    
    int adjs[5][5] = {
        {0,1,0,0,0},
        {1,0,1,1,0},
        {0,1,0,0,1},
        {0,1,0,0,1},
        {0,0,1,1,0}
    };
    int ans[5] = {-1};
    int ans_idx = 0;
    int removeVertex = 0;

    while(removeVertex < 5){
        int visited[5] = {0};
        if(removeVertex == 0){
            DFS(1,adjs,visited,removeVertex);
        }
        else{
            DFS(0,adjs,visited,removeVertex);
        }

        for(int i=0 ; i<5;i++){
            if(i!=removeVertex && visited[i] != 1){
                ans[ans_idx++] = removeVertex;
                break;
            }
        }

        removeVertex++;
        
    }

    for(int i=0 ; i<ans_idx ; i++){
        printf("%d , ",ans[i]);
    }

}