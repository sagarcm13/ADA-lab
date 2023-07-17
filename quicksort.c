#include<stdio.h>
#include <stdlib.h>
#include <time.h>
void swap(int *x,int *y){
    int t=*x;
    *x=*y;
    *y=t;
}
int partion(int a[],int l,int h){
    int i=l,j=h+1;
    int pivot =a[l];
    while (1)
    {
        do
        {
            i++;
        } while (a[i]<pivot);
        do
        {
            j--;
        } while (a[j]>pivot);
        if (i<j)
        {
            swap(&a[i],&a[j]);
        }
        if (i>j)
        {
            swap(&a[l],&a[j]);
            break;
        }
    }
     return j;
    
}
void quicksort(int a[],int l,int h){
    if (l<h)
    {
        int m=partion(a, l, h);
        quicksort(a,l,m-1);
        quicksort(a,m+1,h);
    }
    
}
void main(){
    int n;
    printf("enter the no of elements\n");
    scanf("%d",&n);
    clock_t st,end;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        a[i]=rand()%500;
    }
    st=clock();
    quicksort(a, 0, n-1);
    end=clock();
    for (int i = 0; i < n; i++)
    {
        printf("%d ",a[i]);
    }        
    printf("\nTime taken to %d elements %lf ",n,(((double)(end-st))/CLOCKS_PER_SEC));
}
