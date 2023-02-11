#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
void merge(int arr[], int l, int m, int r)
{
    int sl, sr;
    sl = (m - l) + 1;
    sr = (r - m);

    int L[sl], R[sr];

    for (int i = 0; i < sl; i++)
    {
        L[i] = arr[l + i];
    }
    for (int i = 0; i < sr; i++)
    {
        R[i] = arr[m + 1 + i];
    }
    int li = 0;
    int ri = 0;
    int i = l;
    while (li < sl && ri < sr)
    {
        if (L[li] <= R[ri])
        {
            arr[i] = L[li];
            li++;
        }
        else
        {
            arr[i] = R[ri];
            ri++;
        }
        i++;
    }
    while (li < sl)
    {
        arr[i] = L[li];
        li++;
        i++;
    }
    while (ri < sr)
    {
        arr[i] = R[ri];
        ri++;
        i++;
    }
}

void mergesort(int arr[], int l, int r)
{
    if (l < r)
    {
        int m = l + (r - l) / 2;

        mergesort(arr, l, m);
        mergesort(arr, m + 1, r);

        merge(arr, l, m, r);
    }
}
int main()
{
    FILE *ptr;
    int n;
    printf("\nEnter Range: ");
    scanf("%d", &n);
    int arr[n];
    double start, end;
    ptr = fopen("output.txt", "r");
    printf("\nUnsorted");
    for (int i = 0; i < n; i++)
        fscanf(ptr, "%d", &arr[i]);
    start = omp_get_wtime();
    mergesort(arr, 0, n - 1);
    end = omp_get_wtime();
    // printf("\nSorted");
    // for (int i = 0; i < n; i++)
    // {
    //     printf("\n%d", arr[i]);
    // }
    printf("\nExecution Time: %f", end - start);
}
