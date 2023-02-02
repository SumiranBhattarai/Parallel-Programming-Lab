/*to use more than 1 core: export OMP_NUM_THREADS="int"*/
#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
static long num_steps = 100000;
double step;
void main()
{
    int i, tid, numt, psum;
    double x, pi, sum = 0, end, start;
    start = omp_get_wtime();
    step = 1.0 / (double)num_steps;
#pragma omp parallel default(shared) private(i, tid, psum)
    {
        int from, to, psum = 0;
        tid = omp_get_thread_num();
        numt = omp_get_num_threads();
        from = (num_steps / numt) * tid;
        to = (num_steps / numt) * (tid + 1) - 1;
        if (tid == numt - 1)
            to = num_steps - 1;
        printf("\nHello from %d to %d,my range %d to %d", tid, numt, from, to);
        for (i = from; i <= to; i++)
        {
            x = (i + 0.5) * step;
#pragma omp critical
            sum = sum + 4.0 / (1.0 + x * x);
        }
    }
    pi = step * sum;
    printf("\nValue of PI: %f", pi);
    end = omp_get_wtime();
    printf("\nExecution Time: %f", end - start);
}
