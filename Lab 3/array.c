#include <stdio.h>
#include <omp.h>
void main()
{
    int sum = 0;
    int i, n = 10000;
    int a[n];
    double start = omp_get_wtime(), end;
    for (i = 0; i < n; i++)
    {
        a[i] = 1;
    }
    for (i = 0; i < n; i++)
    {
        sum = sum + a[i];
    }
    printf("\nSum of %d is %d", n, sum);
    end = omp_get_wtime();
    printf("\nExe time: %f", end - start);
}
