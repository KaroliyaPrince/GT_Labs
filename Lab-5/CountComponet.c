#include<stdio.h>

void DFS(int vertex,int adjs[4][4],int visited[]){

    visited[vertex] = 1;
    
    for(int i=0;i<4;i++){
        
        if(adjs[vertex][i] != 0 && !visited[i]){
            DFS(i,adjs,visited);
        }
    }
}

int remainingVisited(int visited[]){
    for(int i=0;i<4;i++){
        if(!visited[i]){
            return i;
        }
    }

    return -1;
}

void main(){

    int adjs[4][4] = {
        {1,1,0,0},
        {1,1,0,0},
        {0,0,1,1},
        {0,0,1,1}
    };

    int visited[4] = {0};

    int count = 0;

    int vertex = remainingVisited(visited);

    while(vertex != -1){

        DFS(vertex,adjs,visited);
        count++;
        vertex = remainingVisited(visited);
    }

    printf("%d",count);

}