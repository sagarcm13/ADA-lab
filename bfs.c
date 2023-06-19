#include<stdio.h>
// #include<conio.h>
void insert_rear(int q[],int *r, int item, int size)
{
    if(*r==size)
    printf("Queue overflow!\n");
    else
    {
        *r=*r+1;
        q[*r]=item;
    }
}
int delete_front(int q[],int *r, int *f)
{
    int del_item=-1;
    *f=*f+1;
    del_item=q[*f];


    return del_item;
}
int isEmpty(int q[], int *r, int *f)
{
    if(*r==-1 || *r==*f)
    return 1;
    else
    return 0;
}
int main()
{
    int n,i,j,r=-1,f=-1,k;
    printf("Enter the number of vertices:\n");
    scanf("%d",&n);
    printf("Enter the adjacency matrix representing the graph:\n");
    int graph[n][n];
    int vis[n],q[n];
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
    printf("Enter starting node: ");
    scanf("%d",&k);

    printf("%d ",k);
    vis[k]=1;
    insert_rear(q,&r,k,n);
    while(isEmpty(q,&r,&f)==0)
    {
        int node=delete_front(q,&r,&f);
        for(j=0;j<n;j++)
        {
            if(graph[node][j]==1 && vis[j]==0)
            {
                printf("%d ",j);
                vis[j]=1;
                insert_rear(q,&r,j,n);
            }
        }
    }
    return 0;
}