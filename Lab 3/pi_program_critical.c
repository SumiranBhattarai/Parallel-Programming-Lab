#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
static long num_steps = 100000;
double step;
void main()
{
    int i;
    double x, pi, sum = 0, end, start;
    start = omp_get_wtime();
    step = 1.0 / (double)num_steps;
#pragma omp parallel for private(x)
    for (i = 0; i < num_steps; i++)
    {
        x = (i + 0.5) * step;
#pragma omp critical
        sum = sum + 4.0 / (1.0 + x * x);
    }
    pi = step * sum;
    printf("%f", pi);
    end = omp_get_wtime();
    printf("\nExecution Time: %f", end - start);
}
