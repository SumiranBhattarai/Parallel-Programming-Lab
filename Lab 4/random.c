#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
void main()
{
    FILE *ptr;
    long int range, n, num;
    ptr = fopen("output.txt", "w");
    if (ptr == NULL)
    {
        printf("\n File cannot be Opened");
    }
    printf("\nFile opened");
    printf("\nEnter range: ");
    scanf("%ld", &range);
    printf("\nHow mSany samples you want to generate ?\n--> ");
    scanf("%ld", &n);
    for (long int i = 0; i < n; i++)
        fprintf(ptr, "%ld\n", rand() % range);
}
