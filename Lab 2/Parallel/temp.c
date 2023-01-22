#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

#define MAX_NUMBERS 1000000

int main()
{
    int even_numbers[MAX_NUMBERS];
    int odd_numbers[MAX_NUMBERS];
    int even_count = 0;
    int odd_count = 0;
    double start, end;
    // Read even numbers from even.txt
    FILE *even_file = fopen("even.txt", "r");
    if (even_file == NULL)
    {
        printf("Could not open even.txt\n");
        return 1;
    }
    while (fscanf(even_file, "%d", &even_numbers[even_count]) == 1)
    {
        even_count++;
    }
    fclose(even_file);

    // Read odd numbers from odd.txt
    FILE *odd_file = fopen("odd.txt", "r");
    if (odd_file == NULL)
    {
        printf("Could not open odd.txt\n");
        return 1;
    }
    while (fscanf(odd_file, "%d", &odd_numbers[odd_count]) == 1)
    {
        odd_count++;
    }
    fclose(odd_file);
    start = omp_get_wtime();
// Sort even numbers
#pragma omp parallel for
    for (int i = 0; i < even_count; i++)
    {

        for (int j = 0; j < even_count - 1; j++)
        {
            if (even_numbers[j] > even_numbers[j + 1])
            {
                int temp = even_numbers[j];
                even_numbers[j] = even_numbers[j + 1];
                even_numbers[j + 1] = temp;
            }
        }
    }

// Sort odd numbers
#pragma omp parallel for
    for (int i = 0; i < odd_count; i++)
    {

        for (int j = 0; j < odd_count - 1; j++)
        {
            if (odd_numbers[j] > odd_numbers[j + 1])
            {
                int temp = odd_numbers[j];
                odd_numbers[j] = odd_numbers[j + 1];
                odd_numbers[j + 1] = temp;
            }
        }
    }

    // Combine and sort even and odd numbers
    int sorted_numbers[even_count + odd_count];
    int e = 0;
    int o = 0;
    for (int i = 0; i < even_count + odd_count; i++)
    {
        if (e < even_count && o < odd_count)
        {
            if (even_numbers[e] < odd_numbers[o])
            {
                sorted_numbers[i] = even_numbers[e++];
            }
            else
            {
                sorted_numbers[i] = odd_numbers[o++];
            }
        }
        else if (e < even_count)
        {
            sorted_numbers[i] = even_numbers[e++];
        }
        else
        {
            sorted_numbers[i] = odd_numbers[o++];
        }
        printf("%d\n", sorted_numbers[i]);
    }
    end = omp_get_wtime();
    printf("Total time: %f\n", end - start);
}