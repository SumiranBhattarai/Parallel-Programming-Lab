#include <stdio.h>
#include <omp.h>
void main()
{
#pragma omp parallel;
    printf("Hello World! \n");
}