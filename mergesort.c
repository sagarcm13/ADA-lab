#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void merge(int a[],int b[], int l, int mid, int h)
{
    
    int i=l, j=mid+1, k=l;
    while (i <= mid && j <= h)
    {
        if (a[i] <= a[j])
        {
            b[k] = a[i];
            i++;
        }
        else
        {
            b[k] = a[j];
            j++;
        }
        k++;
    }
    while (i <=mid) {
        b[k] = a[i];
        i++;
        k++;
    }
    while (j <=h)
    {
        b[k] = a[j];
        j++;
        k++;
    }
}

void mergesort(int a[],int b[], int l, int h)
{
    if (l < h)
    {
        int mid = l + (h - l) / 2;
        mergesort(a,b, l, mid);
        mergesort(a,b, mid + 1, h);
        merge(a,b, l, mid, h);
    }
}

void main()
{
    printf("enter the no of elements\n");
    long n;
    scanf("%ld",&n);
    clock_t st,end;
    int a[n];
    int b[n];   
    for (int i = 0; i < n; i++)
    {
        a[i]=rand()%1000;
    }
    st=clock();
    mergesort(a, 0, n-1);
    end=clock();
    for (int i = 0; i < n; i++)
    {
        printf("%d ",b[i]);
    }
    printf("Time taken to %ld elements %lf ",n,(((double)(end-st))/CLOCKS_PER_SEC));
}
