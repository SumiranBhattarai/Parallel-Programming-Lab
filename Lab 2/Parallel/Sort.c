#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
void main()
{
    double start, end;
    int range, temp, count, i, j;
    FILE *fp = fopen("random.txt", "r");
    FILE *fp2 = fopen("sorted.txt", "w");
    FILE *fp3 = fopen("odd.txt", "r");
    FILE *fp4 = fopen("even.txt", "r");
    printf("Enter n: ");
    scanf("%d", &range);
    int arr[range];
    start = omp_get_wtime();
    i = 0;
    while (!feof(fp3))
    {
        temp = fscanf(fp3, "%d", &arr[i]);
        count++;
        i++;
    }
    printf("Count: %d", count);
    for (i = 0; i < range; i++)
    {
        for (j = i + 1; j < range; j++)
        {
            if (arr[i] > arr[j])
            {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    for (i = 0; i < range; i++)
    {
        printf("%d ", arr[i]);
        fprintf(fp2, "%d\n ", arr[i]);
    }
    end = omp_get_wtime();
    printf("Time taken: %f seconds\n", end - start);
}