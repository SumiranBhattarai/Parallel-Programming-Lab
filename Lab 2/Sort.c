#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
void main()
{
    double start, end;
    int range, temp;
    FILE *fp = fopen("random.txt", "r");
    FILE *fp2 = fopen("sorted.txt", "w");
    printf("Enter n: ");
    scanf("%d", &range);
    int arr[range];
    start = omp_get_wtime();
    for (int i = 0; i < range; i++)
    {
        fscanf(fp, "%d", &arr[i]);
    }
    for (int i = 0; i < range; i++)
    {
        for (int j = i + 1; j < range; j++)
        {
            if (arr[i] > arr[j])
            {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    for (int i = 0; i < range; i++)
    {
        printf("%d ", arr[i]);
        fprintf(fp2, "%d\n ", arr[i]);
    }
    end = omp_get_wtime();
    printf("Time taken: %f seconds\n", end - start);
}