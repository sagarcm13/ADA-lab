#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(int arr[], int N, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (left < N && arr[left] > arr[largest])
    {
        largest = left;
    }

    if (right < N && arr[right] > arr[largest])
    {
        largest = right;
    }

    if (largest != i)
    {
        swap(&arr[i], &arr[largest]);
        heapify(arr, N, largest);
    }
}
void heapSort(int arr[], int N)
{
    for (int i = N / 2 - 1; i >= 0; i--)
    {
        heapify(arr, N, i);
    }

    for (int i = N - 1; i >= 0; i--)
    {
        swap(&arr[0], &arr[i]);
        heapify(arr, i, 0);
    }
}

void printArray(int arr[], int N)
{
    for (int i = 0; i < N; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
void main()
{
    printf("enter no of elements\n");
    int n;
    scanf("%d", &n);
    int arr[n];
    clock_t st,end;
    for (int i = 0; i < n; i++)
    {
        arr[i] =rand();
    }
    st=clock();
    heapSort(arr, n);
    end=clock();
    // printf("Sorted array is\n");
    // printArray(arr, n);
    printf("Time taken to sort %d elements %lf ",n,(((double)(end-st))/CLOCKS_PER_SEC));
}