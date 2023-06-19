#include<stdio.h>
int graph[20][20],c=01;
void DFS(int i,int vis[],int n)
{
    int j;
    printf("%d ",i);
    vis[i]=1;
    for(j=0;j<n;j++)
    {
        if(graph[i][j]==1 && vis[j]==0)
        {
            c++;
            DFS(j,vis,n);
        }
    }
}
void main()
{
    int n;
    printf("Enter the number of vertices:\n");
    scanf("%d",&n);
    printf("Enter the adjacency matrix representing the graph:\n");
    int vis[n];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            scanf("%d",&graph[i][j]);
        }
    }
    for(int i=0;i<n;i++)
    {
        vis[i]=0;
    }
    DFS(0,vis,n);
    if (c==n)
    {
        printf("\nconnected");
    }
    
}