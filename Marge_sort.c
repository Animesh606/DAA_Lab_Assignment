#include <stdio.h>
#include <stdlib.h>

int *inputArr(int n)
{
    int *arr = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    return arr;
}

void printArr(int *arr, int n)
{
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

void margeArray(int *arr, int l, int mid, int r)
{
    int *arr2 = (int *) malloc((r - l + 1) * sizeof(int));
    int i = l, j = mid + 1, k = 0;
    while(i <= mid && j <= r)
    {
        if(arr[i] <= arr[j])
            arr2[k++] = arr[i++];
        else
            arr2[k++] = arr[j++];
    }
    while(i <= mid)
        arr2[k++] = arr[i++];
    while(j <= r)
        arr2[k++] = arr[j++];
    for(int i = l; i <= r; i++)
        arr[i] = arr2[i - l];
    free(arr2);
}

void margeSort(int *arr, int l, int r)
{
    if (l < r)
    {
        int mid = (l + r) / 2;
        margeSort(arr, l, mid);
        margeSort(arr, mid + 1, r);
        margeArray(arr, l, mid, r);
    }
}

int main()
{
    int n;
    printf("Enter the number of Element int array : ");
    scanf("%d", &n);
    printf("Enter %d Elements :\n", n);
    int *arr = inputArr(n);
    margeSort(arr, 0, n - 1);
    printf("The Sorted Array is :\n");
    printArr(arr, n);
    return 0;
}