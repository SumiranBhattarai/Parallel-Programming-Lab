#include <stdio.h>
#include <omp.h>
void main()
{
    int tnum;
#pragma omp parallel
    {
        tnum = omp_get_thread_num();
        printf("Hello World! from thread %d\n", tnum);
    }
}