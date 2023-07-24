#include <stdio.h>
int g[10][10];
int min(int n, int m)
{
    if (n < m)
    {
        return n;
    }
    else
        return m;
}
void floyd(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < n; k++)
            {
                g[j][k] = min(g[j][k], g[j][i] + g[i][k]);
            }
        }
    }
}
void main()
{
    printf("enter no of vertices \n");
    int n;
    scanf("%d", &n);
    printf("enter the weighted matrix if no edge exists enter bigger number\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &g[i][j]);
        }
    }
    floyd(n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", g[i][j]);
        }
        printf("\n");
    }
}