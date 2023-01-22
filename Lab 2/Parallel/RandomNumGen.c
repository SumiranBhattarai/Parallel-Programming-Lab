#include <stdio.h>
#include <stdlib.h>
void main()
{
    FILE *fp = fopen("random.txt", "w");
    FILE *fp2 = fopen("odd.txt", "w");
    FILE *fp3 = fopen("even.txt", "w");
    int range;
    int num;
    int n;
    printf("Enter the range of random numbers: ");
    scanf("%d", &range);
    printf("Enter the number of random numbers: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        num = rand() % range;
        if (i % 2 != 0)
        {
            fprintf(fp2, "%d ", num);
        }
        else
        {
            fprintf(fp3, "%d ", num);
        }
    }
    fprintf(fp, "\n");
    printf("Random numbers generated and stored in odd.txt and even.txt\n");
    fclose(fp);
}