#include <omp.h>
#include <stdio.h>
#include <stdlib.h>
void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}
int partition(int array[], int low, int high)
{
    int pivot = array[high];
    int i = low - 1;
    for (int j = low; j < high; j++)
    {
        if (array[j] <= pivot)
        {
            i++;
            swap(&array[i], &array[j]);
        }
    }
    swap(&array[i + 1], &array[high]);
    return i + 1;
}

void quicksort(int array[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(array, low, high);
        quicksort(array, low, pi - 1);
        quicksort(array, pi + 1, high);
    }
}
void printArray(int array[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d\n", array[i]);
    }
    printf("\n");
}
int main()
{
    FILE *ptr;
    int n;
    printf("\nEnter Range: ");
    scanf("%d", &n);
    int arr[n];
    double t1 = 0.0, t2 = 0.0;
    ptr = fopen("output.txt", "r");
    printf("\nUnsorted");
    for (int i = 0; i < n; i++)
        fscanf(ptr, "%d", &arr[i]);
    t1 = omp_get_wtime();
    quicksort(arr, 0, n - 1);
    t2 = omp_get_wtime();
    // printArray(arr, n);
    printf("Execution Time: %f\n ", t2 - t1);
    return 0;
}
