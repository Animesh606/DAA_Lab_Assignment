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

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int *arr, int l, int r)
{
    int i = l - 1, pivot = arr[r];
    for(int j = l; j < r; j++) {
        if(arr[j] < pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[r]);
    return i + 1;
}

void quickSort(int *arr, int l, int r)
{
    if (l < r)
    {
        int pivot = partition(arr, l, r);
        quickSort(arr, l, pivot - 1);
        quickSort(arr, pivot + 1, r);
    }
}

int main()
{
    int n;
    printf("Enter the number of Element int array : ");
    scanf("%d", &n);
    printf("Enter %d Elements :\n", n);
    int *arr = inputArr(n);
    quickSort(arr, 0, n - 1);
    printf("The Sorted Array is :\n");
    printArr(arr, n);
    return 0;
}