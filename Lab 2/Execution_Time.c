#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
void main()
{
    double start, end;
    start = omp_get_wtime();
    for (int i = 0; i < 1000; i++)
    {
        printf("\n%d", i);
    }
    end = omp_get_wtime();
    printf("Time taken : %lf seconds\n", end - start);
}