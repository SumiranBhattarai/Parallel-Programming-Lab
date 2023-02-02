#include <stdio.h>
#include <omp.h>
#define ASIZE 1000
void main()
{
    double t1, t2;
    int a[ASIZE], i, tid, numt, psum, sum = 0;
    for (i = 0; i < ASIZE; i++)
    {
        a[i] = 1;
    }
    t1 = omp_get_wtime();

#pragma omp parallel default(shared) private(i, tid, psum)
    {
        int from, to, psum = 0;
        tid = omp_get_thread_num();
        numt = omp_get_num_threads();
        from = (ASIZE / numt) * tid;
        to = (ASIZE / numt) * (tid + 1) - 1;
        if (tid == numt - 1)
            to = ASIZE - 1;

        printf("\nHello from %d to %d,my range %d to %d", tid, numt, from, to);
        // #pragma omp for
        for (i = from; i <= to; i++)
            psum += a[i];
#pragma omp critical
        sum += psum;
    }
    t2 = omp_get_wtime();
    printf("\nSum is %d time taken %f", sum, t2 - t1);
}
