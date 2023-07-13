#include <stdio.h>
void swap(int *i, int *j)
{
    int t = *i;
    *i = *j;
    *j = t;
}
int position(int *a, int l, int h)
{
    int i = l, j = h + 1, p = a[l];
    while (1)
    {
        do
        {
            i++;
        } while (p >= a[i]);
        do
        {
            j--;
        } while (p < a[j]);
        if (i < j)
        {
            swap(&a[i], &a[j]);
        }
        if (i>=j)
        {
            break;
        }
        
    }
    if (i > j)
    {
        swap(&a[l], &a[j]);
    }
    return j;
}
void qsort(int *a, int l, int h)
{
    if (l < h)
    {
        int m = position(a, l, h);
        qsort(a, l, m - 1);
        qsort(a, m + 1, h);
    }
}
void main()
{
    int a[5] = {15, 23, 13, 44, 65};
    qsort(a, 0, 4);
    for (int i = 0; i < 5; i++)
    {
        printf("%d ", a[i]);
    }
}