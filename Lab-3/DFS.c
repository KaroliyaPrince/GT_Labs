#include<stdio.h>

void DFS(int vertex,int adjs[5][5],int size[],int visited[]){

    visited[vertex] = 1;
    printf("%d,",vertex);
    
    for(int i=0;i<size[vertex];i++){
        
        if(!visited[adjs[vertex][i]]){
            DFS(adjs[vertex][i],adjs,size,visited);
        }
    }
}
void main(){

    int adjs[5][5] = {
        {1,3},
        {0,2,3,4},
        {1,4},
        {0,1,4},
        {1,2,3}
    };

    int size[5] = {2,4,2,3,3};

    int visited[5] = {0};

    DFS(0,adjs,size,visited);

}