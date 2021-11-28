#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

int rear = -1;

void rearrange(int arr[], int index, int pageframe)
{
    printf("\nPageframe - ");
    int temp = arr[index];
    for (int i = index; i > 0; i--)
    {
        arr[i] = arr[i - 1];
    }
    arr[0] = temp;
    for (int i = 0; i <= rear; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\nHit");
}

void push(int arr[], int num, int pageframe)
{
    printf("\nPageframe - ");
    if (rear >= pageframe - 2)
    {
        rear = pageframe - 2;
    }
    for (int i = rear; i >= 0; i--)
    {
        arr[i + 1] = arr[i];
    }
    arr[0] = num;
    rear++;
    for (int i = 0; i <= rear; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\nMiss");
}

int present(int pages[], int pageframe, int num)
{
    for (int i = 0; i < pageframe; i++)
    {
        if (pages[i] == num)
            return i;
    }
    return -1;
}
int algorithm(int pageref[], int pageframe, int n)
{
    int pages[pageframe], miss = 0;
    for (int i = 0; i < n; i++)
    {
        printf("\nIncoming page number %d", pageref[i]);
        if (present(pages, pageframe, pageref[i]) >= 0)
        {
            rearrange(pages, present(pages, pageframe, pageref[i]), pageframe);
        }
        else
        {
            push(pages, pageref[i], pageframe);
            miss++;
        }
    }
    return miss;
}
int main()
{
    int pageframe = 3;
    int pageref[] = {4, 7, 6, 1, 7, 6, 1, 2, 7, 2};
    printf("\nNumber of Page faults in LRU: %d", algorithm(pageref, pageframe, 10));
    return 0;
}
