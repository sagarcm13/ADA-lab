#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int b[100000];
void merge(int a[], int l, int mid, int h)
{
    int i = l, k = l, j = mid + 1;
    while (i <= mid && j <= h)
    {
        if (a[i] <= a[j])
        {
            b[k++] = a[i++];
        }
        else
        {
            b[k++] = a[j++];
        }
    }

    while (i < mid + 1)
    {
        b[k] = a[i];
        i++;
        k++;
    }
    while (j <= h)
    {
        b[k] = a[j];
        j++;
        k++;
    }
    for (int i = l; i <= h; i++)
    {
        a[i] = b[i];
    }
    
}

void mergesort(int a[], int l, int h)
{
    int mid;
    if (l < h)
    {
        mid = (h + l) / 2;
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
    clock_t st, end;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        a[i]=rand()%1000;
    }
    st = clock();
    mergesort(a, 0, n - 1);
    end = clock();
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("Time taken to %ld elements %lf ", n, (((double)(end - st)) / CLOCKS_PER_SEC));
}
