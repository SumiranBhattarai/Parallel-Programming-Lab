/*NEEDS TO BE dEBUG*/
/*Synchronisation problem*/
#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
static long num_steps = 100000;
double step;
void main()
{
    int i;
    double x, pi, sum1 = 0, sum2 = 0, end, start;
    start = omp_get_wtime();
    step = 1.0 / (double)num_steps;
#pragma omp parallel
    {
#pragma omp sections
        {
#pragma omp section
            {
                for (i = 0; i < num_steps / 2; i++)
                {
                    x = (i + 0.5) * step;
                    sum1 = sum1 + 4.0 / (1.0 + x * x);
                }
            }
#pragma omp section
            {
                for (i = num_steps / 2; i < num_steps; i++)
                {
                    x = (i + 0.5) * step;
                    sum2 = sum2 + 4.0 / (1.0 + x * x);
                }
            }
        }
    }
    sum1 = sum1 + sum2;
    pi = step * sum1;
    printf("%f", pi);
    end = omp_get_wtime();
    printf("\nExecution Time: %f", end - start);
}
