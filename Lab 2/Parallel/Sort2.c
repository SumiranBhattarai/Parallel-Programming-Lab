#include <stdio.h>
#include <omp.h>
#include <stdlib.h>

#define MAX_SIZE 100

void sort(int arr[], int n)
{
    int i, j, temp;
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main(int argc, char *argv[])
{
    int i, n = 0;
    int odd[MAX_SIZE], even[MAX_SIZE];

    // read odd numbers from odd.txt
    FILE *oddfile = fopen("odd.txt", "r");
    if (oddfile == NULL)
    {
        printf("Unable to open odd.txt\n");
        exit(1);
    }

    while (fscanf(oddfile, "%d", &odd[n]) != EOF)
        n++;

    fclose(oddfile);

// sort the odd numbers
#pragma omp parallel for
    for (i = 0; i < n; i++)
        sort(odd, n);

    // read even numbers from even.txt
    n = 0;
    FILE *evenfile = fopen("even.txt", "r");
    if (evenfile == NULL)
    {
        printf("Unable to open even.txt\n");
        exit(1);
    }

    while (fscanf(evenfile, "%d", &even[n]) != EOF)
        n++;

    fclose(evenfile);

// sort the even numbers
#pragma omp parallel for
    for (i = 0; i < n; i++)
        sort(even, n);

    // display the sorted odd numbers
    printf("Sorted Odd Numbers: ");
    for (i = 0; i < n; i++)
        printf("%d ", odd[i]);
    printf("\n");

    // display the sorted even numbers
    printf("Sorted Even Numbers: ");
    for (i = 0; i < n; i++)
        printf("%d ", even[i]);
    printf("\n");

    return 0;
}