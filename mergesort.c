#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void merge(int a[], int l, int mid, int h)
{
    
    
    int i, j, k;
    int n1 = mid - l + 1;
    int n2 = h - mid;
 
    int L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = a[l + i];
    for (j = 0; j < n2; j++)
        R[j] = a[mid + 1 + j];
 
    i = 0;
 
    j=0;
    k = l;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            a[k] = L[i];
            i++;
        }
        else
        {
            a[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        a[k] = L[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        a[k] = R[j];
        j++;
        k++;
    }
}

void mergesort(int a[], int l, int h)
{
    if (l < h)
    {
        int mid = l + (h - l) / 2;
        mergesort(a, l, mid);
        mergesort(a, mid + 1, h);
        merge(a, l, mid, h);
    }
}

void main()
{
    printf("enter the no of elements\n");
    long n;
    scanf("%ld",&n);
    clock_t st,end;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        a[i]=rand()%1000;
    }
    for (int i = 0; i < n; i++)
    {
        printf("%d ",a[i]);
    }
        
    st=clock();
    mergesort(a, 0, n-1);
    end=clock();
    printf("Time taken to %ld elements %lf ",n,(((double)(end-st))/CLOCKS_PER_SEC));
}
