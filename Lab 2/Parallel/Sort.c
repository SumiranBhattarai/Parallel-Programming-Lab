#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

void sortArray(int *array, int size)
{
    int i, j, temp;
    for (i = 0; i < size - 1; i++)
    {
        for (j = 0; j < size - i - 1; j++)
        {
            if (array[j] > array[j + 1])
            {
                temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}

int main(int argc, char *argv[])
{
    int i, j, n1, n2;
    int *odd, *even;
    FILE *fp1, *fp2;
    double start, end;
    start = omp_get_wtime();

    fp1 = fopen("odd.txt", "r");
    fp2 = fopen("even.txt", "r");

    fscanf(fp1, "%d", &n1);
    fscanf(fp2, "%d", &n2);

    odd = (int *)malloc(n1 * sizeof(int));
    even = (int *)malloc(n2 * sizeof(int));

    for (i = 0; i < n1; i++)
        fscanf(fp1, "%d", &odd[i]);

    for (i = 0; i < n2; i++)
        fscanf(fp2, "%d", &even[i]);

    // print the unsorted arrays
    printf("Unsorted Odd Numbers: \n");
    for (i = 0; i < n1; i++)
        printf("%d\n", odd[i]);

    printf("Unsorted Even Numbers: \n");
    for (i = 0; i < n2; i++)
        printf("%d\n", even[i]);
    fclose(fp1);
    fclose(fp2);

#pragma omp parallel sections
    {
#pragma omp section
        {
            sortArray(odd, n1);
        }

#pragma omp section
        {
            sortArray(even, n2);
        }
    }

    printf("Sorted Odd Numbers: \n");
    for (i = 0; i < n1; i++)
        printf("%d\n", odd[i]);

    printf("Sorted Even Numbers: \n");
    for (i = 0; i < n2; i++)
        printf("%d\n", even[i]);

    free(odd);
    free(even);
    end = omp_get_wtime();
    printf("Time taken: %f seconds\n", end - start);
    return 0;
}
