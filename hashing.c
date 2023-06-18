#include <stdio.h>
#define size 7

int arr[size];

void init()
{
    int i;
    for (i = 0; i < size; i++)
    {
        arr[i] = -1;
    }
}

int hashFunc2(int value)
{
    return (5 - (value % 5));
}

void linearProbing(int value)
{
    int key = value % size;
    if (arr[key] == -1)
    {
        arr[key] = value;
        printf("%d inserted at arr[%d]\n", value, key);
    }
    else
    {
        printf("Collision : arr[%d] has element %d already\n", key, arr[key]);
        while (arr[key] != -1)
        {
            key = (key + 1) % size;
        }
        arr[key] = value;
        printf("%d inserted at arr[%d]\n", value, key);
    }
}

void quadraticProbing(int value)
{
    int key = value % size;
    if (arr[key] == -1)
    {
        arr[key] = value;
        printf("%d inserted at arr[%d]\n", value, key);
    }
    else
    {
        printf("Collision : arr[%d] has element %d already\n", key, arr[key]);
        int i = 1;
        while (key != -1)
        {
            key = (key + i * i) % size;
            i++;
        }
        arr[key] = value;
        printf("%d inserted at arr[%d]\n", value, key);
    }
}

void doubleHashing(int value)
{
    int key = value % size;
    if (arr[key] == -1)
    {
        arr[key] = value;
        printf("%d inserted at arr[%d]\n", value, key);
    }
    else
    {
        printf("Collision : arr[%d] has element %d already\n", key, arr[key]);
        int i = 1;
        while (key != -1)
        {
            key = (key + i * hashFunc2(value)) % size;
            i++;
        }
        arr[key] = value;
        printf("%d inserted at arr[%d]\n", value, key);
    }
}
void print()
{
    int i;
    for (i = 0; i < size; i++)
    {
        printf("arr[%d] = %d\n", i, arr[i]);
    }
}

int main()
{
    init();
    int ch=0;
    printf("enter 1 for linearprobing, 2for quadraticprobing, 3 for doublehashing\n");
    scanf("%d", &ch);
    printf("enter 7 elements\n");
    switch (ch)
    {
    case 1:
        for (int i = 0; i< size; i++)
        {
            int val;
            scanf("%d", &val);
            linearProbing(val);
        }        
        break;
    case 2:
        for (int i = 0; i< size; i++)
        {
            int val;
            scanf("%d", &val);
            quadraticProbing(val);
        }        
        break;
    case 3:
        for (int i = 0; i< size; i++)
        {
            int val;
            scanf("%d", &val);
            doubleHashing(val);
        }        
        break;
    default:
    printf("invalid value");
        break;
    }
    print();

    return 0;
}
