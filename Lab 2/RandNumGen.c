#include <stdio.h>
#include <stdlib.h>
void main()
{
    FILE *fp = fopen("random.txt", "w");
    int range;
    int n;
    printf("Enter the range of random numbers: ");
    scanf("%d", &range);
    printf("Enter the number of random numbers: ");
    scanf("%d", &n);
    for (int i = 0; i < 1000; i++)
    {
        fprintf(fp, "%d ", rand() % range);
    }
    fprintf(fp, "\n");
    printf("Random numbers generated and stored in random.txt\n");
    fclose(fp);
}